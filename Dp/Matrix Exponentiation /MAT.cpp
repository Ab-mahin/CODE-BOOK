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
ll n, a1, b1, c1, a2, b2, c2, f0, f1, f2, g0, g1, g2, mod;
const int sz = 6;
struct Mat{
	
	int row, col;
	ll m[sz][sz];
	
	Mat(){memset(m, 0, sizeof m);};
	void Set(int r, int c) {row = r; col = c;}
    Mat(int r, int c) {memset(m, 0, sizeof(m)); Set(r, c);}
    
	void identity(){
		for(int i = 0; i < sz; i++) m[i][i] = 1;
	}
	
	Mat operator* (const Mat a) {
        Mat res(row, a.col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < a.col; j++) {
                for (int k = 0; k < col; k++) {
                    res.m[i][j] = (res.m[i][j] + (m[i][k] * a.m[k][j]) % mod) % mod;
                }
            }
        }
        return res;
    }
};

pair<ll, ll> fun(){
	Mat res(6, 6);
	res.identity();
	Mat T(6, 6);
		
	T.m[0][0] = a1, T.m[0][1] = b1, T.m[0][3] = c1;
	T.m[5][5] = a2, T.m[5][4] = b2, T.m[5][2] = c2;
	T.m[1][0] = T.m[2][1] = T.m[3][4] = T.m[4][5] = 1;
	n -= 2;
	while(n){
		if(n & 1) res = res * T;
		T = T * T;
		n /= 2;
	}
	
	Mat A(6, 1);
	
	A.m[0][0] = f2, A.m[1][0] = f1, A.m[2][0] = f0;
	A.m[3][0] = g0, A.m[4][0] = g1, A.m[5][0] = g2;
		
	A = res * A;	
	return {A.m[0][0], A.m[5][0]};
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
    	cin >> a1 >> b1 >> c1;
    	cin >> a2 >> b2 >> c2;
    	cin >> f0 >> f1 >> f2;
    	cin >> g0 >> g1 >> g2;
    	cin >> mod;
    	
    	ll q;
    	cin >> q;
    	cout << "Case " << tt++ << ": \n";
    	while(q--){
    		cin >> n;
    		
    		if(n <= 2){
    			if(n == 0){
    				cout << (f0 % mod) << ' ' << (g0 % mod) << '\n';
    			}else if(n == 1){
    				cout << (f1 % mod) << ' ' << (g1 % mod) << '\n';
    			}else{
    				cout << (f2 % mod) << ' ' << (g2 % mod) << '\n';
    			}
    			continue;
    		}
    		auto [f, g] = fun();
    		cout << f << ' ' << g << '\n';
    	}
    }
    
    return 0;
}
