#include<iostream>
#include<fstream>
using namespace std;

int main()
{
     ifstream in_file;
     in_file.open("mytestfile.txt");
     
     if(!in_file)
     { 
        cerr<< " error in opening file "<<"\n";
     }
     else
     {   
        //  string line;
        //  while(getline(in_file,line))
        //  {
        //     cout<<line<<"\n";
        //  }
        cout<<"++++++++++++++++++++++++++++++++++"<<"\n";
        string line;
        char c;
        int i;
        float f;
        while(!in_file.eof())
        {
            getline(in_file,line);
            in_file>>i>>f;
            cout<<line<<"\n"<<i<<"\n"<<f;
        }

     }

}
