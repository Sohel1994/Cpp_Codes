#include<iostream>
using namespace std;

int calculate( int , int );

int main()
{
    int result , num1 , num2 ;
    cout<<" Enter the 2 no's for division" <<"\n";
    cin>> num1;
    cin>> num2;

    try{ 
         
       result = calculate ( num1, num2);
       cout << " the division is "<<result<<"\n";  

    }

    // catch(int &ex ) 
    // { 
    //     cerr << " The arithmatic calculation is wrongly done"<<"\n";
    // }
    // catch(string &negtive)  // for, if values are negative.
    // { 
    //     cerr << negtive <<"\n";
    // }
    catch(...) // this will handle any kind of exception as we can say multiple type.
    {
        cerr<< "wrong values entered" << "\n";
    }
    cout<<" Bye "<< "\n";
}

int calculate( int a, int b)
{
    if (b == 0)
    throw 0;
    if( a < 0 || b < 0)
    throw string { " the values entered are negative"};
    return a/b;
}