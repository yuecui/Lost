#include<iostream>
#include<iterator>
#include<vector>
#include<map>

using namespace std;
//This class will create a new map file.
class mapManager{
public:
//constructor
mapManager();
//destructor
~mapManager();
//check if user want to create a new map
bool isRenew();
//==============Map==============
//get user input for x dimension of the map
void setDimensionX();
//get user input for y dimension of the map
void setDimensionY();
//initialize a 2d dynamic array based on the dimision get from user input
void setMap();
//set the boundary of the map
void setBoundary();
//print the current map
void checkMap();
//return value for x dimension of the map
int getDimensionX();
//return value for y dimension of the map
int getDimensionY();
//==============Terrain==============
// set all the things you want in the map into a dictionary
void setTerrain();
//genertae random positions for a certain terrian
void generateArea();
// print the current terrain settings
void getTerrain();
//find a terrain key by name
int findTerrainByName(string terrain);
//find a terrain name by key value
string findTerrainByKey(int key);
//store all the keys for the terrain dictionary to the vector
void setAllTerrainKeys();
//return all the values for the terrain dictionary to the vector
void setAllTerrainValues();
//print out all the keys from the dictionary
void getAllTerrainKeys();
//print out all the values from the dictionary
void getAllTerrainValues();




private:
//All the things that you want to have in the map
map<int,string> TERRAIN;
vector<int> Terrain_keys;
vector<string> Terrain_values;
int X_DIMENSION;
int Y_DIMENSION;
int** MAP;
};
