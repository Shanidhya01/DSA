// given a grid of nxm size.every cell of the grid are marked as 'L' ,'R','U','D'. Character 
// on a cell denotes if you are go standby at that cell , what direction you can move
// CHECK if we start from (0,0) and we can reach to (n-1,m-1) cell or not.
//[[R,R,D,R],[D,L,D,L],[U,D,L,''],[U,R,R,R]]

// #include <bits/stdc++.h>
// using namespace std;
// bool isValid(int x, int y, int n, int m) {
//     return (x >= 0 && x < n && y >= 0 && y < m);
// }
// bool canReachDestination(vector<vector<char>>& grid, int n, int m) {
//     queue<pair<int, int>> q;
//     q.push({0, 0});
//     vector<vector<bool>> visited(n, vector<bool>(m, false));
//     visited[0][0] = true;
//     while (!q.empty()) {
//         pair<int, int> curr = q.front();
//         q.pop();
//         int x = curr.first;
//         int y = curr.second;
//         if (x == n - 1 && y == m - 1) {
//             return true;
//         }
//         char direction = grid[x][y];
//         int nx = x, ny = y;
//         if (direction == 'R') ny++;
//         else if (direction == 'L') ny--;
//         else if (direction == 'U') nx--;
//         else if (direction == 'D') nx++;
//         else continue;  
//         if (isValid(nx, ny, n, m) && !visited[nx][ny]) {
//             visited[nx][ny] = true;
//             q.push({nx, ny});
//         }
//     }
//     return false;
// }

// int main() {
//     vector<vector<char>> grid = {
//         {'R', 'R', 'D', 'R'},
//         {'D', 'L', 'D', 'L'},
//         {'U', 'D', 'L', ' '},  // Assuming ' ' is a valid cell
//         {'U', 'R', 'R', 'R'}
//     };
//     int n = grid.size();
//     int m = grid[0].size();
//     if (canReachDestination(grid, n, m)) {
//         cout << "Yes, we can reach the destination." << endl;
//     } else {
//         cout << "No, we cannot reach the destination." << endl;
//     }
//     return 0;
// }



#include <iostream>
#include <vector>
#include <string>
using namespace std;
pair<int, int> move(const vector<vector<char>>& grid, pair<int, int> pos) {
    int n = grid.size();
    int m = grid[0].size();
    int x = pos.first;
    int y = pos.second;
    if (x < 0 || y < 0 || x >= n || y >= m) return {-1, -1}; // out of bounds
    char dir = grid[x][y];
    if (dir == 'U') x--;
    else if (dir == 'D') x++;
    else if (dir == 'L') y--;
    else if (dir == 'R') y++;
    else return {-1, -1}; 
    if (x < 0 || y < 0 || x >= n || y >= m) return {-1, -1}; 
    return {x, y};
}
bool canReachEnd(const vector<vector<char>>& grid) {
    pair<int, int> slow = {0, 0};
    pair<int, int> fast = {0, 0};
    int n = grid.size();
    int m = grid[0].size();
    while (true) {
        slow = move(grid, slow);
        fast = move(grid, move(grid, fast));
        if (slow.first == -1 || fast.first == -1) return false; // out of bounds
        if (slow == make_pair(n - 1, m - 1) || fast == make_pair(n - 1, m - 1)) return true;
        if (slow == fast) return false; // cycle detected
    }
}

int main() {
    vector<vector<char>> grid = {
        {'R', 'R', 'D', 'R'},
        {'D', 'L', 'D', 'L'},
        {'U', 'D', 'L', ' '},
        {'U', 'R', 'R', 'R'}
    };
    if (canReachEnd(grid)) {
        cout << "Yes, we can reach the destination." << endl;
    } else {
        cout << "No, we cannot reach the destination." << endl;
    }
    return 0;
}