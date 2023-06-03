#include<bits/stdc++.h>
 
using namespace std;
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
int a[100000+10];
int b[100000+10];
void solve(){
    int n, m; 
    cin >> n >> m; 
    vector<int> colors[n+1];
    int c[n+1];
    for(int i = 0; i <= n; ++i){
        c[i] = 0;
    }
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        c[a[i]] = i;
    }
    int diff = 0;
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
        if(b[i] != a[i]){
            ++diff;
            colors[b[i]].push_back(i);
        }
    }
    // print(a, n); 
    // print(b,n);
    // cout << "color start" << endl;
    // for(int i = 1; i <= n; ++i){
    //     if(colors[i].size()){
    //         for(int j =0; j  < colors[i].size(); j++ ){
    //             cout << colors[i][j] << " ";
    //         }
    //     }else{
    //         cout << 'E';
    //     }
    //     cout << endl;
    // }
    // cout << "color end" << endl;
    int counter = 0;
    vector<int> res;
    int current;
    for(int i =1; i <= m; ++i){
        cin >> current;
        int index;
        if(colors[current].size()){
            --diff;
            index = colors[current].back();
            colors[current].pop_back();
            c[current] = index;
        }else if(c[current]){
            index = c[current];
        }else{
            counter++;
            continue;
        }
        while(counter--){
            res.push_back(index);
        }
        res.push_back(index);
        counter = 0;
    }
    if(counter != 0 || diff != 0){
        // cout << "Diff " << diff << endl;
        // cout << "Counter " << counter << endl;
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl; 
    for(int i = 0; i < res.size(); i++){
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