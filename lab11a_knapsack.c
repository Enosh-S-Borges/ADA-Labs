/*a) Implement an algorithm to solve Knapsack problem with 
Dynamic  Programming  approach  and  perform  its  analysis  for 
different inputs. 
b) Implement Prim's algorithm to find Minimum Spanning Tree of a 
graph and perform its analysis for different inputs */

// a) Knapsack problem with Dynamic Programming approach (Recursive calls & Memoization of values)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int opcount = 0, dp[25][25], weight[25], profit[25];

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int knapsackMemo(int n, int W)
{
    if (dp[n][W] != -1)
        return dp[n][W];

    opcount++;
    if (weight[n - 1] <= W)
        return dp[n][W] = max(knapsackMemo(n - 1, W), profit[n - 1] + knapsackMemo(n - 1, W - weight[n - 1]));
    else
        return dp[n][W] = knapsackMemo(n - 1, W);
}

void init(int n, int W)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
    }
}

void tester()
{
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Sack capacity: ");
    scanf("%d", &W);
    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d :", i + 1);
        scanf("%d%d", &weight[i], &profit[i]);
    }
    init(n, W);
    printf("Max profit is %d\n", knapsackMemo(n, W));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    printf("Picked items:\n");
    int k = W;
    for (int i = n; i > 0; i--)
    {
        if (dp[i][k] != dp[i - 1][k])
        {
            printf("%d\t", i);
            k -= weight[i - 1];
        }
    }
    printf("\nOpcount:%d", opcount);
}

void plotter()
{
    FILE *f = fopen("prims.txt", "w");

    srand(1);

    for (int nodes = 5; nodes <= 25; nodes += 5)
    {
        int n = nodes;

        int adjMat[n][n];

        // Generate connected undirected graph
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    adjMat[i][j] = 0;
                else
                    adjMat[i][j] = INT_MAX;
            }
        }

        // Create a chain first to guarantee connectivity
        for (int i = 0; i < n - 1; i++)
        {
            int wt = rand() % 20 + 1;
            adjMat[i][i + 1] = wt;
            adjMat[i + 1][i] = wt;
        }

        // Add extra random edges
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 2; j < n; j++)
            {
                if (rand() % 2)
                {
                    int wt = rand() % 20 + 1;
                    adjMat[i][j] = wt;
                    adjMat[j][i] = wt;
                }
            }
        }
        int heapCount = 0;
        int graphCount = 0;
        prims(n, adjMat);
        fprintf(f, "%d\t%d\n",n, (graphCount > heapCount) ? graphCount : heapCount);
    }
    fclose(f);
    printf("Data written to prims.txt\n");
}
void main()
{
    int ch;
    printf("Enter \n1.Tester\n2.Plotter\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        tester();
        break;
    case 2:
        plotter();
        break;
    default:
        printf("Invalid choice.\n");
    }
}