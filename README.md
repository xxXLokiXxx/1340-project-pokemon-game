# 1340-project-pokemon-game
------


Identification of the team member
  Group member: Lo Lok Fung
  
  
Game description
-- 
It will be a C/C++ program game based off of Pokemon rpg game's combat system.
![This is an image](https://static.wikia.nocookie.net/essentialsdocs/images/7/70/Battle.png/revision/latest?cb=20190219202514)!

Battling system is the highlight of the whole pokemon game. Trainers can raise their pokemons' levels via repetitive battles against pokemons from another trainers. The higher level the pokemons reach, the stronger they get, and this provides satisfaction for the players roleplaying pokemon trainers as they grow stronger and stronger with their pokemons throughout the game.


The Pokémon battling system is turn-based. When the player challenges a Trainer or encounters a wild Pokémon, the screen changes to a battle scene with the player's 
Pokémon, the opposing Pokémon, their respective HP bars and an option menu. At any time, the player may carry up to six Pokémon in his or her active party; the first 
Pokémon in the lineup is automatically sent into battle. At the start of each turn, both sides can choose to attack, use an item, switch the Pokémon for another in 
their party or attempt to flee from battle (against a wild Pokémon). If both sides attack, the one who goes first is determined by Speed, although some moves, items 
and effects can override this. If either side chooses any other option, that action is performed before the attacks. (From wiki)

Introduction of the game rules
--
Our game will bascially minic the original game play flow of Pokemon battling scenes. The rules will basically follow the rule of original battling system.

A list of features in game
-- 
1.Pokemon selection
2.Skills selection
3.Damage dealing system
4.Double and Multi Battles
5.Pokémon types system

Coding Elements
-- 
Generation of random game sets or events
--
Random set of pokemons of the enemy.
Random lv of pokemons of the enemy.

Data structures for storing game status
--
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

Dynamic memory management
-- 
struct vectors are used to store pokemon status instead of arrays
2d vectors are used to store pokemon type chart instead of 2d arrays

File input/output (e.g., for loading/saving game status)
--
Store location of player, set of pokemon ,status of pokemon.???
3 slots of save/load are available by game status commands.

Program codes in multiple files
-- 
file of main game code
file of map
file of battle system
file of pokemon library
files of saving and loading

Proper indentation and naming styles
--

In-code documentation
--
