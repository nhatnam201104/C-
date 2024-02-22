#include <iostream> 
using namespace std;
void docfile(FILE *f, int &n, int a[100][100])
{
    f = fopen("tsp.txt", "rt");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &a[i][j]);
        }
    }
}
void outputTour(int a[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "->";
    }
    
}

int main ()
{

}