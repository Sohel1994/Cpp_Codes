#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class person {
    
    int age ;
    string name;
    public:
    person(): age{0} , name{NULL}
    {
        cout << " Default person constructor " << "\n";
    }

    person ( int a , string str)
    {
        this->age = a;
        this->name = str;
    }


    //comparing ages of userdifined data < overloaded. 
    bool operator<( const person &rhs)const
    {
        return this->age < rhs.age;
    }
   
    //comparing userdefined data == overloaded. 
    bool operator==( const person &rhs )const
    {
        return (this->age==rhs.age) && (this->name == rhs.name);
    } 

    friend ostream& operator<<( ostream &os , const person &p);
    
};

// to display userdefined data type elements << overloaded.
ostream & operator<<( ostream &os , const person &p)
{
    os << p.name << ":" << p.age ;
    return os;
}

template <typename T> 
void display (const vector<T> &vec)
{
     cout << "[" ;
     for ( auto &it : vec)
     cout << it << "," ;
     cout << "]" << "\n";
}

// for_each algorithm is used with lambda expresion to display each element of vector.
void display2(const vector<int> & vec)
{
     cout << "[" ;
     for_each(vec.begin(),vec.end() , [] (int x) { cout << x << ",";});
     cout << "]" << "\n"; 
}

void test1()
{
     cout<< "\n test1 ==============================="<< "\n";

     vector<int> v {2,3,4,5};
     display(v);
     v = { 5,6,7,8};
     display2(v);
     vector<int> vec1 (10,100); // this will fill the vector with ten 100's.
     display2(vec1);
}

void test2()
{
    cout<< "\n test2 ==============================="<< "\n";
    vector<int> v { 4,5,6,7,8};
    cout << " size of vector : " << v.size()<<"\n";
    cout << " Max size of vector : "<< v.max_size()<<"\n";
    cout << " capacity of vector : " << v.capacity()<<"\n";

    v.push_back(9); // this will increse the capacity of vector double.
    display(v);

    cout << "=========================================" << "\n";
    cout << " size of vector : " << v.size()<<"\n";
    cout << " Max size of vector : "<< v.max_size()<<"\n";
    cout << " capacity of vector : " << v.capacity()<<"\n";
    
    v.shrink_to_fit();
    cout << "=========================================" << "\n";
    cout << " size of vector : " << v.size()<<"\n";
    cout << " Max size of vector : "<< v.max_size()<<"\n";
    cout << " capacity of vector : " << v.capacity()<<"\n";

    v.reserve(100); // this makes capacity 100 for vector until the vector hits the 101th element.
     cout << "=========================================" << "\n";
    cout << " size of vector : " << v.size()<<"\n";
    cout << " Max size of vector : "<< v.max_size()<<"\n";
    cout << " capacity of vector : " << v.capacity()<<"\n";

}

// index at at method of vector.
void test3()
{
    cout<< "\n test3 ==============================="<< "\n";
    vector<int> v { 4,5,6,7,8};
    display(v);
    
    v[2] = 100; // no bounce checking
    v.at(3) = 200; // bounce checking throws exception while assigning value over vector size. 
    display(v);   

}

void test4()
{
    cout<< "\n test4 ==============================="<< "\n";
    vector<person> v;
    person p ( 30, "suraj");
    v.push_back(p);
    v.push_back( person{ 29 , "sohel"});
    v.emplace_back( 26 ,"shireen"); // this method directly call constructor.
    
    display(v);

}

// push_back , front , back methods.
void test5(){
    cout<< "\n test5 ==============================="<< "\n";
    vector<person> v = {
                        {30, "suraj"},
                        { 29 , "sohel"},
                        {26 ,"shireen"}
                       };
    display(v);
    cout << "\nfront " << v.front() << "\n";
    cout << "back " << v.back() << "\n";
   
    cout << "\npop_back "<<"\n";
    v.pop_back();
    cout << "\nfront " << v.front() << "\n";
    cout << "back " << v.back() << "\n";
}


