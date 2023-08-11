#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<cstdlib>
#include<map>
#include "restaurant.h"
using namespace std;

int MainFood::getId()
{
    return itemId;
}

int MainFood::getPrice()
{
    return itemPrice;
}

void MainFood::setItem(int id)
{
    ifstream infile("mainmenu.txt");
    while(1)
    {
        infile >> itemId >> itemPrice;
        getline(infile,itemName);
        if(itemId == id)
        {
            break;
        }
    }
}


void MainFood::displayItem()
{
    int i;
    i = itemName.length();
    cout << itemName << setw(29 - i) << ": " << itemPrice << "TK\n";
}


int SideFood::getId()
{
    return itemId;
}

int SideFood::getPrice()
{
    return itemPrice;
}

void SideFood::setItem(int id)
{
    ifstream infile("sidemenu.txt");
    while(1)
    {
        infile >> itemId >> itemPrice;
        getline(infile,itemName);
        if(itemId == id)
        {
            break;
        }
    }
}

void SideFood::displayItem()
{
    int i;
    i = itemName.length();
    cout << itemName << setw(29 - i) << ": " << itemPrice << "TK\n";
}


int Beverages::getId()
{
    return itemId;
}

int Beverages::getPrice()
{
    return itemPrice;
}

void Beverages::setItem(int id)
{
    ifstream infile("beveragemenu.txt");
    while(1)
    {
        infile >> itemId >> itemPrice;
        getline(infile,itemName);
        if(itemId == id)
        {
            break;
        }
    }
}

void Beverages::displayItem()
{
    int i;
    i = itemName.length();
    cout << itemName << setw(29 - i) << ": " << itemPrice << "TK\n";
}

void Checkout::payment()
{
    int choice;
    cout<<"\n---------------PAYMENT---------------\n\n"<<endl;
    cout << "1. Cash on delivery\n";
    cout << "2. Online payment\n";
    cout << "Enter your choice: ";
    cin>>choice;
    cin.ignore();
    if(choice==2)
    {
        char choice2;
        cout <<"\n\n---------------ONLINE PAYMENT---------------\n\n";
        cout << "a. bkash\n";
        cout << "b. rocket\n";
        cout << "Enter your choice: ";
        cin >> choice2;
        if(choice2 == 'a')
        {
            cout<<"\n**********bKash**********\n"<<endl;
        }
        else
        {
            cout << "\n**********Rocket**********\n" << endl;
        }
        cout<<"Enter Mobile No : ";
        cin >> bill.mobile_no;
        cout<<"Enter Amount : ";
        cin>>bill.paid_amount;
        cin.ignore();
    }
}

void Order::restid()
{
    for(int i = 0; i < 100; i++)
    {
        check[i] = 0;
    }
}

void Order::addOrder()
{

    int itemChoice;
    cout << "\nEnter your choice: ";
    cin >> itemChoice;
    cin.ignore();
    if(itemChoice <= 10)
    {
        food[ordernum] = new MainFood;
        food[ordernum]->setItem(itemChoice);
    }
    else if(itemChoice <= 13)
    {
        food[ordernum] = new SideFood;
        food[ordernum]->setItem(itemChoice);
    }
    else if(itemChoice <= 17)
    {
        food[ordernum] = new Beverages;
        food[ordernum]->setItem(itemChoice);
    }
    ordernum++;
}

void Order::deleteOrder()
{
    system("CLS");
    if(ordernum == 0)
    {
        cout << "You haven't ordered anything yet!!\n\n";
        cout << "Press enter to go back\n";
        getchar();
    }
    else
    {
        cout << "-----------------ORDER---------------\n";
        int remove_choice,i,j,k,l;
        map<int,int> m;
        for(i = 0,j = 0; i < ordernum; i++)
        {
            if(check[i] != 1)
            {
                cout << j+1 << ". ";
                food[i]->displayItem();
                m[j+1] = i;
                j++;
            }

        }
        cout << "Enter the order you wish to remove: ";
        cin >> remove_choice;
        check[m[remove_choice]] = 1;
        cout << "Order number " << remove_choice << " removed\n\n";
    }

}

void Order::showmenu()
{
    system("CLS");
    cout << "-------------------------------------------------MENU----------------------------------------------\n\n";
    cout << "              Main Menu                |           Side Menu           |           Beverages       \n";
    cout << "1. Chicken Burger............: 200TK   |  11. French Fries.....: 50TK  |   14. Coka Cola.....: 30TK\n";
    cout << "2. Beef Burger...............: 220TK   |  12. Coleslaw.........: 50TK  |   15. Seven Up......: 30TK\n";
    cout << "3. Chicken Sandwich..........: 150TK   |  13. Potato Wedges....: 60TK  |   16. Coffee........: 40TK\n";
    cout << "4. Sub-Sandwich..............: 180TK   |                               |   17. Cold Coffee...: 70TK\n";
    cout << "5. Shwarma...................: 120TK   |                               |\n";
    cout << "6. Pizza.....................: 200TK   |                               |\n";
    cout << "7. Chicken wings(6 pieces)...: 250TK   |                               |\n";
    cout << "8. Chicken Nachos............: 150TK   |                               |\n";
    cout << "9. Pasta.....................: 180TK   |                               |\n";
    cout << "10.Chicken Nuggets(10 pieces): 160TK   |                               |\n";
}

