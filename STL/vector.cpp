#include<iostream>
// #include<vector>
// #include<algorithm>

#include <bits/stdc++.h>
using namespace std;

class A
{
     int a;
     string name;
     public:
     A()
     {
         a = 0;
         name = "sohel";
     }    
     A (int r , string n)
     {
        a = r;
        name = n;
     }
     friend ostream& operator<<(ostream& os, const A& b);
    //friend ostream& operator<<(ostream& os, const A*b);
};

ostream& operator<<(ostream& os, const A& b)
{
   os<< b.name << " "<< b.a << " ";
   return os;
}

// ostream& operator<<(ostream& os, const A* b)
// {
//    os<< b->name << " "<< b->a << " ";
//    return os;
// }

int main()
{

     vector<int> v = { 2 , 4 , 1 , 5 , 3 };

    //  sort( v.begin() , v.end());

    // //  for( int elmnt : v)
    // //  {
    // //     cout << elmnt << ",";
    // //  }
 
    // sort vector in assending order
    sort( v.begin() , v.end());
    vector<int> :: iterator i;
    for ( i = v.begin() ;  i != v.end() ; i++)
    {
        cout << *i<< ",";
    }

    cout<<"\n=============================\n";

    // reverse sort
    reverse( v.begin() , v.end());
    for ( i = v.begin() ;  i != v.end() ; i++)
    {
        cout << *i<< ",";
    }
   
    cout<<"\n=============================\n";

    // sum of vector elements is by accumulate.
    int sum;
    sum = accumulate(v.begin() , v.end() , 0); // 0 is init value of sum.

    cout << " sum of vector is :" << sum ;

    // vector<A>vec ;
    // vector<A*>vec1;
    // A a;
    // A *b =  new A( 3 , "suraj");
    // vec.push_back(a);
    // vec1.push_back(b);

    // for( auto i : vec)
    // {
    //     cout << i;
    // }

    //  for( auto i : vec1)
    //  {
    //     cout<< *i;
    //  }
}