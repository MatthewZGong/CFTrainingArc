#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;
 
#pragma region
#define ll long long
#pragma endregion
 

vector<int> chart1[1000005]; 
vector<int> chart2[1000005]; 
// bool visited[1000000];

bool isSame(){
    bool ans = true;
    for(int i = 0; i <= 1000000; i++){ 
        sort(chart1[i].begin(), chart1[i].end()); 
        sort(chart2[i].begin(), chart2[i].end());
        ans &= (chart1[i] == chart2[i]); 
    }
    return ans; 
}

int make_chart(vector<int>* chart, string& s, int i, int parent){ 
    if(i >= s.size()){ 
        return i;
    }
    int root = 0;
    while(i < s.size() && s[i] == ' '){ 
        i++; 
    }
    while( i < s.size() && '0' <= s[i] && s[i] <= '9'){ 
        root += (s[i] - '0');
        root *= 10;
        i++; 
    }
    root /= 10;
    // cout << root << endl;
    if(root) chart[parent].push_back(root);
    while( i < s.size() && s[i] != ')'){ 
        if(s[i] == '(') i = make_chart(chart, s, i+1, root);
        else i++; 
    }
    return i+1;
}

void solve(){
    string s; 
    getline(cin, s);
    make_chart(chart1, s, 0,0);
    getline(cin, s); 
    make_chart(chart2, s, 0, 0 );
    if(isSame()) cout << "YES" << endl; 
    
    else cout << "NO" << endl;
}   
 
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}<<<<<<<<<<<<<  ✨ Codeium AI Suggestion  >>>>>>>>>>>>>>
-void solve(){
-    string s; 
-    // int parent; 
-    // cin >> parent;
-    getline(cin, s);
-    make_chart(chart1, s, 0,0);
-    getline(cin, s); 
-    make_chart(chart2, s, 0, 0 );
-    if(isSame()) cout << "YES" << endl; 
-    
-    else cout << "NO" << endl;
-}   
+void solve() {
+    string input1;
+    getline(cin, input1);
+    make_chart(chart1, input1, 0, 0);
+
+    string input2;
+    getline(cin, input2);
+    make_chart(chart2, input2, 0, 0);
+
+    if (isSame()) {
+        cout << "YES" << endl;
+    } else {
+        cout << "NO" << endl;
+    }
+}
<<<<<  bot-cddb4884-438b-46e2-9b37-0174fabdb6bf  >>>>>
