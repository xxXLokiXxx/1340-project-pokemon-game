# 1340-project-pokemon-game
------


Identification of the team member
  Group member: Lo Lok Fung
  
  
## Game description and rules

It will be a C++ program game based off of Pokemon's combat system.
![This is an image](https://static.wikia.nocookie.net/essentialsdocs/images/7/70/Battle.png/revision/latest?cb=20190219202514)!

Battling system is the highlight of the whole pokemon game. Trainers can test out their pokemons' strength by fightning with other's pokemon. The pokemon game is known to be one of the most nostalgic game in console gaming history, with the distinctive and spactacular pokemon fighting system interface.

The rules are somehow similar to the rule of original battling system. The Pokémon battling system is turn-based. When the player challenges a Trainer or encounters a wild Pokémon, the screen changes to a battle scene with the player's Pokémon, the opposing Pokémon, their respective HP and an option menu. At any time, the player may carry up to six Pokémon in his or her active party; the first Pokémon in the lineup is automatically sent into battle. 

Our game will bascially minic the original game play flow of Pokemon battling scenes, with some kinds of creativity and variances implemented in the game. Our game allows player to choose 6 pokemons as his/her pokemon squad to fight. They can choose from all pokemons in generation 1. The pokemons stats and battle power are implemented to the codes and the stats are official stats from the pokemon website and the actual game. This allows the game to be more realistic and similiar to the actual game, so that the pokemon fans can enjoy the pokemon world that they are accustomed to. 

After choosing pokemons, players can fight with the opponent(NPC) with its 6 randomised choices of pokemons. Also, the game allows options for the player to attack and heal to fight with NPC's pokemons. Be aware that certain types of pokemons can counter certain types of pokemons. When your pokemons defeat all 6 opponent's pokemons, you win! If the opponent do that to you, you lose!

## A list of features in game

### 1. Pokemon selection and randomization ###

You can choose 6 pokemons from generation 1 to fight for you. The list of all pokemons in generation 1 is provided with ids and names. The name of each pokemon you choose will appear on the screen as well as its combat power. Besides, you can also randomised your choices of pokemon from 151 gen 1 pokemon to give you a bit of challenge to play with NPC/the computer! Also, the computer's 6 pokemons are randomised too!

### 2. Damage dealing system ###

The damage system is as follows. Amount of damage points will be shown on screen after the attack move is done. Damages done by pokemons depends on the randomisation and the attack stats of the pokemon. The damage points are randomised in the range from 0 to the damage stat of the pokemon as the upper limit. So the stronger the pokemon, the more damage it is likely to deal to the opponent. I've tested out with this range of randomisation, playability is at maximum, so that pokemons won't be always one-shotted or stay too long to the point that makes the game boring. 

### 3. Hp healing system ###

Healing option is available during battling. Amount of HP points healed will be shown on screen after the attack move is done. Hp healed by pokemons depends current pokemon HP and the original HP of the pokemon. The HP points healed are randomised in the range from 0 to the "difference between the original HP of the pokemon and the current pokemon HP" as the upper limit. Therefore, it is more favored to heal when you are in low health, as there is a higher chance to have more HP points healed. It is more favored to heal when the opponent attack is less effective to you. 

### 4. Pokémon types system ###

Types of pokemons and the type countering system are strictly followed to the offcial pokemon type system.
Link for more info of the type: https://pokemondb.net/type .

For certain types of pokemons that counter other types of pokemons, the attack damage points are mulitiplied by 1.5 times and 2 time. The advantages will be shown as " The attack is very effective." will be printed out on screen. On the other hand, " The attack is not very effective." will be printed out if it's not effective, attack points may be mulitpied by 0.5 according to the types of pokemons.

### 5. Quitting in mid-game ###

Escaping is always an option for quitters!

Coding Elements
--
### Generation of random game sets or events ###

Randomisation of the game is demostrated in three ways:
* Chooing pokemons:
    * For the start of the game, player can choose the option to randomise his or her choices of pokemons. 6 pokemons are chosen 
      randomly from 151 pokemons in gen 1 for player to bring to the battle. Opponents pokemons are randomised automatically.
      
* Attack Damages:
    * The damage points are randomised in the range from 0 to the damage stat of the pokemon as the upper limit. So the stronger       the pokemon, the more damage it is likely to deal to the opponent. This is applied to both opponent and the player. 
    
* Healing Damages:
    * The HP points healed are randomised in the range from 0 to the "difference between the original HP of the pokemon and the
      current pokemon HP" as the upper limit. This is available only to the player due to the maintainance of game balance.
      
  
### Data structures for storing game status ###

Inside the "pokemon" struct, stats of a pokemon will be stored, including:

  * integer form of Number (id of pokemon)
  * string form of Name (name of pokemon)
  * string Type1 (dominant type of pokemon)
  * string Type2; (sub-type of pokemon)
  * integer form of Total (Combat power of pokemon, to compare which pokemon is more powerful)
  * integer form of HP (HP of pokemon)
  * integer form of Attack (Attack stat of pokemon)
  * integer form of Defense (Defense stat of pokemon, not used in the the current game, could be used in future development/update version)
  * integer form of SpAtk (Special attack stat of pokemon, not used in the the current game, could be used in future development)
  * integer form of SpDef (Special defence stat of pokemon, not used in the the current game, could be used in future development)
  * integer form of Speed (Speed of pokemon, not used in the the current game, could be used in future development/update version)

Inside the "pokemon_group" struct, pokemon structs will be included (nested struct), representing the 6 pokemons (from A to F) brought to battle:

  * pokemon A 
  * pokemon B 
  * pokemon C 
  * pokemon D 
  * pokemon E 
  * pokemon F 
  
### Dynamic memory management ###

* Struct vectors are used to store 151 "pokemon" struct (gen 1 pokemons stats) instead of arrays.

* 2D vectors are used to store pokemon type chart instead of 2D arrays. Push_back function is used to construct the 2D vectors.     The elements in 2D vectors follow the order of "NORMAL", "FIRE", "WATER", "ELECTRIC", "GRASS", "ICE", "FIGHTING", "POISON",       "GROUND", "FLYING", "PSYCHIC", "BUG" ,"ROCK", "GHOST", "DRAGON" ,"DARK" ,"STEEL", "FAIRY".

* Since new/malloc functions aren't used, memories don't have to be freed afterwards.

### File input/output (e.g., for loading/saving game status) ###

The program takes input of a text file (pokemon_list.txt), which contains the stats of all 151 gen 1 pokemons. This file input feature allows update for future pokemons (gen 2, 3, 4), or allows the easy modification of stats of certain pokemons.

### Program codes in multiple files ###

The program codes are segemented into different files, including:

* file of main game code (pokemon_main.cpp)
* file of generation of pokemon and battle preperation (pokemon_gen_prep.cpp)
  * Header file (pokemon_gen_prep.h)
* header file of struct and nested struct (pokemon_struct.h)
* file of pokemon battle (print_battle.cpp)
  * Header file (print_battle.h)
* file of input input of pokemon stats (pokemon_list_input.cpp)
  * Header file (pokemon_list_input.h)
* text file of the stats of all 151 gen 1 pokemons (pokemon_list.txt)

## Compile Instruction
----
Run ```make game``` for compilation of the game. Enter ```./game``` in order to start the game.

