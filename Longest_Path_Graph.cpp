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

lld dp[100001], n, m;
vector<lld> adj[100001];

//TOP_DOWN
lld longestPathGraph(lld a) {
	lld count = 0;
	if (adj[a].size() == 0) return dp[a] = 0;
	if (dp[a] != -1) return dp[a];
	for (lld i = 0; i < adj[a].size(); i++) {
		count = max(count, longestPathGraph(adj[a][i]) + 1);
	}
	return dp[a] = count;
}

int main() {
	fast;
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	lld i, j;
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (j = 0; j < m; j++) {
		lld x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	lld ans = INT_MIN;
	for (i = 1; i <= n; i++) {
		ans = max(ans, longestPathGraph(i));
	}
	cout << ans << endl;
}
