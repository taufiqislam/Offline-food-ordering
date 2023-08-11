#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<cstdlib>
#include<map>
using namespace std;

struct money
{
    int mobile_no;
    int paid_amount;
};

class Item
{
private:
    string itemName;
    int itemId;
    int itemPrice;
public:
    virtual int getPrice() = 0;
    virtual int getId() = 0;
    virtual void setItem(int id) = 0;
    virtual void displayItem() = 0;
};

class MainFood : public Item
{
private:
    string itemName;
    int itemId;
    int itemPrice;
public:
    int getPrice();
    int getId();
    void setItem(int id);
    void displayItem();
};

class SideFood : public Item
{
private:
    string itemName;
    int itemId;
    int itemPrice;
public:
    int getPrice();
    int getId();
    void setItem(int id);
    void displayItem();
};

class Beverages : public Item
{
private:
    string itemName;
    int itemId;
    int itemPrice;
public:
    int getPrice();
    int getId();
    void setItem(int id);
    void displayItem();
};

class Checkout
{
private:
    money bill;
public:
    void payment();
};

class Order
{
private:
    int orderID;
    int ordernum;
    Item* food[100];
    int check[100] = {};
    int amount;

public:
    Order() : orderID(0), ordernum(0), amount(0)
    { }
    void addOrder();
    void deleteOrder();
    void showmenu();
    int showorder();
    void calcPrice(int id);
    void restid();
};

class Delivery
{
private:
    char deliveryAddress[100];
    int deliveryPostalCode;
    int estimateHour;
    int estimateMinute;
    int estimateSecond;
public:
    void calcDeliveryTime(char ad[],int post);
    void displayDeliveryTime();
};

class Customer
{
private:
    int customerId;
    int visitcnt;
    char customerName[100];
    char password[100];
    char email[100];
    char address[100];
    int postalcode;
    int customerStatus;
    Delivery place;
    Order table;
    Checkout pay;

public:
    Customer() : customerId(0),visitcnt(0)
    { }
    void Register(int id);
    int login(char str[]);
    void showProfile();
    void updateProfile();
    void placeOrder();
};
