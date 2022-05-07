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
#include "print_battle.h"

double Poke_Attack_Bonus(pokemon current_Mypokemons, pokemon current_Rivalpokemons) {

// 	string a ="" ,b= "" ,c="";
 int key0,key1,key2,count=0;
vector<string> TYPE = {"NORMAL", "FIRE", "WATER", "ELECTRIC", "GRASS", "ICE", "FIGHTING", "POISON", "GROUND", "FLYING", "PSYCHIC", "BUG" ,"ROCK", "GHOST", "DRAGON" ,"DARK" ,"STEEL", "FAIRY"};

for (count=0; count<18; count++) {
  if( current_Mypokemons.Type1 == TYPE[count] ){
           key0 = count ;
  }
	if( current_Rivalpokemons.Type1 == TYPE[count] ){
           key1 = count ;
  }
	if( current_Rivalpokemons.Type2 == TYPE[count] ){
           key2 = count ;
  }
}
 vector<vector<double>> Chart ; // 2d vector
   Chart.push_back ({1,1,1,1,1,1,1,1,1,1,1,1,0.5,0,1,1,0.5,1});
   Chart.push_back 	({1,0.5,0.5,1,2,2,1,1,1,1,1,2,0.5,1,0.5,1,2,1});
   Chart.push_back 	({1,2,0.5,1,0.5,1,1,1,2,1,1,1,2,1,0.5,1,1,1});
   Chart.push_back  (	{1,1,2,0.5,0.5,1,1,1,0,2,1,1,1,1,0.5,1,1,1});
   Chart.push_back (	{1,0.5,2,1,0.5,1,1,0.5,2,0.5,1,0.5,2,1,0.5,1,0.5,1});

   Chart.push_back  (	{1,0.5,0.5,1,2,0.5,1,1,2,2,1,1,1,1,2,1,0.5,1});
   Chart.push_back  (	{2,1,1,1,1,2,1,0.5,1,0.5,0.5,0.5,2,0,1,2,2,0.5});
   Chart.push_back 	( {1,1,1,1,2,1,1,0.5,0.5,1,1,1,0.5,0.5,1,1,0,2});
   Chart.push_back 	( {1,2,1,2,0.5,1,1,2,1,0,1,0.5,2,1,1,1,2,1});
   Chart.push_back (	 {1,1,1,0.5,2,1,2,1,1,1,1,2,0.5,1,1,1,0.5,1});

   Chart.push_back 	( {1,1,1,1,1,1,2,2,1,1,0.5,1,1,1,1,0,0.5,1});
   Chart.push_back 	( {1,0.5,1,1,2,1,0.5,0.5,1,0.5,2,1,1,0.5,1,2,0.5,0.5});
   Chart.push_back(	{1,2,1,1,1,2,0.5,1,0.5,2,1,2,1,1,1,1,0.5,1});
   Chart.push_back (	{0,1,1,1,1,1,1,1,1,1,2,1,1,2,1,0.5,1,1});
   Chart.push_back (	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,0.5,0});

   Chart.push_back	( {1,1,1,1,1,1,0.5,1,1,1,2,1,1,2,1,0.5,1,0.5});
   Chart.push_back 	({1,0.5,0.5,0.5,1,2,1,1,1,1,1,1,2,1,1,1,0.5,2});
   Chart.push_back	 ({1,0.5,1,1,1,1,2,0.5,1,1,1,1,1,1,2,2,0.5,1});
//   cout<<Chart[16][5];
	if( current_Rivalpokemons.Type2 == "NULL" ){
// 	   if (Chart[key0][key1] == 2)
// 		cout <<"Super effective"<<endl;
           return Chart[key0][key1] ;}
	else {
           return Chart[key0][key1]*Chart[key0][key2] ;}
}

double Poke_Attack(pokemon current_Attpokemons, pokemon current_Defpokemons) {
  double attack_bonus = Poke_Attack_Bonus(current_Attpokemons, current_Defpokemons);
  srand(time(NULL));
  double org_attack = (rand() % (current_Attpokemons.Attack));
  return (attack_bonus*org_attack);
}

