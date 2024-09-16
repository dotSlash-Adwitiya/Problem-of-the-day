#include<bits/stdc++.h>
using namespace std;

int findMinDifference(vector<string>& timePoints) {
  vector<int> minutePoints;
  for(const string &timePoint : timePoints){
      int hr = stoi(timePoint.substr(0,3));
      int min = stoi(timePoint.substr(3,5));
      minutePoints.push_back(hr*60+min);
  }

  sort(minutePoints.begin(), minutePoints.end());
  int minDiff = INT_MAX;
  for(int i = 1; i < minutePoints.size(); i++)
      minDiff = min(minDiff, minutePoints[i] - minutePoints[i-1]);

  minDiff = min(minDiff, 24*60 - minutePoints.back() + minutePoints.front());
  return minDiff;
}