
#include <vector>
#include <algorithm>

using namespace std;

vector<int> readInput() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    return arr;
}

int findMinActions(const vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int median_index = (n + 1) / 2; 
    int median_value = arr[median_index - 1]; 

    int cnt = 1;
    for (int i = median_index; i < n; ++i) {
        if (arr[i] == arr[i - 1]) {
            cnt++;
        } else {
            break;
        }
    }

    return cnt;
}

void printResult(int cnt) {
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> arr = readInput();
        int minActions = findMinActions(arr);
        printResult(minActions);
    }

    return 0;
}