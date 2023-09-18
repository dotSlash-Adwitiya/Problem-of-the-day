#include<bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n){
  
  if(n == 1)
      return true;
      
  if(n % 2 || n == 0)
      return false;
  
  return isPowerofTwo(n /= 2);
}

int main()
{
  long long n;
  cout << "Input a numeber to check whether its a power of Two : ";
  cin >> n;
  cout <<  n << " is : " << (isPowerofTwo(n) == true ? "power of Two !" : "NOT a power of Two !") << endl;

  return 0;
}