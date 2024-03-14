#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
vector<pair<int, int>> matrix;
int canh;
void input()
{
    fstream in("E:\\Code\\C++\\AI\\Tuan6\\data\\line4.txt", ios::in);
    if (in.fail())
    {
        cout << "kh doc duoc file";
        exit (1);
    }
    in >> canh;
    for (int i = 0; i < canh; i++)
    {
        pair<int, int> canhtmp;
        in >> canhtmp.first;
        in >> canhtmp.second;
        matrix.push_back(canhtmp);
    }
}
void quicksort(vector<pair<int, int>> & matrix, int left, int right)
{
    pair<int, int> x = matrix[(left + right) / 2];
    int i = left, j = right;
    do
    {
        while (matrix[i].first < x.first)
            i++;
        while (matrix[j].first > x.first)
            j--;
        if (i <= j)
            swap(matrix[i++], matrix[j--]);
    } while (i < j);
    if (i < right)
        quicksort(matrix, i, right);
    if (j > left)
        quicksort(matrix, left, j);
}
vector<pair<int, int>> assignment()
{
    vector<pair<int, int>> result;
    quicksort(matrix, 0, canh);
    result.push_back(matrix[0]);
    pair<int, int> tmp;

    for (pair<int, int> i : matrix)
    {
        tmp = result.back();
        if (i.first > tmp.second)
        {
            result.push_back(i);
        }
    }
    return result;
}
int main()
{
    input();
    vector<pair<int, int>> result = assignment();
    for (pair<int, int> i : result)
    {
        cout << i.first << " " << i.second<<"\n";
    }
    cout<<"\n";
    

}

//hrll