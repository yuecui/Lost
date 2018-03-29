#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
#include <iterator>
#include <iomanip>
#include "mapManager.h"
using namespace std;
//default Constructor
mapManager::mapManager(){
  if (isRenew()){
    setDimensionX();
    setDimensionY();

    setMap();
    setTerrain();
    setBoundary();

    setAllTerrainKeys();
    setAllTerrainValues();
    getTerrain();
    generateArea();
    checkMap();

  }
}
mapManager::~mapManager(){
  //delete resources
  int i;
  for(i = 0; i < X_DIMENSION; i++){
    delete[] MAP[i];
  }
  delete[] MAP;
}


bool mapManager::isRenew(){
cout << "Do you wish to create a new map file?(y/n) ";
string isRenew;
getline(cin,isRenew);
if (isRenew == "y" ){
  return true;
}
else
  return false;
}
void mapManager::setDimensionX(){
 cout << "What's the x dimension for the map?"<< endl;
 cin >> X_DIMENSION;
}
void mapManager::setDimensionY(){
 cout << "What's the y dimension for the map?"<< endl;
 cin >> Y_DIMENSION;
}
 int mapManager::getDimensionX(){
 return X_DIMENSION;
}
 int mapManager::getDimensionY(){
 return Y_DIMENSION;
}

void mapManager::setMap()
{
 //allocate space for array
 MAP = new int*[X_DIMENSION]; //rows
 for(int i = 0; i < X_DIMENSION; i++){
   MAP[i] = new int[Y_DIMENSION]; //columns
}
 //set to 0 s
 for(int i = 0 ; i < X_DIMENSION; i++){
   for(int j = 0; j < Y_DIMENSION; j++){
       MAP[i][j] = 0;
   }
 }
}

void mapManager::checkMap(){
 int i, j;
 for (i = 0; i < X_DIMENSION; i++){
   for (j = 0; j < Y_DIMENSION; j++){
     cout <<setw(5)<< MAP[i][j] ;
     }
     cout << endl;
   }
}

void mapManager::setBoundary(){
//set boundary
  int i,j;
  int corner = findTerrainByName("CORNER");
  cout << "corner " << corner << endl;
  for (i = 0; i <= X_DIMENSION-1; i++){
    MAP[i][0] = corner;
    MAP[i][Y_DIMENSION-1] = corner;
    for (j = 0 ; j <= Y_DIMENSION-1; j++){
      MAP[X_DIMENSION-1][j]=corner;
      MAP[0][j] = corner;
    }
  }
}
void mapManager::setTerrain(){
  // string line,dummy,terrain;
  // int key;
  // bool more = true;
  // cout << "Enter the key and the terrain name." << endl;
  // cout << "Follow the example: " << endl;
  //
  // while (more) {
  //   getline(cin,dummy);
  //   cout << "terrain  key " << endl;
  //
  //   getline(cin, line);
  //
  //   stringstream ss(line);
  //   ss >> terrain >> key;
  //
  //   cout << "key = " << key << " terrain = " << terrain << endl;
  //   TERRAIN[key] = terrain;
  //   cout << "Do you wish to create more? (y/n)";
  //   string isMore;
  //   cin >> isMore;
  //   if (isMore == "y"){
  //     continue;
  //   }
  //   else{
  //     more = false;
  //   }
  // }


  TERRAIN[0] = "CORNER";
  TERRAIN[1] = "NOTHING";
  TERRAIN[2] = "MONSTER_PIT";
  TERRAIN[3] = "DAEMON_PIT";
  TERRAIN[4] = "YAOGUAI_PIT";
  TERRAIN[5] = "STORE";//Buy armor and weapon
  TERRAIN[6] = "HOUSE";//Residense house, can have a rest or find some money
  TERRAIN[7] = "RESTAURANTS";//can have a rest or do a part time job to earn money[errands]
  TERRAIN[9] = "EXIT";
}

