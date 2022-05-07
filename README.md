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

### 1.Pokemon selection and randomization ###

You can choose 6 pokemons from generation 1 to fight for you. The list of all pokemons in generation 1 is provided with ids and names. The name of each pokemon you choose will appear on the screen as well as its combat power. Besides, you can also randomised your choices of pokemon from 151 gen 1 pokemon to give you a bit of challenge to play with NPC/the compputer! Also, the computer's 6 pokemons are randomised too!

### 2.Damage dealing system ###

The damage system is as follows. Amount of damage points will be shown on screen after the attack move is done. Damages done by pokemons depends on the randomisation and the attack stats of the pokemon. The damage points are randomised in the range from 0 to the damage stat of the pokemon as the upper limit. So the stronger the pokemon, the more damage it is likely to deal to the opponent. I've tested out with this range of randomisation, playability is at maximum, so that pokemons won't be always one-shotted or stay too long to the point that makes the game boring. 

### 3.Hp healing system ###

Healing option is available during battling. Amount of HP points healed will be shown on screen after the attack move is done. Hp healed by pokemons depends current pokemon HP and the original HP of the pokemon. The HP points healed are randomised in the range from 0 to the "difference between the original HP of the pokemon and the current pokemon HP" as the upper limit. Therefore, it is more favored to heal when you are in low health, as there is a higher chance to have more HP points healed. It is more favored to heal when the opponent attack is less effective to you. 

### 4.Pokémon types system ###

Types of pokemons and the type countering system are strictly followed to the offcial pokemon type system.
Link for more info of the type: https://pokemondb.net/type .
For certain types of pokemons that counter other types of pokemons, the attack damage points are mulitiplied by 1.5 times and 2 time. The advantages will be shown as " The attack is very effective." will be printed out on screen. On the other hand, " The attack is not very effective." will be printed out if it's not effective, attack points may be mulitpied by 0.5 according to the types of pokemons.

### 5.Quitting in mid-game ###

Escaping is always an option for quitters!

Coding Elements
--
### Generation of random game sets or events ###

Randomisation of the game is demostrated in three ways:
* Bullet list
    * Nested bullet
        *
* Chooing pokemons:
--
   For the start of the game, player can choose the option to randomise his or her choices of pokemons. 6 pokemons are chosen 
   randomly from 151 pokemons in gen 1 for player to bring to the battle. Opponents pokemons are randomised automatically.
   
* Attack Damages:
--
  The damage points are randomised in the range from 0 to the damage stat of the pokemon as the upper limit. So the stronger the   pokemon, the more damage it is likely to deal to the opponent. This is applied to both opponent and the player. 
  
* Healing Damages
--
  The HP points healed are randomised in the range from 0 to the "difference between the original HP of the pokemon and the
  current pokemon HP" as the upper limit. This is available only to the player due to the maintainance of game balance.
  
### Data structures for storing game status ###

vector for library of pokemons.
structs for pokemons' battling indexes. 
eg:
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

### Dynamic memory management ###

struct vectors are used to store pokemon status instead of arrays
2d vectors are used to store pokemon type chart instead of 2d arrays

### File input/output (e.g., for loading/saving game status) ###

Store location of player, set of pokemon ,status of pokemon.???
3 slots of save/load are available by game status commands.

### Program codes in multiple files ###

file of main game code
file of map
file of battle system
file of pokemon library
files of saving and loading

### Proper indentation and naming styles ###


### In-code documentation ###

