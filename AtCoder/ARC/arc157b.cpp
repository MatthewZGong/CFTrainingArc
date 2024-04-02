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
vector<tuple<int, int,int,int>> x;
vector<tuple<int,int,int,int>> y;
int N, K;
string s; 
int add(int start, int end){ 
    // cout << start << " " << end << endl;
    int close = start == 0 || end == N; 

    if(s[start] == 'X'){ 
        x.push_back({close, end-start, start, end});
        return 0; 
    }else{ 
        y.push_back({close, end-start, start, end});
        return (end-start)-1;
    }
}
int solve(){
    cin >>  N >> K; 
    cin >> s; 
    int start = 0;
    int i = 1;
    int pairs = 0;
    for(; i < N; i++){ 
        if(s[i] != s[i-1]){ 
            pairs += add(start, i);
            start = i;
        }
    }
    add(start, i);
    sort(x.begin(), x.end()); 
    sort(y.begin(), y.end(), [](const tuple<int, int,int,int>&  l, const tuple<int, int,int,int>& r){
        if(get<0>(l) > get<0>(r)) return true;
        if(get<0>(l) < get<0>(r)) return false; 
        return get<1>(l) > get<1>(r);
    });
    // for(int i =0; i < y.size(); i++){ 
    //     cout << y[i].first << "|" << y[i].second << " ";
    // }
    // cout << endl;
    i = 0; 
    while(K > 0 && i < x.size()){ 
        auto& [closed, range, start,end] = x[i]; 
        if(!closed || start != 0){
            for(int i =0; i < min(K,range); i++){ 
                s[start+i] = 'Y';
            }
        }else{ 
            for(int i = 1; i <= min(K,range); i++){ 
                s[end-i] = 'Y';
            }
        }
        K -= range;
        i++;
    }
    // cout << pairs <<" " << K << endl;
    i = 0; 
    while(K > 0 && i < y.size()){ 
        auto& [closed, range, start,end] = y[i]; 
        if(!closed && end != N){
            for(int i =0; i < min(K,range); i++){ 
                s[start+i] = 'X';
            }
        }else{ 
            for(int i = 1; i <= min(K,range); i++){ 
                s[end-i] = 'X';
            }
        }
        K -= range;
        i++;
    }
    pairs = 0;
    start = 0;
    i = 1;
    for(; i < N; i++){ 
        // cout << s[i] << endl;
        if(s[i] != s[i-1]){ 
            pairs += add(start, i);
            start = i;
        }
    }
    pairs += add(start,i);
    // cout << s << endl;
    cout << pairs << endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    solve();


}
