// /*
// pseudocode
// DFS (u) {
//     <tham dinh u>
//     visted [u] =true // danh dau la u da dc tham
//     //duyet cac dinh ke voi u
//     for (v: adj[u])
//     {
//         if (!visited [v])
//         {
//             DFS(v)
//         }
//     }
// }
// */

// #include <iostream>
// #include <fstream>
// #include <vector>
// using namespace std;
// bool visited[1001];
// vector<vector<int>> arr;
// void input(vector<vector<int>> &arr, int &n, int &m)
// {
//     int x, y;
//     visited[1001] = {false};
//     // fstream input("data.txt", ios::in);
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> x;
//         cin >> y;11
//         arr[x].push_back(y);
//         arr[y].push_back(x);
//     }
// }
// void DFS(int u)
// {
//     cout << u;
//     visited[u] = true;
//     for (int v : arr[u])
//     {
//         cout << v;
//     }
// }
// int main()
// {
//     int n, m;
//     input(arr, n, m);
//     // DFS(1);
//     return 0;
// }