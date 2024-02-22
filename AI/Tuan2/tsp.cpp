#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <string>
#include <ctime>
using namespace std;
#define start 0
int tour[100];
bool visited[100] = {false};
int cost = 0;
int ans = INT_MAX;
int cnt = 0;
int cmin = INT_MAX;
int totalCost(int n, int a[100][100])
{
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += a[tour[i]][tour[i + 1]];
    }
    return cost;
}
void docfile(FILE *f, int &n, int a[100][100])
{
    f = fopen("tsp.txt", "rt");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &a[i][j]);
            cmin = min(cmin, a[i][j]);
        }
    }
}
void outputTour(int a[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "->";
    }
    cnt++;
}

void TSP(int n, int a[100][100], int pos)
{

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            tour[pos] = i;
            visited[i] = true;
            cost += a[tour[pos - 1]][tour[pos]];

            if (pos == n - 1)
            {
                // outputTour(tour, n);
                // cout << tour[n + 1] << " Cost: ";
                // cout << cost + a[tour[pos]][start] << "\n";
                ans = min(ans, cost + a[tour[pos]][start]);
            }
            else if (cost + ((n - i + 1) + 1) * cmin < ans)
            {
                TSP(n, a, pos + 1);
            }
            visited[i] = false;
            cost -= a[tour[pos - 1]][tour[pos]];
        }
    }
}
int main()
{

    int n, a[100][100];
    FILE *f;
    docfile(f, n, a);
    tour[0] = tour[n] = start;
    visited[start] = true;
      clock_t start_time = clock();
    TSP(n, a, 1);
    cout << "\n"
         << "best cost:" << ans << "\n";
    clock_t end_time = clock();
    double duration = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Execution time: " << fixed << setprecision(4) << duration << "ms" << endl;
    fclose(f);
}
