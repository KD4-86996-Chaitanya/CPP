#include<iostream>
using namespace std;
class stack
{
    int size;
    int *ptr;
    int top;
public:

    stack(int size=5)
    {
        this->size=size;
        top=-1;
        ptr=new int[size];
    }
    void push(int value)
    {
        if(isFull())
        {
            cout<<"stack is full.....";
        }
        else
        ptr[++top] = value;
      
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"stack is empty"<<endl;
        }
        else
            ptr[top--];
            cout<<"one element is deleted"<<endl;

    }
    void peek()
    {
      if(isEmpty())
        {
            cout<<"stack is empty"<<endl;
        }
        else
            cout<<"peek:"<<ptr[top]<<endl;
  
    } 
    bool isEmpty()
    {
        return top==-1;
    }
    bool isFull()
    {
        return top==size-1;
    }
    void print()
    {
        if (isEmpty()) 
        {
            cout << "stack is empty" << endl;
        } else 
        {
            for (int i = 0; i <= top; i++) 
            {
                cout << ptr[i] << " ";
            }
            cout << endl;
        }
    }
     ~stack() 
     { 
        delete[] ptr;
     }
};
int main()
{
    stack s1;
    s1.push(12);
    s1.push(22);
    s1.push(33);
    s1.push(45);
    s1.push(58);
    s1.print();
    s1.peek();
    s1.pop();
    s1.print();
    s1.peek();
    s1.pop();
    s1.pop();
    s1.print();
    s1.pop();
    s1.pop();
    s1.print();
    s1.peek();
}