#ifndef FACULTY_H
#define FACULTY_H

#include "base.h"
#include <map>

class faculty : public Base
{
    private:
        std::map<std::string, std::string> faculty_login;
        std::string faculty_username;
        std::vector<std::string> faculty1;
        std::vector<std::string> faculty2;
        std::vector<std::string> faculty3;
        std::vector<std::string> faculty4;

    public:
        faculty();
        void view(std::vector<Student> &students);
        std::vector<Student> get_students();
        std::vector<Student> search_student(const std::string& name);
        void sort_student(bool, bool, bool, std::vector<Student>&);
        bool login(std::string email, std::string password);
        std::vector<Student> filter_student(std::vector<Student> students, std::string grade ,  char cgpa);
};



#endif
