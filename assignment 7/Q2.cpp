#include <iostream>
#include<typeinfo>
using namespace std;

class Employee{

    int id;
    double salary;

public:

    Employee(){
        id=0;
        salary=0;
    }    

    Employee(int id, double salary){
        this->id=id;
        this->salary=salary;
    }

    void setId(int id){
        this->id=id;
    }

     void setSalary(double salary){
        this->salary=salary;
    }

    int getId(){
        return id;
    }

    double getSalary(){
        return salary;
    }

    virtual void accept(){
        cout<<"Enter Id : "<<endl;
        cin>>id;
        cout<<"Enter Salary : "<<endl;
        cin>>salary;
    }

    virtual void display(){
        cout<<"Id : "<<id<<endl;
        cout<<"Salary : "<<salary<<endl;
    }
};

class Manager : virtual public Employee{

    double bonus;

protected:

    void acceptManager(){
        cout<<"Enter bonus : "<<endl;
        cin>>bonus;
    }    

    void displayManager(){
        cout<<"Bonus is : "<<bonus<<endl;
    }

public:

    Manager(){
        bonus=0;
    }    

    Manager(int id, double salary, double bonus): Employee(id,salary){
       this->bonus=bonus;
    }

    void setBonus(double bonus){
        this->bonus=bonus;
    }

    double getBonus(){
        return bonus;
    }

    void accept(){
        Employee::accept();
        acceptManager();
    }

    void display(){
        Employee::display();
        displayManager();
    }

};

class Salesman : virtual public Employee{

    double commision;

protected:

    void acceptSalesman(){
        cout<<"Enter Commision : "<<endl;
        cin>>commision;
    }    

    void displaySalesman(){
        cout<<"Commision is : "<<commision<<endl;
    }

public:

    Salesman(){
        commision=0;
    }    

    Salesman(int id, double salary, double commision): Employee(id,salary){
       this->commision=commision;
    }

    void setCommission(double commision){
        this->commision=commision;
    }

    double getCommision(){
        return commision;
    }

    void accept(){
        Employee::accept();
        acceptSalesman();
    }

    void display(){
        Employee::display();
        displaySalesman();
    }

};

class SalesManager : public Manager, public Salesman{

public:
    SalesManager(){

    }

    SalesManager(int id, double sal, double bonus, double commision):Employee(id,sal){
        setBonus(bonus);
        setCommission(commision);
    }

    void accept(){
        Employee::accept();
        this->acceptManager();
        this->acceptSalesman();
    }

    void display(){
        Employee::display();
        displayManager();
        displaySalesman();
    }

};

int main()
{
    Employee *arr[5];
    int pick;
    do
    {
        cout << "1. Accept Employee " << endl;
        cout << "2. Display the count of all employees with respect to designation " << endl;
        cout << "3. Display All Managers" << endl;
        cout << "4. Display All Salesman" << endl;
        cout << "5. Display All SalesManagers" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Choice ";
        cin >> pick;
        switch (pick)
        {
        case 1:
        {
            for (int i = 0; i < 5; i++)
            {
                cout << "1. Accept Manager " << endl;
                cout << "2. Accept Salesman" << endl;
                cout << "3. Accept SalesManager " << endl;
                int choice;
                cout << "Enter Choice - ";
                cin >> choice;
                if (choice == 1)
                {
                    arr[i] = new Manager();
                    cout<<"Enter Manager Details"<<endl;
                }
                else if (choice == 2)
                {
                    arr[i] = new Salesman();
                    cout<<"Enter Salesman Details"<<endl;
                }

                else if (choice == 3)
                {
                    arr[i] = new SalesManager();
                    cout<<"Enter Salesmanager Details"<<endl;
                }
                else
                {
                    cout << "Sorry";
                }
                arr[i]->accept();
            }
        }
        break;
        case 2:
        {
            int countm = 0;
            int counts = 0;
            int countsm = 0;
            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]) == typeid(Manager))
                {
                    countm += 1;
                }
                else if (typeid(*arr[i]) == typeid(Salesman))
                {
                    counts += 1;
                }
                else
                {
                    countsm += 1;
                }
            }
                cout<<"Number of Manager = "<<countm<<endl;
                cout<<"Number of Salesman = "<<counts<<endl;
                cout<<"Number of SalesManagers = "<<countsm<<endl;

        }
            break;

        case 3:
        {
            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]) == typeid(Manager))
                {
                    arr[i]->display();
                    cout<<"-------"<<endl;
                }
            }
        }
        break;
        case 4:
        {
            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]) == typeid(Salesman))
                {
                    arr[i]->display();
                    cout<<"-------"<<endl;
                }
            }
        }
        break;
        case 5:
        {
            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]) == typeid(SalesManager))
                {
                    arr[i]->display();
                    cout<<"-------"<<endl;
                }
            }
        }
        break;
        case 6:
            cout << "Thank You";
            break;

        default:
            cout << "Wrong Choice" << endl;
            break;
        }
    } while (pick != 6);

    for (int i = 0; i < 3; i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }
    return 0;
}