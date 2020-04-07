#include<bits/stdc++.h>
#include<climits>

using namespace std;

#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define watch(x) cout<<(#x)<<" is " << (x) << endl
#define fast ios_base::sync_with_stdio(false)
#define fie(i,a,b) for(i=a;i<b;i++)
#define MOD 1000000007
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define ll long long
#define lld long long int
#define ALL(x) (x).begin(),(x).end()

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pair<int, int>> vpi;
typedef long long LL;

const lld INF = (1ll) << 56;
const long long OO = 2e18;
const double pi = 2 * acos(0.0);

lld n;
lld a[100001],dp[100001][2];
lld stock(lld i, bool flag) {
	lld sum = INT_MIN;
	lld x=0;
	if(flag) x=1;
	if (i >= n) return dp[i][x]=0;
	if (flag) {
		sum = max(sum, max(stock(i + 1, true), stock(i + 1, false) - a[i]));
	}
	else {
		sum = max(sum, max(stock(i + 1, false), stock(i + 1, true) + a[i]));
	}
	return dp[i][x]=sum;
}

int main() {
	fast;
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	lld t;
	cin >> n;
	for (lld i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << stock(0, true) << endl;
}
