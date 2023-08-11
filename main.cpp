#include "restaurant.h"

using namespace std;

int main()
{
    int choice,it = 0,h = 0;
    Customer c[1000];
    ifstream infile("Userdata.dat",ios::binary);
    infile.seekg(0,ios::end);
    it = (infile.tellg()/sizeof(Customer));
    if(infile.tellg() == EOF)
    {
        it = 0;
    }
    infile.seekg(0);
    for(h = 0; h < it; h++)
    {
        infile.read(reinterpret_cast<char*>(&c[h]),sizeof(c[h]));
    }
    do
    {
        system("CLS");
        cout << "----------Online Food Ordering system-----------\n";
        int index;
        cout << "\n1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(10,'\n');

        if(choice == 1)
        {
            system("CLS");
            cout << "------------------SIGNUP-----------------\n\n";
            c[it].Register(it+1);
            cout << "Registration complete\n";
            it++;
        }
        else if(choice == 2)
        {

            while(1)
            {
                system("CLS");
                cout << "------------------LOGIN-----------------\n\n";
                cout << "Enter your email (press 0 to go back): ";
                char str[100];
                int flag = 0;
                cin >> str;
                cin.ignore();
                if(strcmp(str,"0") != 0)
                {
                    for(index = 0; index < it; index++)
                    {
                        flag = c[index].login(str);
                        if(flag == 2)
                        {
                            break;
                        }
                        else if(flag == 1)
                        {
                            break;
                        }
                    }
                    if(flag == 2)
                    {

                        int choice2;
                        do
                        {
                            system("CLS");
                            cout << "------------------WELCOME!!------------------\n\n";
                            cout << "\n1. Show profile\n";
                            cout << "2. Update profile\n";
                            cout << "3. Place order\n";
                            cout << "4. Go back\n";
                            cout << "Enter your choice: ";
                            cin >> choice2;
                            cin.ignore();
                            if(choice2 == 1)
                            {
                                c[index].showProfile();
                            }
                            if(choice2 == 2)
                            {
                                c[index].updateProfile();
                            }
                            else if(choice2 == 3)
                            {
                                c[index].placeOrder();
                                break;
                            }
                        }
                        while(choice2 != 4);
                        break;
                    }
                    else if(flag == 0)
                    {
                        cout << "\nThis email is not registered\n\n";
                        cout << "Press enter to try again\n";
                        getchar();
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    while(choice != 3);
    ofstream outfile("Userdata.dat",ios::binary);
    for(int i = 0; i < it; i++)
    {
        outfile.write(reinterpret_cast<char*>(&c[i]),sizeof(c[i]));
    }
    return 0;
}
