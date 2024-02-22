#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;
int tour[100];
int visited[100] = { 0 };
int sum = 0;
int min = INT_MAX;
void docfile(FILE* f, int& n, int a[100][100])
{
    f = fopen("tmp.txt", "rt");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fscanf(f, "%d", &a[i][j]);
    }
}
void outputTour(int a[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "->";
    }
}

void TSP(int start, int n, int a[100][100], int pos)
{
    tour[start] = 1;
    visited[0] = start;
    for (int i = 0; i < n; i++)
    {

        if (visited[i] == 0 && a[pos - 1][i] > 0)
        {
            tour[pos] = i;
            visited[pos] = 1;
            if (pos == n - 1 && a[pos - 1][start] > 0)
            {
                outputTour(tour, n);
                cout << start << "\n";

            }
            else
            {
                TSP(start, n, a, pos++);
            }
            visited[i] = 0;
        }
    }
}
int main()
{
    int n, a[100][100];
    FILE* f;
    docfile(f, n, a);
    TSP(1, n, a, 0);
}
