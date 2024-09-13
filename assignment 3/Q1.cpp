#include <iostream>
using namespace std;

class Volume
{
    int length;
    int width;
    int height;
public:
   Volume()
   {
       length =5;
       width =6;
       height =7;
   }
   Volume(int n)
   { 
     length = n;
     width = n;
     height = n;
   }
   Volume(int x, int y, int z)
   {
      length = x;
      width = y;
      height =z;

   }
   void volumeof()
   {
     int val = length * width * height;
     cout<<" volume is : "<< val<< endl;
   
   }
};

int menu()
{
    int m;
    cout<<" For default value enter 1 "<<endl;
    cout<<" For default value enter 2 "<<endl;
    cout<<" For default value enter 3 "<<endl;
    cout<<" for Exit enter 0 "<<endl;
    cin>>m;
    return m;
}
int main()
{ 
    int choice;
    while((choice = menu()) != 0)
    {
        switch(choice)
        {
            case 1:
            {
             Volume v1;

             v1.volumeof();
             break;
            }
            case 2:
            {
             int p;
             cout<<"Enter the single value:  "<<endl;
             cin>>p;
             Volume v1(p);
             v1.volumeof();
             break;
            }
            case 3:
            {
             int v,w,l;
             cout<<"Enter three values : "<<endl;
             cin>>v >> w >> l;
             Volume v1(v,w,l);
             v1.volumeof();
             break;
            }
            default:
              cout<<" Wromg number...."<<endl;
              break;
        }
    }

    return 0;
}
