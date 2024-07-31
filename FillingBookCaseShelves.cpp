#include<bits/stdc++.h>
using namespace std;

// * Recursive solution
int f(int idx, int thickness, int height, vector<vector<int>>& books, int shelfWidth) {
  if (idx == -1) return height;
  

  int thick = books[idx][0];
  int currHeight = books[idx][1];

  // * Case 1: Place the book on a new shelf
  int placeOnNewShelf = height + f(idx - 1, thick, currHeight, books, shelfWidth);

  // * Case 2: Place the book on the current shelf if it fits
  int placeOnCurrentShelf = INT_MAX;
  if (thickness + thick <= shelfWidth) {
      placeOnCurrentShelf = f(idx - 1, thickness + thick, max(height, currHeight), books, shelfWidth);
  }

  return min(placeOnNewShelf, placeOnCurrentShelf);
}

int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
  return f(books.size() - 1, 0, 0, books, shelfWidth);
}

// * MEmoization optimization
int f(int idx, int thickness, int height, vector<vector<int>>& books, int shelfWidth, vector<vector<int>> &dp){
  if (idx == -1) return height;
  
  if(dp[idx][thickness] != -1)
      return dp[idx][thickness];

  int thick = books[idx][0];
  int currHeight = books[idx][1];

  // Case 1: Don't ADD thickness when NOT considering currEle 
  int notTake = height + f(idx - 1, thick, currHeight, books, shelfWidth, dp);

  // Case 2: Add thickness, and take max height when considering currEle
  int take = INT_MAX;
  if (thickness + thick <= shelfWidth) 
      take = f(idx - 1, thickness + thick, max(height, currHeight), books, shelfWidth, dp);

  return dp[idx][thickness] = min(take, notTake);
}

int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
  int n = books.size();
  vector<vector<int>> dp(n+1, vector<int> (shelfWidth + 1, -1));
  return f(books.size() - 1, 0, 0, books, shelfWidth, dp);
}