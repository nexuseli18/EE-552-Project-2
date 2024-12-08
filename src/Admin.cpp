#include "Admin.h"
#include <iomanip>



Admin::Admin() : Base()
{
    admin_login["admin"] = "123456"; // Admin login
}

void Admin::view()
{
    cout << "Admin view" << endl;
    int size = this->students.size();
    int start = 0, end = start + 10;
    char choice;
    while(start < size)
    {
        if (end > size)
        {
            end = size;
        }
        this->clearScreen();
        // cout<<setw(3)<<"|ID|" << setw(20) << "|First Name|" << setw(20) << "|Last Name|" << setw(20) << "|Email|" << 
        // setw(20) << "|Gender|" << setw(20) << "|Part Time Job|" << setw(20) << "|Absence Days|" << 
        // setw(20) << "|Extracurricular Activities|" << setw(20) << "|Weekly Self Study Hours|" << 
        // setw(20) << "|Career Aspiration|" << setw(20) << "\b\b|Math Score|"<<endl;
        cout<<"|"<<setw(3)<<"ID|"<<setw(20)<<"First Name|"<<
        setw(20)<<"Last Name|"<<setw(20)<<"Email|"<<
        setw(20)<<"Gender|"<<
        setw(20)<<"Part Time Job|"<<
        setw(20)<<"Absence Days|"<<
        setw(20)<<"Extracurricular Activities|"<<
        setw(20)<<"Self Study Hours|"<<
        setw(20)<<"Career |"<<setw(20)<<"Math Score|"<<endl;
        for (int i = start; i < end; i++)
        {
            cout<< setw(3)<<this->students[i].id<<setw(20)<<this->students[i].first_name.substr(0, 20)<< 
            setw(20)<<right<<this->students[i].last_name.substr(0, 20)<< 
            setw(20)<<right<<this->students[i].email.substr(0, 20)<< 
            setw(20)<<right<<this->students[i].gender.substr(0, 20)<<
            setw(20)<<right<<this->students[i].part_time_job.substr(0, 20)<<
            setw(20)<<right<<this->students[i].absence_days<<
            setw(27)<<right<<this->students[i].extracurricular_activities.substr(0, 20)<<
            setw(20)<<right<<this->students[i].weekly_self_study_hours<<
            setw(20)<<right<<this->students[i].career_aspiration.substr(0, 20)<<
            setw(20)<<this->students[i].math_score<<endl;
        }

        cout<<endl;
        cout<<setw(20) << "History Score" << setw(20) << "Physics Score" << 
        setw(20) << "Chemistry Score" << setw(20) << "Biology Score" << setw(20) << "English Score" << 
        setw(20) << "Geography Score" << setw(20) << "Grade" << setw(20) << "Age" << 
        setw(20) << "CGPA" << setw(20) << "College Application" << endl;
        for(int i = start; i < end; i++)
        {
            cout<<setw(20)<<right <<this->students[i].history_score<<
            setw(20)<<right <<this->students[i].physics_score<<
            setw(20)<<right <<this->students[i].chemistry_score<<
            setw(20)<<right <<this->students[i].biology_score<<
            setw(20)<<right <<this->students[i].english_score<<
            setw(20)<<right <<this->students[i].geography_score<<
            setw(20)<<right <<this->students[i].Grade.substr(0, 20)<<
            setw(20)<<right <<this->students[i].Age<<
            setw(20)<<right <<this->students[i].CGPA<<
            setw(20)<<right <<this->students[i].College_Application.substr(0, 20)<<endl;


        }
        
        cout << "Press 'n' for next page, 'p' for previous page, 'b' to quit: ";
        cin >> choice;
        if (choice == 'n')
        {
            start += 10;
            end += 10;
        }
        else if (choice == 'p')
        {
            start -= 10;
            end -= 10;
        }
        else if (choice == 'b')
        {
            break;
        }
        
    }
}