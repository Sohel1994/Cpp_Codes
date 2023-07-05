#include<iostream>
using namespace std;

class base
{
    public:
    int amount;
    virtual void withdraw (int a)
    {
       amount = a+100;
       cout <<" i am base class amount to withdraw "<< amount<<"\n";   
    }
    
    virtual ~base()
    {
        cout<<" I am base class destructor"<<"\n";
    }

};

class derived : public base
{
    public:
    virtual void withdraw (int a)
    {
       amount = a+200;
       cout <<" i am derived class amount to withdraw "<< amount<<"\n";   
    }
    
    virtual ~derived()
    {
        cout<<" I am derived class destructor"<<"\n";
    }

};

int main()
{
   base a;
   base &ref = a;
   ref.withdraw(1000); // base:: withdraw(int a);

   derived d;
   base &ref1 = d;
   ref1.withdraw(2000);//derived::withdraw(int a)

}