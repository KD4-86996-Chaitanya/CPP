
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
protected:
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

class Employee : public Person
{
   int id;
   int dept;
   double sal;
   Date joining_date;

public:
    Employee()
    {
        id =0;
        dept=0;
        sal=0;

    }
    Employee(int id , int dept, double sal, string name, string address, int day, int month, int year, int joing_day, int joing_month, int joining_year ) :Person(name, address, day, month, year)
    {
        Date joining_date(joing_day,joing_month,joining_year);
        this->id=id;
        this->dept=dept;
        this->sal=sal;
        this->joining_date.setDay(day);
        this->joining_date.setDay(month);
        this->joining_date.setDay(year);
    
    }
    void acceptEmp()
    {
        Person::aceept();
        cout<<"Enter Employee ID: "<<endl;
        cin>>id;
        cout<<"Enter Employee Dept no: "<<endl;
        cin>>dept;
        cout<<"Enter Employee Salary :"<<endl;
        cin>>sal;
        joining_date.acceptDate();
    }
    void displayEmp()
    {
        cout<<"******************************"<<endl;
        Person::display();
        cout<<"id :"<<id<<endl;
        cout<<"Department no: "<<dept<<endl;
        cout<<"Salary: "<<sal<<endl;
        joining_date.displayDate();
    }
};

int main()
{
    //  Person p1;
    //  p1.aceept();
    //  p1.display();
    Employee e1;
    e1.acceptEmp();
    e1.displayEmp();

    return 0;
}