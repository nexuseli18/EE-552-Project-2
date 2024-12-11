#include "student.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>

StudentUser::StudentUser() : Base()
{
    // Constructor - loads data from Base
    // No login map needed since no password is required
}

bool StudentUser::login(string username)
{
    // We will assume that the username is the student's email.
    // If a student with this email exists in the dataset, login is successful.
    for (auto &st : students)
    {
        if (st.email == username)
        {
            logged_in_user = username;
            cout << "Student login successful: " << username << endl;
            return true;
        }
    }
    cout << "No student found with that username (email)." << endl;
    return false;
}

void StudentUser::view(vector<Student> &students)
{
    // Only display first name, last name, email, and grade.
    // Paginate as done for admin view but with fewer columns.
    int size = (int)students.size();
    int start = 0, end = start + 10;
    char choice;
    while (start < size)
    {
        if (end > size)
            end = size;

        this->clearScreen();
        cout << "Student view (Limited Information)" << endl;
        cout << setw(5) << right << "ID"
             << setw(20) << right << "First Name"
             << setw(20) << right << "Last Name"
             << setw(30) << right << "Email"
             << setw(12) << right << "Grade" << endl;

        for (int i = start; i < end; i++)
        {
            cout << setw(5) << students[i].id
                 << setw(20) << right << students[i].first_name.substr(0, 20)
                 << setw(20) << right << students[i].last_name.substr(0, 20)
                 << setw(30) << right << students[i].email.substr(0, 30)
                 << setw(12) << right << students[i].Grade.substr(0, 20)
                 << endl;
        }

        cout << "Page " << (start / 10) + 1 << " of " << ((size + 9) / 10) << endl;
        cout << "Press 'n' for next page, 'p' for previous page, 'b' to quit: ";
        cin >> choice;
        if (choice == 'n')
        {
            if (end < size)
            {
                start += 10;
                end += 10;
            }
        }
        else if (choice == 'p')
        {
            if (start >= 10)
            {
                start -= 10;
                end -= 10;
            }
        }
        else if (choice == 'b')
        {
            break;
        }
    }
}

void StudentUser::sort_student(bool by_grade, bool by_last_name, vector<Student> &students)
{
    // Sort by grade or last name.
    // Similar to admin logic, but simpler since we only have two sorts:
    // If by_grade: sort by grade in the order: Freshman < Sophomore < Junior < Senior
    // If by_last_name: alphabetical order by last name.
    // If both are true, prioritize grade first, then last name within grade.

    auto gradeRank = [](const string &grade) {
        if (grade == "Freshman") return 1;
        if (grade == "Sophomore") return 2;
        if (grade == "Junior") return 3;
        if (grade == "Senior") return 4;
        return 0;
    };

    sort(students.begin(), students.end(), [=](const Student &a, const Student &b) {
        if (by_grade && a.Grade != b.Grade)
        {
            return gradeRank(a.Grade) < gradeRank(b.Grade);
        }
        if (by_last_name && a.last_name != b.last_name)
        {
            return a.last_name < b.last_name;
        }
        return false;
    });
}

vector<Student> StudentUser::search_student(string name, const vector<Student> &all_students)
{
    // Search by name. Name could be first name, last name, or both.
    string first_name, last_name;
    vector<Student> searches;
    stringstream ss(name);
    ss >> first_name >> last_name;

    // Exact match: first and last name
    for (auto &student : all_students)
    {
        if (!first_name.empty() && !last_name.empty())
        {
            if (student.first_name == first_name && student.last_name == last_name)
            {
                searches.push_back(student);
            }
        }
    }

    // Partial match: only first_name or only last_name if exact not found
    for (auto &student : all_students)
    {
        // If we have both first_name and last_name but no exact matches, consider partials:
        if ((!first_name.empty() && student.first_name == first_name) ||
            (!last_name.empty() && student.last_name == last_name))
        {
            searches.push_back(student);
        }
    }

    if (searches.empty())
    {
        cout << "No student found with the name. Note: Searches are case sensitive: " << name << endl;
    }
    return searches;
}

vector<Student> StudentUser::filter_student(string grade, const vector<Student> &all_students)
{
    // Filter by grade only.
    vector<Student> filtered_students;

    if (grade.empty())
    {
        cout << "No grade provided for filtering." << endl;
        return filtered_students;
    }

    for (auto &student : all_students)
    {
        if (student.Grade == grade)
        {
            filtered_students.push_back(student);
        }
    }

    if (filtered_students.empty())
    {
        cout << "No student found with the specified grade: " << grade << endl;
    }
    return filtered_students;
}
