#include<iostream>
#include<algorithm>
#include<array>
#include<numeric> // for accumulate algorithm
using namespace std;

void display ( array <int , 5> &a)
{
    array <int,5> :: iterator it;
    for( it = a.begin() ; it!=a.end() ; it++ )
    {
        cout << *it << ",";
    } 
}

int main()
{
    array <int , 5 > arr { 1, 10 , 5 ,8, 6 };
     
    sort(arr.begin() , arr.end());
    cout << " sorted array is "<< "\n";
    display(arr);

    cout << "\n==============================="<<"\n";

    // empty returns 1 if array is empty 
    cout << "empty array return 1 else 0  checking :" << arr.empty() << "\n"; 

    array <int , 5 > arr1 = { 10,20,30,40,50};

    cout << "\nsize of array:" << arr1.size() << " \n";

    // max_size(); of  array
    cout << "\nmax_size of array:" << arr1.max_size();

    //swap array element with other array element.
    arr.swap(arr1);
    cout << "\n==============================="<<"\n";
    display(arr);

    
    arr[0] = 1000;
    arr.at(3) = 3000;
   // arr.at(9) = 3000; // bounce checking means if assigne value beyond the limit it throws exception.
                       // terminate called after throwing an instance of 'std::out_of_range'
                       // what():  array::at: __n (which is 9) >= _Nm (which is 5)

    cout << "\n==============================="<<"\n";
    display(arr);
    
    // fill the array element with 0 
    arr.fill(0) ;
    cout << "\n==============================="<<"\n";
    display(arr);

    cout << "\n==============================="<<"\n";

     array<int,5> arr2 { 1000,2000,3000,4000,5000};
    // data returns address of raw array of integers we stored in pointer variable. 
    int *data = arr2.data();
    cout << " \nbase address of raw array behind the array wraper class is :" << data << "\n";
    data[3] = 8;
    display(arr2);

    cout << "\n==============================="<<"\n";
 
   // max_element() , min_element(); returns the iterator to the max and min element of array
    array<int, 5> :: iterator max_num ;
    max_num= max_element(arr2.begin() , arr2.end());
    auto min_num = min_element(arr2.begin() , arr2.end());
    cout << " min num is :" << *min_num << ", max num is :" << *max_num <<  "\n";  

    cout << "\n==============================="<<"\n";

    // adjacent_find returns the iterator to adjecent find in array.
    array <int , 5> arr3 = { 41,42,43,43,45 };
    auto adjec = adjacent_find( arr3.begin() , arr3.end());
    if (adjec!= arr3.end())
    {
        cout << " adjecnt find :" << *adjec << " \n"; 
    }
    cout << "\n==============================="<<"\n";

    //accumulate gives sum of array elements. #include<numeric> 
    array <int , 5> arr4 { 1,2,3,4,5};
    int sum = accumulate( arr4.begin(),arr4.end(), 0 /*init value of sum*/);
    cout << " sum of array element is " << sum;

    cout << "\n==============================="<<"\n";

    // count the element in array return num of element which pass as argument in count
    array <int , 10 > arr5 {1,2,3,4,5,3,4,3,3,2};
    int cnt  = count( arr5.begin() , arr5.end() , 3 /*element for count*/);
    cout<<" count of element 3 in array is : "<< cnt;

    cout << "\n==============================="<<"\n";

    array<int , 10 > arr6 { 3,6,7,12,13,14,15,23,24,25};
    int count = count_if( arr6.begin() , arr6.end() , /*lambda expression*/ [] (int x) { return x>10 && x<20;});
    cout << " found count of element which are match the condition is : "<< count << "\n";  

}