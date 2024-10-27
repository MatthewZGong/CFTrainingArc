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

pair<int,int> trees[5000]; 
pair<int,int> detected[1000];
vector<pair<int,int>> candidates; 
int t;
int s;
int r;

int validate_dir(vector<pair<int,int>>& pos){ 
    for(int i =0; i < s; i++){ 
        if(pos[i] != detected[i]){ 
            return 0;
        }
    }
    return 1;
}
int check_viability(int x, int y){ 
    vector<pair<int,int>> pos_x; 
    vector<pair<int,int>> pos_y;
    vector<pair<int,int>> neg_x; 
    vector<pair<int,int>> neg_y;
    for(int i = 0; i < t; i ++){ 
        auto [tx, ty] = trees[i];
        if(x == tx && y == ty){ 
            return false;
        }
        int a = tx-x;
        int b = ty-y;
        if(abs(a)+abs(b) <= r){
            pos_x.push_back({a,b});
            pos_y.push_back({-b, a});
            neg_x.push_back({-a,-b});
            neg_y.push_back({b, -a});
        }
    }
    if(pos_x.size() != s){ 
        return 0;
    }
    sort(pos_x.begin(), pos_x.end());
    sort(pos_y.begin(), pos_y.end());
    sort(neg_x.begin(), neg_x.end());
    sort(neg_y.begin(), neg_y.end());
    int res = validate_dir(pos_x) + validate_dir(pos_y) + validate_dir(neg_x) + validate_dir(neg_y);
    return res;
}


void solve(){
    cin >> t >> s >> r; 
    int x, y; 
    for(int i =0; i < t; i ++){
        cin >> trees[i].first; 
        cin >> trees[i].second;
    }
    for(int i =0; i < s; i++){ 
        cin >> detected[i].first;
        cin >> detected[i].second;
    }
    sort(detected, detected+s);
    for(int i = 0; i < t; i++){
        auto [tree_x, tree_y] = trees[i];
        for(int j = 0; j < s; j++){ 
            auto [a, b] =  detected[j];
            candidates.push_back({tree_x+a, tree_y+b});
            candidates.push_back({tree_x-b, tree_y+a});
            candidates.push_back({tree_x-a, tree_y-b});
            candidates.push_back({tree_x+b, tree_y-a});
        }
    }
    sort(candidates.begin(), candidates.end());
    int i = 0; 
    bool found = false;
    pair<int,int> res;
    int pos_sol = 0;
    while(i < candidates.size()){ 
        auto cand = candidates[i];
        int count = 0; 
        while(i < candidates.size() && candidates[i] == cand){ 
            count += 1; 
            i += 1;
        }
        if(count >= s){     
            auto[x,y] = cand;
            int asdf = check_viability(x,y);
            if(asdf){ 
                found = true;
                res = cand;
            }
            pos_sol += asdf;
            if(pos_sol > 1){ 
                cout << "Ambiguous" << endl;
                return;
            }
        }
    }
    if(found == true){
        cout << res.first << " " << res.second << endl;
    }else{ 
        cout << "Impossible" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}
// #include <bits/stdc++.h>

// using namespace std;

// using ll = long long;
// const int INF = 1000000000;

// int nt, ns, rmax;
// int points[5001][2];
// int seen[1001][2];

// multiset<pair<int, int>> golden_offs;

// int main() {
//     cin >> nt >> ns >> rmax;
//     for (int i = 1; i <= nt; ++i) {
//         cin >> points[i][0] >> points[i][1];
//     }

//     for (int i = 1; i <= ns; ++i) {
//         cin >> seen[i][0] >> seen[i][1];
//         golden_offs.insert(make_pair(seen[i][0], seen[i][1]));
//     }

//     map<pair<int, int>, int> m;

//     for (int i = 1; i <= nt; ++i) {
//         for (int j = 1; j <= ns; ++j) {
//             int dx = seen[j][0];
//             int dy = seen[j][1];

//             auto a = make_pair(points[i][0] + dx, points[i][1] + dy);
//             auto b = make_pair(points[i][0] - dy, points[i][1] + dx);
//             auto c = make_pair(points[i][0] - dx, points[i][1] - dy);
//             auto d = make_pair(points[i][0] + dy, points[i][1] - dx);

//             m[a]++;
//             m[b]++;
//             m[c]++;
//             m[d]++;
//         }
//     }

//     auto dist = [](pair<int, int> a, pair<int, int> b) {
//         return abs(a.first - b.first) + abs(a.second - b.second);
//     };

//     vector<pair<int, int>> valid;
//     bool amb = false;

//     for (auto [k, cnt] : m) {
//         if (cnt >= ns) {
//             multiset<pair<int, int>> offs_a;
//             multiset<pair<int, int>> offs_b;
//             multiset<pair<int, int>> offs_c;
//             multiset<pair<int, int>> offs_d;

//             for (int i = 1; i <= nt; ++i) {
//                 auto p = make_pair(points[i][0], points[i][1]);
//                 int dx = p.first - k.first;
//                 int dy = p.second - k.second;
//                 if (dist(p, k) <= rmax) {
//                     offs_a.insert(make_pair(+dx, +dy));
//                     offs_b.insert(make_pair(-dy, +dx));
//                     offs_c.insert(make_pair(-dx, -dy));
//                     offs_d.insert(make_pair(+dy, -dx));
//                 }
//             }

//             int works_cnt = (offs_a == golden_offs) + (offs_b == golden_offs) + (offs_c == golden_offs) + (offs_d == golden_offs);

//             if (works_cnt == 1) {
//                 valid.push_back(k);
//             } else if (works_cnt > 1) {
//                 amb = true;
//             }
//         }
//     }

//     if (valid.size() == 1 && !amb) {
//         cout << valid[0].first << " " << valid[0].second << endl;
//     } else if (valid.size() > 1 || amb) {
//         cout << "Ambiguous" << endl;
//     } else {
//         cout << "Impossible" << endl;
//     }

//     return 0;
// }