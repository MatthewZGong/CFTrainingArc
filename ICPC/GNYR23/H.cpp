#include<bits/stdc++.h>
#include<iostream>
#include <mutex>
// g++-14 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
// count number of bits 
// only for int64 and int32
//__builtin_popcount 

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

int north = 0; 
int east = 1; 
int south = 2; 
int west = 3;

struct Intersection{ 
    int x; 
    int y; 
    //n, e, s, w
    pair<int,int> paths[4]{{0,0}, {0,0}, {0,0} , {0,0 }};
};


Intersection points[2501];

int interest[10000];

void create_path(int i, int j, int k, int path_pointer){ 
    interest[path_pointer] = k;
    Intersection& a = points[i];
    Intersection& b = points[j];
    if(a.x == b.x){ 
        if(a.y > b.y){ 
            create_path(j,i,k, path_pointer);
        }else{ 
            a.paths[north] = {j, path_pointer}; 
            b.paths[south] = {i, path_pointer}; 
        }
    }else{ 
        if(a.x > b.x){ 
            create_path(j,i,k, path_pointer);
        }else{
            a.paths[east] = {j, path_pointer};
            b.paths[west] = {i, path_pointer};
        }
    }
};

set<pair<int, int>> path;
vector<int> path_edge;
vector<pair<int,int>> path_intersect;
bool find_cycle(int point, int dir){ 
    // cout << "id: " << point << " moved: "<< points[point].x << " " << points[point].y << " " << dir << endl;
    pair<int,char> loc = {point, dir};
    if(path.find(loc) != path.end()){ 
        path_intersect.push_back(loc);
        return true;
    }
    path_intersect.push_back(loc);
    path.insert(loc);
    vector<tuple<int,int,int> > choices;
    auto intersect = points[point];
    {
        auto [left, left_ptr] = intersect.paths[(4+dir+1)%4];
        auto left_int = interest[left_ptr];
        if(left != 0 && left_int != 0){ 
            choices.push_back({left, left_ptr, (4+dir+1)%4});
        }
        auto [middle, middle_ptr] = intersect.paths[dir];
        auto middle_int = interest[middle_ptr];
        if(middle != 0 && middle_int != 0){ 
            choices.push_back({middle, middle_ptr, dir });
            
        }
        auto [right, right_ptr] = intersect.paths[(4+dir-1)%4];
        auto right_int = interest[right_ptr];
        if(right != 0 && right_int != 0){ 
            choices.push_back({right, right_ptr, (4+dir-1)%4});
        }
        // cout << left << " " << middle << " " << right << " " << intersect.paths[(dir+2)%4].first << endl;
    }
    // cout << choices.size() << endl;
    if(choices.size() == 3){ 
        auto [middle, middle_ptr, new_dir] = choices[1];
        path_edge.push_back(middle_ptr);
        interest[middle_ptr] -= 1; 
        if(interest[middle_ptr] == 0){ 

            auto res =path_intersect.back(); 
            // cout << "middle cycle end: " <<  res.first << " " << res.second << endl;
            path.clear();
            path_edge.clear();
            path_intersect.clear();  
        }
        return find_cycle(middle, new_dir);
    }else if(choices.size() == 2){ 
        auto [left, left_ptr, new_dir] = choices[0];
        path_edge.push_back(left_ptr);
        interest[left_ptr] -= 1; 
        if(interest[left_ptr] == 0){ 


            auto res =path_intersect.back(); 
            // cout << "left cycle end" << res.first << " " << res.second << endl;
            path.clear();
            path_edge.clear();
            path_intersect.clear();  
        }
        return find_cycle(left, new_dir);
    }
    else if(choices.size() == 1){ 
        auto [right, right_ptr, new_dir] = choices[0];
        path_edge.push_back(right_ptr);
        interest[right_ptr] -= 1; 
        if(interest[right_ptr] == 0){ 
            auto res =path_intersect.back(); 
            // cout << "right cycle end" <<  res.first << " " << res.second << endl;
            path.clear();
            path_edge.clear();
            path_intersect.clear();  
        }
        return find_cycle(right, new_dir);
    }
    // cout << "done" << " id: " << point << endl;
    return false;
}

//the new start, new dir
pair<int,int> reduce_cycle(){ 
    map<int,int> count;
    auto end = path_intersect.back();
    int start;
    for(int i =0; i < path_intersect.size(); i++){
        if(path_intersect[i] == end){ 
            start = i;
            break;
        }
    }
    for(int i = start; i < path_edge.size(); i++){ 
        auto edge = path_edge[i];
        count[edge] += 1;
    }
    int walks = 1e9;
    for(auto [edge, c]: count){ 
        int edge_int = interest[edge];
        walks = min((edge_int+c-1)/c, walks);
    }
    for(int i = start; i < path_edge.size(); i++){ 
        auto edge = path_edge[i];
        interest[edge] -= walks-1;
    }
    for(int i = start; i < path_edge.size(); i++){ 
        int edge = path_edge[i]; 
        interest[edge] -= 1; 
        if(interest[edge] == 0){ 
            return path_intersect[i+1];
        }
    }
    
    return {0,0};
}

void solve(){
    int n, m; 
    cin >> n >> m;
    for(int i = 1; i <= n; i++){ 
        cin >> points[i].x;
        cin >> points[i].y;
        // points[i].paths = [{0,0}, {0,0}, {0,0}, {0,0 }];
    }
    for(int p = 1; p <= m; p++){ 
        int i, j, k;
        cin >> i >> j >> k;
        // cout << i << " " << j << " " << k << endl;
        create_path(i,j,k, p);
    }
    int start; 
    char dir_c; 
    cin >> start >> dir_c; 
    int dir = 0;
    if(dir_c == 'N'){ 
        dir = 0;
    }else if(dir_c == 'S'){ 
        dir = 2;
    }else if(dir_c == 'E'){ 
        dir = 1;
    }else{ 
        dir = 3;
    }
    while(find_cycle(start, dir)){ 

        auto new_start = reduce_cycle();
        path.clear();
        path_edge.clear();
        path_intersect.clear(); 
        start = new_start.first; 
        dir = new_start.second;
        // cout << "new start " << points[start].x << " " << points[start].y << " " << dir << endl;
    }
    auto res = points[path_intersect.back().first]; 
    cout << res.x << " " << res.y << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();
    return 0;
}