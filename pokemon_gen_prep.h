#ifndef POKEMON_GEN_PREP_H
#define POKEMON_GEN_PREP_H
#include <string>
#include <vector>

using namespace std;      

void catch_poke_input(int &poke_chosen_id);                   //function declaration done in header files
void listing_allpoke();
void generate_self_poke(pokemon_group &Mypokemons);
void print_ours_pokemon(pokemon_group Rivalpokemons);
void print_oppo_pokemon(pokemon_group Rivalpokemons);
void rand_pokemons(pokemon_group &kemons);
void rand_ipokemons(pokemon_group &kemons);

#endif
