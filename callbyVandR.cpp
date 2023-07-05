#include<iostream>
using namespace std;
void fun ( int *p , int * q)
{
    *p = 20;
	*q = 30;
}

void fun2 ( int a , int b)
{
    a = 40;
	b = 50;
}

int main (){

 int s, r;
 s=2;
 r=3;
//  fun( &s,&r);
fun2( s,r);
cout<< s << " "<< r << "\n";

}