#include<iostream>
#include<sstream>
#include<string>
#include<limits>
#include<iomanip>
#include<ios>

using namespace std;

int main()
{ 
    // int num{};
    // double percent{};
    // string name{};
    // string info = {"sohel 100 99.99"};
    // istringstream inStream {info}; // connecting string info to istringstream object.  
    // inStream >> name >> num >> percent;  // geting string info into inStream accordingly,Like istream to file. 
    // std::cout << std::setw(10)<<left<< name
    //           << setw(5) << num
    //           << setw (10) << percent << "\n"; 

    cout <<"=================================================\n";
 

    int num = 100;
    int percent = 99.99;
    string name {"sohel"};
    ostringstream outStream;
    outStream << std::setw(10)<<left<< name
              << setw(5) << num
              << setw (10) << percent << "\n";  // storing data into buffer of ostringstream object

    cout <<outStream.str();  // displaying string By str() function call which is in ostringstream class.


}