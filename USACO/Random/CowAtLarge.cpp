#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

int solve(int n, int k)
{
    vector<int> adj[n+1];
    for(int i =0; i <n-1; i++){
        int a, b;
        cin >> a >> b; 
        adj[a].push_back(b); 
        adj[b].push_back(a);
   }
   vector<int> queue_front; 
   int visited[n+1];
   for(int i =1; i <=n; i++){ 
        visited[i] = -1;
        if(adj[i].size() == 1){ 
            visited[i] = i;
            queue_front.push_back(i);
        }
        // cout << visited[i] << " ";
   }
//    cout << endl;
   queue_front.push_back(k);
   vector<int> queue_back; 
   int res = 0;
   visited[k] =k;
   while(queue_front.size()){ 
        for(int i =0; i < queue_front.size(); i++){ 

            int current = queue_front[i];
            for(int neighbor: adj[current]){ 
                if(visited[neighbor] == -1){ 
                    queue_back.push_back(neighbor); 
                    visited[neighbor] = visited[current];
                }else{ 
                    if(visited[neighbor] == k && visited[current] != k){ 
                        res += 1;
                    }
                }
            }
        }
        queue_front.swap(queue_back);
        queue_back.clear();         
   }
   cout << res << endl;
   return 0;
    
}
void setIO(string s) {
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("atlarge");
    cin.tie(0);
    int n,k; 
    cin >> n >> k;     
    solve(n, k);
    // cout << 3 << "\n";
    // cin >> n;


}
