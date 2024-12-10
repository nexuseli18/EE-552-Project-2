#ifndef STATS_H
#define STATS_H

#include "base.h"
#include <map>
#include <cmath>
// #include <matplot/matplot.h>
using namespace std;
class stats : public Base
{
private:
    map<string, int> career_aspirations;           //(career_aspiration, count)
    map<string, map<char, int>> grade_cgpa;        //(grade, (cgpa, count))
    map<string, map<string, int>> part_time;       //(grade, (part time job, count))
    map<string, int> gender;                       // (gender, count)
    map<string, map<string, int>> extracurricular; // (grade, (extracurricular, count))

public:
    stats();
    vector<Student> get_students();
    void view(vector<Student> &students);
    // void plot_career_aspirations();
    // void plot_grade_cgpa();
    // void plot_part_time();
    // void plot_gender();
    // void plot_extracurricular();
};

#endif