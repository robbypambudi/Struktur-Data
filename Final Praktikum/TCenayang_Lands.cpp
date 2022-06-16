#include <iostream>

int n, x[500], y[500];

int i, j, k;
int tkc, mvl;
bool icp;

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }

    mvl = 1 << 31;
    mvl--;
    tkc = mvl;
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            for (k = j + 1; k <= n; k++)
            {
                int area = x[i] * (y[j] - y[k]);
                area += x[j] * (y[k] - y[i]);
                area += x[k] * (y[i] - y[j]);
                area = abs(area);

                if (area == 0)
                {
                    continue;
                }
                if (area == tkc)
                    icp = true;
                if (area < tkc)
                    icp = false;
                if (area < tkc)
                    tkc = area;
            }
        }
    }
    if (tkc == mvl)
    {
        printf("-1.00\n");
        return 0;
    }
    if (icp)
    {
        printf("-1.00\n");
        return 0;
    }
    printf("%.2f\n", (float)tkc / 2.0);
}