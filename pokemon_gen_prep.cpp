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

#include "pokemon_struct.h"
#include "pokemon_gen_prep.h"

using namespace std;

vector<pokemon> pokemons;

void catch_poke_input(int &poke_chosen_id) {    // To only allow id of 1-151 pokemons be selected (input is id entered by user)
  cin >> poke_chosen_id;
  while (poke_chosen_id > 151 || poke_chosen_id < 1 ) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input! Please choose pokemon id from 1 to 151!" << endl;
    cout << "Try again: ";
    cin >> poke_chosen_id;
  }
}

void listing_allpoke(){                                           // function to list all the gen 1 pokemon with their ids and names
  cout << "Welcome to Pokemon battling system !!" << endl << endl;
  cout << "A list of 1st gen pokemon available (id<->name):" << endl;
  for (int i = 1; i < 152; i++ ) {
    if ((i % 5) == 0) {                                 //for loop to loop through pokemons, 5 pokemons printed out per line
      cout << "   " << setw(3)  << pokemons[i].Number << setw(12) << setfill(' ') << pokemons[i].Name << endl;
    }
    else {
      cout << "   " << setw(3)  << pokemons[i].Number << setw(12) << setfill(' ')  << pokemons[i].Name;
    }
  }
  cout << endl << endl;
}

void generate_self_poke(pokemon_group &Mypokemons) {   //To put pokemon chosen by user to the struct of my pokemons
  int poke_chosen_id = 1;                              // input is the struct of Mypokemons (space for collection of user's 6 pokemons)
  cout << "Choose your first pokemon in your squad (Enter the id of pokemon to choose): ";
  catch_poke_input(poke_chosen_id);                      // ask for input of desired pokemons
  Mypokemons.A = pokemons[poke_chosen_id];
  cout << "You chose" << " " << Mypokemons.A.Name << "! (Combat power: " << Mypokemons.A.Total << ")" <<endl << endl;

  cout << "Choose your second pokemon in your squad (Enter the id of pokemon to choose): ";
  catch_poke_input(poke_chosen_id);
  Mypokemons.B = pokemons[poke_chosen_id];
  cout << "You chose" << " " << Mypokemons.B.Name << "! (Combat power: " << Mypokemons.B.Total << ")" <<endl<< endl;

  cout << "Choose your third pokemon in your squad (Enter the id of pokemon to choose): ";
  catch_poke_input(poke_chosen_id);
  Mypokemons.C = pokemons[poke_chosen_id];
  cout << "You chose" << " " << Mypokemons.C.Name << "! (Combat power: " << Mypokemons.C.Total << ")" <<endl<< endl;

  cout << "Choose your fourth pokemon in your squad (Enter the id of pokemon to choose): ";
  catch_poke_input(poke_chosen_id);
  Mypokemons.D = pokemons[poke_chosen_id];
  cout << "You chose" << " " << Mypokemons.D.Name << "! (Combat power: " << Mypokemons.D.Total << ")" <<endl<< endl;

  cout << "Choose your fifth pokemon in your squad (Enter the id of pokemon to choose): ";
  catch_poke_input( poke_chosen_id);
  Mypokemons.E = pokemons[poke_chosen_id];
  cout << "You chose" << " " << Mypokemons.E.Name << "! (Combat power: " << Mypokemons.E.Total << ")" <<endl<< endl;

  cout << "Choose your sixth pokemon in your squad (Enter the id of pokemon to choose): ";
  catch_poke_input(poke_chosen_id);
  Mypokemons.F = pokemons[poke_chosen_id];
  cout << "You chose" << " " << Mypokemons.F.Name << "! (Combat power: " << Mypokemons.F.Total << ")" <<endl<< endl;
  cout << endl << endl << endl;
}

void print_ours_pokemon(pokemon_group Rivalpokemons) {
  cout << endl;                                   // input struct of my pokemosn to print out each of users' pokemons name and combat power
  cout << "The list of your pokemons: " << endl <<endl;
  cout << setw(12) <<  "First pokemon:" << " " << Rivalpokemons.A.Name << "! (Combat power: " << Rivalpokemons.A.Total << ")" <<endl;
  cout << setw(12) <<  "Second pokemon:" << " " << Rivalpokemons.B.Name << "! (Combat power: " << Rivalpokemons.B.Total << ")" <<endl;
  cout << setw(12) <<  "Third pokemon:" << " " << Rivalpokemons.C.Name << "! (Combat power: " << Rivalpokemons.C.Total << ")" <<endl;
  cout << setw(12) <<  "Fourth pokemon:" << " " << Rivalpokemons.D.Name << "! (Combat power: " << Rivalpokemons.D.Total << ")" <<endl;
  cout << setw(12) <<  "Fifth pokemon:" << " " << Rivalpokemons.E.Name << "! (Combat power: " << Rivalpokemons.E.Total << ")" <<endl;
  cout << setw(12) <<  "Sixth pokemon:" << " " << Rivalpokemons.F.Name << "! (Combat power: " << Rivalpokemons.F.Total << ")" <<endl;
  cout << endl;
}

void print_oppo_pokemon(pokemon_group Rivalpokemons) {  // input struct of opponent pokemons to print out each of opponents' pokemons name and combat power
  cout << "The list of opponent pokemons: " << endl <<endl;
  cout << setw(12) <<  "First pokemon:" << " " << Rivalpokemons.A.Name << "! (Combat power: " << Rivalpokemons.A.Total << ")" <<endl;
  cout << setw(12) <<  "Second pokemon:" << " " << Rivalpokemons.B.Name << "! (Combat power: " << Rivalpokemons.B.Total << ")" <<endl;
  cout << setw(12) <<  "Third pokemon:" << " " << Rivalpokemons.C.Name << "! (Combat power: " << Rivalpokemons.C.Total << ")" <<endl;
  cout << setw(12) <<  "Fourth pokemon:" << " " << Rivalpokemons.D.Name << "! (Combat power: " << Rivalpokemons.D.Total << ")" <<endl;
  cout << setw(12) <<  "Fifth pokemon:" << " " << Rivalpokemons.E.Name << "! (Combat power: " << Rivalpokemons.E.Total << ")" <<endl;
  cout << setw(12) <<  "Sixth pokemon:" << " " << Rivalpokemons.F.Name << "! (Combat power: " << Rivalpokemons.F.Total << ")" <<endl;
  cout << endl;
}

void rand_pokemons(pokemon_group &kemons) {     //input of a struct of nested struct of pokemons (collection of pokemons)
  srand(time(NULL));
  kemons.A = pokemons[(rand() % 151) + 1];      //random generate a set of pokemon by seed of time
  kemons.B = pokemons[(rand() % 151) + 1];
  kemons.C = pokemons[(rand() % 151) + 1];
  kemons.D = pokemons[(rand() % 151) + 1];
  kemons.E = pokemons[(rand() % 151) + 1];
  kemons.F = pokemons[(rand() % 151) + 1];
}

void rand_ipokemons(pokemon_group &kemons) {   //random generate a set of pokemon by another seed of time*time, so no replication of pokemon
  srand(time(NULL)*time(NULL));
  kemons.A = pokemons[(rand() % 151) + 1];
  kemons.B = pokemons[(rand() % 151) + 1];
  kemons.C = pokemons[(rand() % 151) + 1];
  kemons.D = pokemons[(rand() % 151) + 1];
  kemons.E = pokemons[(rand() % 151) + 1];
  kemons.F = pokemons[(rand() % 151) + 1];
}
