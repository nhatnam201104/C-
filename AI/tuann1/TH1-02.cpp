#include <iostream >
#include <math.h>
using namespace std;
int isprime(int n)
{
    if (n < 2)
        return 0;
    int k = sqrt(n);
    for (int i = 2; i < k; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void sumdong(int a[100][100], int m, int n, FILE *f)
{
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        fprintf(f, "%d ", sum);
    }
    fprintf(f, "\n");
}
void sumcot(int a[100][100], int m, int n, FILE *f)
{
    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += a[i][j];
        }
        fprintf(f, "%d ", sum);
    }
    fprintf(f, "\n");
}
int main()
{
    int a[100][100];
    int m, n;
    FILE *f = fopen("array2.txt", "rt");
    fscanf(f, "%d", &m);
    fscanf(f, "%d", &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &a[i][j]);
        }
    }
    fclose(f);
    FILE *q = fopen("array2.out", "wt");
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isprime(a[i][j]))
                cnt++;
        }
    }
    fprintf(q, "%d\n", cnt);
    sumcot(a, m, n, q);
    sumdong(a, m, n, q);
}