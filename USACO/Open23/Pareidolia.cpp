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

struct Node{ 
    Node(int i, string s = ""): name(s){
        ind = i;
    }
    Node(){
        ind = 0;
    }
    int ind;
    string name;
    vector<pair<int, tuple<int,int,int>>> adj;
};

const int INF = 1e9;
const pair<int,int> EMPTY = {-1,-1};
vector<Node> graph;
vector<array<pair<int,int>,2>> dp;
int bessie[6] = {0,1,2,3,4,5};
int deletion_cost[2'00'000];
int prefix_sum[2'00'001];
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}
//add dp 
pair<int,int> dfs(int node, int selected ){ 
    if(dp[node][selected] != EMPTY ){
        return dp[node][selected];
    }
    Node& current = graph[node];
    // cout << current.name << 
    // " " << current.ind << " " << node  << endl;
    pair<int,int> best = {0,0};
    for(auto [a, b] : current.adj){ 
        auto [count, cost, type] = b;
        if(type < selected){ 
            continue;   
        }
        int sel = selected;
        if(type == 1){ 
            sel = 1; 
        }
        else if(type == 2){ 
            sel = 0; 
        }
        pair<int,int> res = dfs(a, sel);
        
        res.first += count;
        res.second += cost;
        best = min(best, res, cmp);
    }
    // cout << current.name << " " << current.ind <<  " " << node << ": " << best.first << " " << best.second << endl;
    return dp[node][selected] = best;

}

void solve(){
    string s; 
    cin >> s; 
    int n = s.size();
    for(int i = 0; i < n; i++){ 
        cin >> deletion_cost[i];
        prefix_sum[i+1] = prefix_sum[i] + deletion_cost[i];
    } 
    int i = 0;
    while(s[i] !='b'){ 
        i++;
    }
    for(int j =0; j < 6; j++){ 
        graph.push_back(Node(i,"B1"));
    }
    i++;
    for(; i < n; i++){
        int size = graph.size();
        if(s[i] == 'b'){ 
            Node& E2 = graph[bessie[5]];
            Node& pB1 = graph[bessie[0]];
            E2.adj.push_back({size, {0, 0, 2}});
            pB1.adj.push_back({size, {0, 0, 2}});
            // pB1.adj.push_back({size, {0, prefix_sum[i+1]-prefix_sum[pB1.ind+1]}});

            bessie[0] = size;
            graph.push_back(Node(i, "B1"));
        }
        else if(s[i] == 'e'){

            Node& B1 = graph[bessie[0]];
            Node& pE1 = graph[bessie[1]];
            B1.adj.push_back({size, {0, prefix_sum[i]-prefix_sum[B1.ind+1], 2}});

            pE1.adj.push_back({size, {0, prefix_sum[i]-prefix_sum[pE1.ind], 0}});
            pE1.adj.push_back({size, {0, prefix_sum[i+1]-prefix_sum[pE1.ind+1], 1}});
            
            Node& I1 = graph[bessie[4]];
            Node& pE2 = graph[bessie[5]];
            I1.adj.push_back({size+1, {1, prefix_sum[i]-prefix_sum[I1.ind+1], 2}});
            pE2.adj.push_back({size+1, {0,0, 2}});

            bessie[1] = size;
            bessie[5] = size+1;
            graph.push_back(Node(i, "E1"));
            graph.push_back(Node(i, "E2"));


        }
        else if(s[i] == 's'){

            Node& E1 = graph[bessie[1]];
            Node& pS1 = graph[bessie[2]];
            E1.adj.push_back({size, {0, prefix_sum[i]-prefix_sum[E1.ind+1], 2}});
            // E1.adj.push_back({size, {0, prefix_sum[i+1]-prefix_sum[E1.ind+1]}});
            pS1.adj.push_back({size, {0, prefix_sum[i]-prefix_sum[pS1.ind], 0}});
            pS1.adj.push_back({size, {0, prefix_sum[i+1]-prefix_sum[pS1.ind+1], 1}});

            Node& pS2 = graph[bessie[3]];
            pS1.adj.push_back({size+1, {0, prefix_sum[i]-prefix_sum[pS1.ind+1], 2}});

            pS2.adj.push_back({size+1, {0, prefix_sum[i]-prefix_sum[pS2.ind], 0}});
            pS2.adj.push_back({size+1, {0, prefix_sum[i+1]-prefix_sum[pS2.ind+1], 1}});

            bessie[2] = size;
            bessie[3] = size+1;
            graph.push_back(Node(i, "S1"));
            graph.push_back(Node(i, "S2"));

        }
        else if(s[i] == 'i'){
            Node& S2 = graph[bessie[3]];
            Node& pI1 = graph[bessie[4]];
            S2.adj.push_back({size, {0, prefix_sum[i]-prefix_sum[S2.ind+1], 2}});
            
            pI1.adj.push_back({size, {0, prefix_sum[i]-prefix_sum[pI1.ind], 0}});
            pI1.adj.push_back({size, {0, prefix_sum[i+1]-prefix_sum[pI1.ind+1], 1}});

            bessie[4] = size;
            graph.push_back(Node(i, "I1"));
        }
    }
    dp = vector<array<pair<int,int>,2>>(graph.size(), {EMPTY,EMPTY});
    pair<int,int> res = dfs(0,0);
    if(res.first == 0){ 
        cout << 0 << endl << 0 << endl;
    }else{ 
        cout << res.first << endl << res.second << endl;
    }

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);    
    solve();

}
