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
#pragma endregion

vector<int> primes; 
vector<vector<int>> adj; 

const int A_SIZE = 3'00'000;

// vector<bool> primes_visited; 
int lowest_divisors[3'00'001];
int a[3'00'000]; 
int path[3'00'000];
vector<int> num_prime_factors[3'00'000];

void sieve(int n){ 
    // cout << "sieved" << endl;
    memset(lowest_divisors, 63, sizeof(lowest_divisors));
    for(int i = 2; i <= n; ++i){ 
        // cout << i << endl;
        if(lowest_divisors[i] > i){ 
        
            primes.push_back(i);
            adj.push_back({});
            lowest_divisors[i] = primes.size()-1;
            for(int j = i+i; j <= A_SIZE; j+= i){ 
                lowest_divisors[j] = min(lowest_divisors[j], int(primes.size()-1));
            }
        }
    }
    for(int i = n; i <= A_SIZE; ++i){ 
        if(lowest_divisors[i] > i){ 
            lowest_divisors[i] = primes.size();
            primes.push_back(i);
            adj.push_back({}); 
        }
    }
}
void prime_factorize(int ind, int n){ 
    if(lowest_divisors[n] > 300000) return;
    // cout << n << " " << lowest_divisors[n] << endl;
    int current = n;
    for(int i = lowest_divisors[n]; i < primes.size() && primes[i] <= current; ++i){ 
        if(current % primes[i] == 0){ 
            adj[i].push_back(ind);
            num_prime_factors[ind].push_back(i);
            current /= primes[i];
        }
    }
}

int dfs(int start, int end, int n){ 
    for(int i = 0; i < n; ++i){ 
        path[i] = -1;
    }
    path[start] = start;
    int dist = 1; 
    if(start == end){
        return 1;
    }
    vector<int> qfront;
    vector<int> qback; 
    qfront.push_back(start);
    while(qfront.size()){ 
        for(int i = 0; i < qfront.size(); i++){ 
            int current = qfront[i];
            for(int factor: num_prime_factors[current]){
                for(int edge: adj[factor]){ 
                    if(path[edge] != -1) continue;
                    path[edge] = current;
                    if(edge == end) return dist+1;
                    qback.push_back(edge);
                }

                adj[factor].clear();
            }
        
        }

        swap(qfront, qback);
        qback.clear();
        dist++;
    }
    return -1;
}

void solve(){ 
    int n;
    cin >> n; 
    for(int i = 0; i < n; ++i){ 
        cin >> a[i];
        prime_factorize(i, a[i]);
    }
    // cout <<"got here" << endl;
    int s, t; 
    cin >> s >> t; 
    s--;
    t--;
    int res = dfs(s, t, n);
    cout << res << endl; 
    if(res == -1){ 
        return;
    }
    vector<int> ans;
    ans.push_back(t);
    int current = t;
    while(path[current] != current){ 
        // cout << path[current] << endl;
        ans.push_back(path[current]);
        current = path[current];
    }
    for(int i = ans.size()-1; i >= 0; --i){ 
        cout << ans[i]+1 << " ";
    }
    cout << endl;

    

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    sieve(547);
    cout << primes.size() << endl;
    solve();

}
