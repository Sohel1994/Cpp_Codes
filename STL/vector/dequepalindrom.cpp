#include<iostream>
#include<deque>
#include<algorithm>
#include<vector>
using namespace std;

 bool palindrom (string &s)
{  
     deque<char> d;
     for (char c :s)
     {
        if(isalpha(c))
        {
          d.push_back(c);
        }
     }
     char c1;
     char c2;
     while(d.size()>1)
     {
          c1 = d.front();
          c2 = d.back();
          d.pop_front();
          d.pop_back();
          if(c1!=c2)
          {
            return false;
          }
          
     }
     return true;
}

int main ()
{
     vector<string> vec = { "a santa at nasa" , "aba", "sohos" , "suraj"};

        for( int it = 0; it != vec.size() ; it++)
        {
             if(palindrom(vec[it]))
             {
             cout << vec[it] << " :sting is palindrom :"<< "\n";
             }
        }
}