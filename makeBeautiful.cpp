#include<bits/stdc++.h>
using namespace std;

vector<int> makeBeautiful(vector<int> arr) {
    vector<int> ans;
    stack<int> st;
    
  if(arr.size() == 1){
        ans.push_back(arr[0]);
        return ans;
  }
    
  for(int num : arr) {
      if(st.empty())
        st.push(num);
        else{
//* Because in the questions its given, the input array consists of negative and non -ve elements (which includes 0 !)
            if(st.top() < 0 && num >= 0 || st.top() >= 0 && num < 0)
                st.pop();
            else
                st.push(num);
        }
  }
    
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
  vector<int> v = {1 , -2, -4};

  vector<int> a = makeBeautiful(v);

  for(auto it : a)
    cout << it << " ";

  cout << endl;

  return 0;
}