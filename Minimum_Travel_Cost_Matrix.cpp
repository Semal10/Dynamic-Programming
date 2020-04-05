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

lld n, m, a[1001][1001], dp[1001][1001];

//TOP-DOWN
lld minimumTravelCost(lld i, lld j) {
	lld c = INT_MAX;
	if (i == 0 && j == 0) return a[i][j];
	if (i < 0 || j < 0) return dp[i][j] = INT_MAX;
	if (dp[i][j] != -1) return dp[i][j];
	c = min(c, min(minimumTravelCost(i - 1, j) + a[i][j], minimumTravelCost(i, j - 1) + a[i][j]));
	return dp[i][j] = c;
}


int main() {
	fast;
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (lld i = 0; i < n; i++) {
		for (lld j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << minimumTravelCost(n - 1, m - 1) << endl;

}
