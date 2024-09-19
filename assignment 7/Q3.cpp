#include <iostream>
using namespace std;

enum EAccountType
{
    SAVING = 1,
    CURRENT,
    DMAT,
};

class InsufficientFundsException
{
    string message;

public:
    InsufficientFundsException() {}

    InsufficientFundsException(string message) : message(message) {}

    void display()
    {
        cout << message << endl;
    }
};

class Account
{
    int accno;
    EAccountType type;
    double balance;

public:
    Account() {}

    Account(int accno, EAccountType type, double balance)
    {
        this->accno = accno;
        this->balance = balance;
        this->type = type;
    }

    int getAccno()
    {
        return accno;
    }

    void setBalance(double balance)
    {
        this->balance = balance;
    }

    void accept()
    {
        cout << "1. Savings" << endl;
        cout << "2. Current" << endl;
        cout << "3. Dmat" << endl;
        cout << "Enter the choice of account" << endl;
        int choice;
        cin >> choice;
        type = static_cast<EAccountType>(choice);
        cout << "Enter Accno - " << endl;
        cin >> accno;
        cout << "Enter Balance : " << endl;
        cin >> balance;
    }

    void display()
    {
        switch (type)
        {
        case SAVING:
            cout << "Account type : Savings" << endl;
            break;
        case CURRENT:
            cout << "Account type : Current" << endl;
            break;
        case DMAT:
            cout << "Account type : Dmat" << endl;
            break;

        default:
            break;
        }
        cout << "Account No. : " << accno << endl;
        cout << "Balance : " << balance << endl;
    }

    void deposit(double amount)
    {
        if (amount < 0)
            throw InsufficientFundsException("Deposit amount cannot be negative.");
        balance += amount;
        cout << "After Deposit, updated balance is : " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
            throw InsufficientFundsException("Amount cannot be greater than the balance.");
        balance -= amount;
        cout << "After Withdraw, updated balance is : " << balance << endl;
    }
};

int main()
{
    Account *a[5];
    int choice;
    int i = 0;
    do
    {
        cout << "0. EXIT" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. Deposit Amount" << endl;
        cout << "3. Withdraw Amount" << endl;
        cout << "4. Display Account" << endl;
        cout << "Enter Your choice : " << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:

        {
            if (i < 5)
            {
                a[i] = new Account();
                a[i]->accept();
                i++;
            }
            else
            {
                cout << "Cannot add more accounts, limit reached." << endl;
            }
        }
        break;
        case 2:
        {
            int accno;
            cout << "Enter accno for deposit money" << endl;
            cin >> accno;
            // bool found = false;
            for (int j = 0; j<i; j++)
            {
                if (a[j]->getAccno() == accno)
                {
                    // found = true;
                    double amt;
                    cout << "Enter Amount : " << endl;
                    cin >> amt;
                    try
                    {
                        a[j]->deposit(amt);
                    }
                    catch (InsufficientFundsException e)
                    {
                        e.display();
                    }
                    break;
                }
                else
                {
                    cout << "Account not found." << endl;
                }
            }
            // if (!found)
            // {
            //     cout << "Account not found." << endl;
            // }
        }
        break;
        case 3:
        {
            int accno;
            cout << "Enter accno for withdraw money" << endl;
            cin >> accno;
            // bool found = false;
            for (int j = 0; j<i; j++)
            {
                if (a[j]->getAccno() == accno)
                {
                    // found = true;
                    int amt;
                    cout << "Enter Amount : " << endl;
                    cin >> amt;
                    try
                    {
                        a[j]->withdraw(amt);
                    }
                    catch (InsufficientFundsException e)
                    {
                        e.display();
                    }
                    break;
                }
                else
                {
                    cout << "Account not found." << endl;
                }
            }
            // if (!found)
            // {
            //     cout << "Account not found." << endl;
            // }
        }
        break;
        case 4:
            {
                for (int j = 0; j<i ; j++)
                {
                    a[j]->display();
                }
                
            }
            break;
        default:
            cout << "Wrong choice." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
