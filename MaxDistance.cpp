#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>>& arr) {
    int maxDist = 0, maxEle = arr[0][arr[0].size()-1], minEle = arr[0][0];

    for(int i = 1; i < arr.size(); i++){
        int len = arr[i].size();
        // * Subtract the PREVIOUS MIN_ELE from Current Array's MAX_ELE
        // * Subtract the CURRENT MIN_ELE from PREVIOUS Array's MAX_ELE
        // * Above step is to be done to maintain MAX_DISTANCE b/w 2 DIFFERENT ARRAYS NOT the SAME.
        maxDist = max(maxDist, abs(arr[i][len-1] - minEle));
        maxDist = max(maxDist, abs(maxEle - arr[i][0]));
        minEle = min(arr[i][0], minEle);
        maxEle = max(arr[i][len-1], maxEle);
    }
    return maxDist;
}