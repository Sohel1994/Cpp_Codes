#include<iostream>
using namespace std;

class complex{

  int r , i;
  public:
  complex( int a , int b):r{a},i{b}
  { 
     cout<<" this is initilization of memebers "<< r << " and " << i << " by parmeterized constructor"<<"\n";
  }
  complex ( )
  {
    cout<<"default constructor called"<<"\n";
  }
  complex& operator +(complex c)
  {
   //   complex t;
	//  t.i = i + c.i;
	//  t.r = r + c.r;
	//  return t;
   this->i = this->i + c.i;
   this->r = this->r + c.r;
   return *this;
  }
  
  void display()
  {
     cout<< r << "+" << i << "i" << "\n"; 
  }
};

int main (){
 
 complex a( 3 , 4 );
 complex b( 5 , 7 );
 complex c;
 c=a+b; // a.add(b) which return the obejct of complex class.
 c.display();
}