int Order::showorder()
{
    system("CLS");
    if(ordernum == 0)
    {
        cout << "You haven't ordered anything yet!!\n\n";
        cout << "Press enter to go back\n";
        getchar();
        return 0;
    }
    else
    {
        cout << "-----------------ORDER---------------\n";
        int i,j = 1;
        for(i = 0; i < ordernum; i++)
        {
            if((food[i]->getId() >= 1) && (food[i]->getId() <= 10) && (check[i] != 1))
            {
                cout << j << ". ";
                food[i]->displayItem();
                j++;
            }
        }
        for(i = 0; i < ordernum; i++)
        {
            if((food[i]->getId() >= 11) && (food[i]->getId() <= 13) && (check[i] != 1))
            {
                cout << j << ". ";
                food[i]->displayItem();
                j++;
            }
        }
        for(i = 0; i < ordernum; i++)
        {
            if((food[i]->getId() >= 14) && (food[i]->getId() <= 17) && (check[i] != 1))
            {
                cout << j << ". ";
                food[i]->displayItem();
                j++;
            }
        }
        return 1;
    }

}

void Order::calcPrice(int id)
{
    amount = 0;
    for(int i = 0; i < ordernum; i++)
    {
        if(check[i] != 1)
        {
            amount += food[i]->getPrice();
        }
    }
    if(id >= 3)
    {

        cout << setw(32) << "Discount : -" << (amount * 10) / 100 << "TK" << endl;
        amount -= (amount * 10) / 100;
        cout << "-------------------------------------\n";
    }
    cout << setw(32) << "Total : " << amount << "TK" << endl;
    ordernum = 0;
}

void Delivery::calcDeliveryTime(char ad[],int post)
{
    strcpy(deliveryAddress,ad);
    deliveryPostalCode = post;
    int time;
    time = deliveryPostalCode*7;
    estimateHour = time / 3600;
    time %= 3600;
    estimateMinute = time / 60;
    time %=60;
    estimateSecond = time;
}

void Delivery::displayDeliveryTime()
{
    cout << "---------------Delivery----------------\n\n";
    cout << "Your Delivery address is " << deliveryAddress << "\n\n";
    cout << "Estimated time of food arrival: " << estimateHour << " hour " << estimateMinute << " minute " << estimateSecond << " second\n";
}

void Customer::Register(int id)
{
    customerId = id;
    cout << "Enter your name: ";
    cin.getline(customerName,100);
    cout << "Enter your password: ";
    cin >> password;
    cout << "Enter your email: ";
    cin >> email;
    cin.ignore();
    cout << "Enter your address: ";
    cin.getline(address,100);
    cout << "Enter your postal code: ";
    cin >> postalcode;
}

int Customer::login(char str[])
{
    int flag = 0;
    if(strcmp(str,email) == 0)
    {
        char pass[100];
        cout << "Enter your password: ";
        cin >> pass;
        cin.ignore();
        if(strcmp(pass,password) == 0)
        {
            visitcnt++;
            flag = 2;
            return flag;
        }
        else
        {
            flag = 1;
            cout << "\nIncorrect Password\n";
            cout << "\nPress enter to try again\n";
            getchar();
        }
    }
    return flag;
}

void Customer::showProfile()
{
    system("CLS");
    cout << "---------------PROFILE---------------\n\n";
    cout << "Name: " << customerName << endl;
    cout << "Password: " << password << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
    cout << "Postal code: " << postalcode << endl;
    cout << "\nPress enter to go back\n";
    getchar();
}

void Customer::updateProfile()
{
    int choice;
    do
    {
        system("CLS");
        cout << "-------------UPDATE PROFILE-------------\n\n";
        cout << "1. Update name\n";
        cout << "2. Update password\n";
        cout << "3. Update email\n";
        cout << "4. Update address\n";
        cout << "5. Update postal code\n";
        cout << "6. exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if(choice == 1)
        {
            cout << "Enter your new name: ";
            cin.getline(customerName,100);
        }
        else if(choice == 2)
        {
            cout << "Enter your new password: ";
            cin >> password;
            cin.ignore();
        }
        else if(choice == 3)
        {
            cout << "Enter your new email: ";
            cin >> email;
            cin.ignore();
        }
        else if(choice == 4)
        {
            cout << "Enter your address: ";
            cin.getline(address,100);
        }
        else if(choice == 5)
        {
            cout << "Enter your postal code: ";
            cin >> postalcode;
        }
    }
    while(choice != 6);
}

void Customer::placeOrder()
{
    table.restid();
    int choice;
    char g;
    do
    {
        system("CLS");
        cout << "-------------ORDER MENU-------------\n\n";
        cout << "1. Add order\n";
        cout << "2. Remove order\n";
        cout << "3. Show order\n";
        cout << "4. Checkout\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if(choice == 1)
        {
            table.showmenu();
            table.addOrder();
        }
        else if(choice == 2)
        {
            table.deleteOrder();
        }
        else if(choice == 3)
        {
            table.showorder();
            cout << "\nPress enter to go back\n";
            getchar();
        }
        else if(choice == 4)
        {
            if(table.showorder() == 1)
            {
                cout << "-------------------------------------\n";
                table.calcPrice(visitcnt);
                cout << "\n";
                pay.payment();
                cout << "\n";
                system("CLS");
                place.calcDeliveryTime(address,postalcode);
                place.displayDeliveryTime();
                cout << "Press Enter to continue.\n";
                getchar();
                break;
            }
        }
    }
    while(choice != 5);
}
