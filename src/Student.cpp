#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor for the Student class
Student::Student() : Base() // Call the base class constructor
{
    // Initialize with some dummy student login data
    student_login["john.doe@example.com"] = "password123";
    student_login["jane.doe@example.com"] = "pass456";
}

// Function to handle student login
bool Student::login(string email, string password)
{
    // Find the email in the student_login map
    auto it = student_login.find(email);
    // Check if email exists and password matches
    if (it != student_login.end() && it->second == password)
    {
        cout << "Login successful!" << endl;
        return true;
    }
    // If login fails
    cout << "Invalid email or password." << endl;
    return false;
}

// Function to display student information
void Student::view()
{
    // Output table header
    cout << "| " << setw(5) << "ID"
         << " | " << setw(20) << "Name"
         << " | " << setw(20) << "Grade"
         << " | " << setw(30) << "Email" << " |" << endl;
    // Output a separator line
    cout << string(80, '-') << endl;

    // Iterate over the students vector and display each student's information
    for (const auto &student : students)
    {
        cout << "| " << setw(5) << student.id
             << " | " << setw(20) << (student.first_name + " " + student.last_name)
             << " | " << setw(20) << student.Grade
             << " | " << setw(30) << student.email << " |" << endl;
    }
}
