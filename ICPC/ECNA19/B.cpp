#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;
 
#pragma region
#define ll long long
#pragma endregion
int distances[1005][361][2]; 
//angle,dest,time
vector<tuple<int,int,int> > junctions[1005];
int edges[1005][1005];
int INF = 1000000000;

struct Node{ 
    int time; 
    int loc;
    int degree; 
    int visited; 
    bool operator<(const Node& rhs) const{ 
        return time > rhs.time;
    }
};

void solve(int n, int d, int left, int right){ 
    for(int i =0; i < 360; i++){ 
        distances[1][i][0] = 0;
    }
    priority_queue<Node> pq; 
    for(auto [angle, dest, time]: junctions[1]){
         pq.push({time,dest,edges[1][dest], 0});
         distances[dest][edges[1][dest]][0] = time;
    }
    while(!pq.empty()){ 
        auto [time,dest,angle,turn] = pq.top(); 
        pq.pop();
        // cout << time << " " << dest << " " << angle << " " << turn << endl;
        int comp_angle = (angle+180)%360;
        // int comp_angle = angle;
        int start = 0;
        if(dest == d){ 
            turn = 1;
        }
        for(int i = 0; i < junctions[dest].size(); i++){
            auto [ea, ed, et] = junctions[dest][i];
            int turn_right = (comp_angle-ea+360)%360; 
            int turn_left = (ea-comp_angle+360)%360;

            if((turn_right <= right || turn_left <= left) && time+et < distances[ed][edges[dest][ed]][turn]){ 
                pq.push({time+et,ed,edges[dest][ed], turn});
                // if(ed == d){ 
                //     turn = 1;
                // }
                distances[ed][edges[dest][ed]][turn] = time+et;
            }
        }
        // pq.pop(); 
    }

}

void solve(){
    int n, d, left, right; 
    cin >> n >> d >> left >> right; 
    for(int i =1 ; i <= n; i++ ){ 
        int m; 
        cin >> m; 
        for(int j =0; j < m; j++){ 
            int dest, time, angle; 
            cin >> dest >> time >> angle; 
            junctions[i].emplace_back(angle,dest,time);
            edges[dest][i] = angle;
            // cout << dest << " " << i  << " "  << angle << endl;
        }
        sort(junctions[i].begin(), junctions[i].end()); 
    }
    memset(distances, 63, sizeof(distances)); 
    int res = INF; 
    solve(n,d,left,right);
    for(int i =0; i < 361; i++){ 
        res = min(res, distances[1][i][1]);
    }
    // solve(n,d,left,right);
    if(res == INF){ 
        cout << "impossible" << endl; 
    }else{ 
        cout << res << endl;
    }

    
    
}   
 
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}