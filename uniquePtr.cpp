#include<iostream>
#include<memory> // for smart pointer initialization
using namespace std;

//===========================================================================//
//                         unique_ptr                                        //
// Syntax-> unique_ptr <T> poiter_variable;                                  //
// Smart pointers deallocates the memory automatically when the object is no //
// longer in use.                                                            //
// Airthmatic operations are not possible on unique pointers.                //
// They can not be copy                                                      //
//===========================================================================//


class account
{ 
    protected:
    int amount;
    public:
    account(int a): amount{a}
    {
       cout<<" i am account class constructor "<< amount << "\n"; 
    }

    virtual void display()
    {
        
        cout<<" the amount is "<< amount <<"\n";
    
    }

    virtual ~account()
    {
        cout<<"i am account type destructor"<<"\n";
    }

};


class test: public account
{
    int deposit;
    public:
    test(int a) : account(0),deposit(a)
    {
       cout<<" i am test class constructor "<< deposit << "\n"; 
    }
    virtual void display() override
    {
        cout<<" the amount is "<< amount<<"\n";
        cout<<" the deposit is "<< deposit + 1909<<"\n";
    
    }

    virtual ~test()
    {
        cout<<"i am test type destructor"<<"\n";
    }

};

int main()
{ 
     
    //   //raw pointer initilizartion 
    //   account *raw = new account(440);
    //   raw->display();  // destructor never called in this situation
    //   delete raw;      // we need to delete raw pointer to destructor to be called 
    //                    // or dealocate the memory 


    //   //pointer initialization with account class unique_ptr 
    //   std::unique_ptr <account> ptr {new account{100}};
    //   ptr->display();

    //   //allocating 10 intgers on heap pointing by unique_ptr.
    //   std::unique_ptr <int[]> ptr1 {new int [10]};
    //   ptr1[1] = 3000;
    //   cout<< ptr1[1]<<"\n";

    //   //make_unique ptr initialization no need of new 
    //   unique_ptr <account> ptr3 = make_unique<account>(420);
    //   ptr3->display();
    //   // or let compiler decide to deduce the typo by auto keyword
    //   auto ptr4 = make_unique<account>(800);
    //   ptr4->display();

    //   //move the owner ship of the unique pointer

    //   unique_ptr <account> ptr5;
    //   // ptr5 = ptr4; // not possible
    //   // copy contructor of unique pointers not possible.
    //   // unique_ptr <account> ptr5 = ptr4; // not possible
    //   // unique_ptr <account> ptr5 (ptr4);  // not possible 
      
    //   if(!ptr4)
    //   cout<< " ==== ptr4 is null pointer ======" << "\n";

      // inheritance with base class unique pointer ponting to derived 
      unique_ptr<account> ptr7 { new test(3000)};
      unique_ptr<account> ptr8 = make_unique<test>(1000); 
      ptr7->display();
      cout<<"========================="<<"\n";
      ptr8->display();



}