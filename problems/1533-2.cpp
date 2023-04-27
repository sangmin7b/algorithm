#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
const int MOD = 1000003;
ll N, S, E, T;
using mat = vector<vector<ll>>;
mat A;
mat ans;
mat operator *(mat &a, mat&b) {
	mat res(5 * N + 1, vector<ll>(5 * N + 1));
	for (int i = 1; i <= 5 * N; i++) {
		for (int j = 1; j <= 5 * N; j++) {
			for (int k = 1; k <= 5 * N; k++) {
				res[i][j] += (a[i][k] * b[k][j]);
				res[i][j] %= MOD;
			}
		}
	}
	return res;
}
void mpow(void) {
	while (T) {
		if (T % 2) {
			ans = ans *A;
		}
		T /= 2;
		A = A*A;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> S >> E >> T;
	A.assign(5 * N + 1, vector<ll>(5*N+1));
	ans.assign(5 * N + 1, vector<ll>(5 * N + 1));
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 0; j < sz(s); j++) {
			if (s[j]-'0' >= 1) {
				A[i * 5][(j + 1) * 5 - (s[j] - '0' - 1)] = 1;
			}
		}
		for (int j = 1; j <= 4; j++) {
			A[(i - 1) * 5 + j][(i - 1) * 5 + j + 1] = 1;
		}
	}
	for (int i = 1; i <= 5 * N; i++) ans[i][i] = 1;
	mpow();
	cout << ans[5 * S][5 * E] << endl;
	for(int i=0;i<ans.size();i+=5){
        for(int j=0;j<ans[i].size();j+=5){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

}