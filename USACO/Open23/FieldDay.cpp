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
int dist[5'00'000];
int teams[100000];
int to_binary(){ 
    string s; 
    cin >> s; 
    int binary = 0;
    for(int i = 0; i < s.size(); i++){ 
        binary <<= 1; 
        if(s[i] == 'G'){ 
            binary++;
        }
    }
    return binary;
}
void solve(){
    int n, c; 
    cin >> c >> n;
    memset(dist, 63, sizeof(dist));
    vector<int> bfs_front; 
    vector<int> bfs_back; 
    for(int i = 0; i < n; i++){ 
        teams[i] = to_binary();
        dist[teams[i]] = 0;
        bfs_front.push_back(teams[i]);
    }

    while(bfs_front.size()){
        for (size_t i = 0; i < bfs_front.size(); i++)
        {
            int current = bfs_front[i]; 
            for(int j = 0; j < c; j++){ 
                int next = current ^ (1 << j);
                if(dist[next] > dist[current] + 1){ 
                    dist[next] = dist[current] + 1;
                    bfs_back.push_back(next);
                }
            }   
        }
        swap(bfs_front, bfs_back);
        bfs_back.clear();        
    }
    int cap = (1 << c)-1;
    for(int i = 0; i < n; i++){ 
        cout << c - dist[cap^teams[i]] << endl;
    }

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
    solve();

}
