#include <cstdio>
#include <cmath>
#include <algorithm>

void buildTree(int n1, int n2, int h)
{
    int n = n2 - n1 + 1;
    if ((n == 0) || (h == 0))
    {
        return;
    }

    int powerH = pow(2, h);
    if ((n > 1) || (h > 1))
    {
        if (n > (powerH - 1))
        {
            printf(" Impossible.");
            return;
        }
    }
    int goesToLeft = std::max(n - powerH / 2, 0);

    printf(" %d", n1 + goesToLeft);
    if (goesToLeft > 0)
    {
        buildTree(n1, n1 + goesToLeft - 1, h - 1);
    }
    buildTree(n1 + goesToLeft + 1, n2, h - 1);
}

int main()
{
    int N, H;
    int casee = 0;
    do
    {
        casee++;
        scanf("%d %d", &N, &H);
        if (N == 0 && H == 0)
            break;
        printf("Case %d:", casee);
        buildTree(1, N, H);
        printf("\n");
    } while (1);
    return 0;
}