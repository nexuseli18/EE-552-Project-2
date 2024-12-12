#include"faculty.h"
#include"Admin.h"
#include"Student.h"

using namespace std;

int main()
{
    int c = 1;
    while(c != 5)
    {
        cout << "Welcome to student database management system" << endl;
        cout << "1. Student View\n2. Admin Login\n3. Faculty Login\n4. View plots\n5. Exit" << endl;
        cout << "Enter your choice:";
        cin >> c;
        if( c == 1)
        {
            string username;
            cout << "Please enter your student username: ";
            cin >> username;
            StudentUser std;
            if(std.login(username))
            {
                vector<Student> stud;
                stud = std.get_students();
                
                char cho = 'a';
                
                while(cho !='e')
                {
                    std.clearScreen();
                    cout << "Student View." << endl;
                    cout << "a. View Student data\nb. Sort\nc. Search\nd. Filter\ne. Log out" << endl;
                    cout << "Enter your choice: ";
                    cin >> cho;
                    if(cho == 'a')
                    {
                        std.view(stud);
                    }
                    else if(cho == 'b')
                    {
                        bool grade = false, last_name = false;
                        cout << "Enter 1 to sort by Grade else 0: ";
                        cin >> grade; 
                        cout << "Enter 1 to sort by Last name else 0: ";
                        cin >> last_name; 
                        std.sort_student(grade, last_name, stud);
                        std.view(stud);
                    }
                    else if(cho == 'c')
                    {
                        string name;
                        cin.ignore();
                        cout << "Enter the first and last name seprated by space (Eg. 'Tanjiro Kamado'): ";
                        getline(cin, name);
                        vector<Student> search;
                        search = std.search_student(name, stud);
                        std.view(search);
                    }
                    else if(cho == 'd')
                    {
                        cout << "Not yet implemented." << endl;
                    }
                    else if(cho == 'e')
                    {
                        cout << "Logging out from Faculty login!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Invalid choice. Please select correct options." << endl;
                    }
                }
            }
            else
                continue;
        }
        else if(c == 2)
        {
            string username, password;
            cout << "Please enter your admin username: ";
            cin >> username;
            cout << "Please enter your admin password: ";
            cin >> password;
            Admin adm;
            if(adm.login(username, password))
            {
                vector<Student> stud;
                stud = adm.get_students();
                
                char cho = 'a';
                
                while(cho !='e')
                {
                    adm.clearScreen();
                    cout << "You have Logged-in as an faculty." << endl;
                    cout << "a. View Student data\nb. Sort\nc. Search\nd. Filter\ne. Log out" << endl;
                    cout << "Enter your choice: ";
                    cin >> cho;
                    if(cho == 'a')
                    {
                        adm.view(stud);
                    }
                    else if(cho == 'b')
                    {
                        bool grade = false, last_name = false, cgpa = false;
                        cout << "Enter 1 to sort by Grade else 0: ";
                        cin >> grade; 
                        cout << "Enter 1 to sort by Last name else 0: ";
                        cin >> last_name; 
                        cout << "Enter 1 to sort by CGPA else 0: ";
                        cin >> cgpa;
                        adm.sort_student(grade, last_name, cgpa, stud);
                        adm.view(stud);
                    }
                    else if(cho == 'c')
                    {
                        string name;
                        cin.ignore();
                        cout << "Enter the first and last name seprated by space (Eg. 'Tanjiro Kamado'): ";
                        getline(cin, name);
                        vector<Student> search;
                        search = adm.search_student(name);
                        adm.view(search);
                    }
                    else if(cho == 'd')
                    {
                        cout << "Not yet implemented." << endl;
                    }
                    else if(cho == 'e')
                    {
                        cout << "Logging out from Faculty login!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Invalid choice. Please select correct options." << endl;
                    }
                }
            }
            else
                continue;
        }
        else if(c == 3)
        {
            string username, password;
            cout << "Please enter your faculty username: ";
            cin >> username;
            cout << "Please enter your faculty password: ";
            cin >> password;
            faculty fac;
            if(fac.login(username, password))
            {
                vector<Student> stud;
                stud = fac.get_students();
                
                char cho = 'a';
                
                while(cho !='e')
                {
                    fac.clearScreen();
                    cout << "You have Logged-in as an faculty." << endl;
                    cout << "a. View Student data\nb. Sort\nc. Search\nd. Filter\ne. Log out" << endl;
                    cout << "Enter your choice: ";
                    cin >> cho;
                    if(cho == 'a')
                    {
                        fac.view(stud);
                    }
                    else if(cho == 'b')
                    {
                        bool grade = false, last_name = false, cgpa = false;
                        cout << "Enter 1 to sort by Grade else 0: ";
                        cin >> grade; 
                        cout << "Enter 1 to sort by Last name else 0: ";
                        cin >> last_name; 
                        cout << "Enter 1 to sort by CGPA else 0: ";
                        cin >> cgpa;
                        fac.sort_student(grade, last_name, cgpa, stud);
                        fac.view(stud);
                    }
                    else if(cho == 'c')
                    {
                        string name;
                        cin.ignore();
                        cout << "Enter the first and last name seprated by space (Eg. 'Tanjiro Kamado'): ";
                        getline(cin, name);
                        vector<Student> search;
                        search = fac.search_student(name);
                        fac.view(search);
                    }
                    else if(cho == 'd')
                    {
                        cout << "Not yet implemented." << endl;
                    }
                    else if(cho == 'e')
                    {
                        cout << "Logging out from Faculty login!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Invalid choice. Please select correct options." << endl;
                    }
                }
            }
            else
                continue;
        }
        else if(c == 4)
        {
            
        }
        else if(c == 5)
        {
            cout << "Bye!" << endl;
        }
        else
        {
            cout << "Invalid choice. Please enter a valid options." << endl;
        }
    }

    return 1;
}
