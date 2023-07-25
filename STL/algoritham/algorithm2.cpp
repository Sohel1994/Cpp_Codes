/*
* checking algorithm with count , count_if , replace , accumulate, transform 
* lambda functionality.
* lambda syntax  
* ( vector.begin() , vector.end(),[](int variable) { function defination} );
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;
int main()
{
     // count algorithm
     vector<int> nums = { 3,2,4,6,7,5,8,8,8,9,1,0,2};
     int n = count(nums.begin(),nums.end(), 8 /*value*/) ; // count the presence of value in vactor
     cout << " the count of value is :" << n <<"\n";

     //count_if algorithm with lambde function
     int i = count_if(nums.begin(),nums.end(), /*lambda function*/[](int x /*take values from vector*/) { return x % 2 ;});
     cout << " the count of values of vector which are divisible by 2 :" << i <<"\n";

     // replace the vector element 
      replace(nums.begin(),nums.end(), 8, 16);
      for (auto r : nums)
      {
        cout << r <<","<<"\n";  
      }

      // all_of function.
      if( all_of (nums.begin() ,nums.end() , [] (int x) { return x > 10;}))
      {
        cout << " all the elements are less than 10 " << "\n";
      }
      else 
      {
        cout << " not all the elements are less than 10" << "\n";
      }

      // any of  function.
      if(any_of(nums.begin(), nums.end() , [](int x ) { return x>20;}))
      {
        cout << " some of values are grater than 20" <<"\n";
      }
      else
      {
        cout << " non of the value is greater than 20" << " \n";
      }

      //transform the string 
      cout<< " ===========================\n"; 
      string str {" to the transform"};
      cout << str << "\n";

      transform(str.begin() ,str.end(), str.begin(), ::toupper);
      cout<< str << "\n";
}