#include<bits/stdc++.h>
using namespace std;

// * Problem NamE: 241. Different Ways to Add Parentheses
// * Problem Link : https://leetcode.com/problems/different-ways-to-add-parentheses/description/?envType=daily-question&envId=2024-09-19


// * Recursive solution
// * T.C: O(n*x) (where x is the no of operations)
vector<int> f(int i, int j, string &exp){
  // * If the length of the expression is <= 2
  // * Means we need to return the evaluated value 
  if(j - i + 1 <= 2)
      return { stoi(exp.substr(i, j-i+1)) };

  vector<int> res;
  for(int idx = i; idx <= j; idx++){
      // * If its an operator, MAKE A PARTITION HERE.
      if(exp[idx] == '+' || exp[idx] == '-' || exp[idx] == '*'){
          char op = exp[idx];
          vector<int> left = f(i, idx - 1, exp);
          vector<int> right = f(idx + 1, j, exp);

          // * At EVERY Partiton, we will receive a vector from left and right
          // * And for every element in left vector, we perform operation
          // * with every element of right vector.
          for(int &ele1 : left){
              for(int &ele2 : right){
                  if(op == '+') res.push_back(ele1 + ele2);
                  else if(op == '-') res.push_back(ele1 - ele2);
                  else if (op == '*') res.push_back(ele1 * ele2);
              }
          }
      }
  }
  return res;
}

vector<int> diffWaysToCompute(string expression) {
  return f(0, expression.size() - 1, expression);
}

// * Optimization MEMOIZAITON using 3D DP which will store
// * At ith and jth index, the vector which was calculated.
vector<int> f(int i, int j, string &exp, vector<vector<vector<int>>> &dp){
  if(j - i + 1 <= 2)
      return { stoi(exp.substr(i, j-i+1)) };
  
  // * If the res<vector> at dp[i][j] is NOT empty
  if(dp[i][j].empty() == 0) 
      return dp[i][j];
  
  vector<int> res;
  
  for(int idx = i; idx <= j; idx++){
      if(exp[idx] == '+' || exp[idx] == '-' || exp[idx] == '*'){
          char op = exp[idx];
          vector<int> left = f(i, idx - 1, exp, dp);
          vector<int> right = f(idx + 1, j, exp, dp);

          for(int &ele1 : left){
              for(int &ele2 : right){
                  if(op == '+') res.push_back(ele1 + ele2);
                  else if(op == '-') res.push_back(ele1 - ele2);
                  else if (op == '*') res.push_back(ele1 * ele2);
              }
          }
      }
  }
  return dp[i][j] = res;
}

vector<int> diffWaysToCompute(string expression) {
  int n = expression.size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
  return f(0, expression.size() - 1, expression, dp);
}

// * Tabulation solution is very hard to understand.