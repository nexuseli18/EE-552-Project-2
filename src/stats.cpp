#include "stats.h"
#include <iomanip>

/// @brief derives the student list from base class and initializes the stats maps
stats::stats() : Base()
{
    for (auto student : this->students)
    {
        this->career_aspirations[student.career_aspiration]++;
        this->grade_cgpa[student.Grade][student.CGPA]++;
        this->part_time[student.Grade][student.part_time_job]++;
        this->gender[student.gender]++;
        this->extracurricular[student.Grade][student.extracurricular_activities]++;

        if (student.Grade == "Freshman")
        {
            this->freshman_count++;
        }
        else if (student.Grade == "Sophomore")
        {
            this->sophomore_count++;
        }
        else if (student.Grade == "Junior")
        {
            this->junior_count++;
        }
        else if (student.Grade == "Senior")
        {
            this->senior_count++;
        }
    }
}


/// @brief function to get the student list
/// @return vector of students
std::vector<Student> stats::get_students()
{
    return this->students;
}


/// @brief displays the student statistics in the console
/// @param students vector of students
void stats::view(std::vector<Student> &students)
{
    std::cout << "****************Student Statistics****************" << std::endl;

    std::cout << "Total number of students: " << students.size() << std::endl;

    std::cout << "Career Aspirations" << std::endl;
    for (auto career : this->career_aspirations)
    {
        double percentage = (static_cast<double>(career.second) / students.size()) * 100;
        std::cout << career.first << " : " << std::setprecision(2) << std::fixed << percentage << "%" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Grade and CGPA" << std::endl;
    for (auto grade : this->grade_cgpa)
    {
        std::cout << grade.first << std::endl;
        double tot = grade.second['A'] + grade.second['B'] + grade.second['C'] + grade.second['D'];
        for (auto cgpa : grade.second)
        {
            double percentage = (static_cast<double>(cgpa.second) / tot) * 100;
            std::cout << cgpa.first << " : " << std::setprecision(2) << std::fixed << percentage << "%" << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Part Time Job" << std::endl;
    for (auto grade : this->part_time)
    {
        std::cout << grade.first << std::endl;
        double tot = grade.second["True"] + grade.second["False"];
        for (auto job : grade.second)
        {
            double percentage = (static_cast<double>(job.second) / tot) * 100;
            std::cout << job.first << " : " << std::setprecision(2) << std::fixed << percentage << "%" << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Gender Distribution" << std::endl;
    for (auto g : this->gender)
    {
        double percentage = (static_cast<double>(g.second) / students.size()) * 100;
        std::cout << g.first << " : " << std::setprecision(2) << std::fixed << percentage << "%" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Extracurricular Activities" << std::endl;
    for (auto grade : this->extracurricular)
    {
        std::cout << grade.first << std::endl;
        double tot = grade.second["True"] + grade.second["False"];
        for (auto activity : grade.second)
        {
            double percentage = (static_cast<double>(activity.second) / tot) * 100;
            std::cout << activity.first << " : " << std::setprecision(2) << std::fixed << percentage << "%" << std::endl;
        }
        std::cout << std::endl;
    }
}


/// @brief plots the student statistics using matplot++
void stats::plot_student_stats()
{
    std::vector<std::string> career;
    std::vector<double> count;
    for (auto c : this->career_aspirations)
    {
        career.push_back(c.first);
        count.push_back(c.second);
    }
    matplot::gcf()->size(3000,3000);

    matplot::subplot(2, 3, 0);
    matplot::title("Career Aspirations");
    matplot::pie(count, career);

    matplot::subplot(2, 3, 1);
    std::vector<std::vector<int>> Y = {
        {this->freshman_count, this->sophomore_count, this->junior_count, this->senior_count}};
    matplot::title("Grade Distribution");
    matplot::bar(Y);
    matplot::xticklabels({"Freshman", "Sophomore", "Junior", "Senior"});
    matplot::xlabel("Grade");
    matplot::ylabel("No of Students");

    matplot::subplot(2, 3, 2);
    std::vector<std::string> grades = {"Freshman", "Sophomore", "Junior", "Senior"};
    std::vector<std::vector<int>> X = {
        {this->grade_cgpa["Freshman"]['A'], this->grade_cgpa["Sophomore"]['A'], this->grade_cgpa["Junior"]['A'], this->grade_cgpa["Senior"]['A']},
        {this->grade_cgpa["Freshman"]['B'], this->grade_cgpa["Sophomore"]['B'], this->grade_cgpa["Junior"]['B'], this->grade_cgpa["Senior"]['B']},
        {this->grade_cgpa["Freshman"]['C'], this->grade_cgpa["Sophomore"]['C'], this->grade_cgpa["Junior"]['C'], this->grade_cgpa["Senior"]['C']},
        {this->grade_cgpa["Freshman"]['D'], this->grade_cgpa["Sophomore"]['D'], this->grade_cgpa["Junior"]['D'], this->grade_cgpa["Senior"]['D']}};
    matplot::title("Grade and CGPA Distribution");
    matplot::bar(X);
    matplot::xlabel("Grade and CGPA, Each grade has 4 bars for A, B, C, D in that order");
    matplot::ylabel("No of Students");
    matplot::xticklabels(grades);

    matplot::subplot(2, 3, 3);
    std::vector<std::string> part_time = {"True", "False"};
    std::vector<std::vector<int>> Z = {
        {this->part_time["Freshman"]["True"], this->part_time["Sophomore"]["True"], this->part_time["Junior"]["True"], this->part_time["Senior"]["True"]},
        {this->part_time["Freshman"]["False"], this->part_time["Sophomore"]["False"], this->part_time["Junior"]["False"], this->part_time["Senior"]["False"]}};
    matplot::title("Part Time Job Distribution");
    matplot::bar(Z);
    matplot::xlabel("Grade, Each grade has 2 bars for True and False in that order");
    matplot::ylabel("No of Students");
    matplot::xticklabels(grades);

    matplot::subplot(2, 3, 4);
    matplot::title("Gender Distribution");
    std::vector<std::string> gender_l = {"Male", "Female", "Non-Binary"};
    std::vector<std::vector<int>> A = {{this->gender["male"], this->gender["female"], this->gender["non-binary"]}};
    matplot::bar(A);
    matplot::xticklabels(gender_l);
    matplot::xlabel("Gender");
    matplot::ylabel("No of Students");

    matplot::subplot(2, 3, 5);
    std::vector<std::vector<int>> B = {
        {this->extracurricular["Freshman"]["True"], this->extracurricular["Sophomore"]["True"], this->extracurricular["Junior"]["True"], this->extracurricular["Senior"]["True"]},
        {this->extracurricular["Freshman"]["False"], this->extracurricular["Sophomore"]["False"], this->extracurricular["Junior"]["False"], this->extracurricular["Senior"]["False"]}};
    matplot::title("Extracurricular Activities Distribution");
    matplot::bar(B);
    matplot::xlabel("Grade, Each grade has 2 bars for True and False in that order");
    matplot::ylabel("No of Students");
    matplot::xticklabels(grades);

    matplot::sgtitle("Student Statistics");
    matplot::show();

    this->clearScreen();
}
