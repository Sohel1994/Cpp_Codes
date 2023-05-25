# include<iostream>
using namespace std;

class base 
{
    public :
    virtual void fun () const
    {
        cout<<" i am the base class fun ();"<< "\n";
    }
   
    virtual ~base()
    {
        cout<<" i am base class destructor"<<"\n";
    }

};

class derived:public base 
{
    public :
    virtual void fun () override //virtual void fun () override //Overriding function but having diff signature const in base class function fun()const 
                                 //error
    {
        cout<<" i am the derived class fun ();"<< "\n";
    }
   
    virtual ~derived()
    {
        cout<<" i am derived class destructor"<<"\n";
    }

};

int main()
{
  
  base *B = new base();
  B->fun();
  
  base *B1 = new derived();
  B1->fun(); // it is also called base fun because of signature prototype dosen't match.
             // so dynamic binding happen.

}