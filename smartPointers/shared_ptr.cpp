#include<iostream>
#include<memory>
using namespace std;


//===========================================================================//
//                        shared pointer                                     //
// Syntax  shared_ptr<T> ptr;                                                //
// can be copy to the anothe ptr variable.                                   //
// ptr.use_count() gives the count of ptr sharing the same memory location   //
//===========================================================================//


class Account
{
    protected:
    int amount;
    public:
    Account(int a) :amount{a}
    {
        cout<<" the amount is initilize in constructor :" << amount<<"\n";
    }
    
    virtual void withdraw(int w)
    {
        cout<<" the withdraw amount is in account class :" << amount-w <<"\n";
    }
     
    virtual void deposite(int d)
    {
        cout<<" the withdraw amount is in account class :" << amount+d <<"\n"; 
    }
    
    virtual~ Account()
    {
        cout << " the Account class destructor called "<< "\n";  
    }
    
};

class Test:public Account
{
    public:
    Test(int a) : Account(a)
    {
        cout<<" the Test is initilize in constructor :" << amount<<"\n";
    }
    
    virtual void withdraw(int w) override
    {
        cout<<" the withdraw amount is in Test class :" << amount-w <<"\n";
    }
     
    virtual void deposite(int d) override
    {
        cout<<" the withdraw amount is in Test class :" << amount+d <<"\n"; 
    }
    
    virtual~ Test()
    {
        cout << " the Test class destructor called "<< "\n";  
    }
    
};

int main()
{
    // case 1
    //  Account *a = new Test(100);
    //  a->withdraw(5);
    //  delete a;

    // case 2
    // Account a(300);
    // a.deposite(5);

    // // shared_ptr case 1
    // shared_ptr<Account> s { new Account {100}};
    // cout<<" the count of shared ptr "<< s.use_count()<<"\n"; // count of shared pointer
    // s->deposite(10);

    // shared_ptr<Account> s1 = s;
    // cout<<" the count of shared ptr s "<< s.use_count()<<"\n";
    // cout<<" the count of shared ptr s1 "<< s1.use_count()<<"\n";

    // s.reset(); // making null
    // cout<<" the count of shared ptr s "<< s.use_count()<<"\n";
    // cout<<" the count of shared ptr s1 "<< s1.use_count()<<"\n";
   
    // shared_ptr<Account> s2 = move(s); // gives count 0 null ptr assigning
    // cout<<" the count of shared ptr s2 "<< s2.use_count()<<"\n";


    // // shared_ptr case 2
    //    shared_ptr<Account> s { new Test {200}};
    // cout<<" the count of shared ptr "<< s.use_count()<<"\n"; // count of shared pointer
    // s->deposite(10);

    // shared_ptr<Account> s1 = s;
    // cout<<" the count of shared ptr s "<< s.use_count()<<"\n";
    // cout<<" the count of shared ptr s1 "<< s1.use_count()<<"\n";

    // s.reset(); // making null
    // cout<<" the count of shared ptr s "<< s.use_count()<<"\n";
    // cout<<" the count of shared ptr s1 "<< s1.use_count()<<"\n";
   
    // shared_ptr<Account> s2 = move(s); // gives count 0 null ptr assigning
    // cout<<" the count of shared ptr s2 "<< s2.use_count()<<"\n";


    // shared_ptr case 3 make_shared
    shared_ptr<Account>s = make_shared<Test>(100);
    cout<<" the count of shared ptr "<< s.use_count()<<"\n"; // count of shared pointer
    s->deposite(10);

    shared_ptr<Account> s1 = s;
    cout<<" the count of shared ptr s "<< s.use_count()<<"\n";
    cout<<" the count of shared ptr s1 "<< s1.use_count()<<"\n";

    s.reset(); // making null
    cout<<" the count of shared ptr s "<< s.use_count()<<"\n";
    cout<<" the count of shared ptr s1 "<< s1.use_count()<<"\n";
   
    shared_ptr<Account> s2 = move(s); // gives count 0 null ptr assigning
    cout<<" the count of shared ptr s2 "<< s2.use_count()<<"\n";


}