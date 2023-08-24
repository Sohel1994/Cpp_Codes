#include<iostream>
#include<queue>
#include<stack>
#include<iomanip>
using namespace std;

bool is_palindrom( string &str)
{

    stack<char> s;
    queue<char> q;
  /*
    for( int i= 0 ; i<str.length() ; i++)
    {
        if(isalpha(str[i]))
        {
           s.push(str[i]);
           q.push(str[i]);
        }
    }
  */
     for (char c : str)
     {
        if(isalpha(c))
        {
          s.push(c);
          q.push(c);
        }
     }

    char c1;
    char c2;
    //while( (q.size()> 1 )&& (s.size() > 1))
    while(!q.empty()) // stack and queue refering same size
    {
        c1 = s.top(); // last char fron string
        c2 = q.front(); // first char from string
        s.pop();
        q.pop();
        if(c1 != c2)
        {
            return false;
        }

    }
    return true;     

}

int main ()
{
     vector<string> vec = { "a santa at nasa", "shireen" , "aba", "sohos" , "suraj"};

        for( int it = 0; it != vec.size() ; it++)
        {
             if(is_palindrom(vec[it]))
             {
             cout << vec[it] << " :string is palindrom "<< "\n";
             }
             else
             {
             cout << vec[it] << " :string is not palindrom "<< "\n";
             }
        }
}