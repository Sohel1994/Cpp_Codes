#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

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
void display( const list<T> &l)
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
    cout<<"\n test 1 ==================================== "<<"\n";
    list<int> l = { 1,2,3,4,5};
    display(l);

    list<int> l2 = {};
    display(l2);
    l2.push_back(4);
    l2.push_front(7);
    display(l2);

    list<int> l3 = {1,3,4,5,7,5,7,3};
    display(l3);

    list<int> l4(10, 101) ; // fill the list with 101 value
    display(l4);

}

void test2()
{
   cout<<"\n test 2 ==================================== "<<"\n";

   list<int> l1 = { 1,2,3,4,5,6,7,8,9,10};
   display(l1);
   cout << l1.size()  << "\n";
   cout << l1.max_size()  << "\n";
   l1.resize(5);
   display(l1);

   l1.resize(10);
   display(l1); // now extended list elemetnt filled with 0's [ 1 2 3 4 5 0 0 0 0 0 ]

   list<person>p;
   p.resize(5); // default construtor will called list init with default arguments
   display(p);  // for display << operator overloaded with friend function ostream return;

//    person q;
//    cin>>q;
//    cout<<q;
   
}
void test3() // find and insert
{
    cout<<"\n test 3 ==================================== "<<"\n";
    list<int> l = {1,2,3,4,5,6,7,8,9};

    auto it = find(l.begin(),l.end(),5);
    if(it!= l.end())
    {
        l.insert(it,100);  // inserting 100 before 5
    }

    display(l);
    list<int> l2 = {1000,2000,3000};
    l.insert(it,l2.begin(),l2.end()); // inserting another list at iterator pointing in l list

    display(l); // now itrator it at 5 , [ 1 2 3 4 100 1000 2000 3000 5 6 7 8 9 ]
 
     //for advace function include<iterator>
     advance(it,-4); // iterator moving backeward by 4 position. pointing to 100 in list
     cout<<*it<< "\n";

     l.erase(it); // remove 100 from the list.[ 1 2 3 4 1000 2000 3000 5 6 7 8 9 ]
     display(l);

     cout<<*it<<"\n";

}

void test4()
{
    cout<<"\n test 4 ==================================== "<<"\n";

    list<person> st = {
                        {28,"sohel"},
                        {29,"suraj"},
                        {26,"shireen"}
                      };
    display(st);

    int age;
    string name;
    cout<< "Enter the age of person"<<"\n";
    cin>>age;
    cout<< "Enter the name of the person"<<"\n";
    cin >> name;

    st.emplace_back(age,name); // directly called  paramerised constructor.
                               // and insert the element to the end of of the st person list.
    display(st);

    auto it = find(st.begin(),st.end(),person{26,"shireen"});
    if(it!= st.end())
    {
       st.emplace(it,person{50,"parveen"});
    }
    display(st);

}

void test5() //sort < less than operator overloading
{
    cout<<"\n test 5 ==================================== "<<"\n";

    list<person> st = {
                        {28,"sohel"},
                        {29,"suraj"},
                        {26,"shireen"}
                      };

   display(st);

   // sort by ages < operator overloading.
   st.sort();
   display(st);



}
int main()
{
    //test1();
    //test2();
    //test3(); // size and resize and erase
    //test4(); //emplace and emplace_back
    test5(); // sort for person < operator overloading.
}