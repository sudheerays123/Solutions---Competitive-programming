#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp pake_pair
#define INF 0x3f3f3f3f3f
#define MOD 1e9 + 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

bool IsKPossible(ll n , ll k , vector<ll> a , ll kk){

    ll count = 1 , distance = 0;
    fo(i,1,n-1){
        distance += a[i] - a[i-1];
        if(distance >= k){
            count++;
            distance = 0;
        }
    }


    if(count >= kk) return true;
    return false;
}

int main() {

    fast;

    tc{

        ll n,k;
        cin in n in k;

        vi x(n+5);

        fo(i,0,n-1) cin in x[i];
        sort(x.begin() , x.begin()+n);

        ll low = 0 , high = *max_element(x.begin() , x.begin()+n) , ans = -INF;

        while(low < high){
            ll mid = (low+high)/2;
            if(IsKPossible(n,mid,x,k) == true){
                ans = mid;
                low = mid+1;
            }
            else high = mid;
        }

        cout out ans nextline;
    }

    return 0;
}