// erase and clear method for vector.
void test6()
{
    cout<< "\n test6==============================="<< "\n"; 
    vector<int> v { 4,5,6,7,8};
    display2(v);
    v.clear(); // clear the vector element.
    display2(v);

    v = { 1,2,3,4,5,6,7,8,9};
    display2(v);
    v.erase(v.begin(), v.begin()+3); // earase the elament of vector in range provided.
    display(v);
   
    vector <int> v1 = { 1,2,3,4,5,6,7,8,9};
    cout<< " erase even element of vector " <<"\n";
    auto it = v1.begin();
    while( it!=v1.end())
    {
        if (*it % 2 == 0)
         v1.erase(it);
        else
        it++;  
    }
    display(v1);
}

// swap method for vector.
void test7()
{
      cout<< "\n test7==============================="<< "\n";
      vector<int> v = { 1,2,3,4,5};
      vector<int> v1 = {21,22,23,24,25};

      display(v);
      display(v1);

      v.swap(v1); //swaping the vector elements.

      cout << "after swap "<<"\n";
      display(v);
      display(v1);


}

// sortin of vector elements.
void test8()
{

    cout<< "\n test8==============================="<< "\n";
    vector<int> v = { 1,7,21,12,5};
    display(v);

    sort(v.begin(),v.end());
    cout << " after sort" << "\n";
    display(v);

}

//// back_inserter , copy and copy_if
void test9()
{ 

      cout<< "\n test9 ==============================="<< "\n";
      vector<int> v = { 1,2,3,4,5};
      vector<int> v1 = {11,22,33,44,55};
      display(v);
      display(v1);
      copy(v.begin(),v.end() , back_inserter(v1)); // copy elenment of v afrer v1 element.
      cout << "after copy v1 appended with v elements. "<<"\n";
      display(v);
      display(v1); 


     cout<< "\n=========================================== \n";

      // copy_if with lambda expression.
      vector<int> v2 = {1,2,3,4,5,6,7,8,9};
      vector<int> v3 = { 10 ,20} ;
      display(v2);
      display(v3); 

      copy_if(v2.begin(),v2.end() , back_inserter(v3) , [] (int x) { return x % 2 == 0;});
 
      cout << "after copy_if v3 appended with even elements of v2"<<"\n";
      display(v2);
      display(v3); 


}

//transform method with lambda expression and back_inserter.
void test10()
{ 
      cout<< "\n test10 ==============================="<< "\n";
      vector<int> v = { 1,2,3,4,5};
      vector<int> v1 = {10,20,30,40,50};
      vector<int> v2 ;

      cout<<"multipication of 2 vectors storing in 3rd "<<"\n";
      // multipication of 2 vectors storing in 3rd vector v2.
      transform( v.begin() , v.end() , v1.begin() , back_inserter(v2),
                 [](int x /*for v element*/, int y /*for v1 element*/ ){return x*y;}
                 );
 
      display(v);
      display(v1);
      display(v2);


}

//insert method find algorithm.
void test11()  
{
      cout<< "\n test11 ==============================="<< "\n";
      vector<int> v = { 1,2,3,4,5};
      vector<int> v1 = {10,20,30,40,50};
      
      auto it = find(v.begin(),v.end(),3);

      if ( it!=v.end())
      {
        cout << " inserting ... v1 into v ...." << "\n";
        v.insert(it, v1.begin(),v1.end()); // insert whole vector v1 into v before v=3 is found.
      }
      else 
      {
        cout << " sorry 3 is not found" <<"\n";
      }

      display(v);
     
}

int main()
{
    test1();
    test2();  
    test3();  //index at at method 
    test4();  // emplace_back method.
    test5();  // front and back method.
    test6(); //erase and clear method.
    test7(); //swap vector method.
    test8(); //sort vector method.
    test9(); // back_inserter , copy and copy_if with lambda expression.   
    test10(); // transform method with lambda expression and back_inserter.
    test11(); // insert method with find;
}

