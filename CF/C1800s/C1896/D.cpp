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
int a[1'00'001]; 
int prefix[100];
int postfix[100];
int n;
int sum;
void updatePrefix(int ind, int val){ 
    // a[ind] = val; 
    int lower = (ind)/1000*1000;
    int upper = min((ind/1000+1)*1000, n);
    int count = 0;
    int i = lower;
    // cout << "pre: " << i << " " << lower << " " << upper << endl;
    while( i < upper && a[i] == 2){
        count++; 
        i++;
    }
    prefix[ind/1000]  = count;
}
void updatePostfix(int ind,int val){ 
    // a[ind] = val; 
    int lower = (ind)/1000*1000; 
    int upper = (ind/1000+1)*1000;
    int i = min(upper-1, n-1); 
    int count = 0;
    // cout << "post: " << i << " " << lower << " " << upper << endl;
    while( i >= lower && a[i] == 2){ 
        count++; 
        i--;
    }
    postfix[ind/1000] = count;
}


void process_query(int s){
    if(s > sum){ 
        cout << "NO" << endl;
        return;
    }
    if(s%2 == sum%2){ 
        cout << "YES" << endl;
        return;
    }
    int prefix_length = 0;
    for(int i = 0; i <= (n-1)/1000; i++){
        prefix_length += prefix[i];
        if(prefix[i] < 1000){ 
            break;
        }
    }
    int postfix_length = postfix[(n-1)/1000];
    if((n-1)%1000+1 == postfix_length){ 
        for(int i = (n-1)/1000-1; i >= 0; i--){ 
            postfix_length += postfix[i];
            if(postfix[i] < 1000){ 
                break;
            }
        }
    }
    // print(a, n);
    // print(prefix, (n)/1000);
    // print(postfix, (n)/1000);
    // cout << prefix[0] << endl; 
    // cout << postfix[0] << endl;
    int min_length = min(prefix_length, postfix_length);
    // cout << s << " " << sum << " " << prefix_length << " " << postfix_length << endl;
    if(s <= sum-2*min_length){ 
        cout << "YES" << endl;
    }else{ 
        cout << "NO" << endl;
    }
}

int solve(){
    int q; 
    cin >> n >> q; 
    sum = 0;
    // cout << n << " " << q << endl;

    for(int i = 0; i < n; i++){ 
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < n; i+= 1000){ 
        updatePostfix(i, a[i]); 
        updatePrefix(i, a[i]);
    }
    // print(a,n);
    for(int i =0; i < q; i++){ 
        int type; 
        cin >> type; 
        if(type == 1){ 
            int s; 
            cin >> s; 
            process_query(s);
        }else if(type == 2){
            int ind, val; 
            cin >> ind >> val;
            ind = ind - 1;
            sum += (val-a[ind]);
            a[ind] = val;
            updatePostfix(ind, val);
            updatePrefix(ind, val);
        }
    }


    return 0;
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
