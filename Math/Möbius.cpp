const ll N = 5e5 + 5;
vector<ll> v;
bitset<N> pr;
ll mu[N];

void siv(){
	v.push_back(2);
	for(ll i = 3; i < N; i += 2){
		if(!pr[i]){
			v.push_back(i);
			for(ll j = i * i; j < N; j += (2 * i)) pr[j] = 1;
		}
	}
}

void mob(){
	for(ll i = 0; i < N; i++) mu[i] = 1;
	for(ll i = 0; i < v.size(); i++){
		ll x = v[i];
		x *= x;
		for(ll j = x; j < N; j += x) mu[j] = 0;
	} 
	for(ll i = 0; i < v.size(); i++){
		ll x = v[i];
		for(ll j = x; j < N; j += x){
			mu[j] *= -1;
		}
	}
}

