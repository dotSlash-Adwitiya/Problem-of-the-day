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

vector<long long> smallerSum(int n,vector<int> &arr){
       
    //* STEP I: Copy the original array and sort it 
    vector<int> copy;
    copy = arr;
    vector<long long> ans;
    unordered_map<long long, long long> hashMap;

    sort(copy.begin(), copy.end());
    long long sum = 0;

    //* STEP - II: Look for each value in hashMap
    for(int i = 0; i < n; i++) {
        if(hashMap.find(copy[i]) == hashMap.end()){ //* If not found then assign sum till that value
            hashMap[copy[i]] = sum;
        }
        sum += copy[i];     //* SUM will increment in every step
    }


    for(int &i : arr){
        long long temp = hashMap.at(i);
        ans.push_back(temp);
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
