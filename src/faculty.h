#ifndef FACULTY_H
#define FACULTY_H

#include "base.h"
#include <map>

class faculty : public Base
{
    private:
        map<string, string> faculty_login;
        string faculty_username;
        vector<string> faculty1;
        vector<string> faculty2;
        vector<string> faculty3;
        vector<string> faculty4;

    public:
        faculty();
        void view();
        void assign_subject_to_faculty();
        vector<Student> search_student(string, string);
        bool login(string email, string password);
        //void sort_student(bool by_grade, bool by_last_name, bool by_cgpa);
        // filter by grade
        // search
};



#endif
