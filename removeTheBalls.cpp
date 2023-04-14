#include<bits/stc++.h>
using namespace std;

int finLength(int N, vector<int> color, vector<int> rad) {
    
    if(N==1)
        return 1;
    if(N == 0)
        return 0;
    
    stack<int> stk1, stk2;
    int ans = N;
    
        
    for(int i = 0, j = 0; i < N; i++, j++) {
        
        if(!stk1.empty()){
            if(color[i] == stk1.top() && rad[i] == stk2.top())  {
                ans -= 2;
                stk1.pop();
                stk2.pop();
            }
            else {
                stk1.push(color[i]);
                stk2.push(rad[i]);
            }
        }
        else{
            stk1.push(color[i]);
            stk2.push(rad[i]);
        }
    }
    return ans;
}

int main()
{


}