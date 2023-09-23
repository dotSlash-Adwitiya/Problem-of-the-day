#include<iostream>
using namespace std;


template<typename... Values>
auto sum(Values const&... values)
{
    return (... + values);
}

int main()
{
  cout << sum(1,2,3) << endl;
  
  return 0;
}