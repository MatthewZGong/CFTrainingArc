#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
using namespace std;
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
int chord[210];
int rel_chord[210]; 
int suffix[210];
int solve(){
    int n, k;
    cin >> n >> k; 
    // int rel_chord[2*n+1]; 
    // for(int i =0; i < 2*n+1; i++){
    //     rel_chord[i] = 0;
    // }
    for(int i =0; i < k; ++i){
        int x, y; 
        cin >> x >> y; 
        chord[x] = y; 
        chord[y] = x;
    }
    int size = 0; 
    for(int i =1; i <= 2*n; i++){
        if(chord[i] == 0){
            rel_chord[size+1] = i;
            size++;
        }
    }
    for(int i =1; i <= size/2; i++){
        chord[rel_chord[i]] = rel_chord[i+size/2];
        chord[rel_chord[i+size/2]] = rel_chord[i];
    }
    int res =0;
    for(int i =1; i <= 2*n; i++){
        int open = 0; 
        if(chord[i] > i){
            chord[i] = -1;
            for(int j = i+1; j <= 2*n; j++){
                if(chord[j] == i){
                    chord[j] = -1;
                    break;
                }else if(chord[j] == -1){
                    continue;
                }else if(chord[j] > j){
                    res += 1;
                }else{
                    res -= 1;
                }
            }
        }else{

        }
    }
    // print(chord, 2*n+1);
    // print(suffix, 2*n+1);
    cout << res << endl;
    return 0;
}
void clear(){
    for(int i =0; i < 210; ++i){
        chord[i] = 0;
    }
}

int main(){ 
    int t; 
    cin >> t; 
    while(t--){
        solve();
        clear();
    }

}
