#include <iostream>
#include <vector>
using namespace std;
int money [] ={10,20,50};
int currentMoneysum = 0;
vector<int> currentMoney;
void getMoneySet(int pos)
{
    if (currentMoneysum >= 100)
        return ;
    for (int i = 0; i < 3; i++)
    {
        currentMoneysum +=money [i];
        currentMoney.push_back (money[i]);
        getMoneySet (pos++);
    }
}