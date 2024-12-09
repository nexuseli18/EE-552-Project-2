#ifndef ADMIN_H
#define ADMIN_H

#include "base.h"
#include <map>

class Admin : public Base
{
    private:
        map<string, string> admin_login;

    public:
        Admin();
        void view();
        vector<Student> search_student(string, string);
        void sort_student(bool by_grade, bool by_last_name, bool by_cgpa);
        // filter by grade
        // search
};



#endif