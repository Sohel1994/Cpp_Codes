#include<iostream>
#include<sstream>
#include<limits>

using namespace std;

int main()
{
    int value ;
    string input;
    
    // cin >> input ;
    // istringstream ipStream {input};
    
    // if(ipStream>>value)
    // {
    //     cout<<" user entered integer input"<< "\n";
    // }
    // else 
    // {
    //     cout << " user entered non integer value\n";
    // }

    bool done = false;
    do
    {
        cout << " please enter an integer "<<"\n";
        cin >> input ;
        istringstream ipStream {input};

        if(ipStream >> value)
         done = true;
        else
        cout << "you entered  wrong value "<<"\n";

        //discard the input buffer
       cin.ignore( numeric_limits <streamsize> :: max(),'\n');

    } while(!done);
   
     cout<< " you entered value is "<<value <<"\n";


}