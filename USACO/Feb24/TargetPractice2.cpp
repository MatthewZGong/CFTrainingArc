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

ll s[160'000];

ll search_negatives(vector<pair<ll,ll>>& points, vector<ll>& slopes, ll start, ll end){
    while(start < end){ 
        ll mid = (start+end)/2;
        vector<ll> possible_slopes;
        for(auto [x, y] : points){ 
            ll dist = y-mid;
            possible_slopes.push_back(dist/x);
            
        }
        sort(possible_slopes.begin(), possible_slopes.end(), greater<>()); 
        // print(possible_slopes);
        bool works = true;
        for(int i = 0; i < possible_slopes.size(); i++){ 
            if(possible_slopes[i] > slopes[i]){ 
                works = false;
                break;
            }
        }
        if(works){ 
            end = mid;
        }else{ 
            start = mid+1;
        }
    }
    return start;
}

ll search_postivies(vector<pair<ll,ll>>& points, vector<ll>& slopes, ll start, ll end){
    while(start > end){ 
        ll mid = (start+end)/2;
        // cout << mid << endl;
        vector<ll> possible_slopes;
        for(auto [x, y] : points){ 
            ll dist = y-mid;
            possible_slopes.push_back(dist/x);
        }
        sort(possible_slopes.begin(), possible_slopes.end()); 
        bool works = true;
        for(int i = 0; i < possible_slopes.size(); i++){ 
            if(possible_slopes[i] < slopes[i]){ 
                works = false;
                break;
            }
        }
        if(works){ 
            end = mid;
        }else{ 
            start = mid-1;
        }
    }
    return start; 
}

void solve(){
    int N; 
    ll x1;
    cin >> N >> x1; 
    vector<pair<ll,ll>> positive_points; 
    vector<pair<ll,ll>> negative_points;
    vector<pair<ll, ll>> neutral_points;
    ll upper_start = -1e18; 
    ll lower_start = 1e18;
    for(int i = 0; i < N; i++){ 
        ll y1, y2, x2; 
        cin >> y1 >> y2 >> x2; 
        upper_start = max(upper_start, y2); 
        lower_start = min(lower_start, y1);
        negative_points.push_back({x2, y2});
        positive_points.push_back({x2, y1});
        neutral_points.push_back({x1, y1});
        neutral_points.push_back({x1, y2});
    }
    vector<ll> positives; 
    vector<ll> negatives;

    for(int i = 0; i < 4*N; i++){ 
        cin >> s[i];
        if(s[i] < 0){
            negatives.push_back(s[i]);
        }else if(s[i] > 0){
            positives.push_back(s[i]);
        }
    }
    if(positives.size() < N || negatives.size() < N){ 
        cout << "-1" << endl;
        return;
    }
    sort(neutral_points.begin(), neutral_points.end());
    for(int i = 0; i < positives.size()-N; i++){ 
        positive_points.push_back(neutral_points[neutral_points.size()-1-i]);
    }
    for(int i =0; i < negatives.size()-N; i++){
        negative_points.push_back(neutral_points[i]);
    }

    assert(positive_points.size() + negative_points.size() == N*4);
    assert(positives.size() == positive_points.size());
    assert(negatives.size() == negative_points.size());

    sort(positives.begin(), positives.end());
    sort(negatives.begin(), negatives.end(), greater<ll>());
    

    ll positive_start = lower_start-1; 
    ll positive_end = -1e18; 

    ll lower = search_postivies(positive_points, positives, positive_start, positive_end);


    ll negative_start = upper_start+1;
    ll negative_end = 1e18;

    ll upper = search_negatives(negative_points, negatives, negative_start, negative_end);


    cout << abs(upper-lower) << endl;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
