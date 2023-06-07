#include<iostream>
#include<memory>
using namespace std;

/*We can create our own user defined exception class.
  Here illegalBalanceException sub class derived from 
  std::exception base class  
  overriding what() virtual function from std::exception base class */

class illegalBalanceException :public std::exception                                                    
{
    public:
    illegalBalanceException() noexcept = default;
    ~illegalBalanceException() = default;
    virtual  const char* what() noexcept // noexcept kyeword tells compiler that this method will not throw exception.
    {
        return "illegal balance exception, the obeject will not create due to negative amount initilization";
    }

};

class Account
{
    protected:
    int amount;
    public:
    Account(int a) :amount{a}
    {
        cout<<" the amount is initilize in constructor :" << amount<<"\n";
        if(amount<0)
        throw illegalBalanceException(); // object of the illegalBalanceException class.
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
    try 

    {
     unique_ptr <Account> a = make_unique<Test> (-100);
     cout << " Test object created on heap pointing by Account class unique pointer";
    }

    catch(illegalBalanceException &ex)
    {
           cout<< ex.what() << "\n";
    }

}