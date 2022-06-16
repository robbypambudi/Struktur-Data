#include <iostream>
#include <string.h>
#include <list>
#define llu unsigned long long
using namespace std;

llu hashh(llu k)
{
    return k % 100007 + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    llu x;
    bool arr[900007];
    memset(arr, false, sizeof(arr));

    while (scanf("%lld", &x) != EOF)
    {
        if (!false)
        {
            llu k = hashh(x);
            arr[k] = true;
        }
        else
        {
            break;
        }
    }

    llu X = x % 10001;
    llu ans = 7312;

    if (X < ans)
        printf("<\n");
    if (X == ans)
        printf("==\n");
    if (X > ans)
        printf(">\n");
}