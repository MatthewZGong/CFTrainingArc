#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
#pragma endregion

int graph[105][15][2];
// vector<int> lines[15]; 
vector<int> stations[105];
ll distances[105][105][15];
int solve(ll a, ll b, int m, int n){
    priority_queue<tuple<ll,int,int, int>> pq;
    for(int i =1; i <= n; i++){
        distances[1][0][i] = 0;
        ll na = -a;
        int zero = 0;
        if(graph[1][i][0]){ 
            pq.push(tie(na, graph[1][i][0],i,zero));
            distances[graph[1][i][0]][0][i] = a;
        }
        if(graph[1][i][1]){
            pq.push(tie(na,graph[1][i][1],i,zero));
            distances[graph[1][i][1]][0][i] = a;
        }
    }
    while(!pq.empty()){ 
        auto [dist, s, l, sw] = pq.top();
        dist = -dist;
        // cout << dist << " " << s << " " << l << " " << sw << endl;
        pq.pop();
        // if(distances[s][sw][l] < dist){
        //     continue;
        // }
        if(graph[s][l][0]){ 
            if(dist+a < distances[graph[s][l][0]][sw][l] ){ 
                ll next_dist = dist+a;
                distances[graph[s][l][0]][sw][l] = dist+a;
                next_dist = -next_dist;
                // cout << "HELLO 1" << endl; 
                pq.push(tie(next_dist, graph[s][l][0], l, sw));
            }
        }
        if(graph[s][l][1]){ 
            if(dist+a < distances[graph[s][l][1]][sw][l] ){ 
                ll next_dist = dist+a;
                distances[graph[s][l][1]][sw][l] = dist+a;
                next_dist = -next_dist;
                // cout << "HELLO 2" << endl; 

                pq.push(tie(next_dist, graph[s][l][1], l, sw));
            }
        }
        if(sw <= m){
            for(int i =1 ; i <= n; i++){ 
                if(graph[s][i][0] || graph[s][i][1]){ 
                    if( dist+b < distances[s][sw+1][i] ){ 
                        ll next_dist = dist+b;
                        distances[s][sw+1][i] = dist+b;
                        next_dist = -next_dist;
                        int nxt_sw = sw+1;
                        pq.push(tie(next_dist, s, i, nxt_sw));
                    }
                }
            }
        }
    }
    // ll res = 100000000;
    // for(int i =1; i <= n; i++){ 
    //     if(graph[m][i][0] || graph[m][i][1]){ 
    //         res = min(res, distances[m][i]);
    //     } 
    // }
    return -get<0>(pq.top());
}
void solve(){
   int m,n; 
   cin >> m >> n; 
   int a;
   cin >> a; 
   for(int i =1; i <= n; i++){ 
        int s; 
        cin >> s; 
        int prev = 0;
        for(int j =0; j < s; j++){ 
            int station; 
            cin >> station; 
            if(prev){
                graph[prev][i][1] = station;
                graph[station][i][0] = prev;
            }
            prev = station;
            // stations[station].push_back(i);
        }
   }
//    for(int i = 1; i <=n; i++){
//         cout << graph[2][i][0] << " " << graph[2][i][1] << endl;
//    }
    int t; 
    cin >> t;
    memset(distances, 63, sizeof(distances));
    solve(a,0,m,n); 
    // for(int i =0; i <= m;i++){ 
    //     for(int j = 1; j <= n; j++){ 
    //         cout << distances[m][i][j] << " ";
    //     }
    //     cout << endl; 
    // }
    while(t--){
        int b;
        cin >> b;
        ll res = distances[m][0][1]; 
        
        for(int i =0; i <= m;i++){ 
            for(int j = 1; j <= n; j++){ 
                res = min(distances[m][i][j]+b*i, res);
            }
        }
        cout << res << endl;
        // cout << solve(a,b, m, n) <<endl;
    }

    return;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}
