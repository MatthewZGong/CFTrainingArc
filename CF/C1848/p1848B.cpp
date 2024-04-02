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
#pragma endregion



pair<int,int> colors[200005];

int prev_colors[200005];
void clear(int n, int k){ 
    for(int i =1; i <= n; ++i ){ 
         prev_colors[i] = 0;
    }
    for(int i =1; i <= k; ++i){ 
        colors[i].first = 0; 
        colors[i].second = 0;
    }
}

int solve(){
    int n,k;
    cin >> n; 
    cin >> k;
    for(int i =1; i <= n; ++i){ 
        int c; 
        cin >> c; 
        int diff = i -  prev_colors[c]-1; 
        // cout << diff << " ";
        if(diff > colors[c].first){
            int holder = colors[c].first; 
            colors[c].first = diff;
            colors[c].second = holder;  
        }else if(diff > colors[c].second){ 
            colors[c].second = diff;
        }
        prev_colors[c] = i;
    }

    int res = n; 
    for(int i = 1; i <= k; ++i){ 
        int diff = n-prev_colors[i];
        if(diff > colors[i].first){
            int holder = colors[i].first; 
            colors[i].first = diff;
            colors[i].second = holder;  
        }else if(diff > colors[i].second){ 
            colors[i].second = diff;
        }
        // cout << colors[i].first <<" " <<colors[i].second << endl;
        int current = max(colors[i].first/2, colors[i].second); 
        res = min(current,res);
    }
    cout << res << endl; 
    clear(n,k);
    return 0;
}


int main(){
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
