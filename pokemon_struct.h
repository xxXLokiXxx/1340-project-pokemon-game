#ifndef POKEMON_STRUCT_H
#define POKEMON_STRUCT_H
#include<string>
#include<vector>
using namespace std;
// data of pokemon                
struct pokemon {             // stats of pokemon will be stored in a struct 
  int Number;
  string Name;               // the structs declared in header file
  string Type1;
  string Type2;
  int Total;
  double HP;
  int Attack;
  int Defense;
  int SpAtk;
  int SpDef;
  int Speed;
};

//groups of maximum 6 pokemon own by player and enemy
struct pokemon_group {
  pokemon A ;
  pokemon B ;           // structs of pokemons chosen will be stored in a struct (nested struct)
  pokemon C ;
  pokemon D ;
  pokemon E ;
  pokemon F ;
};

extern vector<pokemon> pokemons;       //declare of vector named pokemons, structs of Mypokemons and Rivalpokemons named are declared
extern pokemon_group Mypokemons;
extern pokemon_group Rivalpokemons;


#endif
