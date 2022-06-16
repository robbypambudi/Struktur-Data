#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X, Y;
    cin >> X >> Y;
    int arr[1000005];

    for (int i = 0; i < X; i++)
    {
        arr[i] = 0;
    }

    int a, b, c;
    for (int i = 0; i < Y; i++)
    {
        cin >> a >> b >> c;

        arr[b] = arr[a] + c;
    }

    for (int i = 1; i < X; i++)
    {
        cout << i << " " << arr[i] << "\n";
    }
}