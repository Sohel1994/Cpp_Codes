#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<algorithm>

using namespace std;

struct squre
{
   void operator()(int x)
   {
     cout << x*x<<" ";
   }


};

template<typename T>
class displayer
{    

    public:
    void operator()( const T &data)
    {
        cout << data << "\n";
    }    
 

};

class multiplyer
{
    int num;
    public:
    multiplyer( int n ) : num(n)
    { 
    } 
    int operator()( int n) const
    {
        return num*n;
    }
};


int main(){

    cout << "\n Test1 ============= \n";
    squre s;
    s(5);

    cout << "\n Test2 ============= \n";
    displayer<int> d;
    d(8); // display 8
    displayer<string> str;
    str("sohel"); // display sohel

    cout << "\n Test3 ============= \n";

    vector<int> v {1,2,3,4};
    vector<string> v1 { "sohel","suraj","shireen"};
    std::for_each(v.begin(), v.end() ,s); // s(1),s(2),s(3),s(4) 
                                          //output 1,4,9,16 
    cout<< "\n";
    std::for_each(v1.begin(),v1.end(),displayer<string>());// displayr () overloding calling for each element of vector
                                                           // sohel suraj shireen
    
    cout<<"\n";

    cout << "\n Test4 ============= \n";
    for_each( v.begin(),v.end(),d); // displayer<int>(1) displayer<int>(2) displayer<int>(3) displayer<int>(4) calling 
                                    // 1 2 3 4
    for_each(v1.begin(),v1.end(),str); //displayer<string>(sohel) , displayer<string>(suraj) 
                                       //displayer<string>(shireen) calling
                                       // sohel suraj shireen

    // using lambda 


    cout << "\n Test5 ============= Lambda \n";
    for_each(v.begin(),v.end(),[](int x) {cout << x << " ";}) ; // [](parameter) {code}
    cout << " \n";
    for_each(v1.begin(),v1.end(),[](string str){ cout << str << " ";});
    cout << " \n";
    for_each(v.begin(),v.end(),[](int x) {cout << x+100<< " ";}); 

    cout << "\n Test 6 ============= transform \n";
    vector<int> vec { 10,20,30,40,50};
    multiplyer mul(1000); // parametrized constructor of multiplayer class
    transform(vec.begin(),vec.end(), vec.begin(),mul); // mul(10) ,mul(20),mul(30)... calling for vector element;
                                                       // 10*1000 , 20*1000 , 30*1000     
    displayer<int> m;                                     
    for_each(vec.begin(),vec.end(),m); // displayer<int>() // trancform vector value pass 
    cout<< "\n";

    cout<< "using lambda vector transform \n";
    vector<int> vec1 { 9,8,7,6,5};
    transform( vec1.begin(),vec1.end(),vec1.begin(),[](int x) {return x*5;});
    for_each(vec1.begin(),vec1.end(),[](int x){cout << x << " ";});

}