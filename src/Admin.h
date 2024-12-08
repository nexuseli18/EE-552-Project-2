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
};



#endif