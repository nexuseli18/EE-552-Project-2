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

bool faculty::login(string email, string password)
{
    // Find the email in the student_login map
    auto it = faculty_login.find(email);
    // Check if email exists and password matches
    if (it != faculty_login.end() && it->second == password)
    {
        cout << "Login successful!" << endl;
        faculty_username = email;
        return true;
    }
    // If login fails
    cout << "Invalid email or password." << endl;
    return false;
}

vector<Student> faculty::get_students()
{
    return this->students;
}

void faculty::view(vector<Student> &stud)
{
    cout << "Faculty view" << endl;
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
        vector <string> sub;
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
        ostringstream formattedOutput;
        if(sub.size() == 2)
        {
            formattedOutput << setw(20) << right << sub[0]
                        << setw(20) << right << sub[1];
        }
        else
        {
            formattedOutput << setw(20) << right << sub[0];
        }
        cout <<
        setw(20) << right << "First Name" << 
        setw(20) << right << "Last Name" << 
        setw(30) << right << "Email" << formattedOutput.str() << 
        setw(12) << "Grade" << 
        setw(12) << "CGPA" <<endl;
        for (int i = start; i < end; i++)
        {
            ostringstream score;
            for(int k = 0; k<sub.size(); k++)
            {
                if(sub[k] == "math_score")
                    score << setw(20) << right << stud[i].math_score ;
                else if(sub[k] == "history_score")
                    score << setw(20) << right << stud[i].history_score ;
                else if(sub[k] == "physics_score")
                    score << setw(20) << right << stud[i].physics_score ;
                else if(sub[k] == "chemistry_score")
                    score << setw(20) << right << stud[i].chemistry_score ;
                else if(sub[k] == "biology_score")
                    score << setw(20) << right << stud[i].biology_score ;
                else if(sub[k] == "english_score")
                    score << setw(20) << right << stud[i].english_score ;
                else if(sub[k] == "geography_score")
                    score << setw(20) << right << stud[i].geography_score ;
            }
            cout <<
            setw(20) << right << stud[i].first_name.substr(0, 20) << 
            setw(20) << right << stud[i].last_name.substr(0, 20) << 
            setw(30) << right << stud[i].email.substr(0, 30) << 
            score.str() << 
            setw(12) << right << stud[i].Grade.substr(0, 20) << 
            setw(12) << right << stud[i].CGPA << 
            endl;
        }

        cout << "Page " << (start / 10) + 1 << " of " << (size / 10) + 1 << endl;
        cout << "Press 'n' for next page, 'p' for previous page, 'b' to quit: ";
        cin >> choice;
        if (choice == 'n')
        {
            start += 10;
            end += 10;
        }
        else if (choice == 'p')
        {
            start -= 10;
            end -= 10;
        }
        else if (choice == 'b')
        {
            break;
        }
    }
}

void faculty ::sort_student(bool by_grade, bool by_last_name, bool by_cgpa, vector<Student> &students)
{
    sort(students.begin(), students.end(), [=](const Student a, const Student b) {
        if (by_grade && a.Grade != b.Grade) {
            // Priority order: freshman < junior < senior
            auto gradeRank = [](const string& grade) {
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

vector<Student> faculty :: search_student(string name)
{
    string first_name, last_name;
    vector<Student> searches;
    stringstream ss(name);
    ss >> first_name >> last_name;
    // Search for best match first and add to searches
    for (auto student : students)
    {
        if (student.first_name == first_name && student.last_name == last_name)
        {
            searches.push_back(student);
        }
    }

    for (auto student : students)
    {
        if ((student.first_name == first_name && student.last_name != last_name) || (student.first_name != first_name && student.last_name == last_name))
            searches.push_back(student);
    }

    if (searches.empty())
    {
        cout << "No student found with the name.\nNote: Searches are case sensitive" << name << endl;
    }
    return searches;
}
