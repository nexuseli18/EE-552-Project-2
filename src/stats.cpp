#include "stats.h"
#include <iomanip>

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

std::vector<Student> stats::get_students()
{
    return this->students;
}

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

void stats::plot_career_aspirations()
{
    std::vector<std::string> career;
    std::vector<double> count;
    for (auto c : this->career_aspirations)
    {
        career.push_back(c.first);
        count.push_back(c.second);
    }
    matplot::gcf()->size(2500, 2500);

    matplot::subplot(2,3,0);
    matplot::pie(count, career);
    matplot::title("Career Aspirations");
    matplot::subplot(2,3,1);
    matplot::pie(count, career);
    matplot::title("Career Aspirations");
    matplot::subplot(2,3,2);
    matplot::pie(count, career);
    matplot::title("Career Aspirations");
    matplot::show();
    std::cin.get();

    this->clearScreen();
}