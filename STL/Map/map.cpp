/* 
-map is a associative container which can access through key and value pair
- #include<map>
- I)std::map - no duplicates
- II)std::multimap - sorted by keys allows duplicates.

- #include<unordered_map>
- I)std::unordered_map - no duplicates also not sorted
- II)std::unordered_multimap - duplicates allowed but not sorted.
*/
#include<map>
#include<unordered_map>
#include<iostream>
#include<string>
#include<set>
using namespace std;

void display2(const map< string , set<int> > & m)
{
    cout<< "[ ";
    for ( const auto &elem: m )
    {
      cout << elem.first<< ":{";
      for( const auto &setElem :elem.second)
       cout<<setElem<<" ";
       cout << "} ";
    }
    cout<<" ]" << "\n";
}

// generic display function for (map< data_type1 , set<data_type2> >) 
// template<typename M ,typename S>
// void display2(const map< M , set<S> > & m)
// {
//     cout<< "[ ";
//     for ( const pair<M ,set<S>> &elem: m )
//     {
//       cout << elem.first<< ":{";
//       for( const S &setElem :elem.second)
//        cout<<setElem<<" ";
//        cout << "} ";
//     }
//     cout<<" ]" << "\n";
// }

// generic display function for map< data_type1 , data_type2>
template<typename T1 , typename T2>
void display( map<T1,T2> &maps)
{
       cout<<"[";
       for(const pair<T1,T2> &elem : maps)
       {
          cout<< elem.first << ":" << elem.second << " ";
       }
       cout<<"]"<<"\n";

}

void test1()
{
      cout <<"\n test 1 =====================================\n";
      map<string,int> m = {
                          {"sohel",28},
                          {"suraj",29},
                          {"shireen",26}
                        };

    m.insert(pair<string,int>("allauddin",58));
    m.insert(make_pair("parveen",50));
    
    display(m);

    m["sikandar"] = 55; // if  key is not there then it will add.
    display(m); // [allauddin:58 parveen:50 shireen:26 sikandar:55 sohel:28 suraj:29 ]
    m["sohel"]+= 2; //[allauddin:58 parveen:50 shireen:26 sikandar:55 sohel:30 suraj:29 ]
    display(m);

    m.erase("shireen"); //[allauddin:58 parveen:50 sikandar:55 sohel:30 suraj:29 ]
    display(m);

    cout<< "count for suraj :" << m.count("suraj") << " \n"; // 1
    cout<< "count for shireen :"<< m.count("shireen")<< "\n"; // 0

    map<string,int>::iterator it = m.find("parveen");
    if(it!=m.end())
    {
        cout<<"found :"<< it->first << ":" << it->second << "\n"; //found :parveen:50  
    }
}

void test2()
{
    cout <<"\n test 2 =====================================\n";
     map<string, set<int> > mp  =
     {
       {"school" ,{ 9,10}}, 
       {"college",{ 11,12}},
       {"degree" ,{13,17} }
     };

     display2(mp);
}

int main()
{
  test1();

  test2();

  
}