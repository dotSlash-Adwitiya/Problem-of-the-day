#include<bits/stdc++.h>
using namespace std;


bool knows(int a, int b, vector<vector<int> >& M) {
  return M[a][b];
}

//Function to find if there is a celebrity in the party or not.

int celebrity(vector<vector<int> >& mat) 
{
  int n = mat.size();
  stack<int> st;

  for (int i = 0; i < n; i++)
      st.push(i);

  while (st.size() > 1)   {
      int first = st.top();
      st.pop();

      int second = st.top();
      st.pop();

      if (knows(first, second, mat))
          st.push(second);

      else
          st.push(first);
  }
  
  int candidate = st.top();
  st.pop();
  
  // Verification of a candidate with other remaining members :-
  
  bool checkRow = true;
  
  for(int i = 0; i<n; i++) {
      if(mat[candidate][i] == 1) {
          checkRow = false;
          break;  // No need to check further
      }
  }
  
  bool checkCol = true;
  for(int i = 0; i < n; i++) {
      if(i != candidate && mat[i][candidate] == 0) {
          checkCol = false;
          break;  // No need to check further
      }
  }
  
  if(checkRow && checkCol)
      return candidate;
  return -1;
  
}