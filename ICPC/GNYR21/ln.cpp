
#include <bits/stdc++.h>

#define INF 1000000000
typedef long long ll; 

using namespace std;

int N, K;
bool col[13][13];
bool row[13][13];

int grid[13][13];

bool hn[13][13];
bool vn[13][13];

bool in_bounds(int x) {
    return x >= 1 && x <= N;
}

int biggest = 0;

void print_grid() {
    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            cout << grid[r][c] << ' ';
        }
        cout << endl;
    }
}

void search(int i, int j) {
    if (N * i + j > biggest) {
        cout << "Made it to " << i << " " << j << endl;
        biggest = N * i + j;
        print_grid();
    }

    if (hn[i][j-1] && vn[i-1][j]) {
        set<int> a, b;
        if (in_bounds(grid[i][j-1] + 1)) a.insert(grid[i][j-1] + 1);
        if (in_bounds(grid[i][j-1] - 1)) a.insert(grid[i][j-1] - 1);
        if (in_bounds(grid[i-1][j] + 1)) b.insert(grid[i-1][j] + 1);
        if (in_bounds(grid[i-1][j] - 1)) b.insert(grid[i-1][j] - 1);
        for (int c : a) {
            if (b.count(c) && !row[i][c] && !col[j][c]) {
                grid[i][j] = c;
                row[i][c] = col[j][c] = true;
                if (j + 1 <= N) search(i, j+1);
                else search(i+1, 1);
                row[i][c] = col[j][c] = false;
                grid[i][j] = 0;
            }
        }
        return;
    } else if (hn[i][j-1]) {
        set<int> s;
        if (in_bounds(grid[i][j-1] + 1)) s.insert(grid[i][j-1] + 1);
        if (in_bounds(grid[i][j-1] - 1)) s.insert(grid[i][j-1] - 1);
        for (int c : s) {
            if (!row[i][c] && !col[j][c]) {
                grid[i][j] = c;
                row[i][c] = col[j][c] = true;
                if (j + 1 <= N) search(i, j+1);
                else search(i+1, 1);
                row[i][c] = col[j][c] = false;
                grid[i][j] = 0;
            }
        }
        return;
    } else if (vn[i-1][j]) {
        set<int> s;
        if (in_bounds(grid[i-1][j] + 1)) s.insert(grid[i-1][j] + 1);
        if (in_bounds(grid[i-1][j] - 1)) s.insert(grid[i-1][j] - 1);
        for (int c : s) {
            if (!row[i][c] && !col[j][c]) {
                grid[i][j] = c;
                row[i][c] = col[j][c] = true;
                if (j + 1 <= N) search(i, j+1);
                else search(i+1, 1);
                row[i][c] = col[j][c] = false;
                grid[i][j] = 0;
            }
        }
        return;
    }

    for (int k = 1; k <= N; ++k) {
        if (!grid[i][j]) {
            if (!row[i][k] && !col[j][k]) {
                row[i][k] = col[j][k] = true;
                grid[i][j] = k;

                if (j + 1 <= N) search(i, j+1);
                else search(i+1, 1);

                grid[i][j] = 0;
                row[i][k] = col[j][k] = false;
            }
        } else {
            if (j + 1 <= N) search(i, j+1);
            else search(i+1, 1);
        }
    }

    if (i == N+1) {
        for (int r = 1; r <= N; ++r) {
            for (int c = 1; c <= N; ++c) {
                cout << grid[r][c] << ' ';
            }
            cout << endl;
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= 2 * N - 1; ++i) {
        string s; cin >> s;
        if (i % 2 == 0) {
            for (int j = 0; j < (int) s.size(); ++j)
                vn[i/2][j+1] = s[j] - '0';
        } else {
            for (int j = 0; j < (int) s.size(); ++j)
                hn[i/2 + 1][j+1] = s[j] - '0';
        }
    }


    for (int i = 1; i <= K; ++i) {
        int r, c, v;
        cin >> r >> c >> v;
        row[r][v] = col[c][v] = true;
        grid[r][c] = v;
    }

    search(1, 1);

    return 0;
}