void mapManager::generateArea(){
  srand(time(0));
  int x_bound = X_DIMENSION - 2;
  int y_bound = Y_DIMENSION - 2;
  int x_pox, y_pox;
  int i,j,k;
  int weight;
  int numKeys = Terrain_keys.size();
  int *weightArray = new int[numKeys];
  int *keyArray = new int[numKeys];


  //weight for every terrains
  cout << "There are " << numKeys << " terrains" << endl;
  cout << "And they are " ;
  getAllTerrainValues();
  cout << "Now set the weight for all the terrains:" << endl;
  for(k = 0; k < numKeys; k++){
    cout << Terrain_values.at(k) << " : ";
    cin >> weight;
    weightArray[k] = weight;
    keyArray[k] = Terrain_keys.at(k);

  }

	int length = sizeof(weightArray);
  //cout << "sizeof a " << sizeof(a) <<"sizeof int " << sizeof(int*) << endl;
	int sum = 0;
	for (i = 0; i <= length; i++)
	{
    cout << keyArray[i] << "  "<< weightArray[i] << endl;
    sum += weightArray[i];
	}
  cout << "sum: " << sum << endl;
  for (j = 0; j < 10000 ; j++) {
    int terrain = 0;
    int randVal = rand()%sum;
    //cout << "randval: " << randVal << endl;
    for (i = 0;i <= length; i++)
  	{
  		if (randVal <= weightArray[i])
  		{
  			terrain = keyArray[i];
  			break;
  		}
  		randVal -= weightArray[i];
  	}

    x_pox = rand()% x_bound + 1;
    y_pox = rand()% y_bound + 1;

    if (MAP[x_pox][y_pox] == 0){
      MAP[x_pox][y_pox] = terrain;
    }
  }
  delete []weightArray;
  delete []keyArray;
}

void mapManager::getTerrain(){
  int key;
  string terrain;

  if(!TERRAIN.empty()){
    cout << "Current terrain setting is : " << endl;
    map<int,string> :: iterator it;
    it = TERRAIN.begin();
    for(  it = TERRAIN.begin();it != TERRAIN.end(); ++it){
      cout << it->first << "  " << it->second << endl;
    }
  }


}


int mapManager::findTerrainByName(string terrain){
  int key;
  map<int,string> :: iterator it;
  if(!TERRAIN.empty()){
    it = TERRAIN.begin();
    for(  it = TERRAIN.begin();it != TERRAIN.end(); ++it){
      if (it->second == terrain){
        key = it->first;
        cout << "Found!" << endl;
        break;
      }
    }
    return key;
  }
}

string mapManager::findTerrainByKey(int key){
  string terrain;
  map<int, string> :: iterator it;
  if(!TERRAIN.empty()){
    for (it = TERRAIN.begin(); it != TERRAIN.end(); ++it){
      if(it -> first == key){
        terrain = it -> second;
        cout << "Found!" << endl;
        break;
      }
    }
    return terrain;
  }
}

void mapManager::setAllTerrainKeys(){
  map<int,string> :: iterator it;
  if(!TERRAIN.empty()){
    it = TERRAIN.begin();
    for(it = TERRAIN.begin(); it != TERRAIN.end(); ++it){
      Terrain_keys.push_back(it->first);
    }
  }
}
void mapManager::setAllTerrainValues(){
  map<int,string> :: iterator it;
  if(!TERRAIN.empty()){
    it = TERRAIN.begin();
    for(it = TERRAIN.begin(); it != TERRAIN.end(); ++it){
      Terrain_values.push_back(it->second);
    }
  }
}
void mapManager::getAllTerrainKeys(){
  if(!Terrain_keys.empty()){
    int i;
    for(i = 0 ; i < Terrain_keys.size(); ++i){
      cout << Terrain_keys.at(i) << "  ";
    }
    cout << endl;
  }
}
void mapManager::getAllTerrainValues(){
  if(!Terrain_values.empty()){
    int i;
    for(i = 0; i < Terrain_values.size(); ++i){
      cout << Terrain_values.at(i) << " ";
    }
    cout << endl;
  }
}
