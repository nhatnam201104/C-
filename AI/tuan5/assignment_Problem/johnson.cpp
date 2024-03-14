#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
struct job
{
    int time1, time2;
};
vector<job> Jobs;
int m;
void docfile()
{

    fstream input("../data/Johnsond.txt", ios::in);
    input >> m;
    Jobs.resize(m);
    for (int i = 0; i < m; i++)
    {
        input >> Jobs[i].time1;
    }
    for (int i = 0; i < m; i++)
    {
        input >> Jobs[i].time2;
    }
}

bool compare(job a, job b)
{
    return a.time1 < b.time1;
}
vector<job> johnson()
{
    vector<job> n1, n2;
    sort(Jobs.begin(), Jobs.end(), compare);
    for (int i = 0; i < m; i++)
    {
        if (Jobs[i].time1 <= Jobs[i].time2)
        {
            n1.push_back(Jobs[i]);
        }
        else
            n2.push_back(Jobs[i]);
    }
    for (job i : n2)
    {
        n1.push_back(i);
    }
    return n1;
}

int totalTime(vector<job> Jobs)
{
    johnson();
    int total = 0;
    int may1 = 0, may2 = 0;
    for (int i = 0; i < Jobs.size(); i++)
    {
        may1 += Jobs[i].time1;
        may2 = max(may1, may2) + Jobs[i].time2;
    }
    total += max(may1, may2);
    return total;
}
int main()
{
    docfile();
    vector<job> jobs = johnson();
    cout << "total time: " << totalTime(jobs);
}