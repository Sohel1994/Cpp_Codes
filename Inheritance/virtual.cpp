#include<iostream>
using namespace std;

class base {
     public:
     virtual void fun()
       {
        cout <<" I am base class function"<<"\n";
       }
    virtual ~base()
    {
        cout<<" i am base class destructor"<<"\n";
    }
};

class derived : public base{
    public:
    void fun ()
    {
        cout<<" I am derived class fun "<<"\n";
    }

    ~derived()
    {
        cout<<" i am derived class destructor"<<"\n";
    }
};

class test : public base{
    public:
    void fun ()
    {
        cout<<" I am test class fun "<<"\n";
    }

    ~test()
    {
        cout<<" i am test class destructor"<<"\n";
    }
};


int main ()
{
    
    base *p= new derived();
    p->fun();

    base *p1= new test();
    p1->fun();

    /*we can below use instead of above line of code for testing*/

    base *p3;
    derived d1;
    p3 = &d1;
    p3->fun();

    base *p4;
    test t1;
    p4 = &t1;
    p4->fun();
   
    /* deleting base class pointers which are pointing to derived class objects*/
   
    cout<<" deleting pointer "<<"\n";
    delete p;
    delete p1;
    delete p3;

}