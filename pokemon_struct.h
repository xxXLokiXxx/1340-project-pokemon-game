#ifndef POKEMON_STRUCT_H
#define POKEMON_STRUCT_H
#include<string>
#include<vector>
using namespace std;
// data of pokemon
struct pokemon {
  int Number;
  string Name;
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
  pokemon B ;
  pokemon C ;
  pokemon D ;
  pokemon E ;
  pokemon F ;
};

extern vector<pokemon> pokemons;
extern pokemon_group Mypokemons;
extern pokemon_group Rivalpokemons;


#endif
