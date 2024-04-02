#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#define ll long long

int N, P;

//make fence
//unfurl to number line 
//prefix sum 
//both ways 
unordered_map<int, vector<pair<int,int>>> x_line; 
unordered_map<int, vector<pair<int,int>>> y_line;
pair<ll,ll> posts[200'000];

vector<ll> edges[200'000];

ll post_to_points[200'000]; 

ll number_line_max = -1;
ll last_point;
int end_post;
int start_post = 0;

vector<int> number_line;
vector<int> post_ordering;


int ans[200'000];

int prefix[200'001];


void dfs_unfurl(int i, int parent, int point){ 
    // cout << i << " " << parent << " " << point << " " << post_to_points[i]<< endl;
    if(post_to_points[i] >= 0){
        if(number_line_max > -1) return;
        number_line_max = point;
        return; 
    }
    number_line.push_back(point);
    post_ordering.push_back(i);
    post_to_points[i] = point;
    auto [x1,y1] = posts[i];
    for(auto j : edges[i]){ 
        if(j == parent) continue;
        auto [x2,y2] = posts[j];
        if(post_to_points[j] == 0){ 
            last_point = point;
            end_post = i;
        }
        dfs_unfurl(j, i, point+abs(x1-x2)+abs(y1-y2));
    }
    return;
}
ll get_point(ll x,ll y){ 
    // cout <<"find: " <<  x << " " << y << endl;
    auto y_post_canid = lower_bound(y_line[y].begin(), y_line[y].end(), x, [](auto a, auto b){ return a.first < b;});
    if(y_line[y].end() != y_post_canid && x == (*y_post_canid).first){
        return post_to_points[(*y_post_canid).second];
    }
    auto x_post_canid = lower_bound(x_line[x].begin(), x_line[x].end(), y, [](auto a, auto b){ return a.first < b;});
    if(x_line[x].end() != x_post_canid && y == (*x_post_canid).first){
        return post_to_points[(*x_post_canid).second];
    }

    int x_post_index = x_post_canid - x_line[x].begin();
    int y_post_index = y_post_canid - y_line[y].begin();
    // cout << x_post_index << " " << y_post_index << endl;
    // cout << "X:" << endl;
    // for(int i =0; i < x_line[x].size(); i++){
    //     cout << x_line[x][i].first << " " << x_line[x][i].second << " " << posts[x_line[x][i].second].first << " " << posts[x_line[x][i].second].second << endl;
    // }
    // cout << "Y:" << endl;
    // for(int i =0; i < y_line[y].size(); i++){
    //     cout << y_line[y][i].first << " " << y_line[y][i].second  << " " << posts[y_line[y][i].second].first << " " << posts[y_line[y][i].second].second << endl;
    // }
    if(x_post_canid == x_line[x].end() || x_post_index%2 == 0){ 
        //y_post is valid
        // cout << "y post valid: " << y_post_index << endl;
        int post1 = y_line[y][y_post_index].second; 
        int post2 = y_line[y][y_post_index-1].second;
    
    
        ll point1 = post_to_points[post1];
        ll point2 = post_to_points[post2];
        // cout << point1 << " " << point2 << endl;
        if(post1 == end_post && post2 == start_post){ 
            point2 = number_line_max;
        }
        if(post2 == end_post && post1 == start_post){ 
            point1 = number_line_max;
        }
        // cout << point1 << " " << point2 << endl;
        if(point1 < point2){ 
            return point1 + abs(x - posts[post1].first) + abs(y - posts[post1].second);
        }else{ 
            return point2 + abs(x - posts[post2].first) + abs(y - posts[post2].second);
        }

        //post is zero
        

    }else{ 
        //x_post is valid
        int post1 = x_line[x][x_post_index].second;
        int post2 = x_line[x][x_post_index-1].second;
        // cout <<"x post:" << post1 << " " << post2 << endl;
        ll point1 = post_to_points[post1];
        ll point2 = post_to_points[post2];
        if(post1 == end_post && post2 == start_post){ 
            point2 = number_line_max;
        }
        if(post2 == end_post && post1 == start_post){ 
            point1 = number_line_max;
        }
        if(point1 < point2){
            return point1 + abs(x - posts[post1].first) + abs(y - posts[post1].second);
        }else{
            return point2 + abs(x - posts[post2].first) + abs(y - posts[post2].second);
        }
        
    }

}


void solve(){
    cin >> N >> P; 
    //make fences
    //pair axis, index
    
    for(int i = 0; i < P; i++){ 
        int x, y; 
        cin >> x >> y;
        x_line[x].push_back({y,i}); 
        y_line[y].push_back({x,i});
        posts[i] = {x, y};
    }
    for(auto& [x, ys] : x_line){ 
        sort(ys.begin(), ys.end(), []  (pair<int,int> a, pair<int,int> b){
            return a.first < b.first;
        });
        for(int i = 0; i < ys.size(); i+=2){ 
            auto[y1, i1] = ys[i];
            auto[y2, i2] = ys[i+1];
            edges[i1].push_back(i2);
            edges[i2].push_back(i1);
        }
        
    }
    for(auto& [y, xs] : y_line){ 
        sort(xs.begin(), xs.end(), []  (pair<int,int> a, pair<int,int> b){
            return a.first < b.first;
        });

        for(int i = 0; i < xs.size(); i+=2){
            auto[x1, i1] = xs[i];
            auto[x2, i2] = xs[i+1];
            edges[i1].push_back(i2);
            edges[i2].push_back(i1);
        }
    }
    memset(post_to_points, -1, sizeof(post_to_points));
    // for(int i = 0; i < P; i++){ 
    //     cout << edges[i][0] << " " << edges[i][1] << endl;

    // }
    dfs_unfurl(0, -1, 0);

    // cout << "number line: " << number_line_max << endl;


    //solve the problem
    for(int i = 0; i < N; i++){ 
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll p1 = get_point(x1, y1);
        ll p2 = get_point(x2, y2);
        ll start = min(p1, p2);
        ll end = max(p1, p2);

        ll start_ind = lower_bound(number_line.begin(), number_line.end(), start) - number_line.begin();
        ll end_ind = lower_bound(number_line.begin(), number_line.end(), end) - number_line.begin();
        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << endl;
        // cout << p1 << " " << p2 << " " << endl;
        // cout << "ind: " << start_ind << " " << end_ind << " " << endl;
        // cout << "range: " <<start << " " << end << endl;
        ll path1 = end-start; 
        ll path2 = number_line_max-path1; 
        
        if(path1 < path2){ 
            // cout << "here" << endl;
            prefix[start_ind] += 1;
            if(end_ind == number_line.size() || end < number_line[end_ind] ){ 
                prefix[end_ind] -= 1;
            }else{ 
                prefix[end_ind+1] -= 1;
            }
        }else{ 
            prefix[0] += 1; 
            if(start_ind != number_line.size() && number_line[start_ind] == start){
                prefix[start_ind+1] -= 1;
            }else{ 
                prefix[start_ind] -= 1;
            }
            prefix[end_ind] += 1;

        }
    
    }
    int acc = 0;
    // for(int i = 0; i < P; i++){ 
    //     cout << post_ordering[i] << " ";
    // }
    // cout << endl; 
    // for(int i = 0; i < P; i++){
    //     cout << number_line[i] << " ";
    // }
    // cout << endl;
    for(int i = 0; i < P; i++){ 
        acc += prefix[i];
        ans[post_ordering[i]] = acc;
        
    }
    // cout << "ans" << endl;
    for(int i = 0; i < P; i++){ 
        cout << ans[i] << "\n";
    }



    



}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
 
        
    solve();
    return 0;
}
