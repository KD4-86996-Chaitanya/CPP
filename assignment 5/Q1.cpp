#include <iostream>
using namespace std;
class Date
{
    int day;
    int month;
    int year;


public:
    Date()
    {
        day =0;
        month=0;
        year=0;

    }
    Date (int day, int month, int year)
    {
         this-> day =day;
         this-> month =month;
         this-> year =year;
    }
        void setDay(int day)
    {
        this->day = day;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    void setYear(int year)
    {
        this->year = year;
    }
    void acceptDate()
    {
        cout << "Enter the day, month and year - "<<endl;
        cin >> day >> month >> year;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
    

};
class Person 
{
    string name;
    string address;
    Date birthdate;

public:
    Person()
    {
        name ="";
        address ="";
    }
    Person(string name, string address, int day, int month, int year): birthdate(day, month, year)
    {
        this->name;
        this->address;
        this->birthdate.setDay(day);
        this->birthdate.setMonth(month);
        this->birthdate.setYear(year);
    }
    void aceept()
    {
        cout<<" Enter the name: "<<endl;
        getline(cin,name);
        cout<<" Address : "<<endl;
        getline(cin,address);
        birthdate.acceptDate();
    }
    void display()
    {
        cout<<"name: "<< name <<endl;
        cout<< "Addres: "<<address<<endl;
        cout<<"Date of birth: ";
        birthdate.displayDate();
    }
};

int main()
{
     Person p1;
     p1.aceept();
     p1.display();
    return 0;
}