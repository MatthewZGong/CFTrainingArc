#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Define the partitionings
const int num_partitions = 5;
const int partitions[num_partitions][6] = {
    // Each partitioning assigns district IDs to the 6 cells (indices 0 to 5)
    // Partitioning 1
    {1, 1, 1, 2, 2, 2},
    // Partitioning 2
    {1, 1, 2, 2, 1, 2},
    // Partitioning 3
    {1, 2, 2, 1, 1, 2},
    // Partitioning 4
    {1, 1, 2, 1, 2, 2},
    // Partitioning 5
    {1, 1, 2, 2, 2, 1}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string row1, row2;
        cin >> row1 >> row2;
        vector<char> grid(2 * n);
        for (int i = 0; i < n; ++i) {
            grid[i] = row1[i];
            grid[n + i] = row2[i];
        }
        int total_votes = 0;
        for (int i = 0; i < n; i += 3) {
            // Extract the block of 6 cells
            char block[6];
            block[0] = grid[i];             // (1, i)
            block[1] = grid[i + 1];         // (1, i+1)
            block[2] = grid[i + 2];         // (1, i+2)
            block[3] = grid[n + i];         // (2, i)
            block[4] = grid[n + i + 1];     // (2, i+1)
            block[5] = grid[n + i + 2];     // (2, i+2)

            int max_votes = 0;
            // Try all partitionings
            for (int p = 0; p < num_partitions; ++p) {
                int district_votes[3] = {0, 0, 0};
                int district_As[3] = {0, 0, 0};
                for (int cell = 0; cell < 6; ++cell) {
                    int district = partitions[p][cell];
                    if (block[cell] == 'A')
                        district_As[district - 1]++;
                }
                int votes = 0;
                for (int d = 0; d < 2; ++d) {
                    if (district_As[d] >= 2)
                        votes++;
                }
                if (votes > max_votes)
                    max_votes = votes;
            }
            total_votes += max_votes;
        }
        cout << total_votes << '\n';
    }
    return 0;
}