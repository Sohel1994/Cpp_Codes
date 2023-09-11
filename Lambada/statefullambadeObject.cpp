#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

class person
{
    int age;
    string name;
    public:
    person() = default;
    person(string name , int age) : age{age} ,name{name} // parametrized constructor 
    {
    
    }
     
    person( const person &p)= default;  // parameterized copy constructor

    string get_name() const 
    {
       return this->name;         
    }
    void set_name( string name )
    {
         this->name =name;
    }
    int get_age() const
    {
        return this->age;
    }
  
    void set_age( int age)
    {
       this->age = age;
    }

    friend ostream & operator <<( ostream &os , const person &p);

    //lambda functions as member function
    //1) this pointer as capture list of person object to change by lambda function
    auto class_person1() { return [this] (string newName , int newAge ){ name = newName;
                                                                        age = newAge;};};
    //2) [=] default pass by value 
    auto class_person2() { return [=] (string newName, int newAge) { name = newName;
                                                                     age = newAge;};};
    
    //3) [&] default pass by reference 
    auto class_person3() { return [&] (string newName, int newAge) { name = newName;
                                                                     age = newAge;};};
 
};

ostream & operator <<( ostream &os , const person &p)
{
    os<< p.name << " " << p.age << "\n";
    return os; 
}

class People
{
    vector<person> people; // vector person
    int maxPeople; // max people in vector
    public:
    People(int max = 10 ): maxPeople{max} //default vector maxpeople intialize with 10;
    {

    };
    People(const People &p) = default; //defualt copy constructor
    void addPeople( string name, int age) // add person in people vector 
    {
        people.emplace_back(name,age);
    } 

    void setMax(int max) // set max no of person in people vector
    {
        this->maxPeople = max;
    }

    int getMax()const   // get max no of person in people vector
    {
        return this->maxPeople;
    }

    // this method returns vector<person> by user input age having above that of person && max_people requried.
    // using lambde capture by value and reference here 
    // used copy_if algorithm 
    // feeling vector<person> result with vector<person> people by condition  > age && maxPeople into it. 
    vector<person> getPeople( int maxAge)
    {
          vector<person> result;
          int count = 0;
          copy_if(people.begin(),people.end(), back_inserter(result),[this,&count,maxAge](person &p)
                                                                      {return p.get_age()>maxAge && ++count <= this->maxPeople;});
          return result;
    }

};


void test1()
{
    cout << "\n====================== Test1() ========================\n";

    person p("sohel",29);
    cout << p << "\n";
    auto lamPerson = p.class_person1(); //lambda person calling with argument mostaly used;
    lamPerson("hilal",30);
    cout << p <<"\n";

    auto l2 = p.class_person2(); // lambda person calling by default [=] capture list not used mostaly
    l2("allauddin",57);
    cout << p << "\n"; 
    
    auto l3 = p.class_person3(); // lambda person calling by default[&] capture list minimum used
    l3("suraj",30);
    cout << p << "\n"; 
}

class lambda{
  int y;
  public:
  lambda( int y) :y{y} // capture list initilizetion of object
  { 
     cout << " lambda constructor : " << y << " \n";
  };
  void operator()(int x)const  // lambda call
  {
      cout << x-y << "\n";
  }

};

void test2()
{
    cout << "\n====================== Test1() lambda impelementation ========================\n";

    int y = 100;
    lambda l(y); // initilization of object 
    l(2000); //  function call() operator call

     cout << "\n====================== lambda value ===================\n";

     auto l2 = [y](int x )mutable{y = x+y;
                            cout << y << "\n" ;};
     l2(3000);
     cout << y << "\n";

     cout <<"======================== lambda capture list by & ==========\n";
     // capture list pass by reference 
     auto l3 = [&y](int x )mutable{ y = x+y;
                                          cout << y << "\n" ;};

     l3(1000);
     cout << y << "\n";

}

void test3()
{
      
       cout <<"======================== lambda function on person object ==========\n";
       People friends;  // this will invoked People counstructor with maxpeople 10;
       friends.addPeople("sohel",28);
       friends.addPeople("suraj",29);
       friends.addPeople("shireen",30);
       friends.addPeople("allauddin",60);
       friends.addPeople("parvin",54);
       friends.addPeople("ebrahim",65);

       auto result = friends.getPeople(21); // this gives result person vector whose age is greater than 21 by lambda function 

       cout << "\n";
       for (const auto &p : result)
       cout<< p << "\n";

       friends.setMax(3); // setting max peopel required only 3
       result = friends.getPeople(21);
       cout << "\n";
       for (const auto &p : result)
       cout<< p << "\n";


}


int main ()
{
    //   person p;
    //   p.set_name("sohel");
    //   p.set_age(28);
    //   cout << p << "\n";

    //   person s("suraj",29);

    //   auto l = [s](string newName , int newAge ){ newName =  s.get_name();
    //                                               cout<< newName <<" ";                    
    //                                               newAge= s.get_age();
    //                                               cout<<newAge ;};
    //  l("\0",0); // lambda call 
 
    //  test1(); // lambda function calling by [this] ,[=] and [&] capture list

    //  test2(); // lambda function internal implementation test


     test3(); //  lambda for object of vector 

}