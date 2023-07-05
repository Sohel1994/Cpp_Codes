#include<iostream>
using namespace std;

class GfG 
{
public:
	// static member function
	static int i ;
	static void printMsg() 
	{ 
	cout << "Welcome to GfG!"; 
     i = 20;
	}
};
int GfG::i=10;
int main()
{
	cout<< GfG::i;
	GfG::printMsg();
	cout << "\n";
	cout<< GfG::i;
}
