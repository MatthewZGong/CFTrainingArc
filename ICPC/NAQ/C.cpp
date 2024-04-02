#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
double q[1000005]; 
int f[1000005];
// int food[1000005]
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

bool possible(int n, int k, double target){
    priority_queue<pair<int,double>> pq;
    double quant = k*target;
    for(int i =1; i <= n; i++){
        if(q[i] != 0){
            pq.push(make_pair(f[i], q[i]));
        }

        double current = quant; 
        while(!pq.empty() && current > 0){
            pair<int, double> food = pq.top(); 
            pq.pop();
            current -= food.second; 
            if(current < 0){ 
                food.second = -current;
                pq.push(food);
            }
        }
        if(current > 0){ 
            return false;
        }
        while(!pq.empty() && pq.top().first == i){ 
            pq.pop();
        }
    }
    return true;
}


void solve(){
    int n, k; 
    double end = 0;
    cin >> n >> k;
    for(int i =1; i <= n; i++){ 
        cin >> q[i] >> f[i];
        // cout << q[i] << endl;
        end = max(end, q[i]);
    }
    // cout << end << "\n";
    double start = 0;
    int counter = 0;
    while(counter < 60){ 
        double mid = (start+end)/2; 
        if(possible(n, k, mid)){ 
            start = mid;
        }else{ 
            end = mid;
        }
        counter++;
    }
    double res = (start+end)/2;  
    if(res < 1e-9 ){ 
        cout << -1 << '\n';
    }else{
        cout<< fixed << setprecision(10) << res << '\n';
    }    
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}
