#include<iostream>
using namespace std;

template <typename T>
class myinfo
{

    T a;
    public:
    myinfo(T b) : a{b}
    {
        cout<< " the myinfo constructor called"<<"\n";         
    }

    void display ()
    {
         cout << a << "\n";
    }

};

template<class Q , class S>
Q* fun( Q*a , S *b)
{
   
    *a = *a + *b ;
    return a;

}

int main ()
{
    // myinfo<int > t(20);
    // t.display();
    // myinfo<char> c('b');
    // c.display();
    // myinfo <string> q("sohel");
    // q.display();
    
     int a = 6 ;
     float b = 8;

     int *p;

     p = fun<int,float>(&a,&b);
     cout << *p;
}