void damage_calculation(pokemon &current_Defpokemons, double Dmg_dealt) {
  if (current_Defpokemons.HP <= Dmg_dealt) {
    current_Defpokemons.HP = 0;
    cout << current_Defpokemons.Name << " fainted!" << endl;
  }
  else {
    current_Defpokemons.HP -= Dmg_dealt;
  }
}

void print_attk_sentence(pokemon current_Mypokemons, pokemon current_Rivalpokemons) {
  cout << current_Mypokemons.Name << " did " << Poke_Attack(current_Mypokemons, current_Rivalpokemons) << " points of damage to " << current_Rivalpokemons.Name << "!" << endl;
  if (Poke_Attack_Bonus(current_Mypokemons, current_Rivalpokemons) > 1)
    cout << "It was very effective!" << endl;
  else if (Poke_Attack_Bonus(current_Mypokemons, current_Rivalpokemons) < 1)
    cout << "It was not effective!" << endl;
}

void dmg_deal_term_A_to_B(pokemon &current_Mypokemons, pokemon &current_Rivalpokemons, double Dmg_dealt) {
  Dmg_dealt = Poke_Attack(current_Mypokemons, current_Rivalpokemons);
  print_attk_sentence(current_Mypokemons, current_Rivalpokemons);
  damage_calculation(current_Rivalpokemons, Dmg_dealt);
}

void switch_current_pokemon(pokemon_group Mypokemons, pokemon &current_Mypokemons, int &counter) {
  if (counter==0)
    current_Mypokemons = Mypokemons.B;
  else if (counter==1)
    current_Mypokemons = Mypokemons.C;
  else if (counter==2)
    current_Mypokemons = Mypokemons.D;
  else if (counter==3)
    current_Mypokemons = Mypokemons.E;
  else if (counter==4)
    current_Mypokemons = Mypokemons.F;
  counter++;
}

void receive_input(string &option) {
  cout << "What choice would you choose? (Enter A/B/D): ";
  cin >> option;
}

void switch_fainted_pokemon(pokemon_group &Mypokemons, pokemon_group &Rivalpokemons, pokemon &current_Mypokemons, pokemon &current_Rivalpokemons, int &mycounter, int &rivalcounter) {
  if ((current_Mypokemons.HP == 0) && (current_Rivalpokemons.HP == 0)) {
    switch_current_pokemon(Mypokemons, current_Mypokemons, mycounter);
    switch_current_pokemon(Rivalpokemons, current_Rivalpokemons, rivalcounter);
  }
  else if (current_Mypokemons.HP == 0) {
    switch_current_pokemon(Mypokemons, current_Mypokemons, mycounter);
  }
  else if (current_Rivalpokemons.HP == 0) {
    switch_current_pokemon(Rivalpokemons, current_Rivalpokemons, rivalcounter);
  }
}

void heal(pokemon_group &ypokemons, pokemon &current_Mypokemons, int &counter) {
  srand(time(NULL));
  int healamount=0;

  if (counter==0) {
    healamount = rand()%(int(ypokemons.A.HP-current_Mypokemons.HP)+1);
    current_Mypokemons.HP += healamount;
  }
  else if (counter==1) {
    healamount = rand()%(int(ypokemons.B.HP-current_Mypokemons.HP)+1);
    current_Mypokemons.HP += healamount;
  }
  else if (counter==2) {
    healamount = rand()%(int(ypokemons.C.HP-current_Mypokemons.HP)+1);
    current_Mypokemons.HP += healamount;
  }
  else if (counter==3) {
    healamount = rand()%(int(ypokemons.D.HP-current_Mypokemons.HP)+1);
    current_Mypokemons.HP += healamount;
  }
  else if (counter==4) {
    healamount = rand()%(int(ypokemons.E.HP-current_Mypokemons.HP)+1);
    current_Mypokemons.HP += healamount;
  }
  else if (counter==5) {
    healamount = rand()%(int(ypokemons.F.HP-current_Mypokemons.HP)+1);
    current_Mypokemons.HP += healamount;
  }
  cout << "Your " << current_Mypokemons.Name << " just healed for " << healamount << " points!" << endl;
}

