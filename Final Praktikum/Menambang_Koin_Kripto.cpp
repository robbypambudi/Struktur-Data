#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
#define SR 316
int n, m, q;

ll a[N];
ll val[N], sum[N];

vector<int> arr[N], rev[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        arr[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            int &x = arr[i][j];
            cin >> x;
            x--;
        }
        if (k >= SR)
        {
            for (int x : arr[i])
            {
                rev[x].push_back(i);
                val[i] += sum[i] * a[x];
                sum[i] += a[x];
            }
        }
    }
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            ll y;
            cin >> x >> y;
            x--;

            for (auto i : rev[x])
            {
                val[i] += (sum[i] - a[x]) * (y - a[x]);
                sum[i] += (y - a[x]);
            }
            a[x] = y;
        }
        else
        {
            int x;
            cin >> x;
            x--;
            if (arr[x].size() < SR)
            {
                val[x] = sum[x] = 0;
                for (int i : arr[x])
                {
                    val[x] += sum[x] * a[i];
                    sum[x] += a[i];
                }
            }
            cout << val[x] << "\n";
        }
    }
}