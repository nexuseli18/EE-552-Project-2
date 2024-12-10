#ifndef STUDENT_USER_H
#define STUDENT_USER_H

#include "base.h"
#include <vector>
#include <string>

class StudentUser : public Base
{
private:
    std::string logged_in_user; // This will hold the email of the currently logged in student

public:
    StudentUser();
    bool login(std::string username); // username will be the student's email
    void view(std::vector<Student> &students);
    void sort_student(bool by_grade, bool by_last_name, std::vector<Student> &students);
    std::vector<Student> search_student(std::string name, const std::vector<Student> &students);
    std::vector<Student> filter_student(std::string grade, const std::vector<Student> &students);
};

#endif
