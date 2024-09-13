#include <iostream>
using namespace std;
class Tollbooth
{
   int Tcars;
   double amount;
   int nopay;
   int pay;
public:
   Tollbooth()
   {
     pay= 0;
     Tcars = 0;
     amount = 0;
     nopay =0;
   }
   void payingCar()
   {
     pay++;
     Tcars++;
     amount = amount +0.50;
   }
   void nonpayingcars()
   {
      nopay++;
      Tcars++;
   }
   void printOnConsole()
   {
      cout<<"Non paying cars :"<<nopay<<endl;
      cout<<" Total cars :"<<Tcars<<endl;
      cout<<"total Amount..."<<amount<<endl;
      
   }
   int getTcars()
   {
    return Tcars;
   }
      int getnopay()
   {
    return nopay;
   }
   int getpay()
   {
    return pay;
   }
//    int getAmount()
//    {
//     return amount;
//    }

};

int menu()
{
    int n;
    cout<<"Enter 3 for Total cars.."<<endl;
    cout<<"Enter 1 for the car and pay...."<<endl;
    cout<<"Enter 2 for the car only...."<<endl;
    cout<<"Exit...0"<<endl;
    cin>>n;
    return n;

}
int main()
{
     Tollbooth t1;
    int choice;
    while((choice= menu()) != 0)
    switch(choice)
    {

        
        case 1:
        {
          //Tollbooth t1;
          t1.payingCar();
          cout<<" Total cars: "<<t1.getpay()<<endl;
          break;

        }
        case 2:
        {
           

            t1.nonpayingcars();
            cout<<"no. of cars without paying..."<<t1.getnopay()<<endl;

            break;
        }
        case 3:
        {
            //Tollbooth t1;
            t1.printOnConsole();
            
            break;
        }
            default:
            cout <<"Wrong choice...."<<endl;
            break;
     }
    return 0;
}