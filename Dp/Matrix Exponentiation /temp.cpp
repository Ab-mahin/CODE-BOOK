#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007 // 998244353
// 0x3f

#define MAX LLONG_MAX

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order() and order_of_key()
// k-th largest element and strictly smaller

// Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 2e5 + 5;
ll a, b, k, n, mod = 1;
const int sz = 2;
struct Mat{
	int m[sz][sz];
	Mat(){
		memset(m, 0, sizeof m);
	}
	void identity(){
		for(int i = 0; i < sz; i++) m[i][i] = 1;
	}
	Mat operator* (Mat a){
		Mat res;
		for(int i = 0; i < sz; i++){
			for(int j = 0; j < sz; j++){
				for(int k = 0; k < sz; k++){
					res.m[i][j] = (res.m[i][j] + (m[i][k] * a.m[k][j]) % mod) % mod;
				}
			}
		}
		return res;
	}
};

int fun(){
	Mat res;
	res.identity();
	Mat T;
	T.m[0][1] = T.m[1][0] = T.m[1][1] = 1;
	
	if(n <= 1){
		return (!n ? (a % mod) : (b % mod));
	}
	n--;
	while(n){
		if(n & 1) res = res * T;
		T = T * T;
		n /= 2;
	}
	
	return ((res.m[1][0] * a) % mod + (res.m[1][1] * b) % mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;

    cin >> t;

    while (t--) {
        cin >> a >> b >> n >> k;
        mod = 1;
        ll c = k;
        while(c--) mod *= 10;
        cout << "Case " << tt++ << ": " << fun() << '\n';        
    }
    return 0;
}
