#include<bits/stdc++.h>
using namespace std;

vector<long long> smallerSum(int n,vector<int> &arr){
    
    vector<long long> ans;
    
    for(int i = 0; i < n; i++){ 
        long long sum = 0;
        for(int j = 0; j < n; j++) { // For every element, start traversal from 0th element
            if(arr[j] < arr[i]) //* And check how many are smaller than arr[i]th element
                sum+=arr[j];
        }
        ans.push_back(sum);
    }
    return ans;
}

int main ()
{
    vector<int> v = {12 ,4, 6, 9, 4, 6};
    int n = 6;

    vector<long long> ans = smallerSum(n,v);

    for(auto it: ans)
        cout << it << " ";

    cout << endl;

    return 0;
}