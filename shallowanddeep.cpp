#include<iostream>
using namespace std;

/*====================================================================================*/
//  when there is no copy constructor then compiler will call defaualt copy constuctor 
//  implicitly that is way memory allocation on heap is pointing by the both the object
//  is same this is called shallow copy
/*====================================================================================*/
class cpy
{
    int a , *p;
    public : 
    explicit cpy()
    {
       p = new int ;
    }

    void fun ( int i , int j )
    {
        a = i;
        *p = j;
    }

    void show ()
    {

        cout << a <<"\n"<< *p <<"\n";
    }
    
    
    cpy ( cpy &c)
    {
       a = c.a;
       p = new int;
       *p = *(c.p);
    }

    ~cpy()
    {
       delete p;
    }

};

int main ()
{
   cpy c;
   c.fun(10,20);
   c.show();
   cout<< " ========================="<<"\n";
   cpy d = c;
   cout<< " after copy object "<<"\n";
   d.show();
   d.fun(30,40);
   cout<< " after fun() function called "<<"\n";
   d.show();
   cout<< "============================="<<"\n";
   c.show();
   cout<< "============================="<<"\n";
   cpy e(d);
   e.show();
   e.fun(70, 100);

   cout<< "===============++++=============="<<"\n";
   e.show();
   d.show();
   c.show();
}