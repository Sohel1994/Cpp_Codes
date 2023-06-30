#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    
     ifstream in_file ("mytestfile.txt");
     ofstream out_file ("copyfile.txt");

     if(in_file.is_open())
        cout<<"read from file"<<"\n";
     else
        cerr<<"error while reading from file"<<"\n";

     if(out_file.is_open())
        cout<<"write to the file"<<"\n";
     else
        cerr<<"error while reading from file"<<"\n";
     
     string line;
     while( getline(in_file,line))
    {
        out_file<<line<<"\n";
    }
    in_file.close();
    out_file.close();

}