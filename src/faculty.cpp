#include "faculty.h"
#include <iomanip>
#include <algorithm>

faculty::faculty() : Base()
{
    faculty_login["faculty1"] = "123456"; // Faculty login
    faculty_login["faculty2"] = "234567";
    faculty_login["faculty3"] = "345678";
    faculty_login["faculty4"] = "456789";
    faculty1.push_back("math_score");
    faculty2.push_back("history_score");
    faculty3.push_back("physics_score");
    faculty4.push_back("chemistry_score");
    faculty1.push_back("biology_score");
    faculty2.push_back("english_score");
    faculty3.push_back("geography_score");
}

bool faculty::login(string email, string password)
{
    // Find the email in the student_login map
    auto it = faculty_login.find(email);
    // Check if email exists and password matches
    if (it != faculty_login.end() && it->second == password)
    {
        cout << "Login successful!" << endl;
        faculty_username = email;
        return true;
    }
    // If login fails
    cout << "Invalid email or password." << endl;
    return false;
}

void faculty::assign_subject_to_faculty()
{
    
}

void faculty::view()
{
    cout << "Faculty view" << endl;
    int size = this->students.size();
    int start = 0, end = start + 10;
    char choice;
    while (start < size)
    {
        if (end > size)
        {
            end = size;
        }
        this->clearScreen();
        vector <string> sub;
        if(faculty_username == "faculty1")
            for(auto ele : faculty1)
            {
                sub.push_back(ele);
            }
        else if(faculty_username == "faculty2")
            for(auto ele : faculty2)
            {
                sub.push_back(ele);
            }
        else if(faculty_username == "faculty3")
            for(auto ele : faculty3)
            {
                sub.push_back(ele);
            }
        else if(faculty_username == "faculty4")
            for(auto ele : faculty4)
            {
                sub.push_back(ele);
            }
        ostringstream formattedOutput;
        if(sub.size() == 2)
        {
            formattedOutput << setw(20) << right << sub[0]
                        << setw(20) << right << sub[1];
        }
        else
        {
            formattedOutput << setw(12) << right << sub[0];
        }
        cout <<
        setw(20) << right << "First Name" << 
        setw(20) << right << "Last Name" << 
        setw(30) << right << "Email" << formattedOutput.str() << 
        setw(12) << "Grade" << 
        setw(12) << "CGPA" <<endl;
        for (int i = start; i < end; i++)
        {
            ostringstream score;
            for(int k = 0; k<sub.size(); k++)
            {
                if(sub[k] == "math_score")
                    score << setw(20) << right << students[i].math_score ;
                else if(sub[k] == "history_score")
                    score << setw(20) << right << students[i].history_score ;
                else if(sub[k] == "physics_score")
                    score << setw(20) << right << students[i].physics_score ;
                else if(sub[k] == "chemistry_score")
                    score << setw(20) << right << students[i].chemistry_score ;
                else if(sub[k] == "biology_score")
                    score << setw(20) << right << students[i].biology_score ;
                else if(sub[k] == "english_score")
                    score << setw(20) << right << students[i].english_score ;
                else if(sub[k] == "geography_score")
                    score << setw(20) << right << students[i].geography_score ;
            }
            cout <<
            setw(20) << right << this->students[i].first_name.substr(0, 20) << 
            setw(20) << right << this->students[i].last_name.substr(0, 20) << 
            setw(30) << right << this->students[i].email.substr(0, 30) << 
            score.str() << 
            setw(12) << right << this->students[i].Grade.substr(0, 20) << 
            setw(12) << right << this->students[i].CGPA << 
            endl;
        }

        cout << "Page " << (start / 10) + 1 << " of " << (size / 10) + 1 << endl;
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
