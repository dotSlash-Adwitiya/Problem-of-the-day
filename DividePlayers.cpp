#include<bits/stdc++.h>
using namespace std;

long long dividePlayers(vector<int>& skill) {
  int n = skill.size();
  if(n == 2)
      return skill[0] * skill[1];
  
  sort(skill.begin(), skill.end());

  long long isEqual = skill[0] + skill[n-1];
  long long chemistry = skill[0] * skill[n-1];
  for(int i = 1, j = n-2; i < j; i++, j--){
      if(skill[i] + skill[j] != isEqual)
          return -1;
      chemistry = chemistry + (skill[i] * skill[j]);
  }
  return chemistry;
}