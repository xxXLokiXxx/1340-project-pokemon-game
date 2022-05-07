#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include <fstream>
#include <sstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#include "pokemon_struct.h"
#include "pokemon_list_input.h"


void read_list() {
  
  ifstream fin;
	fin.open("pokemon_list.txt");

	if ( fin.fail() ){
		cout << "Error in file opening!" << endl;
 		exit(1);
	}

  string line;
	string name;

  pokemon p;
  pokemons.push_back(p);

  while (getline(fin, line)){
    pokemon p;
    istringstream iss(line);
    iss >> name >> p.Number >> p.Name >>p.Type1;
    getline(fin, line);
	  istringstream iss2(line);
    iss2 >> p.Type2 >> p.Total >> p.HP >> p.Attack >> p.Defense >> p.SpAtk >> p.SpDef >> p.Speed;
    pokemons.push_back(p);
  }
  fin.close();
//  for (int i = 0; i < 152; i++ ) {
//    cout << pokemons[i].Number << "  " << pokemons[i].Name << "  " << pokemons[i].Type1 << endl;
//  }
}
