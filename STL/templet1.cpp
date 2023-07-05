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

int main ()
{
    myinfo<int > t(20);
    t.display();
    myinfo<char> c('b');
    c.display();
    myinfo <string> q("sohel");
    q.display();
}