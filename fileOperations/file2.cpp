#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

struct city
{
   string name;
   int population; 
};
struct country
{
    string title;
    vector<city> cities;
};

struct tours
{
   string vacation;
   vector<country> countries;

};



int main()
{

  tours tour
  {
   " my vacation",
  {
  {"india",
  {{"bangalore",700000000},{"hyderabad", 500000000},{"Pune",30000000}}
  },
  {"soudiarebia",
  {{"dubai",400000000},{"makkaa", 300000000},{"mdiana",20000000}}
  }
  }
  };

  cout<< setw(20)<<""<< tour.vacation << " \n";
  cout<<"\n";
  cout<< setw(10) << right << "Country";
  cout<< setw(10) << right << "City";
  cout<< setw(20) << right<< "Population";
  cout<< " \n";
  for( auto country : tour.countries)
  {  
     cout<<setw(10)<<right<<country.title;
     for(auto city : country.cities)
     {
        cout<<"\n"<< setw(25) << right<< city.name << setw(15) <<right<<city.population;
     }
     cout<< " \n";
  }


}