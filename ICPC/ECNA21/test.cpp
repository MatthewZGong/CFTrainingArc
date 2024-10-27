#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> park(n, vector<int>(m));

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> park[r][c];
        }
    }

    vector<int> linear;
    for (const auto& row : park) {
        for (int c : row) {
            if (c != -1) {
                linear.push_back(c);
            }
        }
    }

    sort(linear.begin(), linear.end());
    vector<int> rev = linear;
    reverse(rev.begin(), rev.end());

    int s = 0;
    int count1 = 0, count2 = 0;

    // First set of diagonals
    for (int c = -n + 1; c < m; ++c) {
        int r = n - 1;
        int c2 = c;

        vector<int> diag;

        while (r >= 0) {
            if (c2 >= 0 && c2 < m && park[r][c2] != -1) {
                diag.push_back(park[r][c2]);
            }
            --r;
            ++c2;
        }

        size_t len = diag.size();
        if (len > 0) {
            vector<int> sortedDiag(linear.begin() + s, linear.begin() + s + len);
            vector<int> rSortedDiag(rev.begin() + s, rev.begin() + s + len);

            vector<int> diagSorted = diag;
            sort(diagSorted.begin(), diagSorted.end());

            for (size_t i = 0; i < len; ++i) {
                if (diagSorted[i] != sortedDiag[i]) {
                    ++count1;
                }
                if (diagSorted[i] != rSortedDiag[i]) {
                    ++count2;
                }
            }
            s += len;
        }
    }

    s = 0;
    int count3 = 0, count4 = 0;

    // Second set of diagonals
    for (int c = 0; c < m + n - 1; ++c) {
        int r = n - 1;
        int c2 = c;

        vector<int> diag;

        while (r >= 0) {
            if (c2 >= 0 && c2 < m && park[r][c2] != -1) {
                diag.push_back(park[r][c2]);
            }
            --r;
            --c2;
        }

        size_t len = diag.size();
        if (len > 0) {
            vector<int> sortedDiag(linear.begin() + s, linear.begin() + s + len);
            vector<int> rSortedDiag(rev.begin() + s, rev.begin() + s + len);

            vector<int> diagSorted = diag;
            sort(diagSorted.begin(), diagSorted.end());

            for (size_t i = 0; i < len; ++i) {
                if (diagSorted[i] != sortedDiag[i]) {
                    ++count3;
                }
                if (diagSorted[i] != rSortedDiag[i]) {
                    ++count4;
                }
            }
            s += len;
        }
    }

    int best = min({count1, count2, count3, count4});

    cout << best << endl;

    return 0;
}