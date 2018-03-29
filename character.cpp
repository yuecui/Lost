#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "character.h"

using namespace std;
//default constructor
character::character() {
   setHP();
   setLEVEL();
   setMONEY();
   setEXP();
   setID();
   setUsername();
   setPosX();
   setPosY();
}
void character::setID(){
  srand(time(0));
  static const char alphanum[] =
  "0123456789"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz";
  int stringLength = sizeof(alphanum) - 1;
  for(unsigned int i = 0; i < 16; ++i)
  {
    ID += alphanum[rand() % stringLength];
  }
}

void character::setUsername(){
  cout << "Enter your name, please: " ;
  getline(cin,USERNAME);

}
void character::setHP() {
   HP = 500;
}
void character::setLEVEL(){
  LEVEL = 1;
}
void character::setMONEY( ) {
   MONEY = 1000;
}
void character::setEXP() {
  EXP = 0;
}
void character::setPosX(){
  pos_X = 1;
}
void character::setPosY(){
  pos_Y = 1;
}
void character::setHP( int hp ) {
   HP = HP + hp;
}

void character::setMONEY( int money ) {
   MONEY = MONEY + money;
}
void character::setEXP( int exper) {
  EXP = EXP + exper;
  int levelup_bar = (pow((LEVEL+1),2)+(LEVEL+1))/2*100-((LEVEL+1)*100);
  if (EXP >= levelup_bar){
    levelUp();
  }
}
void character::setPosX(int x){
  pos_X += x;
}
void character::setPosY(int y){
  pos_Y += y;
}
string character::getID(){
  return ID;
}
string character::getUsername(){
  return USERNAME;
}
int character::getHP(){
  return HP;
}
int character::getLEVEL(){
  return LEVEL;
}
int character::getEXP(){
  return EXP;
}

int character::getPosX(){
  return pos_X;
}
int character::getPosY(){
  return pos_Y;
}
void character::levelUp(){
  LEVEL++;
  cout << "LEVEL UP!" << endl;
  srand(time(NULL));
  setHP(1000);
  setMONEY(rand()%2000+1000);
}
void character::getMap(){

}
void character::getStatus(){
  string divider = "==============================================";
  cout << divider << endl;
  cout << "ID: " << ID << endl
       << "Username: " << USERNAME
       <<" HP: " << HP
       <<" Level: " << LEVEL
       << " EXP: " << EXP
       << " Money: " << MONEY
       << " Current position " << pos_X << " " << pos_Y
       << endl;
  cout << divider << endl;
}
