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
    Node(int d, int i, string s = ""): name(s){
        del = d;
        ind = i;
    }
    Node(){
        del = 0;
        ind = 0;
    }
    int ind;
    string name;
    int del;
    vector<pair<int, pair<int,int>>> adj;
};

const int INF = 1e9;
const pair<int,int> EMPTY = {-1,-1};
vector<Node> graph;
vector<pair<int,int>> dp;
int bessie[6] = {0,1,2,3,4,5};
int deletion_cost[2'00'000];
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}
//add dp 
pair<int,int> dfs(int node){ 
    if(dp[node] != EMPTY ){
        return dp[node];
    }
    Node& current = graph[node];
    // cout << current.name << 
    // " " << current.ind << " " << node  << endl;
    pair<int,int> best = {0,0};
    for(auto [a, b] : current.adj){ 
        pair<int,int> res = dfs(a);
        res.first += b.first;
        res.second += b.second;
        best = min(best, res, cmp);
    }
    // cout << current.name << " " << current.ind <<  " " << node << ": " << best.first << " " << best.second << endl;
    return dp[node] = best;

}

void solve(){
    string s; 
    cin >> s; 
    int n = s.size();
    for(int i = 0; i < n; i++){ 
        cin >> deletion_cost[i];
    } 
    int i = 0;
    int sum_del =0;
    while(s[i] !='b'){ 
        sum_del += deletion_cost[i];
        i++;
    }
    if(i == n){
        cout << 0 << " " << 0 << endl; 
        return;
    }
    sum_del += deletion_cost[i];
    for(int j =0; j < 6; j++){ 
        graph.push_back(Node(sum_del,i,"B1"));
    }

    i++;
    for(; i < n; i++){
        sum_del += deletion_cost[i];
        int ind = graph.size(); 
        // cout << s[i] << " " << ind << " ";
        if(s[i] == 'b'){ 
            //skip the current b
            Node& E2 = graph[bessie[5]];
            Node& pB1 = graph[bessie[0]];
            E2.adj.push_back({ind, {0, 0}});
            pB1.adj.push_back({ind, {0, 0}});

            //over write
            bessie[0] = ind;
            graph.emplace_back(sum_del,i, "S1");
        }
        else if(s[i] == 'e'){
            
            //E1 first E 
            Node& B1 = graph[bessie[0]];
            Node& pE1 = graph[bessie[1]];
            B1.adj.push_back({ind, {0,sum_del-deletion_cost[i]-B1.del}});
            pE1.adj.push_back({ind, {0, sum_del-deletion_cost[i]-pE1.del+deletion_cost[pE1.ind]}});
            

            ind++;
            //E2 second E
            Node& I1 = graph[bessie[4]];
            I1.adj.push_back({ind, {1, sum_del-deletion_cost[i]-I1.del}});
            Node& pE2 = graph[bessie[5]];
            pE2.adj.push_back({ind, {0, sum_del-deletion_cost[i]-pE2.del+deletion_cost[pE2.ind]}});    

            //over write
                        //over write 
            bessie[1] = ind-1;
            bessie[5] = ind;
            graph.emplace_back(sum_del,i,"E1");
            graph.emplace_back(sum_del,i,"E2");
        }
        else if(s[i] == 's'){
            //S1 first S
            Node& E1 = graph[bessie[1]];
            Node& pS1 = graph[bessie[2]];
            E1.adj.push_back({ind, {0, sum_del-deletion_cost[i]-E1.del}});
            pS1.adj.push_back({ind, {0, sum_del-deletion_cost[i]-pS1.del+deletion_cost[pS1.ind]}});
            //S2 second S
            ind++;
            Node& pS2 = graph[bessie[3]];

            pS1.adj.push_back({ind, {0, sum_del-deletion_cost[i]-pS1.del}});
            pS2.adj.push_back({ind, {0, sum_del-deletion_cost[i]-pS2.del+deletion_cost[pS2.ind]}});


            graph.emplace_back(sum_del,i, "S1");
            graph.emplace_back(sum_del,i, "S2");
            //over write
            bessie[2] = ind-1;
            bessie[3] = ind;

        }
        else if(s[i] == 'i'){
            //I1 first I
            Node& S2 = graph[bessie[3]];
            Node& pI1 = graph[bessie[4]];
            S2.adj.push_back({ind, {0, sum_del-deletion_cost[i]-S2.del}});
            pI1.adj.push_back({ind, {0, sum_del-deletion_cost[i]-pI1.del+deletion_cost[pI1.ind]}});
            //over write
            bessie[4] = ind;
            graph.emplace_back(sum_del,i, "I1");
        }
    }
    // cout << endl;
    dp = vector<pair<int,int>>(graph.size(), EMPTY);
    // cout << graph[0].del << endl;
    pair<int,int> res = dfs(0);
    // cout << res.first << " " << res.second << endl;
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
