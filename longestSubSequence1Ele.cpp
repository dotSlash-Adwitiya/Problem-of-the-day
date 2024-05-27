#include<bits/stdc++.h>
using namespace std;

    int helper(int idx, vector<int> &a, vector<int> &sub, int &maxSeq){
        if(idx == a.size()){
            int sz = sub.size();
            maxSeq = max(maxSeq, sz);
            return maxSeq;
        }
        
        int take = 0, notTake = 0;
        
        if(sub.size() == 0 || abs(sub.back()-a[idx]) == 1) {
            sub.push_back(a[idx]);
            take =  helper(idx + 1, a, sub, maxSeq);
            sub.pop_back();
        }
        
        notTake = helper(idx + 1, a, sub, maxSeq);
        
        return maxSeq;
        
    }
  
    int longestSubseq(int n, vector<int> &a) {
        vector<int> sub;
        int maxSeq = 0;
        helper(0, a, sub, maxSeq);
        return maxSeq;
    }

int main()
{

  vector <int> v = {2,8,5,1,10,5,9,3,5};
  cout << longestSubseq(10, v) << endl;

  // cout << v.
  return 0;
}