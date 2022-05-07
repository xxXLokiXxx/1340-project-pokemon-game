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
#include "print_battle.h"
#include "pokemon_gen_prep.h"

pokemon_group Mypokemons;
pokemon_group Rivalpokemons;

int main() {
  read_list();                //function call list of gen one pokemon printed 
  listing_allpoke();
  string opt;
  cout << "Enter \"Y\" to choose pokemons by yourself to battle. Enter \"N\" to randomly select pokemons to you." << endl;  // user choose self selection or random generation of pokemons
  cout << "Your choice: ";
  while (opt != "Y" && opt != "N") {
    cin >> opt;
    if (opt == "Y")
      generate_self_poke(Mypokemons);
    else if (opt == "N")
      rand_ipokemons(Mypokemons);
    else
      cout << "Invalid input!" << endl;
  }
  rand_pokemons(Rivalpokemons);       //function call to generate opponents pokemons 
  print_ours_pokemon(Mypokemons);
  print_oppo_pokemon(Rivalpokemons);       // print each sides pokemons

  ///battle_start///
  pokemon current_Mypokemons= Mypokemons.A;
  pokemon current_Rivalpokemons= Rivalpokemons.A;
  print_match_start();                                 //function call to print interface
  print_battle(current_Mypokemons,current_Rivalpokemons);

  string option;
  double Dmg_dealt;
  int mycounter = 0, rivalcounter = 0;

  while ((mycounter != 6) && (rivalcounter != 6)) {           //while loop to continue battling till one side or two sides' pokemons all fainted
    receive_input(option);

    if (option == "A") {       // user chose A, to attact opponent
      print_battle_1stcolumn();
      dmg_deal_term_A_to_B(current_Rivalpokemons, current_Mypokemons, Dmg_dealt);
      cout << endl;
      dmg_deal_term_A_to_B(current_Mypokemons, current_Rivalpokemons, Dmg_dealt);
      switch_fainted_pokemon(Mypokemons, Rivalpokemons, current_Mypokemons, current_Rivalpokemons, mycounter, rivalcounter);
      print_battle_2ndcolumn();
      print_battle(current_Mypokemons,current_Rivalpokemons);
    }
    else if (option == "B") {    // user choose B, to heal
      print_battle_1stcolumn();
      heal(Mypokemons, current_Mypokemons, mycounter);
      cout << endl;
      dmg_deal_term_A_to_B(current_Rivalpokemons, current_Mypokemons, Dmg_dealt);
      switch_fainted_pokemon(Mypokemons, Rivalpokemons, current_Mypokemons, current_Rivalpokemons, mycounter, rivalcounter);
      print_battle_2ndcolumn();
      print_battle(current_Mypokemons,current_Rivalpokemons);
    }
    else if (option == "D") {
      cout << "You escaped!" << endl;     // user choose D to escape
      break;
    }
    else {
      cout << "Invalid input. Please only enter A/B/D!" << endl;
    }
  }
  print_match_result(mycounter,rivalcounter);     // function call to print who win and match results
}
