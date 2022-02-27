/**
 * It's not my code, but i've leanrd some neat tricks about *
 * moving in a "maze"
 * @source https://github.com/charles-wangkai/kickstart/blob/main/2013/Round%20A/Cross%20the%20maze/Solution.java
 *
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, iter = 0;
const unsigned int M = 1000000007;

int mod(int a, int m = M)
{
  return (a % m + m) % m;
}

int STEP_LIMIT = 10000;
char MOVES[4] = {'N', 'E', 'S', 'W'};
int R_OFFSETS[4] = {-1, 0, 1, 0};
int C_OFFSETS[4] = {0, 1, 0, -1};

bool isWall(const vector<vector<char>> &cells, int x, int y)
{
  int N = cells.size();

  return x == -1 || x == N || y == -1 || y == N || cells[x][y] == '#';
}

bool isEmpty(const vector<vector<char>> &cells, int x, int y)
{
  int N = cells.size();

  return x >= 0 && x < N && y >= 0 && y < N && cells[x][y] == '.';
}

int findDirection(int N, int sx, int sy)
{
  if (sx == 0)
  {
    if (sy == 0)
    {
      return 1;
    }
    else
    {
      return 3;
    }
  }
  else
  {
    if (sy == 0)
    {
      return 0;
    }
    else
    {
      return 2;
    }
  }
}

int findNextDirection(const vector<vector<char>> &maze, int x, int y, int direction)
{
  if (isWall(maze, x + R_OFFSETS[(direction + 3) % 4], y + C_OFFSETS[(direction + 3) % 4])) // verify if there-s a wall on the left
  {
    if (isEmpty(maze, x + R_OFFSETS[direction], y + C_OFFSETS[direction])) // if thre is a lear road ahead
    {
      return direction;
    }
    else if (isEmpty(maze, x + R_OFFSETS[(direction + 1) % 4], y + C_OFFSETS[(direction + 1) % 4])) // if there is a clear road on our right
    {
      return (direction + 1) % 4;
    }
    else if (isEmpty(maze, x + R_OFFSETS[(direction + 2) % 4], y + C_OFFSETS[(direction + 2) % 4])) // if there is a clear road oppouse to our facing
    {
      return (direction + 2) % 4;
    }
  }
  else if (isEmpty(maze, x + R_OFFSETS[(direction + 3) % 4], y + C_OFFSETS[(direction + 3) % 4])) // if our left is empty, there is the last place we can go
  {
    return (direction + 3) % 4;
  }
  // otherwise we are in an edge case where we are trapped
  return -1;
}

void solve()
{
  string ans = "";
  ll N;
  cin >> N;
  vector<vector<char>> maze(N, vector<char>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> maze[i][j];
    }
  }
  int sx, sy, ex, ey;
  cin >> sx >> sy >> ex >> ey;
  sx--;
  sy--;
  ex--;
  ey--;
  int x = sx, y = sy;
  int direction = findDirection(N, sx, sy);

  while (true)
  {
    direction = findNextDirection(maze, x, y, direction);
    if (ans.length() > STEP_LIMIT || direction == -1)
    {
      ans = "Edison ran out of energy";
      printf("Case #%lld: ", iter);
      cout << ans << endl;
      return;
    }
    // cout << x << " " << y << " " << direction << endl;
    ans += MOVES[direction];
    x += R_OFFSETS[direction];
    y += C_OFFSETS[direction];

    if (x == ex && y == ey)
    {
      break;
    }
  }

  printf("Case #%lld: ", iter);
  cout << ans.size() << endl
       << ans << endl;
}

int main()
{
  cin >> T;
  while (iter++ < T)
    solve();
}