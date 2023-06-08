
//* This approach is without implementation of permutation function, you still gotta learn the implementation and how to find the kth permuation from that
string kthPermutation(int n, int k) {
        string ans = "";
        for(int i = 1; i<=n; ++i)
            ans += to_string(i);
        
        while(k-- > 1)
            next_permutation(ans.begin(), ans.end());
        
        return ans;
    }
