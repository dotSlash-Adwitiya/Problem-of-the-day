#include<bits/stdc++.h>
using namespace std;

int countBuildings(vector<int> &height) {
  int buildings = 1;
  int highestBuilding = height[0];
  for(int i = 1; i < height.size(); i++){
      if(height[i] > highestBuilding){
          highestBuilding = height[i];
          buildings++;
      }
  }
  return buildings;
}