void print_match_start() {
  cout << endl << endl;
  cout << "═════════════════════════  Battle begins! ══════════════════════════════" << endl;
}

void print_battle_1stcolumn() {
  cout << endl << endl;
  cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤" << endl;
  cout << endl << endl;
}

void print_battle_2ndcolumn() {
  cout << endl << endl;
  cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤" << endl;
}

void print_match_result(int mycounter,int rivalcounter) {
  cout << endl;
  if ((mycounter == 6) && (rivalcounter == 6)) {
    cout << "═════════════════════════════  Draw! ══════════════════════════════════" << endl;
  }
  else if ((mycounter == 6)) {
    cout << "════════════════════════════  You Lose! ═══════════════════════════════" << endl;
  }
  else if ((rivalcounter == 6)) {
    cout << "═════════════════════════════ You Win! ════════════════════════════════" << endl;
  }
  cout << endl;
}

void print_battle(pokemon Mypokemons,pokemon Rivalpokemons){
  cout<< endl;

  cout << "╔══════════════════════════════╗" << endl; //32unit
  cout << "║                              ║ " << endl; //32unit
  cout << "║ " << setw(14) << setfill(' ')<< Rivalpokemons.Name<< setw(10) << setfill(' ')<< "" <<setw(2) << setfill(' ')<<"" <<"  "<<" ║" << endl; //2 14 10 2 2 2
  cout << "║                              ║ " << endl; //32unit
  cout << "║ " << "          "<<"HP"<< setw(9) << setfill(' ')<< Rivalpokemons.HP << setw(7) <<"  "<< " ║" << endl;  //2 10 2 14 2 2
  // cout << "********************************" << endl; //32unit
  cout << "║                              ║ " << endl; //32unit
  cout << "╚══════════════════════════════╝" << endl; //32unit
  cout<< endl;
  cout<< endl;
  cout<< endl;
  cout << setw(40) << setfill(' ')<< " "<<"╔══════════════════════════════╗" << endl; //32unit
  cout << setw(40) << setfill(' ')<< " "<<"║                              ║ " << endl; //32unit
  cout << setw(40) << setfill(' ')<< " "<<"║ " << setw(14) << setfill(' ')<< Mypokemons.Name<< setw(10) << setfill(' ')<< "" <<setw(2) << setfill(' ')<<"" <<"  "<<" ║" << endl; //2 14 10 2 2 2
  cout << setw(40) << setfill(' ')<< " "<<"║                              ║" << endl; //32unit
  cout << setw(40) << setfill(' ')<< " "<<"║ " << "          "<<"HP"<< setw(9) << setfill(' ')<< Mypokemons.HP << setw(7) <<"  "<< " ║" << endl;  //2 10 2 14 2 2
  cout << setw(40) << setfill(' ')<< " "<<"║                              ║" << endl; //32unit
  cout << setw(40) << setfill(' ')<< " "<<"╚══════════════════════════════╝" << endl; //32unit
   cout<< endl;

cout<<"╔═══════════════════════════╦═════════════════════════════════════════╗"<<endl; //32 40 2
cout<<"║                           ║ ┌─────────────────┐ ┌─────────────────┐ ║"<< endl;  //─────────────
cout<<"║        What will          ║ │   A. FIGHT      │ │   B. HEAL       │ ║ "<< endl;
cout<<"║                           ║ ╞═════════════════╡ ╞═════════════════╡ ║" << endl ;//  ┬ ┴ ├ ─ ┼ ┤ ┌ ┐ ╞ ═ ╪ ╡ │ ▕ └ ┘
cout<<"║" ;
cout << setw(20) << setfill(' ')<< Mypokemons.Name << " do?   ║ │   C. POKEMON    │ │   D. RUN        │ ║ "<< endl;
cout<<"║                           ║ └─────────────────┘ └─────────────────┘ ║ "  << endl ;
cout<<"╚═══════════════════════════╩═════════════════════════════════════════╝"<<endl; //32 40 2
}
