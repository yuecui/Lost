#include <iostream>
using namespace std;
class map(){
public:
  map();

  //pring the current explored map
  printMap();
  setPosX(int x);
  setPosY(int y);
  getPosX();
  getPosY();

private:
  map<int,string> UserMap;
  int pos_x;
  int pos_y;
  int** userMap;

};
