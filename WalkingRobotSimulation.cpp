#include<bits/stdc++.h>
using namespace std;

// * TLE Solution, T.C: O(N * (M * 2)), where N = size of commands[], M = No of Rows in obstacles 
bool search(int x, int y, std::vector<std::vector<int>> obstacles) {
  // * Check if the current position is an obstacle
  for (const auto& obstacle : obstacles) {
      if (obstacle[0] == x && obstacle[1] == y)
          return true;
  }
  return false;
}

int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
  int x = 0, y = 0, maxAns = 0;
  char dir = 'N';

  for (int i = 0; i < commands.size(); i++) {
      if (commands[i] > 0) {
          int move = commands[i];
          while (move--) {
              if (dir == 'N') {
                  y++;
                  if (search(x, y, obstacles)) {
                      y--;  // Undo move if there's an obstacle
                      break;
                  }
              } else if (dir == 'S') {
                  y--;
                  if (search(x, y, obstacles)) {
                      y++;  // Undo move if there's an obstacle
                      break;
                  }
              } else if (dir == 'W') {
                  x--;
                  if (search(x, y, obstacles)) {
                      x++;  // Undo move if there's an obstacle
                      break;
                  }
              } else { // * East
                  x++;
                  if (search(x, y, obstacles)) {
                      x--;  // Undo move if there's an obstacle
                      break;
                  }
              }
          }
          maxAns = std::max(maxAns, x * x + y * y);
      } else if (commands[i] == -1) {
          if (dir == 'N') dir = 'E';
          else if (dir == 'E') dir = 'S';
          else if (dir == 'S') dir = 'W';
          else if (dir == 'W') dir = 'N';
      } else if (commands[i] == -2) {
          if (dir == 'N') dir = 'W';
          else if (dir == 'W') dir = 'S';
          else if (dir == 'S') dir = 'E';
          else if (dir == 'E') dir = 'N';
      }
  }
  return maxAns;
}

// * Optimized solution using Unordered_set<pair<int, int>, hashFunction> 
// * Had to do some research on STACKOVERFLOW to figure this out.
struct hashFunction {
  inline size_t operator()(const std::pair<int,int> & v) const {
      return v.first*31+v.second;
  }
};

int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
  int x = 0, y = 0, maxAns = 0;
  char dir = 'N';

  // * Use unordered_set to store obstacles as pairs of coordinates
  unordered_set<pair<int, int>, hashFunction> obstacleSet;
  for (const auto& obstacle : obstacles) 
      obstacleSet.insert({obstacle[0], obstacle[1]});

  for (int i = 0; i < commands.size(); i++) {
      if (commands[i] > 0) {
          int move = commands[i];
          while (move--) {
              if (dir == 'N') { // * If current direction is NORTH
                  y++;
                  if (obstacleSet.count({x, y})) {
                      y--;  // Undo move if there's an obstacle
                      break;
                  }
              } else if (dir == 'S') { // * If current direction is SOUTH
                  y--;
                  if (obstacleSet.count({x, y})) {
                      y++;  // Undo move if there's an obstacle
                      break;
                  }
              } else if (dir == 'W') { // * If current direction is WEST
                  x--;
                  if (obstacleSet.count({x, y})) {
                      x++;  // Undo move if there's an obstacle
                      break;
                  }
              } else { // * // * If current direction is EAST
                  x++;
                  if (obstacleSet.count({x, y})) {
                      x--;  // Undo move if there's an obstacle
                      break;
                  }
              }
          }
          maxAns = std::max(maxAns, x * x + y * y);
      } else if (commands[i] == -1) {  // Turn right
          if (dir == 'N') dir = 'E'; // * If prevDir was N, then then taking right will turn the robot to EAST
          else if (dir == 'E') dir = 'S'; 
          else if (dir == 'S') dir = 'W';
          else if (dir == 'W') dir = 'N';
      } else if (commands[i] == -2) {  // Turn left
          if (dir == 'N') dir = 'W';
          else if (dir == 'W') dir = 'S';
          else if (dir == 'S') dir = 'E';
          else if (dir == 'E') dir = 'N';
      }
  }
  return maxAns;
}