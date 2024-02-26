#include <iostream>
#include <vector>
#include <fstream>
#include <limits.h>
using namespace std;
vector<int> route;
vector<int> beginarr;
void docfile(int &n, int &begin, vector<vector<int>> &a)
{
    fstream input("Data/GTS1a6  .txt", ios::in);
    input >> n;
    input >> begin;
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            input >> a[i][j];
    }
    input.close();
}
void input(vector<int> beginarr)
{

    for (int i : beginarr)
    {
        cout << i << " ";
    }
}
int timDinhGanNhat(vector<vector<int>> &a, vector<bool> &visited, int dinhHienTai)
{
    int dinhGanNhat = -1;
    int minCost = INT_MAX;
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && a[dinhHienTai][i] < minCost)
        {
            minCost = a[dinhHienTai][i];
            dinhGanNhat = i;
        }
    }
    return dinhGanNhat;
}

void tsp(vector<vector<int>> &a, int begin)
{
    int n = a.size();
    int cost = 0;

    vector<bool> visited(n, false);
    visited[begin - 1] = true;

    int currentVertex = begin - 1;
    route.push_back(begin);

    for (int i = 0; i < n - 1; i++)
    {
        int nextVertex = timDinhGanNhat(a, visited, currentVertex);
        route.push_back(nextVertex + 1);
        // cout<< a[currentVertex][nextVertex]<<" ";
        cost += a[currentVertex][nextVertex];
        visited[nextVertex] = true;
        currentVertex = nextVertex;
    }
    // Quay lại điểm ban đầu
    route.push_back(begin);
    cost += a[currentVertex][begin - 1];
    for (int i = 0; i < n; i++)
    {
        cout << route[i] << " -> ";
    }
    cout << endl;
    cout << "Total Cost: " << cost << endl;
}

int main()
{
    int n, begin;
    vector<vector<int>> a;
    docfile(n, begin, a);
    tsp(a, begin);
    return 0;
}
