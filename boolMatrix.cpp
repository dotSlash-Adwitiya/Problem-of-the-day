#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col) {
    
    set<vector<int>> st;
    vector<vector<int>> ans;

    for(int i = 0; i < row; i++) {
      vector<int> temp;
        for(int j = 0; j < col; j++) {
            temp.push_back(M[i][j]);
        }
      //* Check if the row already exists in the HashSet. If it does, no need to insert it. 
      //* If it doesn't exist then it must also be included in the ans !
      if(st.find(temp) == st.end()) {
        ans.push_back(temp);
        st.insert(temp);
      }
    }
    return ans;
}


int main()
{
  int arr[] = {1,2,3,4,5,20,12,30,14,42,17};

  int matrix[3][3] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};

  vector<int> v = {1,2,3,4,5,20,12,30,14,42,17};
  vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

  string str = "ABC";



  return 0;
}