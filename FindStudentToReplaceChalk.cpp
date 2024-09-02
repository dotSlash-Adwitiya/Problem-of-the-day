#include<bits/stdc++.h>
using namespace std;

int chalkReplacer(vector<int>& chalk, int k) {
  // * Calculate SUM
  k %= accumulate(chalk.begin(), chalk.end(), 0l);

  for (int i = 0; i < chalk.size(); ++i)
      if ((k -= chalk[i]) < 0)
          return i;
  
  return 0;
}