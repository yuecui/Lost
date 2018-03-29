#include <iostream>
using namespace std;


class character {

public:
  //Constructor
  character();
  //generate a random unique integer as user ID
  void setID();
  //set inital HP value
  void setHP();
  //set inital Level value
  void setLEVEL();
  //set inital Money value
  void setMONEY();
  //set inital experience value
  void setEXP();
  //set user name from input
  void setUsername();

  void setPosX();
  void setPosY();
  //update HP value with an increment of hp
  void setHP(int hp);
  //update MONEY value with an increment of money
  void setMONEY(int money);
  //update EXP value with an increment of exper
  void setEXP(int exper);

  //get user ID
  string getID();
  //get user current HP
  int getHP();
  //get user  current Level
  int getLEVEL();
  //get user current Money
  int getMONEY();
  //get user current Experience
  int getEXP();
  //get user name
  string getUsername();
  // print user current status
  void getStatus();
  //level up
  void levelUp();

  void setPosX(int x);
  void setPosY(int y);
  int getPosX();
  int getPosY();
  void getMap();
private:
     string ID;
     string USERNAME;
     int HP;
     int LEVEL;
     int MONEY;
     int EXP;
     int pos_X;
     int pos_Y;
     int** userMap;

};
