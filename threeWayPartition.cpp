#include<bits/stdc++.h>
using namespace std;

// * Intuition : You only need to arrange the below range integers and above range integers
// * T.C : O(N), S.C : O(1)

void threeWayPartition(vector<int>& arr,int a, int b)
{
  int i = 0, start = 0, end = arr.size() - 1;
  int j = arr.size() - 1;
  
  // * First, shift all the elements below int 'a' to the start
  while(i < arr.size()){
      if(arr[i] < a)
          swap(arr[i], arr[start++]);
      i++;
  }
  
  // * Now, shift all the elements above int 'b' to the end
  while(j >= 0){
      if(arr[j] > b)
          swap(arr[j], arr[end--]);
      j--;
  }

}