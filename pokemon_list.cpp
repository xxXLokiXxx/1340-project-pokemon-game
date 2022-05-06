#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include <fstream>
#include <sstream>

using namespace std;


void read_list() {
    ifstream fin;
	   fin.open("pokemon_list.txt");

	if ( fin.fail() ){
		cout << "Error in file opening!" << endl;
 		exit(1);
	}

    string line;
	string name;
    while (getline(fin, line)){
      pokemon p();
      istringstream iss(line);
      iss >> name >> p.Number >> p.Name >>p.Type1 ;
      getline(fin, line);
	istringstream iss(line);
      iss >> p.Type2 >>p.Total >> p.HP >> p.Attack >>p.Defense>>p.Spatk>>p.Spdef>>p.Speed ;
      pokemons.push_back(p)
    }

    fin.close();

	return 0;
}
