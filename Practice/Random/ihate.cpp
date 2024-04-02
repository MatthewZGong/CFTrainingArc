#include <bits/stdc++.h>

#define INF 1000000000
typedef long long ll; 

using namespace std;

int dist[37][37][37][37];

int start[4][2];
int target[4][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    memset(dist, 63, sizeof dist);

    cin >> start[0][0] >> start[0][1];
    cin >> start[1][0] >> start[1][1];
    cin >> start[2][0] >> start[2][1];
    cin >> start[3][0] >> start[3][1];

    cin >> target[0][0] >> target[0][1];
    cin >> target[1][0] >> target[1][1];
    cin >> target[2][0] >> target[2][1];
    cin >> target[3][0] >> target[3][1];

    auto f = [](int i, int j) -> int {
        return 6 * i + j;
    };

    auto to_coords = [](int i) -> pair<int, int> {
        return {i / 6, i % 6};
    };

    auto in_bounds = [&](int i, int j) -> bool {
        return i >= 0 && i < 6 && j >= 0 && j < 6;
    };

    queue<array<int, 4>> bfs;
    bfs.push({
        f(start[0][0], start[0][1]), 
        f(start[1][0], start[1][1]), 
        f(start[2][0], start[2][1]), 
        f(start[3][0], start[3][1])}
    );

    dist[f(start[0][0], start[0][1])]
        [f(start[1][0], start[1][1])]
        [f(start[2][0], start[2][1])]
        [f(start[3][0], start[3][1])] = 0;

    while (!bfs.empty()) {
        auto [a, b, c, d] = bfs.front();
        bfs.pop();

        for (int i : array<int, 4>{a,b,c,d}) {
            for (int k = 0; k < 4; ++k) {
                auto [x,y] = to_coords(i);
                while (1) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    bool ok = make_pair(nx, ny) != to_coords(a)
                                && make_pair(nx, ny) != to_coords(b)
                                && make_pair(nx, ny) != to_coords(c)
                                && make_pair(nx, ny) != to_coords(d);

                    if (in_bounds(nx, ny) && ok) {
                        x = nx;
                        y = ny;
                    } else {
                        break;
                    }
                }

                assert((i==a)+(i==b)+(i==c)+(i==d) == 1);

                if (i == a) {
                    if (dist[f(x,y)][b][c][d] > dist[a][b][c][d] + 1) {
                        dist[f(x,y)][b][c][d] = dist[a][b][c][d] + 1;
                        bfs.push({f(x,y), b, c, d});
                    } 
                } else if (i == b) {
                    if (dist[a][f(x,y)][c][d] > dist[a][b][c][d] + 1) {
                        dist[a][f(x,y)][c][d] = dist[a][b][c][d] + 1;
                        bfs.push({a, f(x,y), c, d});
                    } 
                } else if (i == c) {
                    if (dist[a][b][f(x,y)][d] > dist[a][b][c][d] + 1) {
                        dist[a][b][f(x,y)][d] = dist[a][b][c][d] + 1;
                        bfs.push({a, b, f(x,y), d});
                    }
                } else if (i == d) {
                    if (dist[a][b][c][f(x,y)] > dist[a][b][c][d] + 1) {
                        dist[a][b][c][f(x,y)] = dist[a][b][c][d] + 1;
                        bfs.push({a, b, c, f(x,y)});
                    }
                }
            }
        }
    }
    

    vector<int> to_check = {f(target[0][0], target[0][1]), f(target[1][0], target[1][1]), f(target[2][0], target[2][1]), f(target[3][0], target[3][1])};
    std::sort(to_check.begin(), to_check.end());

    int ans = INF;
    array<int, 4> source = {
        f(start[0][0], start[0][1]), 
        f(start[1][0], start[1][1]), 
        f(start[2][0], start[2][1]), 
        f(start[3][0], start[3][1])
    };

    vector<array<int, 4>> path;
    do {
        if (dist[to_check[0]][to_check[1]][to_check[2]][to_check[3]] < ans) {
            ans = dist[to_check[0]][to_check[1]][to_check[2]][to_check[3]]; 
            path.clear();
            path.push_back(to_check);
        }
    } while (next_permutation(to_check.begin(), to_check.end()));

    cout << ans << '\n';
    return 0;
}

