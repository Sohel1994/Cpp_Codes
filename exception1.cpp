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

    catch(int &ex )
    { 
        cerr << " The arithmatic calculation is wrongly done"<<"\n";
    }
    cout<<" Bye "<< "\n";
}

int calculate( int a, int b)
{
    if (b == 0)
    throw 0;
    return a/b;
}