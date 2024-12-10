#include "stats.h"


// namespace plt = matplot;

stats::stats() : Base()
{
    for(auto student : this->students)
    {
        this->career_aspirations[student.career_aspiration]++;
        this->grade_cgpa[student.Grade][student.CGPA]++;
        this->part_time[student.Grade][student.part_time_job]++; 
        this->gender[student.gender]++;
        this->extracurricular[student.Grade][student.extracurricular_activities]++;        
    }
}

vector<Student> stats::get_students()
{
    return this->students;
}


void stats::view(vector<Student> &students)
{
    cout <<"****************Student Statistics****************" << endl;

    cout<< "Total number of students: " << students.size() << endl;


    cout << "Career Aspirations" << endl;
    for(auto career : this->career_aspirations)
    {
        double percentage = (static_cast<double>(career.second) / students.size()) * 100;
        cout << career.first << " : " << percentage <<"%" << endl;
    }
    cout<<endl;

    cout << "Grade and CGPA" << endl;
    for(auto grade : this->grade_cgpa)
    {
        cout << grade.first << endl;
        for(auto cgpa : grade.second)
        {
            double percentage = (static_cast<double>(cgpa.second) / students.size()) * 100;
            cout << cgpa.first << " : " << percentage<<"%" << endl;
        }
    }
    cout<<endl;

    cout << "Part Time Job" << endl;
    for(auto grade : this->part_time)
    {
        cout << grade.first << endl;
        for(auto job : grade.second)
        {
            double percentage = (static_cast<double>(job.second) / students.size()) * 100;
            cout << job.first << " : " << percentage<<"%" << endl;
        }
    }
    cout<<endl;

    cout << "Gender Distribution" << endl;
    for(auto g : this->gender)
    {
        double percentage = (static_cast<double>(g.second) / students.size()) * 100;
        cout << g.first << " : " << percentage<<"%" << endl;
    }
    cout<<endl;

    cout << "Extracurricular Activities" << endl;
    for(auto grade : this->extracurricular)
    {
        cout << grade.first << endl;
        for(auto activity : grade.second)
        {
            double percentage = (static_cast<double>(activity.second) / students.size()) * 100;
            cout << activity.first << " : " << percentage<<"%" << endl;
        }
    }


}