#include<bits/stdc++.h>
using namespace std;

// * Stack Approach O(n²): Time & Space - Common Error Approach
vector<long long> nextLargerElement(vector<long long> arr, int n){
  vector<long long> ans(n);
  stack<long long> stk1, stk2;
  
  for(int i = n-1; i >= 0; i--) {
      
      if(!stk1.empty() && stk1.top() > arr[i])
          ans[i] = stk1.top();
          
      else if(!stk1.empty() && stk1.top() <= arr[i]) {
          while(!stk1.empty() && stk1.top() <= arr[i]){
              stk2.push(stk1.top());
              stk1.pop();
          }
          if(!stk1.empty())
              ans[i] = stk1.top();
              
          else 
              ans[i] = -1;
              
          // *REDUNDANT that's causing TLE !
          //* NOTE : We only need the next greater element, not the elements beyond it.
          //* So, if ANY element is found to be matching the criteria : currEle < stk.TOP(),
          //* We only need to store that !, not anything beyond it. So no need of putting them back into stack!
          while(!stk2.empty()){
              stk1.push(stk2.top());
              stk2.pop();
          }
      }
      else {
          ans[i] = -1;
      }
      stk1.push(arr[i]);
  }
  
  return ans;
}

//* Stack Corrected Approach