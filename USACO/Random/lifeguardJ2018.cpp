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

int solve(int n){
    vector<pair<int,int>> intervals; 
    for(int i =0; i < n; i++){ 
        int x, y; 
        cin >> x >> y; 
        // cout << x << " " << y << endl;
        intervals.emplace_back(x,y);
    }
    sort(intervals.begin(), intervals.end()); 
    vector<int> uncover(n, 0);

    pair<int,int>& past = intervals[0];
    int total = past.second-past.first;
    uncover[0] = total;
    for(int i =1; i < n; i++){ 
        pair<int,int>& current = intervals[i];
        uncover[i] = current.second - current.first; 
        // cout << "current " << current.first << " " << current.second << endl;
        // cout << "past " << past.first << " " << past.second << endl;

        if(current.second <= past.second){ 
            uncover[i] = 0;
        }else{ 
            if(current.first <= past.second){ 
                int overlap = past.second - current.first; 
                uncover[i] -= overlap; 
                uncover[i-1] -= overlap;
                total += current.second - past.second;
                // cout <<  current.second - past.second  << endl;
            }else{ 
                total += current.second - current.first;
            }
            past = current;
        }
    }
    // cout << total << endl; 
    // for(int i =0; i < n; i++){ 
    //     cout << uncover[i] << " ";
    // }
    // cout << endl;
    // cout << *min_element(uncover.begin(), uncover.end()) << endl;
    return total - max(0,*min_element(uncover.begin(), uncover.end())); 
    // for(auto& [x,y]: intervals){ 
    //     cout << x <<"," << y << " | ";
    // }
    // cout << endl; 

}
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    ios::sync_with_stdio(false); 
    setIO("lifeguards");
    cin.tie(nullptr);
    int n; 
    cin >> n;     
    cout << solve(n) << endl;


}
