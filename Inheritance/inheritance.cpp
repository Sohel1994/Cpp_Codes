#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class base
{
     int i;
     void funPrivet()
     {
         cout<<" privet fun of base class "  << "\n";

     }
     public:
     base() =default;
     ~base() = default;
     void fun()
     {
        cout << " base class fun()" << "\n";
     }

};

class derived : private base
{
     int j ;
     public :
     derived(): base(),j{0}
     {
        cout << "derived class constructor" <<"\n";
     } 
     ~derived() = default;
    
     void funDeriv()
     {
          fun();
          cout << "funDerived() "<<"\n";
     }

};

int main ()
{
        derived d;
        d.funDeriv();
      //  d.fun();// due to privet access spcifirer base class inheritated so   
                  // this fun() from base becomes privet to derived and only access by member function of derived.

}
