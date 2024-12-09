#include "Admin.h"
#include <iomanip>
#include <algorithm>

Admin::Admin() : Base()
{
    admin_login["admin"] = "123456"; // Admin login
}

void Admin::view()
{
    cout << "Admin view" << endl;
    int size = this->students.size();
    int start = 0, end = start + 10;
    char choice;
    while (start < size)
    {
        if (end > size)
        {
            end = size;
        }
        this->clearScreen();
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
            cout << setw(5) << this->students[i].id << 
            setw(20) << right << this->students[i].first_name.substr(0, 20) << 
            setw(20) << right << this->students[i].last_name.substr(0, 20) << 
            setw(30) << right << this->students[i].email.substr(0, 30) << 
            setw(12) << right << this->students[i].gender.substr(0, 20) << 
            setw(20) << right << this->students[i].part_time_job.substr(0, 20) << 
            setw(20) << right << this->students[i].absence_days << 
            setw(25) << right << this->students[i].extracurricular_activities.substr(0, 20) << 
            setw(20) << right << this->students[i].weekly_self_study_hours << 
            setw(20) << right << this->students[i].career_aspiration.substr(0, 20) << 
            setw(5) << this->students[i].math_score << endl;
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
            cout << setw(8) << right << this->students[i].history_score << 
            setw(12) << right << this->students[i].physics_score << 
            setw(12) << right << this->students[i].chemistry_score << 
            setw(12) << right << this->students[i].biology_score << 
            setw(12) << right << this->students[i].english_score << 
            setw(12) << right << this->students[i].geography_score << 
            setw(12) << right << this->students[i].Grade.substr(0, 20) << 
            setw(12) << right << this->students[i].Age << 
            setw(12) << right << this->students[i].CGPA << 
            setw(30) << right << this->students[i].College_Application.substr(0, 30) << endl;
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


void Admin ::sort_student(bool by_grade, bool by_last_name, bool by_cgpa)
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


// void Admin:: search_student(string )