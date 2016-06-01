#include <iostream>
#include <vector>

using namespace std;

int findfirst(vector<int> cursors, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (cursors[i] == -1)
            return i;
    }
    return -1;
}

void directOrder(vector<int> cursors, int n, int father)
{
    if (father == -1)
        father = findfirst(cursors, n);
    cout << father << " ";
    for (int i = 0; i < n; ++i)
    {
        if (cursors[i] == father)
            directOrder(cursors, n, i);
    }
}

void reverseOrder(vector<int> cursors, int n, int father)
{
    if (father == -1)
        father = findfirst(cursors, n);
    for (int i = 0; i < n; ++i)
    {
        if (cursors[i] == father)
            reverseOrder(cursors, n, i);
    }
    cout << father << " ";
}

void symmeticOrder(vector<int> cursors, int n, int father)
{
    if (father == -1)
        father = findfirst(cursors, n);
    int ind = 0;
    for (ind; ind < n; ++ind)
    {
        if (cursors[ind] == father)
        {
            symmeticOrder(cursors, n, ind++);
            break;
        }
    }
    cout << father << " ";
    for (ind; ind < n; ++ind)
    {
        if (cursors[ind] == father)
            symmeticOrder(cursors, n, ind);
    }
}

int main()
{
    int n, a;
    cin >> n;
    vector<int> cursors;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        cursors.push_back(a);
    }
    directOrder(cursors, n, -1);
    cout << endl;
    reverseOrder(cursors, n, -1);
    cout << endl;
    symmeticOrder(cursors, n, -1);
    cout << endl;
    return 0;
}