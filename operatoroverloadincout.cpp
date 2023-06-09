#include<iostream>
using namespace std;

// operator overloding insertion (<<) and extraction (>>) operator
// cin is a object of istream class and cout is a object of ostream class.
// classes are defined in iostream std lib.
class A 
{
    int mm, dd, yy;
    public:
    A( int m, int d, int y):mm{m},dd{d},yy{y}
    {
        cout << " i am parameterized constructor"<<"\n";
    }

    friend ostream &operator<<( ostream &os , A &a);
    friend istream &operator>>( istream &os , A &a);
};
    ostream &operator<<( ostream &os , A &a)
    {
       os<<" date :"<< a.mm<<" "<<a.dd<<" "<<a.yy<<" "<<"\n";
       return os;
    }
    istream &operator>>( istream &os , A &a)
    {
        os>> a.dd>>a.mm>>a.yy;
    }


int main()
{
  A a(12,12,12);
  cin>>a;
  cout << " =============================== "<<"\n";
  cout<<a;
}