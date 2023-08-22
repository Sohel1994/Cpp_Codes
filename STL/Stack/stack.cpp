/* stack is adaptor container can be implemented as vector list or deque
// stack is last in first out data structure. 
// all operations are work on end of the stack(top)
// no iterators are supported on stack.
*/
#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;

template<typename T>
void display( stack<T ,vector<T>> s)
{
     cout << " [" ;
     while(!s.empty())
     {
        T ele = s.top();
        s.pop();
        cout << ele << " ";
     }
     cout << "]" ;
    
}

template<typename I>
void display1( stack<I> s)
{
     cout << " [" ;
     while(!s.empty())
     {
        I ele = s.top();
        s.pop();
        cout << ele << " ";
     }
     cout << "]" ;

}

int main()
{
   stack<int> s;
   for ( auto i : {1,2,3,4,5})
   {
      s.push(i);
   }
   display1(s);

   cout << "\n============================\n";

   s.push(10);
   display1(s);

   s.top() = 100; // can replace the top of stack;
   
   cout << "\n============================\n";
   display1(s);

   
   vector<int> v = { 1,3,4,5,6,7};
   stack<int , vector<int> > s1 (v);
   cout << "\n============================\n"; 
   display(s1);

   cout<<" \n size " << s1.size(); 

   

}
