#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> operations;

        int k = 0;
        for (int i = 0; i < 8 && k < n - 1; i++) {
            int x = 0;
            for (int j = 0; j < n; j++) {
                x ^= a[j];
                if (x == 0) {
                    operations.push_back({j + 1, j + 1});
                    k++;
                }
            }

            if (x != 0) {
                int j = 0;
                while ((x & (1 << j)) == 0) {
                    j++;
                }
                for (int l = 0; l < n; l++) {
                    if (a[l] & (1 << j)) {
                        operations.push_back({1, l + 1});
                    }
                }
                k++;
            }
        }

        cout << k << endl;
        for (auto op : operations) {
            cout << op.first << " " << op.second << endl;
        }
    }

    return 0;
}

