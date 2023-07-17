#include<iostream>
using namespace std;

template<class T , class Q >
class arithmatic{
     
     Q a;
     T b;

     public:
     arithmatic()
     {
        a = 0;
        b = 0;
        cout<< "normal constructor called \n";
     }
     arithmatic( Q p , T q); // parameterizedf constructor
     bool display( Q r , T s) ;
         
};

template<class T , class Q>
arithmatic < T, Q> :: arithmatic( Q p , T q)
{
         
          a = p;
          b = q;

}

template<class T , class Q>
bool arithmatic <T , Q>::display( Q r , T s)
{         
        
          if( a != r && b != s)
          return false;
          else 
          return true;
}

int main()
{
    // arithmatic<int , float> a(6,7.8);
     bool s;
     arithmatic <int , float> a;
     arithmatic <int , float> b( 7 , 50.65);
     s = b.display (7,50.65);
     cout << s ;
     
     
}