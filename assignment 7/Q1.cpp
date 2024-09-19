#include <iostream>
#include<typeinfo>
using namespace std;

class Product
{

    int id;
    string title;
    double price;

public:
    Product()
    {
        id = 1;
        title = "";
        price = 1.0;
    }

    Product(int id, string title, double price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }

    virtual void accept()
    {
        cout << "Enter id : " << endl;
        cin >> id;
        cout << "Enter Title : " << endl;
        cin >> title;
        cout << "Enter Price : " << endl;
        cin >> price;
    }

    virtual void display()
    {
        cout << "Id : " << id << endl
             << "Title : " << title << endl
             << "Price : " << price << endl;
    }

    double getPrice(){
        return price;
    }
};

class Book : public Product
{
    string auther;

public:
    Book()
    {
        auther = "";
    }

    Book(int id, string title, double price, string auther) : Product(id, title, price)
    {
        this->auther = auther;
    }

    void accept()
    {
        Product::accept();
        cout << "Enter Auther : " << endl;
        cin >> auther;
    }

    void display()
    {
        Product::display();
        cout << "Auther : " << auther << endl;
    }

};

class Tape : public Product
{
    string artist;

public:
    Tape()
    {
        artist = "";
    }

    Tape(int id, string title, double price, string artist) : Product(id, title, price)
    {
        this->artist = artist;
    }

    void accept()
    {
        Product::accept();
        cout << "Enter Artist : " << endl;
        cin >> artist;
    }

    void display()
    {
        Product::display();
        cout << "Artist : " << artist << endl;
    }
};



int main()
{

    Product *arr[3];
    double total=0;
    int choice;
    do
    {
        cout << "0. Exit" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Display Items" << endl;
        cout << "3. Print Bill" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exit ..." << endl;
            break;
        case 1:
        {   
            int c;
            for(int i=0; i<3; i++)
            {
                cout<<"Enter 0 for Book and 1 for Tape : "<<endl;
                cin>>c;
                if(c==0){
                    arr[i] = new Book;
                    arr[i]->accept();
                    
                }
                else if(c==1){
                    arr[i] = new Tape;
                    arr[i]->accept();
                    
                }
                else{
                    cout<<"Enter correct choice"<<endl;
                }
            }
            
        }
    
            break;
        
        case 2:
            {
                cout<<"Items in your cart are : "<<endl;
                for (int i = 0; i < 3; i++)
                {
                    arr[i]->display();
                }
                
            }

            break;
        case 3:
            {
                for(int i=0 ; i<3 ; i++){
                    if(typeid(*arr[i])==typeid(Book)){
                        double p=arr[i]->getPrice();
                      total+= p-(p*0.05);
                    }
                    else if(typeid(*arr[i])==typeid(Tape))
                    {
                        double p=arr[i]->getPrice();
                      total+= p-(p*0.10);
                    }
                }

                cout<<"Total Price : "<<total;
            }
            break;
        default:
             cout<<"Wrong choice ....."<<endl;
            break;
        }

    } while (choice != 0);
    return 0;
}