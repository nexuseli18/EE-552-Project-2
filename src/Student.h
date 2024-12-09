#ifndef STUDENT_H
#define STUDENT_H

#include "base.h"
#include <map>

class Student : public Base
{
private:
    map<string, string> student_login; // Map to store student email and password for login

public:
    Student();
    bool login(string email, string password);
    void view();
};

#endif
