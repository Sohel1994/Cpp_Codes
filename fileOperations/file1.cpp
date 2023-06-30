#include<iostream>
#include<iomanip>
#include<ios>
using namespace std;

int main()
{



//std::boolalpha; // std boolean flag 
cout<< " boolalpha ( 10==10 ) :"<< (10==10) << "\n";
cout<< " boolalpha ( 10==20 ) :"<< (10==20) << "\n";

cout << " ======================================== "<<" \n";

cout<<setiosflags(std::ios/*namespace*/::boolalpha/*flag*/);
cout<< " noboolalpha ( 10==10 ) :"<< (10==10) << "\n";
cout<< " noboolalpha ( 10==20 ) :"<< (10==20) << "\n";

cout << " ======================================== "<<" \n";

cout<<resetiosflags(std::ios/*namespace*/::boolalpha/*flag*/);
cout<< " noboolalpha ( 10==10 ) :"<< (10==10) << "\n";
cout<< " noboolalpha ( 10==20 ) :"<< (10==20) << "\n";

cout << " ======================================== "<<" \n";

int num {-255};
cout<<setiosflags( std::ios::showbase); // shows base of NO 
cout<<setiosflags( std::ios::uppercase); // shows base value in upper case
cout<<" dec " << dec << num << "\n";
cout<<" hex " << hex << num << "\n";
cout<<" oct " << oct << num << "\n";

cout << " ======================================== "<<" \n";

cout<<resetiosflags( std::ios::showbase);
cout<<" dec " << dec << num << "\n";
cout<<" hex " << hex << num << "\n";
cout<<" oct " << oct << num << "\n";

cout << " ======================================== "<<" \n";

cout<<setiosflags(std::ios::showpos); // showpos show NO +ve or -ve
cout<<" dec " << dec << num << "\n";
cout<<" hex " << hex << num << "\n";
cout<<" oct " << oct << num << "\n";

int N {84}; 
int P {-95};

cout.setf(std::ios::showbase);
cout.setf(std::ios::uppercase);
cout.setf(std::ios::showpos);

cout<<" dec " << dec << N << "\n";
cout<<" hex " << hex << N << "\n";
cout<<" oct " << oct << N << "\n";

cout << " ======================================== "<<" \n";

cout<<" dec " << dec << P << "\n";
cout<<" hex " << hex << P << "\n";
cout<<" oct " << oct << P << "\n";


}