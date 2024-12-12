#include "faculty.h"
#include <iomanip>
#include <algorithm>

faculty::faculty() : Base()
{
    faculty_login["faculty1"] = "123456"; // Faculty login
    faculty_login["faculty2"] = "234567";
    faculty_login["faculty3"] = "345678";
    faculty_login["faculty4"] = "456789";
    faculty1.push_back("math_score");
    faculty2.push_back("history_score");
    faculty3.push_back("physics_score");
    faculty4.push_back("chemistry_score");
    faculty1.push_back("biology_score");
    faculty2.push_back("english_score");
    faculty3.push_back("geography_score");
}

bool faculty::login(std::string email, std::string password)
{
    // Find the email in the student_login map
    auto it = faculty_login.find(email);
    // Check if email exists and password matches
    if (it != faculty_login.end() && it->second == password)
    {
        std::cout << "Login successful!" << std::endl;
        faculty_username = email;
        return true;
    }
    // If login fails
    std::cout << "Invalid email or password." << std::endl;
    return false;
}

std::vector<Student> faculty::get_students()
{
    return this->students;
}

void faculty::view(std::vector<Student> &stud)
{
    std::cout << "Faculty view" << std::endl;
    int size = stud.size();
    int start = 0, end = start + 10;
    char choice;
    while (start < size)
    {
        if (end > size)
        {
            end = size;
        }
        this->clearScreen();
        std::vector <std::string> sub;
        if(faculty_username == "faculty1")
            for(auto ele : faculty1)
            {
                sub.push_back(ele);
            }
        else if(faculty_username == "faculty2")
            for(auto ele : faculty2)
            {
                sub.push_back(ele);
            }
        else if(faculty_username == "faculty3")
            for(auto ele : faculty3)
            {
                sub.push_back(ele);
            }
        else if(faculty_username == "faculty4")
            for(auto ele : faculty4)
            {
                sub.push_back(ele);
            }
        std::ostringstream formattedOutput;
        if(sub.size() == 2)
        {
            formattedOutput << std::setw(20) << std::right << sub[0]
                        << std::setw(20) << std::right << sub[1];
        }
        else
        {
            formattedOutput << std::setw(20) << std::right << sub[0];
        }
        std::cout <<
        std::setw(20) << std::right << "First Name" << 
        std::setw(20) << std::right << "Last Name" << 
        std::setw(30) << std::right << "Email" << formattedOutput.str() << 
        std::setw(12) << "Grade" << 
        std::setw(12) << "CGPA" <<std::endl;
        for (int i = start; i < end; i++)
        {
            std::ostringstream score;
            for(int k = 0; k<sub.size(); k++)
            {
                if(sub[k] == "math_score")
                    score << std::setw(20) << std::right << stud[i].math_score ;
                else if(sub[k] == "history_score")
                    score << std::setw(20) << std::right << stud[i].history_score ;
                else if(sub[k] == "physics_score")
                    score << std::setw(20) << std::right << stud[i].physics_score ;
                else if(sub[k] == "chemistry_score")
                    score << std::setw(20) << std::right << stud[i].chemistry_score ;
                else if(sub[k] == "biology_score")
                    score << std::setw(20) << std::right << stud[i].biology_score ;
                else if(sub[k] == "english_score")
                    score << std::setw(20) << std::right << stud[i].english_score ;
                else if(sub[k] == "geography_score")
                    score << std::setw(20) << std::right << stud[i].geography_score ;
            }
            std::cout <<
            std::setw(20) << std::right << stud[i].first_name.substr(0, 20) << 
            std::setw(20) << std::right << stud[i].last_name.substr(0, 20) << 
            std::setw(30) << std::right << stud[i].email.substr(0, 30) << 
            score.str() << 
            std::setw(12) << std::right << stud[i].Grade.substr(0, 20) << 
            std::setw(12) <<std:: right << stud[i].CGPA << 
            std::endl;
        }

        std::cout << "Page " << (start / 10) + 1 << " of " << (size / 10) + 1 << std::endl;
        std::cout << "Press 'n' for next page, 'p' for previous page, 'b' to quit: ";
        std::cin >> choice;
        if (choice == 'n')
        {
            if (end < size)
            {
                start += 10;
                end += 10;
                if (end > size)
                {
                    end = size;
                }
            }
        }
        else if (choice == 'p')
        {
            if (start >= 10)
            {
                start -= 10;
                end -= 10;
                if (start < 0)
                {
                    start = 0;
                    end = 10;
                }
            }
        }
        else if (choice == 'b')
        {
            break;
        }
    }
}

void faculty ::sort_student(bool by_grade, bool by_last_name, bool by_cgpa, std::vector<Student> &students)
{
    sort(students.begin(), students.end(), [=](const Student a, const Student b) {
        if (by_grade && a.Grade != b.Grade) {
            // Priority order: freshman < junior < senior
            auto gradeRank = [](const std::string& grade) {
                if (grade == "Freshman") return 1;
                if(grade == "Sophomore") return 2;
                if (grade == "Junior") return 3;
                if (grade == "Senior") return 4;
                return 0;
            };
            return gradeRank(a.Grade) < gradeRank(b.Grade);
        }
        if (by_cgpa && a.CGPA != b.CGPA) {
            return a.CGPA < b.CGPA; // Priority order: A < B < C < D
        }
        if (by_last_name) {
            return a.last_name < b.last_name; // Alphabetical order
        }
        return false; // Equal elements
    });
}

std::vector<Student> faculty::search_student(const std::string& name)
{
    std::string first_name, last_name;
    std::vector<Student> searches;

    if (name.empty())
    {
        std::cout << "No name provided for search." << std::endl;
        return searches;
    }

    std::stringstream ss(name);
    ss >> first_name >> last_name;

    if (first_name.empty() && last_name.empty())
    {
        std::cout << "Invalid name input for search." << std::endl;
        return searches;
    }

    // Convert input names to lowercase for case-insensitive comparison
    std::transform(first_name.begin(), first_name.end(), first_name.begin(), ::tolower);
    std::transform(last_name.begin(), last_name.end(), last_name.begin(), ::tolower);

    for (const auto& student : students)
    {
        // Convert student names to lowercase
        std::string student_first = student.first_name;
        std::string student_last = student.last_name;
        std::transform(student_first.begin(), student_first.end(), student_first.begin(), ::tolower);
        std::transform(student_last.begin(), student_last.end(), student_last.begin(), ::tolower);

        // Exact match: first and last name
        if (!first_name.empty() && !last_name.empty())
        {
            if (student_first == first_name && student_last == last_name)
            {
                searches.push_back(student);
            }
        }
        // Partial match: only first name
        else if (!first_name.empty() && student_first == first_name)
        {
            searches.push_back(student);
        }
        // Partial match: only last name
        else if (!last_name.empty() && student_last == last_name)
        {
            searches.push_back(student);
        }
    }

    if (searches.empty())
    {
        std::cout << "No student found with the name: " << name << std::endl;
    }

    return searches;
}

std::vector<Student> faculty::filter_student(std::vector<Student> students, std::string grade ,  char cgpa)
{
    std::vector<Student> filtered_students;
    
    // exact matches
    for (auto student : students)
    {


        if((student.Grade == grade) && 
           (student.CGPA == cgpa))
           {
                filtered_students.push_back(student);
           }
    }
    if (filtered_students.empty())
    {
        std::cout << "No student found with the filter criteria" << std::endl;
    }
    return filtered_students;
}
