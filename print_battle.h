#ifndef PRINT_BATTLE_H
#define PRINT_BATTLE_H

using namespace std;

double Poke_Attack_Bonus(pokemon current_Mypokemons, pokemon current_Rivalpokemons);
double Poke_Attack(pokemon current_Attpokemons, pokemon current_Defpokemons);
void damage_calculation(pokemon &current_Defpokemons, double Dmg_dealt);
void print_attk_sentence(pokemon current_Mypokemons, pokemon current_Rivalpokemons);
void dmg_deal_term_A_to_B(pokemon &current_Mypokemons, pokemon &current_Rivalpokemons, double Dmg_dealt);
void switch_current_pokemon(pokemon_group Mypokemons, pokemon &current_Mypokemons, int &counter);
void receive_input(string &option);
void switch_fainted_pokemon(pokemon_group &Mypokemons, pokemon_group &Rivalpokemons, pokemon &current_Mypokemons, pokemon &current_Rivalpokemons, int &mycounter, int &rivalcounter);
void heal(pokemon_group &ypokemons, pokemon &current_Mypokemons, int &counter);
void print_match_start();
void print_battle_1stcolumn();
void print_battle_2ndcolumn();
void print_match_result(int mycounter,int rivalcounter);
void print_battle(pokemon Mypokemons,pokemon Rivalpokemons);


#endif
