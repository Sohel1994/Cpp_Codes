// SETS associative containers collection of stored objects that allow
// fast retrieval using keys.
// usaully implemeted as a binary blanced tree or hashsets.

// four types of sets containers.
// (1) std::set
/*
- sets not allowed duplicates elements 
- set<int> s = {1,2,4,3,5,3,6,4}  // { 1,2,3,4,5,6} // also sets are sorted.
- cout<< s.size() ; //  6
- coutr<< s.max_size(); //  a very large number.
- sets do not allow direct access to the element so we can not use .at() method or s[] operator.
- No concepts of front and back so not allow push_back or pop_back methods are in sets.
- to add elements we can use s.insert() method or s.empalce() method to add elements.  
*/

//2) std::multiset // #include<set>
/*
-  allows duplicate elements  in sorted form.
*/ 

//3) std::unordered_set // #include<unordered_set>
/* 
- the sets elements are unordered.
*/

//4) std::unordered_multiset // #include<unordered_set>
/*
- unsorted sets with duplicates allows.
*/

#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
#include<set>
#include<unordered_set>

using namespace std;

class person
{ 
    int age ;
    string name;
    public:
    person (): age{0},name{"unknown"}
    {
        cout << "default constructor person class"<<"\n";
    }

     person (int a , string str) : age(a) ,name(str)
     {
        cout<< " parameterized constructor "<<" \n";
     }
      
     bool operator<( const person &rhs ) const //  < operator overloading
     {
           return this->age < rhs.age;
     }

     bool operator==( const person &rhs) const // == operator overloading
     {
        return this->age == rhs.age && this->name ==rhs.name;
     }

     friend ostream & operator<<( ostream  &os , const person &p);
     friend istream & operator>>( istream  &is , person &p);
};

ostream &operator<<( ostream &os , const person &p)
{
   os << p.name << ":" << p.age;
}

istream &operator>>( istream  & is ,  person &p)
{
    cout<< " enter the person name "<<"\n";
    is >> p.name;
    cout<< " enter the person age "<< "\n";
    is >> p.age;
    return is;
}

template <class T>
void display( const set<T> &l)
{
     cout << "[ ";
     for (const auto &elem : l)
     { 
        cout << elem <<" ";
     }
     cout << "]" << "\n";
}

void test1()
{
    cout<<" test 1 =================================="<<"\n";

    std::set<int> s = {1,3,2,5,4}; // {1,2,3,4,5} SORTED
    display(s);
    std:: set<int> s1  = {1,2,3,2,4,6,3,5,7,1,5} ; //{ 1,2,3,4,5,6,7}
    display(s1);

    s.insert(0);
    s.insert(10);
    display(s);    //{ 0,1,2,3,4,5,10}

//   set<int>::iterator it;
    auto it = s.find(5);
    if (it!= s.end())
    {
       cout<< "found :" << *it << "\n";
    }

    s1.clear();
    display(s1);
}


void test2()
{
    cout<<" \n test 2 =================================="<<"\n";

    set<person> p = {
                     { 29 ,"suraj"},
                     { 28 ,"sohel"},
                     { 26 ,"shireen"},
                     { 58,"allauddin"},
                     { 50 ,"parveen"}
                    };
    display(p);    // set uses < operator to sort the set elements by ages.
                   // { shireen:26 , sohel:28 , suraj:29, parveen:50 , allauddin:58 }
    
    p.insert( person(55, "sikandar"));
    display(p);

    p.emplace( 55,"balasaheb"); // NOt allowed already exist 55 age duplicate element by age.
    display(p);

    auto it = p.find( person(28,"sohel")); // find sohel
    if(it!=p.end())
    {
        p.erase(it); // { shireen:26 , suraj:29 , parveen:50 , sikandar:55 , allauddin:58 }
    }
    display(p);

    // p.erase(person(55,"XXXX"));
    // display(p);
    it = p.find( person(55,"XXXXX")); // find sikandar:55 by < operator to the age and remove 
       if(it!=p.end())
    {
        p.erase(it);
    }
    display(p);  // {shireen:26 ,suraj:29 , parveen:50 , allauddin:58 }

} 

void test3()
{
    cout<<" \n test 3 =================================="<<"\n";

    set<string> s = { "A","D","B","C"}; 
    display(s); // [ A B C D ] sorted

    // pair<set<string>::iterator,bool> result = s.insert("E");
    // display(s);
    // cout << "*(result.first) is iterator to element that inserted "<< *(result.first) <<"\n";
    // cout << " (result.second) is return true ot false by successful insertion of element in set : "
    //      << result.second<< "\n";

    auto result = s.insert("B"); // duplicate element in set.
    cout << "*(result.first) is iterator to element that inserted "<< *(result.first) <<"\n";
    cout << " (result.second) is return true ot false by successful insertion of element in set : "
         << result.second<< "\n";
}

int main()
{
   //test1();
   //test2(); 
    test3();  
}