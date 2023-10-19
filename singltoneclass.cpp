#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* singletone class is the class where class has only instants to be creacted*/

class singletone
{
     static singletone *stc;
     string name;
     public:
     singletone( ) = default;
     static singletone *getinstant()
     {
         if(stc == NULL)
         return stc = new singletone();
         else 
         return 
         stc;
     }
    
     singletone( const singletone & obj) = delete; // deleting copy constructor

     void setValues( string n)
     {
         this->name = n;
     }

     void display()
     {
        cout<< " the name is "<< name << "\n";
     }

};
singletone *singletone::stc = NULL;

int main()
{
     singletone *sohel = singletone::getinstant();
     
     sohel->setValues("sohel");
     sohel->display(); 
     cout<< "address of sohel is :"<< sohel << "\n"; // 

     singletone *suraj =singletone :: getinstant();
     suraj->setValues("suraj");
     suraj->display();
     cout<< "address of suraj is :"<< suraj << "\n"; // instance poniting to same address as sohel
}
