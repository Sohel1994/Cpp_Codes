/* 
//   queue is adaptor container implemented as already exist containers list , vector or deque
//   queue is first in first out data container.
//   elemets are pushed at back and popped at front.
//   No iterators are supported.
*/
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<queue>
using namespace std;

template<typename T>
void display( queue<T> q)
{
       T elem;
       cout<< "[";
       while(!q.empty()) // q.empty() return true if queue is empty
       {
           elem = q.front();
           q.pop();
           cout<< elem << " ";
       }
       cout << "]"<< "\n";
}

int main()
{
    queue<int> q;
    
    for( int i : { 1,2,3,4,5})
    {
        q.push(i);
    }

    display (q); // [1 2 3 4 5 ]

    q.front() = 5;  // change the front element.
    q.back () = 1; // change the back element.
    
    cout<< "\n=========== fornt and back============== \n";
    display(q);  // [9 2 3 4 100 ]

   cout<< "\n=========== size of queue============== \n";
    cout<< " size " << q.size() << "\n";

    q.push(10); // push at the end
    q.push(11); // push at the end

    cout<< "\n=========== new element push() ============== \n";
    display(q); // [5 2 3 4 1 10 11 ]

    cout<< "\n=========== retrive first element pop()============== \n";
    q.pop();
    display(q); // [ 2 3 4 1 10 11 ]

}
