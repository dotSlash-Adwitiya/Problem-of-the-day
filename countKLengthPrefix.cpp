#include<bits/stdc++.h>
using namespace std;

int klengthpref(string arr[], int n, int k, string str){    
    if(k > str.size())
        return 0;
    
    int cnt = 0;
    string match = str.substr(0,k);
    
    for(int i = 0; i < n; i++) {
        string temp = arr[i];
        temp = temp.substr(0,k);
        
        if(temp == match) cnt++;
    }
    return cnt;
}

int main()
{
  string arr[] = {"adwitiya", "adwitiyamourya", "adi", "awiasdaisd"};

  int k = 2;
  int size = (sizeof(arr)/sizeof(arr[0]));
  string str = "adwitiya";
  cout << "Count of strings that match the kth-prefix are : " << klengthpref(arr,size, k, str) << endl;

  return 0;
}