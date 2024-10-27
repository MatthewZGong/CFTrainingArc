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

int solve(){
    int n, q; 
    cin >> n >> q; 
    map<pair<int,int>, vector<int>> location_to_time; 
    vector<pair<int,int>> time_to_location;
    // map<pair<int,int>, vector<int>> location_to_time_reversed;
    // vector<pair<int,int>> time_to_location_reversed;
    string directions = "";
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){ 
        location_to_time[{x,y}].push_back(i);
        time_to_location.push_back({x,y});
        char d; 
        directions += d;
        cin >> d;
        if(d == 'U'){ 
            y += 1;
        }else if(d== 'R'){ 
            x +=1;
        }else if(d == 'L'){ 
            x -= 1;
        }else{ 
            y -= 1;
        }
    }
    location_to_time[{x,y}].push_back(n);
    time_to_location.push_back({x,y});
    // cout << "finsihed 1" << endl;
    //  x = 0; y = 0;
    // for(int i =0; i < n; i++){ 
    //     location_to_time_reversed[{x,y}].push_back(i);
    //     time_to_location_reversed.push_back({x,y});
    //     char d = directions[n-1-i];
    //     if(d == 'U'){ 
    //         y += 1;
    //     }else if(d== 'R'){ 
    //         x +=1;
    //     }else if(d == 'L'){ 
    //         x -= 1;
    //     }else{ 
    //         y -= 1;
    //     }
    // }
    // location_to_time_reversed[{x,y}].push_back(n);
    // time_to_location_reversed.push_back({x,y});
    // for(int i =0; i < time_to_location.size(); i++){ 
    //     cout << i <<": " <<  time_to_location[i].first << " " << time_to_location[i].second << endl;
    // }

    for(int i = 0; i < q; i++){ 
        int xi, yi, l, r; 

        cin >> xi >> yi >> l >> r;
        // cout << "QUERY: " << xi << " " << yi << " " << l << " " << r << endl;
        l -=1; 
        // r -=1;
        auto [start_x, start_y] = time_to_location[l];
        auto [end_x, end_y] = time_to_location[r];
        // cout << "start_x: " << start_x << " start_y: " << start_y << " end_x: " << end_x << " end_y: " << end_y << endl;
        // double mid_x = (start_x + end_x)/2.0;
        // double mid_y = (start_y + end_y)/2.0;

        int cx = start_x+end_x-xi;
        int cy = start_y+end_y-yi;

        // cout << "mid_x: " << mid_x << " mid_y: " << mid_y << " cx: " << cx << " cy: " << cy << endl;
        if(location_to_time.count({xi,yi}) ){ 
            vector<int>& times = location_to_time[{xi,yi}];
            // cout << "times: ";
            // print(times);
            auto left = lower_bound(times.begin(), times.end(), l); 
            auto right = lower_bound(times.begin(), times.end(), r);
            if(! (right == times.end() && left == times.begin())){
                cout << "YES" << endl;
                continue;
            }
        }
        if(location_to_time.count({cx,cy})){
            vector<int>& times = location_to_time[{cx,cy}];
            auto left = lower_bound(times.begin(), times.end(), l);
            auto right = lower_bound(times.begin(), times.end(), r);
            if(left != times.end() && *left <= r){
                
                cout << "YES" << endl;
                continue;
            }

        }
        cout << "NO" << endl;
    }
    return 0;
    
    
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

        
    solve();

}
