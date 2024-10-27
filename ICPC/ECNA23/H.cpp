#include <iostream>
#include <string>

using namespace std;

string a, s, t;
int T;

int main() {
    cin >> T;
    while (T--) {
        cin >> a >> s >> t;
        if (a.size() > 2) {
            cout << 0 << endl;
            continue;
        }
        
        int switches = 0;
        for (int i = 0; i + 1 < s.size(); ++i) {
            if (s[i] != s[i+1]) ++switches;
        }
        
        if (switches != 1) {
            cout << 0 << endl;
            continue;
        }
        
        switches = 0;
        for (int i = 0; i + 1 < t.size(); ++i) {
            if (t[i] != t[i+1]) ++switches;
        }
        
        if (switches != 1) {
            cout << 0 << endl;
            continue;
        }
        
        cout << 1 << endl;
    }
    
    
    return 0;
}