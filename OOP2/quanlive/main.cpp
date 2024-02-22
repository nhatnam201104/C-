#include <iostream>
#include "hanhkhach.cpp"
using namespace std;
int main()
{
    cout << "Nhap So Luong Khach Hang: "; int n; cin >> n;
    hanhkhach *arr = new hanhkhach[n];
    for (int i = 0; i < n; ++i) arr[i].in();
    cout << endl << endl << "Output" << endl << endl;
    for (int i = 0; i < n; ++i)
    {
        arr[i].out();
        cout << endl << "------------------" << endl << endl;
    }
    
}