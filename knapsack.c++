#include <bits/stdc++.h>
using namespace std;

struct item
{
    int profit, weight;
};

// sorting the item in descending order by ratio of item(profit / weight)
static bool cmp(struct item a, struct item b)
{
    double r1 = a.profit / a.weight;
    double r2 = b.profit / b.weight;
    return r1 > r2;
}

double knapsackFunction(int W, struct item arr[], int N)
{

    sort(arr, arr + N, cmp);
    double sumOfProfit = 0.0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            sumOfProfit += arr[i].profit;
        }
        else
        {
            sumOfProfit += arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    return sumOfProfit;
}

int main()
{
    int W = 50;
    item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int size = sizeof(arr) / sizeof(arr[0]);
    double result = knapsackFunction(W, arr, size);

    cout << "Total profit is: " << result;

    return 0;
}
