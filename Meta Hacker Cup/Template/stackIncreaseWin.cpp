
#pragma comment(linker, "/STACK:268435456")
#pragma comment(linker, "/STACK:1073741824")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

static void run_with_stack_size(void (*fstack)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%esp, (%0)\n"
        "mov %0, %%esp\n"
        :
        : "r"(send));
    fstack();
    asm volatile("mov (%0), %%esp\n" : : "r"(send));
    free(stack);
}

//Start...................

const ll N = 4e3 + 5;
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};

//.............

void solve(){
    ll n;
    cin >> n;
}

void fun(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll t, tt = 1;
    cin >> t;
    while(t--){
        cout << "Case #" << tt++ << ": "; 
        solve();
    }
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    run_with_stack_size(fun , 1024 * 1024 * 1024);

    return 0;
}
