#include<bits/stdc++.h>

using namespace std;
#pragma region
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

int a[100000+10];
int b[100000+10];
int c[100000+10];
void solve(){
    int n, m; 
    cin >> n >> m; 
    vector<int> colors[n+1];
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int diff = 0;
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
        if(b[i] != a[i]){
            ++diff;
            colors[b[i]].push_back(i);
        }
    }
    for(int i = 1; i <= m; ++i){
        cin >> c[i];
    }
    int last = -1; 
    for(int i =1 ; i <=n; ++i){
        if(c[m] == b[i]){
            last = i;
        }
    }
    if(last == -1){
        cout << "NO" << endl;
        
        return;
    }
    vector<int> res;
    int current;
    for(int i = m; i >= 1; i--){
        current = c[i];
        int index;
        if(colors[current].size() == 0){
            if(i == m){
                res.push_back(last);
            } else{
                res.push_back(res.front());
            }                     
            continue;
        }
        --diff;
        index = colors[current].back();
        colors[current].pop_back();
        res.push_back(index);
    }

    if(diff){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl; 
    for(int i = res.size()-1; i >=0; i--){
        cout << res[i] << " ";
    }
    cout << endl;

}


int main(){ 
    int t; 
    cin >> t; 
    while(t--){
        solve();
    }

}
