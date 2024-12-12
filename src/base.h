#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

// using namespace std;

// Structure for student data, each student has 18 attributes
struct Student
{
    int id;
    std::string first_name;
    std::string last_name;
    std::string email;
    std::string gender;
    std::string part_time_job;
    int absence_days;
    std::string extracurricular_activities;
    int weekly_self_study_hours;
    std::string career_aspiration;
    int math_score;
    int history_score;
    int physics_score;
    int chemistry_score;
    int biology_score;
    int english_score;
    int geography_score;
    std::string Grade;
    int Age;
    char CGPA;
    std::string College_Application;
};
class Base
{
protected:
    // All the Student data is stored in a vector of Student structures
    std::vector<Student> students;

public:

    // Constructor to load data from the CSV file
    Base()
    {
        std::ifstream file("student-scores.csv");
        std::string line;

        // skip the first line
        getline(file, line);

        while (getline(file, line))
        {
            std::stringstream ss(line);
            std::string temp;
            Student _student;
            getline(ss, temp, ',');
            _student.id = stoi(temp);
            getline(ss, _student.first_name, ',');
            getline(ss, _student.last_name, ',');
            getline(ss, temp, ',');
            _student.email = temp.substr(0, temp.find('@'));
            getline(ss, _student.gender, ',');
            getline(ss, temp, ',');
            _student.part_time_job = /*(temp == "TRUE") ? "Yes" : "No";*/ temp;
            getline(ss, temp, ',');
            _student.absence_days = stoi(temp);
            getline(ss, temp, ',');
            _student.extracurricular_activities = /*(temp == "TRUE") ? "Yes" : "No";*/ temp;
            getline(ss, temp, ',');
            _student.weekly_self_study_hours = stoi(temp);
            getline(ss, _student.career_aspiration, ',');
            getline(ss, temp, ',');
            _student.math_score = stoi(temp);
            getline(ss, temp, ',');
            _student.history_score = stoi(temp);
            getline(ss, temp, ',');
            _student.physics_score = stoi(temp);
            getline(ss, temp, ',');
            _student.chemistry_score = stoi(temp);
            getline(ss, temp, ',');
            _student.biology_score = stoi(temp);
            getline(ss, temp, ',');
            _student.english_score = stoi(temp);
            getline(ss, temp, ',');
            _student.geography_score = stoi(temp);
            getline(ss, _student.Grade, ',');
            getline(ss, temp, ',');
            _student.Age = stoi(temp);
            getline(ss, temp, ',');
            _student.CGPA = temp[0];
            getline(ss, _student.College_Application, ',');
            this->students.push_back(_student);
        }
    }
    virtual void view(std::vector<Student> &) = 0;
    std::vector<Student> search_student(std::string);

    /// Clear the screen
    void clearScreen()
    {
#ifdef _WIN32
        // For Windows
        system("cls");
#else
        // For Unix/Linux/Mac
        system("clear");
#endif
    }
};
#endif