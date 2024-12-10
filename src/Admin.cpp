#include "Admin.h"
#include <iomanip>
#include <algorithm>

Admin::Admin() : Base()
{
    admin_login["admin"] = "123456"; // Admin login
}

bool Admin::login(string username, string password)
{
    if (admin_login.find(username) != admin_login.end() && admin_login[username] == password)
    {
        cout << "Admin login successful" << endl;
        return true;
    }
    cout << "Invalid username or password" << endl;
    return false;
}

vector<Student> Admin::get_students()
{
    return this->students;
}

void Admin::view(vector<Student> &students)
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
        cout << "Admin view" << endl;
        cout << setw(5) << right << "ID" << 
        setw(20) << right << "First Name" << 
        setw(20) << right << "Last Name" << 
        setw(30) << right << "Email" << 
        setw(12) << right << "Gender" << 
        setw(20) << right << "Part Time Job" << 
        setw(20) << right << "Absence Days" << 
        setw(25) << right << "Extracurricular" << 
        setw(20) << right << "Self Study Hours" << 
        setw(20) << right << "Career " << 
        setw(5) << "Math" << endl;
        for (int i = start; i < end; i++)
        {
            cout << setw(5) << students[i].id << 
            setw(20) << right << students[i].first_name.substr(0, 20) << 
            setw(20) << right << students[i].last_name.substr(0, 20) << 
            setw(30) << right << students[i].email.substr(0, 30) << 
            setw(12) << right << students[i].gender.substr(0, 20) << 
            setw(20) << right << students[i].part_time_job.substr(0, 20) << 
            setw(20) << right << students[i].absence_days << 
            setw(25) << right << students[i].extracurricular_activities.substr(0, 20) << 
            setw(20) << right << students[i].weekly_self_study_hours << 
            setw(20) << right << students[i].career_aspiration.substr(0, 20) << 
            setw(5) << students[i].math_score << endl;
        }

        cout << endl;
        cout << setw(8) << "History" << 
        setw(12) << "Physics" << 
        setw(12) << "Chemistry" << 
        setw(12) << "Biology" << 
        setw(12) << "English" << 
        setw(12) << "Geography" << 
        setw(12) << "Grade" << 
        setw(12) << "Age" << 
        setw(12) << "CGPA" << 
        setw(30) << "College Application" << endl;
        for (int i = start; i < end; i++)
        {
            cout << setw(8) << right << students[i].history_score << 
            setw(12) << right << students[i].physics_score << 
            setw(12) << right << students[i].chemistry_score << 
            setw(12) << right << students[i].biology_score << 
            setw(12) << right << students[i].english_score << 
            setw(12) << right << students[i].geography_score << 
            setw(12) << right << students[i].Grade.substr(0, 20) << 
            setw(12) << right << students[i].Age << 
            setw(12) << right << students[i].CGPA << 
            setw(30) << right << students[i].College_Application.substr(0, 30) << endl;
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


void Admin ::sort_student(bool by_grade, bool by_last_name, bool by_cgpa, vector<Student> &students)
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


 vector<Student> Admin:: search_student(string name)
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

    // Search for partial match and add to searches
    for (auto student : students)
    {
        if (student.first_name == first_name || student.last_name == last_name)
        {
            searches.push_back(student);
        }
    }

    if (searches.empty())
    {
        cout << "No student found with the name.\nNote: Searches are case sensitive" << name << endl;
    }
    return searches;
}

// vector<Student> Admin::filter_student(string grade ="",  char cgpa = ' ', string gender = "",  string part_time_job = "",  vector<Student> students)
// {
//     vector<Student> filtered_students;
    
//     // exact matches
//     for (auto student : students)
//     {
//         if((grade != "" && student.Grade == grade) && 
//            (cgpa != ' ' && student.CGPA == cgpa) &&
//            (gender != "" && student.gender == gender) &&
//            (part_time_job == "" && student.part_time_job == part_time_job))
//            {
//                 filtered_students.push_back(student);
//            }
//     }
//     // partials matches
//     for (auto student : students)
//     {
//         if((grade != "" && student.Grade == grade) ||
//            (cgpa != ' ' && student.CGPA == cgpa)||
//            (gender != "" && student.gender == gender)||
//            (part_time_job == "" && student.part_time_job == part_time_job))
//            {
//                 filtered_students.push_back(student);
//            }
//     }

//     if (filtered_students.empty())
//     {
//         cout << "No student found with the filter criteria" << endl;
//     }
//     return filtered_students;
// }
