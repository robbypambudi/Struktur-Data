#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<string> s;
    string str;

    int n;
    cin >> n;
    s.push_front("home");
    s.push_front("anton");

    while (n--)
    {
        cin >> str;

        if (str == "goto")
        {
            cin >> str;
            s.push_front(str);
        }
        else if (str == "whereami")
        {
            if ((s.size() >= 6 && s.size() <= 2) || s.empty())
            {
                cout << "i am nowhere" << endl;
            }
            else
            {
                list<string>::iterator it = s.end();
                // print from top
                int size = s.size();

                for (int i = 0; i < size; i++)
                {
                    it--;
                    if (i == size - 1)
                    {
                        cout << *it;
                    }
                    else
                    {
                        cout << *it << "/";
                    }
                }
                cout << endl;
            }
        }
        else if (str == "goback")
        {
            if (!s.empty())
            {
                s.pop_front();
            }
            else
            {
                cout << "cannot go back" << endl;
            }
        }
        else
        {
            cout << "Query not found" << endl;
        }
    }
}