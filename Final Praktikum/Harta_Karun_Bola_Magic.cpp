#include <iostream>
#include <deque>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int ans = 0, res = 0;
    cin >> N;
    deque<int> s;
    for (int i = 0; i < N; i++)
    {
        int deq = 0;
        ans = 0;
        bool sat = false;
        int x;
        cin >> x;
        s.push_back(x);
        int size = s.size();
        int temp = s.back();
        res += 1;
        for (int j = size - 1; j >= 0 && deq != x; j--, deq++)
        {
            // cout << "j: " << s[j] << endl;
            if (s[j] == x)
            {
                sat = true;
                ans += 1;
            }
            else
            {
                sat = false;
                break;
            }
        }

        if (ans == x)
        {
            for (int k = 0; k < x; k++)
            {
                s.pop_back();
                res -= 1;
            }
        }
        cout << res << "\n";
    }
}