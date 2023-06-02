#include<iostream>
#include<memory>
using namespace std;

////////////////////////////////////////////////////////////
//                     weak_ptr                           //
//  Syntax : weak_ptr<T> ptr ;                            //
//  Use to avoid memory leak by strong circular reference //
//  by shared_ptr on heap.                                //
////////////////////////////////////////////////////////////


class B;

class A 
{
   
   shared_ptr<B> b_ptr;
   public:
   void set_b( shared_ptr<B> &b) // this gives ref count of one while calling
   {
       b_ptr = b;
   }
   
   A()
   {
      cout<<" the class A constructor A()"<<"\n";
   }

    ~A()
   {
      cout<<" the class A  destructor ~A()"<<"\n";
   }

};

class B
{
   
   //shared_ptr<A> a_ptr;  
   weak_ptr<A> a_ptr; //  make weak_ptr to break that strong reference count. 
   public:
   void set_a( shared_ptr<A> &a) // this gives  strong circular reference count of one while calling.
   {
       a_ptr= a;
   }

    B()
   {
      cout<<" the class B constructor B()"<<"\n";
   }

    ~B()
   {
      cout<<" the class B  destructor ~B()"<<"\n";
   }

};

int main()
{

     shared_ptr<A> a = make_shared<A>();
     shared_ptr<B> b = make_shared<B>();
   // case 1 to work with weak_ptr
   // the below funtions call pointing to each other on heap by shared pointer strong circular referance.
   // so we are getting memory leak even a and b going out of scope
   // destructor gets never called.
     a->set_b(b);
     b->set_a(a);
}
