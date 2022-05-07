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


void read_list() {       // function to read a text file (pokemon_list.txt), so stats of 151 gen 1 pokemons inputted in program
  
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

  while (getline(fin, line)){           // read a line 
    pokemon p;
    istringstream iss(line);
    iss >> name >> p.Number >> p.Name >>p.Type1;      // store the stats of the one pokemon in the line to the struct of pokemon
    getline(fin, line);               // read another line 
	  istringstream iss2(line);
    iss2 >> p.Type2 >> p.Total >> p.HP >> p.Attack >> p.Defense >> p.SpAtk >> p.SpDef >> p.Speed; // store the stats of the one pokemon in the another line to the struct of pokemon
    pokemons.push_back(p);          // finish storing the stats of the one pokemon and the one pokemon struct is pushed back to the vector of pokemons
  }                  // loop through and stored all 151 pokemons stats
  fin.close();
//  for (int i = 0; i < 152; i++ ) {              // hidden codes for print debugging to see if the stats are read and stored
//    cout << pokemons[i].Number << "  " << pokemons[i].Name << "  " << pokemons[i].Type1 << endl;
//  }
}
