#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<fstream> //file operation
#include<sstream> // stringstream operation
#include<iomanip> //setw
using namespace std;

// this function gives clean word from string by avoiding , : ; and . 
string cleanString( string &s)
{
    string result;
    for (char c : s)
    {
         if( (c =='.') || (c ==';')||(c ==',') || (c ==':'))
         continue;
         else
         result+=c;

    }
    return result;
}

//display words appears in text file map<string , int>
void displyPartOne( map<string,int> &words)
{
    cout<<setw(12) << left << "\nWord"
        <<setw(6) << right << "Count" << "\n";
    cout<<"================================\n";
    for(pair<string,int> P : words)
    {
        cout<<setw(12) << left <<P.first
        <<setw(6) << right << P.second <<"\n";

    }
}


void displyPartTwo( map<string,set<int>>&words)
{
    cout<<setw(12) << left << "\nWord"
        <<setw(6) << right << " LineNumber" << "\n";
    cout<<"================================\n";
    for(pair<string,set<int>> P : words)
    {
        cout<<setw(12) << left << P.first << " {";
        for(const int &s :P.second)
        {
        cout<< s<<" ";
        }
        cout << " } " <<"\n";
    }
}

//process the file and build the map for words and
// number of times they occur in the file.
void part_one()
{
    map<string,int> words;
    string line;
    string word;
    ifstream in_line {"speech.txt"};
    if(in_line)
    {
    while (getline (in_line,line))
    {
        cout<<line << "\n";
        stringstream ss {line};
        while(ss>>word)
        {
            word = cleanString(word); // funtion call to avoid , . ; and : from words
            words[word]++; // increament the count for the word in map;
                           // words["keystring"] 
        }
        
    }
    in_line.close();
    displyPartOne(words);
    }
    else
    { 
        cerr<<" error in opening file "<<"\n";
    }
}


//process the file and build the map for words and
// set of line numbers at they repeat in the file.
void part_two()
{
    map<string,set<int>> words;
    string line;
    string word;
    set<int>s;
    ifstream in_line {"speech.txt"};
    if(in_line)
    {
     int count = 0;
    while (getline (in_line,line))
    {
       
        count++; // line number
        cout<<line << "\n";
        stringstream ss {line};
        while(ss>>word)
        {
            word = cleanString(word); // function call to avoid , . ; and : from words
            words[word].insert(count); // reapeted words founds at line no added through set<int> insert method;
                                       // words["keystring"]       
        } 
    }
    in_line.close();
    displyPartTwo(words);
    }
    else
    { 
        cerr<<" error in opening file "<<"\n";
    }
}

int main ()
{
   part_one();
   cout << "========================================================= \n";
   part_two();
}
