#include<bits/stdc++.h>
using namespace std;

//*sdfsdfd
//* Optimal Approach : TC - O(n! * n), SC : O(1)
void solve(set<string>& st, string S, int l, int h) {

    if(l == h)
        st.insert(S);
  
    for(int i = l; i <= h; i++) {
  
        swap(S[i], S[l]);
        solve(st,S,l+1, h);
        swap(S[i], S[l]);
    }
    
}
        
vector<string>find_permutation(string S) {
  set<string> st;
  string out = "";
  solve(st,S,0,S.size()-1);    

  vector<string> vpt(st.begin(), st.end());
  return vpt;
}


//* Extra space complexity, TC : O (n! * n)
void spacePermute(string &str, unordered_map<int,bool> &flag, string &ds, int l, int h, set<string> &ans) {

    if(ds.size() == h) {
      ans.insert(ds);
      cout << "Now return because value max in Data structure" << endl;
      return;
    }
  
    for(int i = 0; i < h; i++) {
      cout << "Value of i : " << i << " flag[i] : " << (bool)flag[i] << " for char : " << str[i] << endl;
      if(flag[i] == false) {  //* If its not visited yet
        flag[i] = true;  //* Mark it visited
        cout << "For (Before call) : " << i << " str[i] = " << str[i] << endl;
        ds += str[i];
        spacePermute(str, flag, ds, l+1, h, ans);
        flag[i] = false;  //* While returning, mark it unvisited, similar to (2nd swap in another approach)
        cout << "For (After call) : " << i << " str[i] = " << str[i] << endl;
        ds.pop_back();
        cout << "After completing one call" << endl;
      }
    }
}

vector<string>find_permutation_extra_space(string S)
{
    int l = 0;
    int h = S.size();
    
    //* Declaring all auxilarry spaces
    vector<string> ans;
    set<string> st;
    string out = "";
    
    //*By default unordered_map has false values assigned to bool part
    unordered_map<int, bool> flag;
        

    spacePermute(S, flag, out, l, h, st);
    
    //* Copying set elements to vector
    for(auto it = st.begin(); it != st.end(); it++) 
        ans.push_back(*it);
    
    return ans;
}



int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    // cout << "Permutations of the string:" << endl;
    vector<string> v = find_permutation(input);

    // for(auto it : v)
      // cout << it << " ";

    cout << endl;

    v = find_permutation_extra_space(input);
    for(auto it : v)
      cout << it << " ";

    return 0;
}