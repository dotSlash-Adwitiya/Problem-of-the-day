#include<bits/stdc++.h>
using namespace std;

//* BRUTE FORCE APPROACH - TC :O(N), SC : O(|N|)
unsigned int getFirstSetBit2(int n)
{
  if (n == 0)
        return 0;

  //* Step-1 : Create a binary array to store the binary numbers of size calculated in Step-1
  vector<int> bin;
  while (n)
  {
    bin.push_back(n % 2);
    n /= 2;
  }

  //* Traverse until you find the first set bit, and return i+1, because arr[idx] start from 0
  for(int i = 0; i < bin.size(); i++) 
      if(bin[i] == 1)
          return i+1;

    return 0;
}

//* OPTIMISED BITWISE APPROACH - TC :O(logn), SC : O(1)
unsigned int getFirstSetBit(int n)
{
  int pos = 1;
  while(n){
      
      if(n&1) return pos;
      
      //* Inc pos value and shift all the bits by 1
      pos++;
      n >>=1;
  }

  //* If there doesn't exist a set bit then return 0;
  return 0;
}


int main()
{
  cout << getFirstSetBit2(18) << endl;
  return 0;
}