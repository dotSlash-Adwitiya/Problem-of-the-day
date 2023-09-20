#include<bits/stdc++.h>
using namespace std;

vector <int> rotate (int n, int d)
{
    vector <int> res(2,0);
    d %= 16;
    res[0] = ((n << d) | (n >> (16 - d))) & 0xFFFF;
    res[1] = ((n >> d) | (n << (16 - d))) & 0xFFFF;
    return res;
}

int main()
{

  return 0;
}