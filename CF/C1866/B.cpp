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
double dist(double ax, double ay, double bx, double by){
    return sqrt(pow(ax-bx,2) + pow(ay - by,2));
}
int solve(){
    double px, py; 
    double ax, ay; 
    double bx, by; 
    cin >> px >> py >> ax >> ay >> bx >> by;
    // cout << fixed << setprecision(10) << px << " " << py << " " << ax << " " << ay << " " << bx << " " << by << endl;
    double a2p = dist(ax, ay, px, py);
    double a2o = dist(ax, ay, 0,0); 
    double a2b = dist(ax, ay, bx, by)/2;
    double b2p = dist(bx, by, px, py);
    double b2o = dist(bx, by, 0,0);
    double res = 0;
    // cout << fixed << setprecision << a2p << " " << a2o << " " << a2b << endl;
    // cout << fixed << setprecision << b2p << " " << b2o << endl;
    if(a2o <= b2o && a2p <= b2p){
        res = max(a2o, a2p);
    }else if(b2o <= a2o && b2p <= a2p){
        res = max(b2o, b2p);
    }else{ 
        double max_dist_a = min(a2o,b2o);
        double max_dist_b = min(b2p,a2p);
        double max_dist = max(max_dist_a, max_dist_b);
        // cout << fixed << setprecision(10) << max_dist << " " << max_dist_a << " " << max_dist_b << endl;
        res = max(a2b, max_dist);
    }
    cout << fixed << setprecision(10) << res << '\n';


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
