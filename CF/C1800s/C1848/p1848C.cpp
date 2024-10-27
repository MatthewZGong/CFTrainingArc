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

int a[100005];
int b[100005];
int find_depth(int a, int b, int depth){ 
    if(a == b){ 
        return depth;
    }
    if(a == 0){ 
        return depth+1;
    }
    if(b == 0){ 
        return depth+2;
    }
    if(a > 2*b){ 
        int diff = a-b;
        int count = (diff)/b;
        int step = count/2;
        if(count%2 == 0){ 
            return find_depth(a-count*b, b, depth+step*3);
        }else{ 
            return find_depth(a-(count)*b, a-(count+1)*b, depth+step*3+2);
        }
    }else{ 
        return find_depth(b, abs(a-b), depth+1);
    }

}
int brute_force_depth(int a, int b, int depth){ 
    if(a == b){ 
        return depth;
    }
    if(a == 0){ 
        return depth+1;
    }
    if(b == 0){ 
        return depth+2;
    }
    return brute_force_depth(b, abs(a-b), depth+1);
    
}

int solve(){
    int n; 
    cin >> n;
    for(int i =0; i < n; i++){ 
        cin >> a[i];
    } 
    for(int i =0; i < n; i++){ 
        cin >> b[i];
    }
    int i =0; 
    int depth;
    for(i =0; i < n; i++){
        if(a[i] == 0 && b[i] == 0) continue;
        depth = find_depth(a[i], b[i], 0)%3;
        break;
    }
    // cout << depth << " ";
    for(; i < n; i++){ 
        if(a[i] == 0 && b[i] == 0) continue;
        int cur_depth = find_depth(a[i],b[i], 0)%3; 
        // cout << find_depth(a[i],b[i], 0) << "|" << brute_force_depth(a[i],b[i],0) << " ";
        if(cur_depth != depth ){ 
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl; 

    return 0;

}

int main(){
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
