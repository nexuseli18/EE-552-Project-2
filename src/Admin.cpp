#include "Admin.h"
#include <iomanip>
#include <algorithm>



/// @brief Contructor for Admin class, intializes the admin login credentials
Admin::Admin() : Base()
{
    admin_login["admin"] = "123456"; // Admin login
}



/// @brief login function for Admin class
/// @param username username of the admin
/// @param password password of the admin
/// @return success or failure of the login
bool Admin::login(std::string username, std::string password)
{
    if (admin_login.find(username) != admin_login.end() && admin_login[username] == password)
    {
        std::cout << "Admin login successful" << std::endl;
        return true;
    }
    std::cout << "Invalid username or password" <<std:: endl;
    return false;
}


/// @brief returns the students list
/// @return vector of students
std::vector<Student> Admin::get_students()
{
    return this->students;
}


/// @brief Displays the student data
/// @param students vector of students
void Admin::view(std::vector<Student> &students)
{
    int size = students.size();
    int start = 0, end = start + 10;
    char choice;
    while (start < size)
    {
        if (end > size)
        {
            end = size;
        }
        this->clearScreen();
        std::cout << "Admin view" <<std:: endl;
        std::cout << std::setw(5) << std::right << "ID" << 
        std::setw(20) << std::right << "First Name" << 
        std::setw(20) << std::right << "Last Name" << 
        std::setw(30) << std::right << "Email" << 
        std::setw(12) << std::right << "Gender" << 
        std::setw(20) << std::right << "Part Time Job" << 
        std::setw(20) << std::right << "Absence Days" << 
        std::setw(25) << std::right << "Extracurricular" << 
        std::setw(20) << std::right << "Self Study Hours" << 
        std::setw(20) << std::right << "Career " << 
        std::setw(5) << "Math" << std::endl;
        for (int i = start; i < end; i++)
        {
            std::cout << std::setw(5) << students[i].id << 
            std::setw(20) << std::right << students[i].first_name.substr(0, 20) << 
            std::setw(20) << std::right << students[i].last_name.substr(0, 20) << 
            std::setw(30) << std::right << students[i].email.substr(0, 30) << 
            std::setw(12) << std::right << students[i].gender.substr(0, 20) << 
            std::setw(20) << std::right << students[i].part_time_job.substr(0, 20) << 
            std::setw(20) << std::right << students[i].absence_days << 
            std::setw(25) << std::right << students[i].extracurricular_activities.substr(0, 20) << 
            std::setw(20) << std::right << students[i].weekly_self_study_hours << 
            std::setw(20) << std::right << students[i].career_aspiration.substr(0, 20) << 
            std::setw(5) << students[i].math_score << std::endl;
        }

        std::cout << std::endl;
        std::cout << std::setw(8) << "History" << 
        std::setw(12) << "Physics" << 
        std::setw(12) << "Chemistry" << 
        std::setw(12) << "Biology" << 
        std::setw(12) << "English" << 
        std::setw(12) << "Geography" << 
        std::setw(12) << "Grade" << 
        std::setw(12) << "Age" << 
        std::setw(12) << "CGPA" << 
        std::setw(30) << "College Application" << std::endl;
        for (int i = start; i < end; i++)
        {
            std::cout << std::setw(8) << std::right << students[i].history_score << 
            std::setw(12) << std::right << students[i].physics_score << 
            std::setw(12) << std::right << students[i].chemistry_score << 
            std::setw(12) << std::right << students[i].biology_score << 
            std::setw(12) << std::right << students[i].english_score << 
            std::setw(12) << std::right << students[i].geography_score << 
            std::setw(12) << std::right << students[i].Grade.substr(0, 20) << 
            std::setw(12) << std::right << students[i].Age << 
            std::setw(12) << std::right << students[i].CGPA << 
            std::setw(30) << std::right << students[i].College_Application.substr(0, 30) << std::endl;
        }

        std::cout << "Page " << (start / 10) + 1 << " of " << (size / 10) + 1 << std::endl;
        std::cout << "Press 'n' for next page, 'p' for previous page, 'b' to quit: ";
        std::cin >> choice;
        if (choice == 'n')
        {
            start += 10;
            end += 10;
            if (end > size)
            {
                end = size;
            }
        }
        else if (choice == 'p')
        {
            start -= 10;
            end -= 10;
            if (start < 0)
            {
                start = 0;
                end = 10;
            }
        }
        else if (choice == 'b')
        {
            break;
        }
    }
}


/// @brief sorts the students based on the criteria
/// @param by_grade grade of the student (Freshman, Sophomore, Junior, Senior)
/// @param by_last_name last name of the student
/// @param by_cgpa cgpa of the student (A, B, C, D)
/// @param students vector of students
void Admin ::sort_student(bool by_grade, bool by_last_name, bool by_cgpa, std::vector<Student> &students)
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


/// @brief search the student based on the name
/// @param name full name of the student
/// @return vector of students matching the name
std::vector<Student> Admin::search_student(const std::string& name)
{
    std::string first_name, last_name; 
    std::vector<Student> searches; // Store search results
    std::stringstream ss(name);
    ss >> first_name >> last_name; // Extract first and last name from name
    
    // Search for best match first and add to searches
    for (auto student : students)
    {
        if (student.first_name == first_name && student.last_name == last_name)
        {
            searches.push_back(student);
        }
    }

    
    // Search for partial match and add to searches
    for (auto student : students)
    {
        if ((student.first_name == first_name || student.last_name == last_name) && 
        (student.first_name != first_name || student.last_name != last_name))
        {
            searches.push_back(student);
        }
    }

    if (searches.empty())
    {
        std::cout << "No student found with the name.\nNote: Searches are case sensitive" << name << std::endl;
    }
    return searches;
}


/// @brief filters the students data based on the criteria
/// @param students vector of students
/// @param grade grade of the student (Freshman, Sophomore, Junior, Senior) to filter by.
/// @param cgpa cgpa of the student (A, B, C, D) to filter by.
/// @param gender gender of the student to filter by.
/// @param part_time_job part time job status of the student to filter by.
/// @return vector of students matching the filter criteria
std::vector<Student> Admin::filter_student(std::vector<Student> students, std::string grade ,  char cgpa, std::string gender,  std::string part_time_job)
{
    std::vector<Student> filtered_students;
    
    // exact matches
    for (auto student : students)
    {


        if((student.Grade == grade) && 
           (student.CGPA == cgpa) &&
           (student.gender == gender) &&
           (student.part_time_job == part_time_job))
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
