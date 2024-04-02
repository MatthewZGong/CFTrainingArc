//https://codeforces.com/problemset/problem/1680/C
#include<bits/stdc++.h>

using namespace std;




const int sbound = 200010;
int sums[sbound];
int n;
bool works(int val){
    if(sums[n] <= val){
        return true;
    }
    int start = 1;
    int end = n+1;
     for (start=1;start< n+1;start++){
        if(sums[start] > val){
            break;
        }
     }
	while (start>0)
	{
        start--;
		while (start < end-1){ 
            int rOnes =(sums[n]-sums[end-1]);
            int lOnes = sums[start];
            if(rOnes + lOnes<=val){
                end--;
            }else{
                break;
            }
        }
        int ones = sums[end-1]-sums[start]; 
        int nums = (end-1-start);
        int zeroes = nums-ones;
		if ((zeroes)<=val){
            return true;
        }
	}
    return false;
}
void print(int v[]){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
int solve2(string& s){ 
    n = s.size(); 
    s = ' '+s;
    for(int i =1; i < n+1; ++i){ 
        sums[i] = sums[i-1]+(s[i]-'0');
    }
    int start = -1; 
    int end = n; 
    while(start+1  < end){ 
        int mid = (start+end) / 2; 
        if(works(mid)){ 
            end = mid;
        }else{ 
            start = mid; 
        }

    }
    return end;
}

int main(){ 
    int n; 
    cin >> n; 
    for(int i = 0; i < n; ++i){
        string s; 
        cin >> s; 
        cout << solve2(s) << endl;;
    }

}
