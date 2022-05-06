#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//pokemon type chart referenced to https://pokemondb.net/type
double Type_Attack_Bonus(struct attack_skill, struct defense_pokemon) {

// 	string a ="" ,b= "" ,c="";
 int key0,key1 ,key2,count=0;
vector<string> TYPE = {"NORMAL", "FIRE", "WATER", "ELECTRIC", "GRASS", "ICE", "FIGHTING", "POISON", "GROUND", "FLYING", "PSYCHIC", "BUG" ,"ROCK", "GHOST", "DRAGON" ,"DARK" ,"STEEL", "FAIRY"};
vector<string>::iterator iter;
for(iter = TYPE.begin(); iter != TYPE.end(); iter++) {
      if( attack_skill.type == iter ){ 
           key0 = count ;}
	if( defense_pokemon.type1 == iter ){ 
           key1 = count ;}
	if( defense_pokemon.type2 == iter ){ 
           key2 = count ;}
	count++;
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
	if( defense_pokemon.type2 == "NULL" ){ 
// 	   if (Chart[key0][key1] == 2)
// 		cout <<"Super effective"<<endl;
		
           return Chart[key0][key1] ;}
	else { 
           return Chart[key0][key1]*Chart[key0][key2] ;}
}
