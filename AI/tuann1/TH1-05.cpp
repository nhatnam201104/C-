#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;
int khoitaoboso(int *&a, int n)
{
    int tmp;
    do
    {
        tmp = (rand() % (n * n)) + 1;
        a[tmp]++;
        cout << a[tmp] << "\n";
    } while (a[tmp] != 1);
    return tmp;
}
int main()
{
    srand(time(NULL));
    FILE *f = fopen("taci.txt", "wt");
    int n;
    cin >> n;
    fprintf(f, "%d\n", n);
    int *tmp = new int[n * n + 1]();
    int i = 0, j = 0;
    while (i < n)
    {
        if (j == n)
        {
            fprintf(f, "\n");
            j = 0;
            i++;
        }
        else
        {
            fprintf(f, "%d\t", khoitaoboso(tmp, n));
            j++;
        }
    }
}