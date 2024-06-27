#include<bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();

    for(int i = 0; i<row-1; i++){
        for(int j = 0; j<col-1; j++){
            
            // checking for diagonal element equal or not
            if(mat[i][j] != mat[i+1][j+1]){
                return 0;
            }
        }
    }
    return 1;
}