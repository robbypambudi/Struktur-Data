#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main()
{

    string player[5];
    cin >> player[1] >> player[2] >> player[3] >> player[4];
    int N;
    string seeker;
    cin >> N >> seeker;
    int target;
    for (int i = 1; i <= 4; i++)
    {
        if (player[i] == seeker)
        {
            target = i;
            break;
        }
    }
    // cout << target << endl;

    vector<int> p[5];
    for (int i = 0; i < N; i++)
    {
        int player, pos;
        cin >> player >> pos;
        if (player == 1)
        {
            p[1].push_back(pos);
        }
        else if (player == 2)
        {
            p[2].push_back(pos);
        }
        else if (player == 3)
        {
            p[3].push_back(pos);
        }
        else if (player == 4)
        {
            p[4].push_back(pos);
        }
    }

    int size_Seeker = p[target].size();
    // cout << size_Seeker << endl;
    bool visited[5] = {false, false, false, false, false};

    for (int i = 0; i < size_Seeker; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (j == target)
                continue;
            if (p[j].size() == 0)
            {
                continue;
            }

            if (p[j][i] == p[target][i])
            {
                visited[j] = true;
            }
        }
    }
    int coutn = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (visited[i] == true && i != target)
        {
            coutn++;
        }
    }

    if (coutn == 0)
    {
        cout << player[target] << " jaga lagi" << endl;
        return 0;
    }

    for (int i = 1; i <= 4; i++)
    {
        if (visited[i] == true && i != target)
        {
            if (coutn == 1)
            {
                cout << player[i] << " ";
            }
            else if (coutn == 2)
            {
                cout << player[i] << ", dan ";
                coutn = coutn - 1;
            }
            else
            {
                cout << player[i] << ", ";
                coutn = coutn - 1;
            }
        }
    }
    cout << "ditangkap oleh " << player[target] << endl;
}