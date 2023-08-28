#include<iostream>
#include<vector>
# define PI 3.14
using namespace std;

struct squre
{   
      
       int i;
       squre (int a) : i{a}
       {

       } 
       void operator()( int x) // function call operator overloading
       {
             cout << i * x << "\n";

       }

};

template<class T>
class circle
{
    T c;
    public:
    circle( T a):c(a)
    {
          cout << " circle c : " << c<<"\n";
    }
    void operator()(T i )
    {
        cout << " the redius of the circle : "<< PI * i ;
    }

};
int main()
{
     squre s(3); // parameterized calll
     s(10); // s.operator()(10) calling

     circle <int> cr(5); // parameterized constructor call
     cr(20); // cr.operator()(20) function call() operator overloading
}