#include "faculty.h"
#include "Admin.h"
#include "Student.h"
#include "stats.h"

#ifdef _WIN32
#include <windows.h> // Include for Windows-specific console handling
#endif

using namespace std;

// Function to enable ANSI escape codes on Windows
void EnableVirtualTerminalProcessing()
{
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
        return;
    
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
        return;
    
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif
    // On Linux and macOS, ANSI escape codes are enabled by default, so do nothing here.
}

int main()
{
    // Enable ANSI escape codes on Windows
    EnableVirtualTerminalProcessing();

    int c = 1;
    while (c != 5)
    {
        // Optional: Clear the console screen
        // Uncomment the appropriate line for your system
        // system("cls"); // For Windows
        // system("clear"); // For Linux and macOS

        // ASCII art with colored text
        cout << "\033[1;34m" << "======================================================" << "\033[0m" << endl;
        cout << "\033[1;34m" << "|                                                    |" << "\033[0m" << endl;
        cout << "\033[1;32m" << "|          Welcome to Student Database System        |" << "\033[0m" << endl;
        cout << "\033[1;34m" << "|                                                    |" << "\033[0m" << endl;
        cout << "\033[1;34m" << "======================================================" << "\033[0m" << endl;
        cout << endl;
        cout << "\033[1;33m" << "                Please select an option               " << "\033[0m" << endl;
        cout << "\033[1;34m" << "------------------------------------------------------" << "\033[0m" << endl;
        cout << "\033[1;36m" << "|  1. Student View                                   |" << "\033[0m" << endl;
        cout << "\033[1;36m" << "|  2. Admin Login                                    |" << "\033[0m" << endl;
        cout << "\033[1;36m" << "|  3. Faculty Login                                  |" << "\033[0m" << endl;
        cout << "\033[1;36m" << "|  4. View Plots                                     |" << "\033[0m" << endl;
        cout << "\033[1;36m" << "|  5. Exit                                           |" << "\033[0m" << endl;
        cout << "\033[1;34m" << "------------------------------------------------------" << "\033[0m" << endl;
        cout << "\033[1;35m" << "Enter your choice: " << "\033[0m";
        cin >> c;

        if (c == 1)
        {
            string username;
            cout << "\033[1;35m" << "Please enter your student username: " << "\033[0m";
            cin >> username;
            StudentUser *std = new StudentUser();
            if (std->login(username))
            {
                vector<Student> stud = std->get_students();
                char cho = 'a';

                while (cho != 'e')
                {
                    std->clearScreen();
                    cout << "\033[1;34m" << "========================================" << "\033[0m" << endl;
                    cout << "\033[1;32m" << "|             Student View             |" << "\033[0m" << endl;
                    cout << "\033[1;34m" << "========================================" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "a. View Student Data" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "b. Sort" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "c. Search" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "d. Filter" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "e. Log Out" << "\033[0m" << endl;
                    cout << "\033[1;35m" << "Enter your choice: " << "\033[0m";
                    cin >> cho;

                    if (cho == 'a')
                    {
                        std->view(stud);
                    }
                    else if (cho == 'b')
                    {
                        bool grade = false, last_name = false;
                        cout << "\033[1;35m" << "Enter 1 to sort by Grade else 0: " << "\033[0m";
                        cin >> grade;
                        cout << "\033[1;35m" << "Enter 1 to sort by Last Name else 0: " << "\033[0m";
                        cin >> last_name;
                        std->sort_student(grade, last_name, stud);
                        std->view(stud);
                    }
                    else if (cho == 'c')
                    {
                        string name;
                        cin.ignore();
                        cout << "\033[1;35m" << "Enter the first and last name separated by space (e.g., 'Jane Doe'): " << "\033[0m";
                        getline(cin, name);
                        vector<Student> search = std->search_student(name, stud);
                        std->view(search);
                    }
                    else if (cho == 'd')
                    {
                        string grd;
                        cout << "\033[1;35m" << "Enter the grade (Freshman, Sophomore, Junior, Senior): " << "\033[0m";
                        cin >> grd;
                        vector<Student> filtered = std->filter_student(grd, stud);
                        std->view(filtered);
                    }
                    else if (cho == 'e')
                    {
                        cout << "\033[1;31m" << "Logging out from Student view." << "\033[0m" << endl;
                        std->clearScreen();
                        delete std;
                        break;
                    }
                    else
                    {
                        cout << "\033[1;31m" << "Invalid choice. Please select a correct option." << "\033[0m" << endl;
                    }
                }
            }
        }
        else if (c == 2)
        {
            string username, password;
            cout << "\033[1;35m" << "Please enter your admin username: " << "\033[0m";
            cin >> username;
            cout << "\033[1;35m" << "Please enter your admin password: " << "\033[0m";
            cin >> password;
            Admin *adm = new Admin();
            if (adm->login(username, password))
            {
                vector<Student> stud = adm->get_students();
                char cho = 'a';

                while (cho != 'e')
                {
                    adm->clearScreen();
                    cout << "\033[1;34m" << "========================================" << "\033[0m" << endl;
                    cout << "\033[1;32m" << "|              Admin View              |" << "\033[0m" << endl;
                    cout << "\033[1;34m" << "========================================" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "a. View Student Data" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "b. Sort" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "c. Search" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "d. Filter" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "e. Log Out" << "\033[0m" << endl;
                    cout << "\033[1;35m" << "Enter your choice: " << "\033[0m";
                    cin >> cho;

                    if (cho == 'a')
                    {
                        adm->view(stud);
                    }
                    else if (cho == 'b')
                    {
                        bool grade = false, last_name = false, cgpa = false;
                        cout << "\033[1;35m" << "Enter 1 to sort by Grade else 0: " << "\033[0m";
                        cin >> grade;
                        cout << "\033[1;35m" << "Enter 1 to sort by Last Name else 0: " << "\033[0m";
                        cin >> last_name;
                        cout << "\033[1;35m" << "Enter 1 to sort by CGPA else 0: " << "\033[0m";
                        cin >> cgpa;
                        adm->sort_student(grade, last_name, cgpa, stud);
                        adm->view(stud);
                    }
                    else if (cho == 'c')
                    {
                        string name;
                        cin.ignore();
                        cout << "\033[1;35m" << "Enter the first and last name separated by space (e.g., 'John Smith'): " << "\033[0m";
                        getline(cin, name);
                        vector<Student> search = adm->search_student(name);
                        adm->view(search);
                    }
                    else if (cho == 'd')
                    {
                        string grd, gender, ptj;
                        char cgpa;
                        cout << "\033[1;35m" << "Enter the grade (Freshman, Sophomore, Junior, Senior): " << "\033[0m";
                        cin >> grd;
                        cout << "\033[1;35m" << "Enter the CGPA (A, B, C, D): " << "\033[0m";
                        cin >> cgpa;
                        cout << "\033[1;35m" << "Enter the gender (male, female, non-binary): " << "\033[0m";
                        cin >> gender;
                        cout << "\033[1;35m" << "Enter 'True' or 'False' for part-time job: " << "\033[0m";
                        cin >> ptj;
                        vector<Student> filtered = adm->filter_student(stud, grd, cgpa, gender, ptj);
                        adm->view(filtered);
                    }
                    else if (cho == 'e')
                    {
                        cout << "\033[1;31m" << "Logging out from Admin view." << "\033[0m" << endl;
                        delete adm;
                        adm->clearScreen();
                        break;
                    }
                    else
                    {
                        cout << "\033[1;31m" << "Invalid choice. Please select a correct option." << "\033[0m" << endl;
                    }
                }
            }
        }
        else if (c == 3)
        {
            string username, password;
            cout << "\033[1;35m" << "Please enter your faculty username: " << "\033[0m";
            cin >> username;
            cout << "\033[1;35m" << "Please enter your faculty password: " << "\033[0m";
            cin >> password;
            faculty *fac = new faculty();
            if (fac->login(username, password))
            {
                vector<Student> stud = fac->get_students();
                char cho = 'a';

                while (cho != 'e')
                {
                    fac->clearScreen();
                    cout << "\033[1;34m" << "========================================" << "\033[0m" << endl;
                    cout << "\033[1;32m" << "|             Faculty View             |" << "\033[0m" << endl;
                    cout << "\033[1;34m" << "========================================" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "a. View Student Data" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "b. Sort" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "c. Search" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "d. Filter" << "\033[0m" << endl;
                    cout << "\033[1;36m" << "e. Log Out" << "\033[0m" << endl;
                    cout << "\033[1;35m" << "Enter your choice: " << "\033[0m";
                    cin >> cho;

                    if (cho == 'a')
                    {
                        fac->view(stud);
                    }
                    else if (cho == 'b')
                    {
                        bool grade = false, last_name = false, cgpa = false;
                        cout << "\033[1;35m" << "Enter 1 to sort by Grade else 0: " << "\033[0m";
                        cin >> grade;
                        cout << "\033[1;35m" << "Enter 1 to sort by Last Name else 0: " << "\033[0m";
                        cin >> last_name;
                        cout << "\033[1;35m" << "Enter 1 to sort by CGPA else 0: " << "\033[0m";
                        cin >> cgpa;
                        fac->sort_student(grade, last_name, cgpa, stud);
                        fac->view(stud);
                    }
                    else if (cho == 'c')
                    {
                        string name;
                        cin.ignore();
                        cout << "\033[1;35m" << "Enter the first and last name separated by space (e.g., 'Alice Johnson'): " << "\033[0m";
                        getline(cin, name);
                        vector<Student> search = fac->search_student(name);
                        fac->view(search);
                    }
                    else if (cho == 'd')
                    {
                        string grd;
                        char cgpa;
                        cout << "\033[1;35m" << "Enter the grade (Freshman, Sophomore, Junior, Senior): " << "\033[0m";
                        cin >> grd;
                        cout << "\033[1;35m" << "Enter the CGPA (A, B, C, D): " << "\033[0m";
                        cin >> cgpa;
                        vector<Student> filtered = fac->filter_student(stud, grd, cgpa);
                        fac->view(filtered);
                    }
                    else if (cho == 'e')
                    {
                        cout << "\033[1;31m" << "Logging out from Faculty view." << "\033[0m" << endl;
                        fac->clearScreen();
                        delete fac;
                        break;
                    }
                    else
                    {
                        cout << "\033[1;31m" << "Invalid choice. Please select a correct option." << "\033[0m" << endl;
                    }
                }
            }
        }
        else if (c == 4)
        {
            stats s;
            vector<Student> students = s.get_students();
            s.view(students);
            s.plot_student_stats();
        }
        else if (c == 5)
        {
            cout << "\033[1;31m" << "Thank you for using the Student Database System. Goodbye!" << "\033[0m" << endl;
        }
        else
        {
            cout << "\033[1;31m" << "Invalid choice. Please enter a valid option." << "\033[0m" << endl;
        }
    }

    return 0;
}
