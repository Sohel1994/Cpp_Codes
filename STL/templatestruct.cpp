#include<iostream>
using namespace std;

template <typename T>
T minfun( T a , T b)
{
    
    return a<b ? a : b ; 
}

template< typename t1 , typename t2 >
void func( t1 a , t2 b)
{

  cout << a  << " " << b << "\n"; // a and b are person struct which is user defined so we need to 
                                  // operator overloding for ostream.
}
struct person 
{
     
      int age;
      string name;
      bool operator<( person &rhs) // operator overloading for compare age through template
      {
        return this->age<rhs.age;
      }  

};
ostream &operator<<(ostream &os ,const person &p) // oserator overloadin for struct person name.
{
    os << p.name;
    return os;
 }

int main()
{
      person p1 { 28 , "sohel"}; // init the structure parameter.
      person p2 { 30 , "suraj"}; 

      person p3 = minfun(p1, p2);

      cout << p3.name << " is younger"<<"\n";
     
      func( p1 , p2); 

}
