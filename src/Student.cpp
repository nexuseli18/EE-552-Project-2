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

bool StudentUser::login(std::string username)
{
    // We will assume that the username is the student's email.
    // If a student with this email exists in the dataset, login is successful.
    for (auto &st : students)
    {
        if (st.email == username)
        {
            logged_in_user = username;
            std::cout << "Student login successful: " << username << std::endl;
            return true;
        }
    }
    std::cout << "No student found with that username (email)." << std::endl;
    return false;
}

std::vector<Student> StudentUser::get_students()
{
    return this->students;
}

void StudentUser::view(std::vector<Student> &students)
{
    // Only display first name, last name, email, and grade.
    // Paginate as done for admin view but with fewer columns.
    int size = static_cast<int>(students.size());
    int start = 0, end = start + 10;
    std::string input;
    while (start < size)
    {
        if (end > size)
            end = size;

        this->clearScreen();
        std::cout << "Student view (Limited Information)" << std::endl;
        std::cout << std::setw(5) << std::right << "ID"
                  << std::setw(20) << std::right << "First Name"
                  << std::setw(20) << std::right << "Last Name"
                  << std::setw(30) << std::right << "Email"
                  << std::setw(12) << std::right << "Grade" << std::endl;

        for (int i = start; i < end; i++)
        {
            std::cout << std::setw(5) << students[i].id
                      << std::setw(20) << std::right << students[i].first_name.substr(0, 20)
                      << std::setw(20) << std::right << students[i].last_name.substr(0, 20)
                      << std::setw(30) << std::right << students[i].email.substr(0, 30)
                      << std::setw(12) << std::right << students[i].Grade.substr(0, 20)
                      << std::endl;
        }

        int current_page = (start / 10) + 1;
        int total_pages = (size + 9) / 10;
        std::cout << "Page " << current_page << " of " << total_pages << std::endl;
        std::cout << "Press 'n' for next page, 'p' for previous page, 'b' to quit, or enter page number to jump: ";
        std::cin >> input;

        if (input == "n")
        {
            if (end < size)
            {
                start += 10;
                end += 10;
            }
            else
            {
                std::cout << "You are on the last page." << std::endl;
            }
        }
        else if (input == "p")
        {
            if (start >= 10)
            {
                start -= 10;
                end -= 10;
            }
            else
            {
                std::cout << "You are on the first page." << std::endl;
            }
        }
        else if (input == "b")
        {
            break;
        }
        else
        {
            try
            {
                int page = std::stoi(input);
                if (page >= 1 && page <= total_pages)
                {
                    start = (page - 1) * 10;
                    end = start + 10;
                    if (end > size)
                        end = size;
                }
                else
                {
                    std::cout << "Invalid page number." << std::endl;
                }
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Invalid input." << std::endl;
            }
        }
    }
}

void StudentUser::sort_student(bool by_grade, bool by_last_name, std::vector<Student> &students)
{
    // Sort by grade or last name.
    // Similar to admin logic, but simpler since we only have two sorts:
    // If by_grade: sort by grade in the order: Freshman < Sophomore < Junior < Senior
    // If by_last_name: alphabetical order by last name.
    // If both are true, prioritize grade first, then last name within grade.

    auto gradeRank = [](const std::string &grade) {
        if (grade == "Freshman") return 1;
        if (grade == "Sophomore") return 2;
        if (grade == "Junior") return 3;
        if (grade == "Senior") return 4;
        return 0;
    };

    std::sort(students.begin(), students.end(), [=](const Student &a, const Student &b) {
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

std::vector<Student> StudentUser::search_student(std::string name, const std::vector<Student> &all_students)
{
    // Search by name. Name could be first name, last name, or both.
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

    for (const auto &student : all_students)
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

std::vector<Student> StudentUser::filter_student(std::string grade, const std::vector<Student> &all_students)
{
    // Filter by grade only.
    std::vector<Student> filtered_students;

    if (grade.empty())
    {
        std::cout << "No grade provided for filtering." << std::endl;
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
        std::cout << "No student found with the specified grade: " << grade << std::endl;
    }
    return filtered_students;
}
