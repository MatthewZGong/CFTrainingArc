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

int solve(){
    int T, C; 
    cin >> T >> C;
    unordered_map<int, int> targets;    
    array<unordered_map<int, int>, 4> hits;
    for(int i = 0; i < T; i++){ 
        int t; 
        cin >> t;
        for(int j  = 0; j < 4; j++){
            hits[j][t] = 0;
        }
        targets[t] = 0;
    }
    string cmd; 
    cin >> cmd; 
    array<int,4> offsets = {-2, -1, 1, 2};
    array<int,4> destroyed = {0, 0, 0, 0};
    // cout << "got here lul" << endl;
    int pos = 0;
    int ans = 0;
    for(int i =0; i < cmd.size(); i++){ 
        if( cmd[i] == 'R'){
            pos++; 
        }else if( cmd[i] == 'L')
        {
            pos--;
        }else{ 
            if(targets.find(pos)  != targets.end())
            { 
                targets[pos]++;
                if(targets[pos] == 1) ans++;
            }
            for( int j = 0; j < 4; j++)
            {
                int off = offsets[j]; 
                int cur_pos = pos + off;
                unordered_map<int, int> &hit = hits[j];
                if( hit.find(cur_pos) != hit.end() )
                { 
                    if(hit[cur_pos] == 0) destroyed[j]++;
                    hit[cur_pos]++;
                }
            }
        }
    }
    // cout << ans << endl;
    // for(int i = 0; i < 4; i++){
    //     cout << destroyed[i] << " ";
    // }
    // cout << endl;
    pos = 0;
    // int ans =0;
    for(int i =0; i < cmd.size(); i++){
        // cout << pos << " " << ans << endl;
        if( cmd[i] == 'R'){
            //R -> F: -1 
            int additional = 0;
            if(hits[1].find(pos) != hits[1].end() && hits[1][pos] == 0) additional++;
            ans = max(ans, destroyed[1]+additional);
            //R -> L: -2
            ans = max(ans, destroyed[0]);
            pos++; 
        }else if( cmd[i] == 'L')
        {
            //L -> F: 1
            int additional = 0;
            if(hits[2].find(pos) != hits[2].end() && hits[2][pos] == 0) additional++;
            ans = max(ans, destroyed[2]+additional);
            //L -> R: 2
            ans = max(ans, destroyed[3]);
            pos--;
        }else{
           //removed hits from offset;
            for( int j = 0; j < 4; j++)
            {
                int off = offsets[j]; 
                int cur_pos = pos + off;
                unordered_map<int, int> &hit = hits[j];
                if( hit.find(cur_pos) != hit.end() )
                {                  
                    if(hit[cur_pos] == 1) destroyed[j]--;
                    hit[cur_pos]--;
                    assert (hit[cur_pos] >= 0);
                    // hit[cur_pos] = max(hit[cur_pos], 0);
                    
                }
            } 
            //F -> R: 1
            ans = max(ans, destroyed[2]);

            //F -> L: -1
            ans = max(ans, destroyed[1]);

            for( int j = 0; j < 4; j++)
            {
                int cur_pos = pos;
                unordered_map<int, int> &hit = hits[j];
                if( hit.find(cur_pos) != hit.end() )
                { 
                    if(hit[cur_pos] == 0) destroyed[j]++;
                    hit[cur_pos]++;
                }
            }


            //add hits from normal position;

        }
    }
    // ans = max(ans, destroyed[0]);
    // for(int i =0; i <4; i++){ 
    //     cout << destroyed[i] << " ";
    // }
    // cout << endl;
    for(int i =0; i < 4; i++){
        assert(destroyed[i] == destroyed[0]);
    }
    cout << ans << endl;
    return 0;












}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();

}
