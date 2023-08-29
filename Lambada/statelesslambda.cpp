#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

class person
{
       string name;
       int age;
       public:
       person() = default ;
       person( string n, int a): name(n),age(a)
       {

       }
       person(const person &p) : name{p.name},age{p.age} // copy constructor
       {

       }
       ~person() = default;
       string getName()const
       {
         return this->name;
       }
       void setName( string name)
       {
         this->name = name;
       }
    
       int getAge()const
       {
         return this->age;
       }
       
       void setAge( int a)
       {
          this->age = a;
       }

     friend ostream & operator << ( ostream &os , person &p);

};

ostream &operator << ( ostream &os , person &p)
{
   os<< p.name << ":" << p.age;
   return os;  
}

void test1()
{
    [](){ cout << " hi" << "\n";}();
    [](int x) { cout << " x : " << x << "\n";}(100);
    [](int x , int y) { cout << " sum is : " << x+y;}(200,300);

}
void test2()
{
    auto l = [](){ cout << " hi" << "\n";};
    l();
    
  
    auto l2 = []( int x , int y ) { cout << " addition is : " << x+y <<"\n";};
    l2(5,10);

    int num1 = 100;
    int num2 = 200;
    auto l3 = []( int &x /* will affect original passed value*/, int y)
                { cout << " x:" << x <<" y:"<<y << "\n";
                  x = 1000;
                  y = 2000;};

    l3(num1, num2); // lambde call
    cout<<" num1:"<<num1<<" num2:"<< num2 <<"\n";
}

void test3()
{
      person per( "sohel" , 28);

      auto l = [] (person p) {
        cout<< p << "\n";
      };
      l(per); // sohel:28

      auto l1= []( person &p)
      {
          cout<<p<<"\n"; 
      };
      l1(per); // sohel:28

      //can change actual parameter value of person per
      auto l3= []( person &p)   
      {
          cout<<p<<"\n";
          p.setAge(30); // seting
      };
      l3(per);

      cout << per << "\n"; // sohel : 30
}

// test4 for predicte lambda  
void fun_filter ( vector<int> &v , 
                  function<bool(int)>func)//#include<functional>
                                          //predicate lambda fuction return bool taking int value
{
   cout<<"[";
   for(auto i : v)
   {
       if(func(i))
       cout<< i << " ";
   }
   cout<< " ]" <<"\n";
}

void test4() // predicate lambda function
{
    vector<int> v { 10,20,30,40,50,60,70,80,90,100};

    fun_filter(v ,[](int x){return x>50;}/* argument for function<bool(int)> */); //predicte lambda function
    
    fun_filter(v ,[](int x){return x<50;}/* argument for function<bool(int)> */); //predicte lambda function

 
}

auto make_lambda() // test5
{
   return[](){ cout << " i am returning lambda expresion  \n";};
}

void test6()
{
     auto i = []( auto x, auto y){ cout << "x:"<<x<<" y:" << y <<"\n";};

     i(5,10);//// x:5 y:10
     i(6.8,9.8); //x:6.8 y:9.8
     i(person("sohel",28) ,person("suraj",30));// x:sohel:28  y:suraj:30
}




int main ()
{
   
   cout << "\n============ test1 ============\n";
   test1();

   cout << "\n============ test2 ============\n";
   test2();

   cout << "\n============ test3 ============\n";
   test3();

   cout << "\n============ test4 ============\n";
   test4(); // predicat lambda function test

 cout << "\n============ test5 ============\n";
 auto a  = make_lambda();
 a(); 

   cout << "\n============ test6 ============\n";
   test6(); // auto let compiler decided the parameter

   cout << "\n============ test 7============\n";
   vector<person> stooges { {"sohel" ,28 },
                            {"suraj" ,30 },
                            {"shireen",26 }};

   // sorting vector by age using lambda expression
   sort(stooges.begin(),stooges.end(),[](person &p1, person &p2)
                                        {
                                          return p1.getAge() < p2.getAge();
                                        });
  
    // display the sorted vector
    for_each(stooges.begin(),stooges.end(),[](person &p1)
                                              {
                                                 cout<<p1 << " ";
                                              });
 
} 

