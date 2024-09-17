#include <iostream>
using namespace std;
class Employee
{
    int id;
    double salary;

public:
    Employee()
    {
        id=0;
        salary=0;
    }
    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;

    }
    void setid(int id)
    {
        this->id=id;
    }
    int getid()
    {
        return id;
    }
    void setsalary(double salary)
    {
        this->salary=salary;
    }
    double getsalary()
    {
       return salary;
    }

    virtual void accept()
    {
        cout << "Enter empid - ";
        cin >> id;
        cout << "Enter Salary - ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << "Empid -  " << id << endl;
        cout << "Salary -  " << salary << endl;
    }
};

class Manager : virtual public Employee
{
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus = " << bonus << endl;
    }

public:
    Manager()
    {
        bonus=0;
    }
    Manager(int id, double salary, double bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
    void setBonus(double Bonus)
    {
        this->bonus=Bonus;
    }
    double getBonus()
    {
        return bonus;
    }
};

class Salesman : virtual public Employee
{
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "commission = " << commission << endl;
    }

public:
    Salesman()
    {
        commission=0;
    }
    Salesman(int id, double salary, double commission) : Employee(id, salary)
    {
        this->commission = commission;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displaySalesman();
    }
    void setCommision(double comission)
    {
        this->commission=commission;
    }
    double getCommission()
    {
        return commission;

    }
};

class Salesmanager : public Manager, public Salesman
{
public:
    Salesmanager()
    {}
    Salesmanager(int id, double salary, double bonus, double commission) : Employee(id, salary)
    {
        setBonus(bonus);
        setCommision(commission);
    }

    void accept()
    {
        Employee::accept();
        this->acceptManager();
        this->acceptSalesman();
    }
    void display()
    {
        Employee::display();
        this->displayManager();
        this->displaySalesman();
    }
};
int main()
{
    Salesmanager s;
    s.accept();
    s.display();
   



    return 0;
}