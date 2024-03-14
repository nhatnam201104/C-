#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
struct vertex
{
    int id, bac;
};

// tim bac lon nhat
// to mau cho bac lon nhat
vector<int> colors;
int mau = 1;
void docfile(int &m, vector<vector<int>> &matrix, vector<vertex> &dsdinh)
{
    fstream input("./data/color4.txt", ios::in);
    input >> m;
    dsdinh.resize(m);
    matrix.resize(m);
    for (int i = 0; i < m; i++)
    {
        matrix[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            input >> matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        dsdinh[i].id = i;
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
                cnt++;
        }
        dsdinh[i].bac = cnt;
    }
}

void xuat()
{
    for (int i = 0; i < colors.size(); i++)
    {
        cout << "Dinh " << i + 1 << " to mau " << colors[i] << "\n";
    }
}

bool compareInterval(vertex i1, vertex i2)
{
    return (i1.bac > i2.bac);
}
void tomau(vector<vector<int>> matrix, vector<vertex> &dinh)
{
    sort(dinh.begin(), dinh.end(), compareInterval);
    colors.resize(dinh.size(), 0);
    bool can_color, all_colored;
    while (true)
    {
        all_colored = true;
        for (int i = 0; i < dinh.size(); i++)
        {
            int a = colors[dinh[i].id];
            if (a == 0)
            {
                can_color = true;
                for (int j = 0; j < dinh.size(); j++)
                {
                    // kiem tra xem dinh j co ke voi i khong va da duoc to mau do chua
                    if (matrix[dinh[i].id][dinh[j].id] == 1 && colors[j] == mau)
                    {
                        can_color = false;
                        break;
                    }
                }
                if (can_color)
                {
                    colors[dinh[i].id] = mau;
                    all_colored = false;
                }
            }
        }
        if (all_colored)
            break;
        else
            mau++;
    }
}

int main()
{
    int m = 0;
    vector<vertex> dinh;
    vector<vector<int>> a;
    docfile(m, a, dinh);

    tomau(a, dinh);
    xuat();
    cout << "total: " << mau;
}
