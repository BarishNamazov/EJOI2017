#include <bits/stdc++.h>

using namespace std;

int val[128], v[100005], nxt = 0;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (!val[s[i]]) {
            val[s[i]] = ++nxt;
        }
        v[i] = val[s[i]] - 1;
    }
    vector <int> cur(nxt);
    map <vector <int>, int> mp;
    int res = 0;
    for (int i = 0; i < n; i++) {
        mp[cur]++, cur[v[i]]++;
        int mn = *min_element(cur.begin(), cur.end());
        for (int j = 0; j < nxt; j++) {
            cur[j] -= mn;
        }
        res = (res + mp[cur]) % 1000000007;
    }
    cout << res << endl;
    return 0;
}
