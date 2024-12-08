#include "Admin.h"

Admin::Admin() : Base()
{
    admin_login["admin"] = "123456"; // Admin login
}

void Admin::view()
{
    cout << "Admin view" << endl;
    int size = this->students.size();
    int start = 0, end = start + 10;
    // cout
    while(start < size)
    {
        if (end > size)
        {
            end = size;
        }
    }
}