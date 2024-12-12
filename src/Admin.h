#ifndef ADMIN_H
#define ADMIN_H

#include "base.h"
#include <map>
#include<string>

class Admin : public Base
{
    private:
        std::map<std::string, std::string> admin_login;

    public:
        Admin();
        bool login(std::string, std::string);
        std::vector<Student> get_students();
        void view(std::vector<Student> &);
        void sort_student(bool by_grade, bool by_last_name, bool by_cgpa,std::vector<Student> &students);
        std::vector<Student> search_student(const std::string& name);
        std::vector<Student> filter_student(std::vector<Student> students,std::string grade, 
                                       char cgpa,
                                       std::string gender, 
                                       std::string part_time_job);                                    
};



#endif