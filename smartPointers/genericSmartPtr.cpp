#include<iostream>
using namespace std;

// This programm implementation of generic smart pointer.

class person
{

   int age;
   string name;
   public:
   person(): age{0},name{NULL}
   {
     cout << " default constructor of person "<<"\n";
   } 
   person(int a , string str): age{a},name{str}
   {
    cout << "parameterized constructor called of person"<<"\n";
   }

   ~person()
   {
    cout<< " destructor of person is invoked"<<"\n";
   }

   void display()
   {
     cout << " age of persone:"<< age << " name of person :"<< name << "\n";
   }

};
template<class T> 
class smartPtr 
{
   T *ptr;
   public:
   smartPtr(T* p = NULL)
   {
      ptr = p;
   }

//    smartPtr( smartPtr &c ) // deep copy constructor 
//    {
//        ptr = new T;
//        *ptr = *(c.ptr);
//    }
   ~smartPtr()
   {
     cout<<" destructor gets called for delete ptr "<<"\n";
     delete ptr;
   }
   
   //dereferece operatorover * loading.
   T& operator*()
   {
    return *ptr; // dereference value on ptr returning in reference.
   }

   T* operator->()
   {
     return ptr;   
   }

};

int main ()
{
    //  smartPtr<int> p(new int());
    //  *p = 30;
    //  cout << *p <<"\n";
    //  {
    //     smartPtr <int> q = p;
    //     cout<< *q << "\n"; // q destructor gets called which causes ptr pointer gets deleted
    //                        // ptr is refered by p and q both.    
    //  }
    //  cout<<*p<<"\n"; // p becomes dagling pointer.
    //  smartPtr<char> c( new char());
    //  *c = 'a';
    //  cout << *c <<"\n";
     
    smartPtr <person> t = new person(30, "suraj");
    t->display();

}