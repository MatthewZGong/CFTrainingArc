#include<bits/stdc++.h>
using namespace std;


#define ll long long
ll N, K;
ll t[300'001];

ll uf[300'001];
ll rank_uf[300'001]; 

ll find_parent(ll x){ 
    if(uf[x] == x){ 
        return x;
    }
    return uf[x] = find_parent(uf[x]);
}
ll union_find(ll x, ll y){ 
    if(y < 0){ 
        return 0;
    }
    ll p_x = find_parent(x); 
    ll p_y = find_parent(y); 
    if(p_x == p_y){ 
        return rank_uf[p_x];
    }
    if(rank_uf[p_x] > rank_uf[p_y]){ 
        rank_uf[p_x] += rank_uf[p_y]; 
        uf[p_y] = p_x;
        return rank_uf[p_x];
    }else{ 
        rank_uf[p_y] += rank_uf[p_x]; 
        uf[p_x] = p_y;
        return rank_uf[p_y];
    }
}

void solve(){
    cin >> N >> K;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq; 
    for(int i = 0; i < N; i++){ 
        cin >> t[i];
    }
    t[N] = 1000000000;
    for(int i = 0; i < K; i++){ 
        uf[i] = i;
        rank_uf[i] = 1;
        pq.push({t[i], i});
    }
    ll ans_farmer = -1;
    ll ans_time = -1;
    ll next_cow = K; 
    ll prev_time = -1; 
    ll prev_farmer = -1;
    while(next_cow <= N){
        auto [time, farmer] = pq.top();
        // cout << time << " " << farmer << endl;
        pq.pop();
        if(next_cow == N){ 
            ans_farmer= farmer;
            ans_time = time;
        }
        if(time == prev_time){ 
            union_find(prev_farmer, farmer);
        }
        pq.push({time+t[next_cow], farmer});
        next_cow++;
        prev_time = time;
        prev_farmer = farmer;
    }

    while(!pq.empty() && pq.top().first == ans_time){
        auto [time, farmer] = pq.top();
        pq.pop();
        if(time == ans_time){ 
            union_find(ans_farmer, farmer);
        }
    }
    ll ans_parent = find_parent(ans_farmer); 
    cout << ans_time << endl;
    // cout << N << " " << K << endl;
    for(int i = 0; i < K; i++){ 
        if(find_parent(i) == ans_parent){  
            cout << "1";
        }else{
            cout << "0";
        }
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    return 0;
}
