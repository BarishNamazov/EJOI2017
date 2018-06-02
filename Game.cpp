#include <bits/stdc++.h>

using namespace std;

int arr[100005];
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
        vector <int> c(n + 1, 0);
        int cur = 0;
        for (int i = 1; i <= p; i++) {
            c[arr[i]]++;
            cur = max(cur, arr[i]);
        }
        long long a[2] = {0, 0}; int f = 1, dont = 0;
        for (int i = p + 1; i <= n; i++) {
            if (dont == 0) {
                a[f = 1 - f] += cur; c[cur]--;
            }
            if (arr[i] > cur) {
                a[f = 1 - f] += arr[i];
                dont = 1;
            } else {
                c[arr[i]]++;
                dont = 0;
                for (; cur > 0 && c[cur] == 0; cur--);
            }
        }
        for (int i = n; i >= 1; i--) {
            while (c[i] > 0) {
                a[f = 1 - f] += i, c[i]--;
            }
        }
        cout << a[0] - a[1] << endl;
    }
    return 0;
}
