#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n){
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
struct Line{ 
    Line(int x1,int  y1){ 
        start = x1; 
        end = y1; 
    }
    int start; 
    int end;
};
int a[2'00'001]; 
int b[2'00'001]; 

int solve(){
    int n; 
    cin >> n;
    for(int i =0 ; i < n; i++){ 
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){ 
        cin >> b[i]; 
    }
    ll beauty = 0;
    // vector<Line> start_point; 
    // vector<Line> end_point;
    ll best_start = -1'000'000'001; 
    ll best_end = 1'000'000'001;
    for(int i =0;  i < n; i++){ 
        beauty += abs(a[i]-b[i]); 
        ll start = min(a[i], b[i]);
        ll end = max(a[i], b[i]);
        best_start = max(best_start, start);
        best_end = min(best_end, end);
        // start_point.emplace_back(min(a[i], b[i]), max(a[i], b[i]));
        // end_point.emplace_back(min(a[i], b[i]), max(a[i], b[i]));j
    }
    // cout << beauty << " " << best_start << " " << best_end << endl;
    cout << beauty + max(0ll, 2*(best_start-best_end)) << endl;
    // sort(start_point.begin(), start_point.end(), [](const Line& l1, const Line& l2){ return l1.start > l2.start});
    // sort(end_point.begin(), end_point.end(), [](const Line& l1, const Line& l2){ return l1.end < l2.end});
    return 0;
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
