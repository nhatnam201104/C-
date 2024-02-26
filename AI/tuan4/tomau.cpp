#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
struct thanhpho
{
    int bac = 0, mau = 0, dinh;
};
#include <map>
int maumax = 0;

using namespace std;
void docfile(int &m, vector<vector<int>> &color, vector<thanhpho> &tp)
{
    fstream input("./data/data1.txt", ios::in);
    input >> m;
    color.resize(m);
    for (int i = 0; i < m; i++)
    {
        color[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            input >> color[i][j];
        }
    }
    tp.resize(m);
    for (int i = 0; i < m; i++)
    {
        tp[i].dinh = i;
        for (int j = 0; j < m; j++)
        {
            if (color[i][j] == 1)
            {
                tp[i].bac++;
            }
        }
    }
}
void sort(vector<thanhpho> &tp)
{
    thanhpho tmp;
    for (int i = 0; i < tp.size(); i++)
    {
        for (int j = i + 1; j < tp.size(); j++)
        {
            if (tp[i].bac < tp[j].bac)
            {
                tmp = tp[i];
                tp[i] = tp[j];
                tp[j] = tmp;
            }
        }
    }
}

void tomau(vector<thanhpho> &tp, vector<vector<int>> color)
{

    sort(tp);
    for (int i = 0; i < tp.size(); i++)
    {
    }
}

void to(int dinh, vector<vector<int>> color, vector<thanhpho> &tp)
{
    tp[dinh].mau =maumax+1;
    tp [dinh].bac=0;
    for (int j = 0; j < color[dinh].size(); j++)
    {
        if (color [dinh][j]==0)
            tp[j].bac =0;
    }
    maumax++;
}
void xuat(int m, vector<thanhpho> color)
{
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << color[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < color.size(); i++)
    {
        cout << color[i].bac << " ";
    }
}

int main()
{
    vector<vector<int>> a;
    vector<thanhpho> tp;
    int m;
    docfile(m, a, tp);

    xuat(m, tp);
}