#include <iostream>
using namespace std;

class Address
{
 string building;
 string street;
 string city;
 int pin;

public:
  Address()
  {
    
      building="Sunbeam";
      street="Shanivar peth";
     city="Karad";
      pin=4956;

  }
  Address(string a, string b, string c, int d)
  {
     building=a;
     street =b;
     city= c;
     pin =d;
  }
  void accept()
  {

    cout<<"Enter address : building..street..city..pin"<<endl;
    cin>>building >> street >> city >> pin;
  }
  void display()
  {
    cout<<building<<","<<street<<","<<city<<","<<pin<<endl; 
  }

  void setB(string b)
  {
    building =b;
  }
    void sets(string s)
  {
    street =s;
  }
    void setc(string c)
  {
    city =c;
  }
    void setp(int p)
  {
    pin =p;
  }
  string getb()
  {
    return building;
  }
    string gets()
  {
    return street;
  }
    string getc()
  {
    return city;
  }
    int getp()
  {
    return pin;
  }
};
int main()
{
   Address a1;
   a1.display();
   Address a2("Galaxy","Breaker street","London",221);
   a2.display();
   Address a3;
   a3.setB( "Sunbeam");
   a3.sets("marketyard");
   a3.setc("pune");
   a3.setp(3664);
   cout<<a3.getb() <<","<<a3.gets()<<","<<a3.getc()<<","<<a3.getp()<<endl;
   Address a4;
   a4.accept();
   a4.display();

    return 0;

}