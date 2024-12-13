#ifndef STATS_H
#define STATS_H

#include "base.h"
#include <map>
#include <cmath>
#include <matplot/matplot.h>
class stats : public Base
{
private:
    std::map<std::string, int> career_aspirations;                     //(career_aspiration, count)
    std::map<std::string, std::map<char, int>> grade_cgpa;             //(grade, (cgpa, count))
    std::map<std::string, std::map<std::string, int>> part_time;       //(grade, (part time job, count))
    std::map<std::string, int> gender;                                 // (gender, count)
    std::map<std::string, std::map<std::string, int>> extracurricular; // (grade, (extracurricular, count))
    int freshman_count = 0;
    int sophomore_count = 0;
    int junior_count = 0;
    int senior_count = 0;

public:
    stats();
    std::vector<Student> get_students();
    void view(std::vector<Student> &students);
    void plot_student_stats();
};

#endif