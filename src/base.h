#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

// Structure for student data, each student has 18 attributes
struct Student
{
    int id;
    string first_name;
    string last_name;
    string email;
    string gender;
    string part_time_job;
    int absence_days;
    string extracurricular_activities;
    int weekly_self_study_hours;
    string career_aspiration;
    int math_score;
    int history_score;
    int physics_score;
    int chemistry_score;
    int biology_score;
    int english_score;
    int geography_score;
    string Grade;
    int Age;
    char CGPA;
    string College_Application;
};
class Base
{
protected:
    
    // All the Student data is stored in a vector of Student structures
    vector<Student> students;

public:
    Base()
    {
        ifstream file("student-scores.csv");
        string line;

        // skip the first line
        getline(file, line);

        while (getline(file, line))
        {
            stringstream ss(line);
            string temp;
            Student _student;
            getline(ss, temp, ',');
            _student.id = stoi(temp);
            getline(ss, _student.first_name, ',');
            getline(ss, _student.last_name, ',');
            getline(ss, temp, ',');
            _student.email = temp.substr(0, temp.find('@'));
            getline(ss, _student.gender, ',');
            getline(ss, temp, ',');
            _student.part_time_job = (temp == "TRUE") ? "Yes" : "No";
            getline(ss, temp, ',');
            _student.absence_days = stoi(temp);
            getline(ss, temp, ',');
            _student.extracurricular_activities = (temp == "TRUE") ? "Yes" : "No";
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
    virtual void view(vector<Student> &) = 0;
    vector<Student> search_student(string, string);
    void clearScreen()
    {
        system("clear");
    }
};
#endif