/* stateful lambda expresion is passing capture list to lambda expresion 
which where cpture list can not be modified because it is impelemeted
copy constructor and operator () const overloading calling on expresion. 
*/

/*syntax lambda expresion */

//auto l = [ y /* coustructor called */] ( int x /*operator () const called */ ) { cout << x + y; }

// Implemetation of stateful lambda behind the seen
/*class lambda 
{
     private:
     int y ;  // 
     public:
     lambda( int y ): y{y} // for capture list pramterized constructor called
     {

     }
     lambda (const lambda &l )  // if capture list contain object then copy constructor called
     {
        this->y = l.y;
     }
     void operator()( int x) const
     {
         std::cout << x + y ; // y can not be changed due const function 
     }
}; */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gY = 1000;

void test1()
{
   cout << "\n ================ test 1 =================== \n";
   int lX = 100;

   // capture list parameter call by value
   auto l = [lX /* capture list*/] (){ 
                   cout << lX <<"\n"
                        << gY << "\n";
                  };

    l(); // calling  lambda expression operator fucntion called invoke
}

void test2()
{
   cout << "\n ================ test 2 =================== \n";
   int x = 100;
   
   // capture list parameter call by value to change it use mutable keyword 
   // note l is an object which initilized only once for by constructor 
   // l();  is  operator()()const{  }; called 

   auto l = [x /* capture list*/]() mutable { 
                    x+= 110;
                   cout <<" x :" << x <<"\n";
                  };
    l(); // x = 210 by lambda expression call

    cout << " Affected value by lambda expression  x : " << x << "\n";

    cout << "\n";

    l() ; // 320  // due to operator()()const { }; called again
    
    cout << " Affected value by lambda expression  x : " << x << "\n";

}

void test3()
{
   cout << "\n ================ test 3 =================== \n";
   int x = 100;

   // call by reference will affect the actual variable due to lambda operation
   auto l = [ &x /* capture list*/]() mutable { 
                                               x+= 110;
                                               cout <<" x :" << x <<"\n";
                                              };
    l(); // x = 210 by lambda expression call

    cout << " Affected value by lambda expression  x : " << x << "\n";

}

void test4 ( )
{

   cout << "\n ================ test 4 =================== \n";
   int x = 100;
   int y = 200;

   // call by value default [=] will not affect actual varible by lambda
   auto l = [=/* use = default capture by value*/]() mutable { 
                                               x+= 110;
                                               y+= 220;
                                               cout <<" x :" << x <<"\n";
                                               cout <<" y :" << y <<"\n";
                                              };
    l();
    cout << "\n";

    cout <<" x :" << x <<"\n"; // 100
    cout <<" y :" << y <<"\n"; // 200

}

void test5( )
{

   cout << "\n ================ test 5 =================== \n";
   int x = 100;
   int y = 200;

   // call by reference default [&] will affect the actual variable due to lambda operation
   auto l = [&/* use & default capture by reference*/]() mutable { 
                                               x+= 110;
                                               y+= 220;
                                               cout <<" x :" << x <<"\n";
                                               cout <<" y :" << y <<"\n";
                                              };
    l();
    cout << "\n";

    cout <<" x :" << x <<"\n"; // 210
    cout <<" y :" << y <<"\n"; // 420

}

void test6( )
{

   cout << "\n ================ test 6 =================== \n";
   int x = 100;
   int y = 200;
   int z = 300;

   auto l = [=,&y]() mutable { 
                                 x+= 110;
                                 y+= 220;
                                 z+= 330;
                                 cout <<" x :" << x <<"\n";
                                 cout <<" y :" << y <<"\n";
                                 cout <<" z :" << z <<"\n"; 
                                };
    l();
    cout << "\n";

    cout <<" x :" << x <<"\n"; 
    cout <<" y :" << y <<"\n"; 
    cout <<" z :" << z <<"\n";
    
    
}

void test7( )
{

   cout << "\n ================ test 7 =================== \n";
   int x = 100;
   int y = 200;
   int z = 300;

   auto l = [&,y]() mutable { 
                                 x+= 110;
                                 y+= 220;
                                 z+= 330;
                                 cout <<" x :" << x <<"\n";
                                 cout <<" y :" << y <<"\n";
                                 cout <<" z :" << z <<"\n"; 
                                };
    l(); // lambda call
    cout << "\n";

    cout <<" x :" << x <<"\n"; 
    cout <<" y :" << y <<"\n"; 
    cout <<" z :" << z <<"\n";
    
    
}
int main()
{
     test1(); //  capture list parameter call by value  

     test2(); //  capture list variable call by value and changed by mutable keyword 
              //  will not affect actual variable due to call by value 

     test3(); //  call by reference will affect actual varible 

     test4(); //  l = [=]()mutable { };  in capture list use = for default capture by value

     test5(); //  l = [&]()mutable { };  in capture list use & for default capture by value

     test6(); //  try capture list default by value only excepts 1 reference [=,&y]

     test7(); //  try capture list default by reference only excepts 1 by value [&,y]

}