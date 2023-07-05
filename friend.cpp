#include<iostream>
using namespace std;
class A
{
    int n;
	public:
	A()
   	{  n = 10;
	   cout<<" class A constructor called"<<"\n";
	}
    friend int fun ( A );
};

int fun (A a)
{
    return a.n += 10; 
}

int main ()
{
   A b;
   cout << " friend function called " << fun(b)<< "\n";
}