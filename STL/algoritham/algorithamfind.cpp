#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

class person
{
     int age ;
     string name ;
     public:
     person () 
     {
        cout<< " i am default constructor"<<"\n";
     }
     person ( int a , string n): name{n} ,age{a}
     {
        cout<< " i am parameterized constructor "<<"\n";
     }
     
     bool operator==( const person &rhs) const // operator overloading for to find two objects are equal
     {
          if((this->age)==rhs.age &&  (this->name)==rhs.name)
           return true;
     }
};

int main()
{
    // person p { 28 , "sohel"};
    // person q {  28 , "sohel"};
    // person t { 28 , "sohel"};

    // if(p==q)
    // cout<< " both are equal "<<"\n";
    // if(p==t)
    // cout<< " both are equal 1"<<"\n";
    
    list<person> s  = { { 30 , "sohel"},
                        { 29 , "suraj"},
                        { 44 , "allauddin"},
                        { 43 , "parvin"} };
    
    list <person> ::iterator it;

    it = find(s.begin() , s.end() , person{44,"allauddin"}); //need overload (==)operator to find the match in list.
    if(it!=s.end())
    {
        cout << " found the person in the list\n" ;
    }

    
}