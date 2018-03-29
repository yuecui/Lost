#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <iterator>
#include "mapManager.h"
using namespace std;

int main(){
  mapManager mg;
  return 0;
}

// int main(){
//   map<int,string> aList;
//   aList[1] = "MONSTER_PIT";
//   aList[2] = "DAEMON_PIT";
//   aList[3] = "YAOGUAI_PIT";
//   aList[4] = "STORE";
//
//   std::map<int, string>::iterator it = aList.begin();
//   while(it != aList.end())
//   {
//   std::cout<<it->first<<" :: "<<it->second<<std::endl;
//   it++;
//   }
//   map<int,string> ::iterator itt;
//
//   for (itt = aList.begin();itt != aList.end(); ++itt){
//     cout << itt->second << endl;
//   }
// cout << aList.begin()->first;
//   return 0;
// }
// int main(){
// 	//
// 	int a[8] = {3,2,1,1,3,2,1,2,};
// 	int length = sizeof(a)/sizeof(int);
//   cout << "sizeof a " << sizeof(a) <<"sizeof int " << sizeof(int) << endl;
// 	int sum = 0;
// 	for (int i = 0; i < length; i++)
// 	{
// 		sum += a[i];
// 	}
//   cout << sum << endl;
//   srand((int)time(0));
// 	int randVal = rand()%sum;
// 	printf("%d\n",randVal);
// 	int grade = 0;
// 	for (int i = 0;i < length; i++)
// 	{
// 		if (randVal <= a[i])
// 		{
// 			grade = i+1;
// 			break;
// 		}
// 		randVal -= a[i];
// 	}
// 	printf("%d代号\n",grade);
//
// 	return 0;
// }

// int main(){
//   int r = 30;
//   int c = 20;
//   int **map = new int*[r];
//   int i, j;
//
//   for (i = 0; i < r; i++){
//     map[i] = new int[c];
//   }
//   for(i = 0; i < r ; i++){
//     for (j = 0; j < c; j ++){
//       map[i][j] = 1;
//     }
//   }
//   cout << map[15][16] <<endl;
//   for (i = 0; i < r; i++){
//     delete[] map[i];
//   }
//   delete[] map;
//   return 0;
// }
