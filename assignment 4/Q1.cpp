#include <iostream>
using namespace std;

class Time
{
    int Hrs;
    int min;
    int sec;
public:
    Time()
    {
        Hrs=0;
        min =0;
        sec = 0;
    }
    Time(int h,int m,int s)
    {
        Hrs=h;
        min=m;
        sec =s;
    }
    void setHour(int p)
    {
         Hrs = p;
    }
    void setMinute(int q)
    {
        min = q;
    }
    void setSeconds(int r)
    {
        sec =r;
    }
    int getHour()
    {
        return Hrs;
    }
    int getMinute()
    {
        return min;
    }
    int getSec()
    {
        return sec;
    }
    void accept()
    {
        cout<<"Enter hrs : min : sec  "<<endl;
        cin >>Hrs >> min >> sec;
    }
    void display()
    {
        cout<<"Time:"<<Hrs<<":"<<min<<":"<<sec<<endl;
    }

};


int main()
{ 
    Time **ptr =new Time*[5];
    ptr[0]= new Time(10,30,03);
    ptr[1]= new Time(11,40,23);
    ptr[2]= new Time(13,31,53);

     for (int i=0;i<3;i++)
      ptr[i] ->display();

      for (int i=0;i<3;i++)
      {
        cout<<"Time"<<ptr[i]->getHour()<<":"<<ptr[i]->getMinute()<<":"<<ptr[i]->getSec()<<endl;
      }

      for(int i=0;i<3;i++)
      {
        int w,x,y;
         cout<<"Enter hrs : min : sec  "<<endl;
        cin >>w >> x >> y;
        ptr[i]->setHour(w);
        ptr[i]->setMinute(y);
        ptr[i]->setSeconds(w);
        ptr[i]->display();
      }

    for (int i = 0; i < 5; i++)
        {
            delete ptr[i];
            ptr[i] = NULL;
        }

    return 0;
}