#include<bits/stdc++.h>
using namespace std;



//* TC : O(n), SC- O(n) (Deque Approach)
int distributeTicket(int N, int K) {
  int ele = 1, ans = 0;
  
  //* Create a queue to implement movie counter queue
  deque<int> q;
  
  while(ele <= N) {
      q.push_back(ele);
      ele++;
  }
  
  //* Implementing such a mechanism which allows us to to pop k elements from 1st and last. 
  bool first = true, last = false;
  
  while(!q.empty()) {

      if(first == true){
          int temp = K;
          
          while(temp-- && !q.empty()) {
              ans = q.front();
              q.pop_front();
          }
          first = false;
          last = true;
      }
      else{
          int temp2 = K;
          while(temp2-- && !q.empty()) {
              ans = q.back();
              q.pop_back();
          }
          
          last = false;
          first = true;
      }
  }
  return ans;    
}


int main()
{
  int arr[] = {1,2,3,4,5};

  vector<int> v = {10,20,30,40,50};


  return 0;
}