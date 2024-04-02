#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T> 
void print(vector<T> v){
    for(int i =0 ; i < v.size(); ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion
struct Point{ 
    Point(){ 
        x = 0; 
        y = 0;
    }
    Point(int x1, int y1){
        x = x1; 
        y = y1;
        
    }
    int x; 
    int y; 
};
Point points[100'000]; 
int solve(){
    int n; 
    cin >> n; 
    for(int i =0; i < n; i++){ 
        int x, y; 
        cin >> x >> y;  
        points[i] = {x,y};
        // cout << x << " " << y << endl;
    }
    sort(points, points+n, [](const Point& left, const Point& right){
        if(left.y == right.y){ 
            return left.x > right.x;
        } 
        return left.y > right.y;     
    });
    // for(int i =0; i < n; i++){ 
    //     cout << points[i].x << " " << points[i].y << endl;
    // }
    vector<int> components; 
    for(int i = 0; i < n; i++){ 
        int x = points[i].x; 
        int comp = x;
        while(components.size() && x <= components[components.size()-1]){ 
            comp = max(comp,components[components.size()-1]);
            components.pop_back();  
        }
        components.push_back(comp);
        // print(components);
    }
    return components.size();
}
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    ios::sync_with_stdio(false); 
    setIO("moop");
    cin.tie(nullptr);
    cout << solve() << endl;
}
