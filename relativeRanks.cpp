#include<bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
  map<int, int> mp;

  for(int i = 0; i < score.size(); i++)
      mp[score[i]] = i+1;

  // for(auto it : mp)
  //     cout << it.first << " " << it.second << endl;
  
  vector<string> ans(score.size());

  int cnt = score.size();
  for(auto it : mp) {
      if(cnt == 1)
          ans[it.second - 1] = "Gold Medal";  
      else if(cnt == 2)
          ans[it.second - 1] = "Silver Medal";
      else if(cnt == 3)
          ans[it.second - 1] = "Bronze Medal";
      else 
          ans[it.second - 1] = to_string(cnt);
      cnt--;
  }
  return ans;
}