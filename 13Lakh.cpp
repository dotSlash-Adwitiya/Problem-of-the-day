#include<bits/stdc++.h>
using namespace std;

class Phone {
  public:
    int price;
    int speed;
};

static bool comp(Phone &p1, Phone &p2) {
  if(p1.price < p2.price)
    return true;
  else if(p1.price > p2.price)
    return false;
  else {
    if(p1.speed > p2.speed)
      return true;
    else
      return false;
  }
}

int main()
{
  Phone arr[] = {{23,10}, {25,65}, {23,15} , {8,6}};

  int n = sizeof(arr)/sizeof(arr[0]);

  sort(arr, arr+n, comp);

  for(int i = 0; i < n; i++)
    cout << "Price : " << arr[i].price << " Speed : " << arr[i].speed << endl;

  return 0;

}
