#ifndef  _POKEMON_LIST_H_   
#define _POKEMON_LIST_H_  
#include<string>
#include<vector>

 // data of pokemon
struct pokemon {
  int Number;
  string Name;
  string Type1;
  string Type2;
  int Total;
  int HP;
  int Attack;
  int Defense;
  int SpAtk;
  int SpDef;
  int Speed;
};
vector<pokemon> pokemons;
void read_list();

//groups of maximum 6 pokemon own by player and enemy
struct pokemon_group {
    int A ;int A_lv  ;
    int B ;int B_lv ;
    int C  ;int C_lv  ;
    int D  ;int D_lv  ;
    int E ;int E_lv  ;
    int F  ;int F_lv  ;
};
pokemon_group Mypokemons;
pokemon_group Rivalpokemons;
 
 #endif    
