#include<bits/stdc++.h>
using namespace std;

void insert(queue<int> &q, int k){
    q.push(k);
}

// Function to find frequency of an element
// return the frequency of k
int findFrequency(queue<int> &q, int k){
    // Your code here
    int size = q.size(), cnt = 0;
    
    while(size--) {
        //*Check if the front element is == k, if it is. Then increment the cnt.
        if(q.front() == k) cnt++;

        //* Get the front element in a temp var, then pop. Then Enque. This will insert it into last position.
        q.push(q.front());
        q.pop();
    }
    return cnt;
}


int main()
{
  int arr[] = {1,2,3,4,5};

  vector<int> v = {10,20,30,40,50};

  queue<int> q;

  insert(q,1);
  insert(q,2);
  insert(q,3);
  insert(q,4);
  insert(q,5);
  insert(q,6);
  insert(q,7);

  int size = q.size();
  for(int i = 0; i < size; i++) {
    int temp = q.front();
    cout << "element : " << i << " " << temp << endl;
    q.pop();
    q.push(temp); 
  }

  cout << "Frequency is : " << findFrequency(q, 1) << endl;

  return 0;
}