#include <bits/stdc++.h>

using namespace std;

int arr[10005];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int cc = 1; cc <= k; cc++) {
        int p; cin >> p;
        multiset <int> s;
        for (int i = 1; i <= p; i++) {
            s.insert(arr[i]);
        }
        int a[2] = {0, 0}, f = 1, idx = p + 1;
        while (!s.empty()) {
            a[f = 1 - f] += *s.rbegin();
            s.erase(s.find(*s.rbegin()));
            if (idx <= n) {
                s.insert(arr[idx++]);
            }
        }
        cout << a[0] - a[1] << endl;
    }
    return 0;
}
