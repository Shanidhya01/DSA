// In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].
// A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
// https://camo.githubusercontent.com/20c68f6577a80d6a712f17617b96eaf6673b69ccad624419c485684b4ecdef5f/68747470733a2f2f666173746c792e6a7364656c6976722e6e65742f67682f646f6f63732f6c656574636f6465406d61696e2f736f6c7574696f6e2f313130302d313139392f313139372e4d696e696d756d2532304b6e696768742532304d6f7665732f696d616765732f6b6e696768742e706e67
// Return the minimum number of steps needed to move the knight to the square [x, y]. It is guaranteed the answer exists.
// Example 1:
// Input: x = 2, y = 1
// Output: 1
// Explanation: [0, 0] -> [2, 1] is one possible move.
// Example 2: 
// Input: x = 5, y = 5
// Output: 4
// Explanation: [0, 0] -> [2, 1] -> [4, 2] -> [5, 4] -> [5, 5] is one possible path.

// Constraints:
// -300 <= x, y <= 300
// 0 <= |x| + |y| <= 300

#include<bits/stdc++.h>
using namespace std;
int minKnightMoves(int x, int y) {
    x += 310;
    y += 310;
    int ans = 0;
    queue<pair<int, int>> q;
    q.push({310, 310});
    vector<vector<bool>> vis(700, vector<bool>(700));
    vis[310][310] = true;
    vector<vector<int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    while (!q.empty()) {
      for (int k = q.size(); k > 0; --k) {
        auto p = q.front();
        q.pop();
        if (p.first == x && p.second == y) return ans;
        for (auto& dir : dirs) {
          int c = p.first + dir[0], d = p.second + dir[1];
          if (!vis[c][d]) {
            vis[c][d] = true;
            q.push({c, d});
          }
        }
      }
      ++ans;
    }
  return -1;
}
int main(){
  cout<<minKnightMoves(5, 5); 
  return 0;
}