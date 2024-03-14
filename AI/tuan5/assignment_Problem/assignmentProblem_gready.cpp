#include <iostream>
#include <fstream>
#include <vector>
#include <Limits.h>
using namespace std;
vector<vector<int>> matrix;
int m;
vector<bool> congviec;
vector<bool> congnhan;

void docfile()
{
    fstream input("../data/assignmentd.txt", ios::in);
    input >> m;
    matrix.resize(m);
    congviec.resize(m, true);
    congnhan.resize(m, true);
    for (int i = 0; i < m; i++)
    {
        matrix[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            input >> matrix[i][j];
        }
    }
    input.close ();
}
int phancong()
{
    int max = INT_MIN;
    int pos, cn;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] > max && congviec[j] && congnhan[i])
            {
                max = matrix[i][j];
                pos = j;
                cn = i;
            }
        }
    }
    congviec[pos] = false;
    congnhan[cn] = false;
    return max;
}
int solve()
{
    int cost = 0;
    int cnt = 0;
    while (cnt != m)
    {
        cost += phancong();
        cnt++;
    }
    return cost;
}
void xuat()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    docfile();
    cout << "total " << solve();
}