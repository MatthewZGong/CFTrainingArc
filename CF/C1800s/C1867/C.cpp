#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
void print1(int v[], int n){
    for(int i =1 ; i <= n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T>
void print(vector<T> v){
    for(int i =0 ; i < v.size(); ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

char m[1005][1005]; 
int solveLayer(int start, int end){ 
    vector<char> top; 
    vector<char> bottom;
    vector<char> left;
    vector<char> right;
    for(int i = start; i < end; i++){ 
        top.push_back(m[start][i]);
        right.push_back(m[i][end]); 
        bottom.push_back(m[end][i+1]);
        left.push_back(m[i+1][start]);
    }
    reverse(bottom.begin(), bottom.end());
    reverse(left.begin(), left.end());
    int res = 0;
    for(int i = 0; i < end-start; i++){
        char large = max(top[i], max(bottom[i], max(left[i], right[i])));
        res += top[i]-large;
        res += bottom[i]-large;
        res += left[i]-large;
        res += right[i]-large;
    }
    return -res;
}
void solve(){
    int n; 
    cin >> n; 
    for(int i =0; i <n ;i++){ 
        for(int j =0; j < n; j++){ 
            cin >> m[i][j];
        }
    }
    int start = 0; 
    int end = n-1; 
    int res = 0;
    while(start < end){ 
        res += solveLayer(start, end);
        // cout << start << " " << end << " " << res << endl;

        start += 1; 
        end -=1;
    }
    cout << res << endl;
    
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
