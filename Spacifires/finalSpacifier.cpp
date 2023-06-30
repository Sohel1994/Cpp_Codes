#include<iostream>
using namespace std;

class A final // final spacifire: we can not form derived class from this class
{
  
   public:
   virtual void fun()
   {
     cout<<" I am class A fun()"<<"\n";
   }

   virtual ~A()
   {
     cout<<" I am class A destructor"<<"\n";
   }

};

class B 
{
   public:
   virtual void fun1() final // function can not be override in derived class
   {
     cout<<" I am class B fun1()"<<"\n";
   }

   virtual void fun2()
   {
     cout<<" I am class B fun2()"<<"\n";
   }

  virtual ~B()
   {
     cout<<" I am class A destructor"<<"\n";
   }

};

class C:public B 
{
   public:
   virtual void fun1() // function can not be override in derived class
   {
     cout<<" I am class C fun1()"<<"\n";
   }
    
   virtual void fun2() // function can not be override in derived class
   {
     cout<<" I am class C fun2()"<<"\n";
   }
  virtual ~C()
   {
     cout<<" I am class A destructor"<<"\n";
   }

};

int main()
{
  A *a = new A();
  a->fun();

  B *b = new B();
  b->fun1();

  b=new C();
  b->fun2();

}