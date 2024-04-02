#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;
 
#pragma region
#define ll long long
#pragma endregion
int a[50005];
int t[50005];
int g[50005];
int c[50005];
pair<int,int> res[4];

void get_range(int x, int y){ 
    res[0].first = a[y]-a[x-1];
    res[0].second = 3; 
    res[1].first = t[y]-t[x-1];
    res[1].second = 2; 
    res[2].first = g[y]-g[x-1];
    res[2].second = 1; 
    res[3].first = c[y]-c[x-1];
    res[3].second = 0; 
    sort(res, res+4); 
    for(int i = 3; i >= 0; i--){ 
        if(res[i].second == 3){ 
            cout << 'A';
        }
        if(res[i].second == 2){ 
            cout << 'T';
        }
        if(res[i].second == 1){ 
            cout << 'G';
        }
       if(res[i].second == 0){ 
            cout << 'C';
        }
    }
    cout << endl;
}
void solve(){
    string dna; 
    cin >> dna; 
    for(int i =0; i < dna.size(); i++){ 
        if(dna[i] == 'A'){ 
            a[i+1] = 1; 
        }else if(dna[i] == 'T'){ 
            t[i+1] = 1; 
        }else if(dna[i] == 'G'){ 
            g[i+1] = 1; 
        }else{ 
            c[i+1] = 1; 
        }
    }
    for(int i =1; i <= dna.size()+1; i++){ 
        a[i] = a[i-1]+a[i]; 
        t[i] = t[i-1]+t[i]; 
        g[i] = g[i-1] + g[i];
        c[i] = c[i-1] + c[i];
    } 
    int m; 
    cin >> m; 
    while(m--){ 
        int x, y; 
        cin >> x >> y; 
        get_range(x,y); 
    }
}   
 
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}