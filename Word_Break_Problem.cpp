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
#define endl "\n"

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
lld dp[1001][1001];
string a[100001];
string s;

//TOP-DOWN
bool wordBreakProblem(lld i, lld j) {
	string ans = "";
	bool flag = false;
	if (j >= s.length()) return dp[i][j] = false;
	if (dp[i][j] != -1) return dp[i][j];
	for (lld ch = i; ch <= j; ch++) ans += s[ch];
	for (lld k = 0; k < n; k++) {
		string temp = a[k];
		if (temp == ans) {
			flag = true;
			if (j == s.length() - 1) return dp[i][j] = true;
			return dp[i][j] = wordBreakProblem(j + 1, j + 1) || wordBreakProblem(i, j + 1);
		}
	}
	if (!flag) {
		return dp[i][j] = wordBreakProblem(i, j + 1);
	}
	return dp[i][j] = true;
}


int main() {
	fast;
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n ;
	for (lld i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> s;
	string ans = "" + s[0];
	memset(dp, -1, sizeof(dp));
	if (wordBreakProblem(0, 0)) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

}
