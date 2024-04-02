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
int f[100005];
pair<int,int> sorted_depth[100005]; 
int uf[100005];
int rank_uf[100005]; 
int n,b;
void print_uf(int x, int y){ 
    cout << "----------" << endl;
    cout << f[x] << " " <<  f[y] <<endl;
    for(int i =0; i < n; i++){
        cout << uf[i] << " ";
    }
    cout << endl;
    for(int i =0; i < n; i++){
        cout << rank_uf[i] << " ";
    }
    cout << endl;
} 
int find_parent(int x){ 
    if(uf[x] == x){ 
        return x;
    }
    return uf[x] = find_parent(uf[x]);
}
int union_find(int x, int y){ 
    if(y < 0){ 
        return 0;
    }
    int p_x = find_parent(x); 
    int p_y = find_parent(y); 
    if(f[x] > f[y]){ 
        return rank_uf[x];
    }  
    if(p_x == p_y){ 
        return rank_uf[p_x];
    }
    if(rank_uf[p_x] > rank_uf[p_y]){ 
        rank_uf[p_x] += rank_uf[p_y]; 
        uf[p_y] = p_x;
        // print_uf(x,y);
        return rank_uf[p_x];
    }else{ 
        rank_uf[p_y] += rank_uf[p_x]; 
        uf[p_x] = p_y;
        // print_uf(x,y);
        return rank_uf[p_y];
    }
}
int find_gap(int depth, vector<pair<int,int>>& depths){
    // cout << "H1" << endl;
    int end = depths.size()-1; 
    int start = 0;
    while(start < end){ 
        int mid = (start+end)/2; 
        if(depth >= depths[mid].first){ 
            end = mid;
        }else{ 
            start = mid+1;
        }
    }
    // cout << "H2" << endl;
    return depths[start].second;

}
void solve()
{
    for(int i =0; i <n; i++){
        cin >> f[i]; 
        sorted_depth[i].first = f[i];
        sorted_depth[i].second = i; 
        uf[i] = i;
        rank_uf[i] = 1;
    }
    sort(sorted_depth, sorted_depth+n);
    int i = n-1; 
    vector<pair<int,int>> depths;
    int largest_gap = 0; 
    
    while(i >= 0){ 
        // cout << i << endl;
        depths.emplace_back(sorted_depth[i].first, largest_gap);
        int gap = union_find(sorted_depth[i].second, sorted_depth[i].second+1);
        largest_gap = max(largest_gap, gap);
        gap = union_find(sorted_depth[i].second, sorted_depth[i].second-1);
        largest_gap = max(largest_gap, gap);
        i--;  
        while(i >= 0 && sorted_depth[i].first == sorted_depth[i+1].first){ 
            int gap = union_find(sorted_depth[i].second, sorted_depth[i].second+1);
            largest_gap = max(largest_gap, gap);
            gap = union_find(sorted_depth[i].second, sorted_depth[i].second-1);
            largest_gap = max(largest_gap, gap); 
            i--;
        }
    }
    // cout << largest_gap << endl;
    // for(auto& [depth, gap]: depths){ 
    //     cout << depth << "|" << gap << " "; 
    // }
    // cout << endl;
    int s, d;
    // cout << b << endl;
    for(int i =0; i <b; i++){ 
        cin >> s >> d;
        int gap = find_gap(s, depths);
        // cout << gap <<" " <<s << " " << d << endl;
        if(d > gap){ 
            cout << "1\n";
        }else{ 
            cout << "0\n";
        }
        // cout << endl;
    }
    // cout << endl;
}
void setIO(string s) {
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("snowboots");
    cin.tie(0);
    n,b; 
    cin >> n >> b;     
    solve();
    // cout << 3 << "\n";
    // cin >> n;


}
