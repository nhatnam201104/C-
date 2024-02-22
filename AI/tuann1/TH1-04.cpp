#include <iostream>
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
int main()
{
    int cnt = 0;
    FILE *f = fopen("array1.txt", "rt");
    int n;
    fscanf(f, "%d", &n);
    int tmp;
    while (!feof(f))
    {
        fscanf(f, "%d", &tmp);
        cout<<tmp<<"\n";
        if (isprime(tmp))
            cnt++;
    }
    fclose (f);
    FILE *q = fopen("array1.out", "wt");
     fprintf(q, "%d\n", cnt);
}