#include <iostream>
#include <vector>
using namespace std;
long long int N, M;
bool sat = false;
bool dfs(vector<string> &arr, int r, int c)
{

    if (r == N - 1 && c == M - 1)
    {
        sat = true;
        return true;
    }
    if (sat)
        return true;
    if (r < 0 || r >= N || c < 0 || c >= M)
        return false;
    if (r >= N || c >= M)
        return false;
    if (arr[r][c] == '#')
        return false;

    bool res = false;
    arr[r][c] = '#';
    res |= dfs(arr, r, c + 1);
    if (!res)
        res |= dfs(arr, r + 1, c);
    return res;
}

int main()
{
    cin >> N >> M;
    if (N * M <= 3)
        return 0;

    vector<string> arr1;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        arr1.push_back(s);
    }

    sat = false;
    bool sat1 = dfs(arr1, 0, 1);
    sat = false;
    bool sat2 = dfs(arr1, 1, 0);

    if (sat1 && sat2)
    {
        cout << "2" << endl;
    }
    else if (sat1 || sat2)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
}