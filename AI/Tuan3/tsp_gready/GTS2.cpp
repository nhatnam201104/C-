#include <iostream>
#include <vector>
#include <limits.h>
#include <fstream>
using namespace std;
vector<int> route;
vector <int> beginarr;
int minCost = INT_MAX;
void docfile(int &n, int &begin, vector<vector<int>> &a)
{
    fstream input("Data/GTS2c.txt", ios::in);
    input >> n;
    input >> begin;
    int tmp;
    for (int i = 0; i < begin; i++)
    {
        input>>tmp;
        beginarr.push_back (tmp);
    }
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            input >> a[i][j];
    }
    input.close();
}

int timDinhGanNhat(vector<vector<int>> &a, vector<bool> &visited, int dinhHienTai)
{
    int dinhGanNhat = -1;
    int minCost = INT_MAX;
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && a[dinhHienTai][i] < minCost && i != dinhHienTai)
        {
            minCost = a[dinhHienTai][i];
            dinhGanNhat = i;
        }
    }
    return dinhGanNhat;
}

void tsp(vector<vector<int>> &a, int begin)
{
    vector<int> routeTmp;
    int n = a.size();
    int cost = 0;

    vector<bool> visited(n, false);
    visited[begin - 1] = true;

    int currentVertex = begin - 1;
    routeTmp.push_back(begin);

    for (int i = 0; i < n - 1; i++)
    {
        int nextVertex = timDinhGanNhat(a, visited, currentVertex);
        routeTmp.push_back(nextVertex + 1);
        cost += a[currentVertex][nextVertex];
        visited[nextVertex] = true;
        currentVertex = nextVertex;
    }
    // Quay lại điểm ban đầu
    routeTmp.push_back(begin);
    cost += a[currentVertex][begin - 1];
    if (cost < minCost)
    {
        minCost = cost;
        route = routeTmp;
        
    }
}
void GTS2(vector<vector<int>> &a, int n)
{
    for (int i = 0; i < beginarr.size(); i++)
    {
        tsp(a, beginarr[i]);
    }
    cout << "Total Cost: " << minCost << endl;
    for (int i = 0; i < route.size(); i++)
    {
        cout << route[i] << " -> ";
    }
}
int main()
{
    int n, begin;
    vector<vector<int>> a;
    docfile(n, begin, a);
    GTS2(a, n);
    return 0;
}
