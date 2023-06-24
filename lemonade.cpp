#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(int N, vector<int> &bills) {

    if(bills[0] == 10 || bills[0] == 20)
        return false;
    
    int five = 1, ten = 0;
    
    for(int i= 1; i < N; i++) {
        if(bills[i] == 5) five++;
            
        else {
            if(bills[i] == 10){
                //*If there are any 5 notes then we can definetly return them
                if(five) {
                    ten++;
                    five--;
                }
                else return false;
                    
            }
            else{
                //* Ten & Five must be greater than 0.
                if(ten && five){
                    ten--;
                    five--;
                }
                else if(five >= 3) five -= 3;
                
                
                else return false;
            }
        }
    }
    
    return true;
}

int main()
{
  int arr[] = {1,2,3,4,5};

  vector<int> v = {5,5,10,10,20};

  cout << (lemonadeChange(v.size(), v)) ? "TRUE" : "FALSE";

  return 0;
}