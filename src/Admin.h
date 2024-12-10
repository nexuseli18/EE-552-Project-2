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
        bool login(string, string);
        vector<Student> get_students();
        void view(vector<Student> &);
        void sort_student(bool by_grade, bool by_last_name, bool by_cgpa, vector<Student> &students);
        vector<Student> search_student(string);
        // vector<Student> filter_student(string grade ="", 
        //                                char cgpa = ' ',
        //                                string gender = "", 
        //                                string part_time_job = "", 
        //                                vector<Student> students);
};



#endif