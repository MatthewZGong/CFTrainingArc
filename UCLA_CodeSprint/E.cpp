#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n, int i = 0){
    for(; i < n; ++i){ 
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
ll inv_mod_prime(ll a, ll MOD) {
  return a <= 1 ? a : MOD - (MOD/a) * inv_mod_prime(MOD % a, MOD) % MOD;
}
// void sieve(int n){ 
//     // cout << "sieved" << endl;
//     memset(lowest_divisors, 63, sizeof(lowest_divisors));
//     for(int i = 2; i <= n; ++i){ 
//         // cout << i << endl;
//         if(lowest_divisors[i] > i){ 
        
//             primes.push_back(i);
//             adj.push_back({});
//             lowest_divisors[i] = primes.size()-1;
//             for(int j = i+i; j <= A_SIZE; j+= i){ 
//                 lowest_divisors[j] = min(lowest_divisors[j], int(primes.size()-1));
//             }
//         }
//     }
//     for(int i = n; i <= A_SIZE; ++i){ 
//         if(lowest_divisors[i] > i){ 
//             lowest_divisors[i] = primes.size();
//             primes.push_back(i);
//             adj.push_back({}); 
//         }
//     }
// }
#pragma endregion

struct Node{
    Node( int m, int d, int e): mask(m), dist(d), added_edge(e){}
    
    int mask; 
    int dist;
    int added_edge;  
    
};

const int k = 16;

vector<Node> graph[1<<15];
pair<int,int> distances[1<<15];
queue<int> bfs[k+1]; 

bool used[1 << 15];



void solve(){
    int n;
    
    cin >> n;
    for(int i =0; i < n*( 1 << (n-1) ); i++){ 
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back({b, cost, 0});
        graph[b].push_back({a, cost, 0});
        
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        distances[mask] = {INT_MAX, INT_MAX};
        int mask_cnt = __builtin_popcount(mask);
        for(int submask = mask; submask; submask = (submask - 1) & mask) {
            int submask_cnt = __builtin_popcount(submask ^ mask);
            if (submask_cnt > 4 || submask_cnt <= 1) continue;
            graph[mask].push_back({submask, submask_cnt*submask_cnt, 1});
            graph[submask].push_back({mask, submask_cnt*submask_cnt, 1});
        }
        if(mask_cnt > 4 || mask_cnt <= 1) continue;
        graph[mask].push_back({0, mask_cnt*mask_cnt, 1});
        graph[0].push_back({mask, mask_cnt*mask_cnt, 1});
        
    }
    bfs[0].push(0);
	distances[0] = {0,0};
	int pos = 0, num = 1;

	while (num > 0)
	{
		while (bfs[pos % (k + 1)].empty())
		{
			++pos;
		}
		int u = bfs[pos % (k + 1)].front(); 
        // cout << "start: "  <<  u << endl;
		bfs[pos % (k + 1)].pop();
		--num;
		if (used[u]) // used vertex can be in other queues
		{
			continue;
		}
		used[u] = true;
        int added = distances[u].second;
		for (auto [w, cost, isAdded] : graph[u])
		{
            int total_dist = distances[u].first + cost;
			if (total_dist <= distances[w].first)
			{
				// distances[w].first = total_dist;
    
                if(total_dist == distances[w].first ){
                    distances[w].second = min(distances[w].second, added+isAdded);
                }else{
                    distances[w].first = total_dist;
                    distances[w].second = added+isAdded;
                    // cout << "push: " << w << endl;
                    bfs[distances[w].first% (k + 1)].push(w);
                    ++num;
                }
			}
		}
	}
    // for(int i =0; i < (1 << n); i++){ 
    //     cout << i << ": " << distances[i].first << " " << distances[i].second << endl;
    // }
    cout << distances[(1<<n)-1].first << endl;
    cout << distances[(1<<n)-1].second << endl;








}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();
    return 0;
}
