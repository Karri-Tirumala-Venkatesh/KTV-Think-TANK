#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<vector<int>> graph = {{0, 1, 1, 0, 0}, {1, 0, 0, 1, 0}, {1, 0, 0, 1, 1}, {0, 1, 1, 0, 1}, {0, 0, 1, 1, 0}};
    vector<vector<int>> graph = {{0, 1, 1, 0, 0}, {1, 0, 1, 0, 0}, {1, 0, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    // vector<vector<int>> graph = {{0, 1, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 1, 0}, {0, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 1, 0}};
    int n = graph.size();
    vector<int> visited;
    visited.push_back(0);
    for (int i = 1; i < n; i++)
    {
        if (graph[0][i] == 0)
        {
            visited.push_back(i);
            break;
        }
    }
    int key = 1;
    while (key == 1)
    {
        key = 0;
        for (int i = 0; i < n; i++)
        {
            for (auto j : visited)
            {
                if (graph[j][i] == 0 && j != i)
                {
                    key = 1;
                }
                else
                {
                    key = 0;
                    break;
                }
            }
            if (key == 1)
            {
                visited.push_back(i);
            }
        }
    }

    // let k = number of edges
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                k++;
            }
        }
    }

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto j : visited)
        {
            if (graph[j][i] == 1)
            {
                temp++;
            }
        }
    }

    for (auto i : visited)
    {
        cout << i << " ";
    }
    cout << "\n";

    if (temp == k)
    {
        cout << "Bipartite\n";
    }
    else
    {
        cout << "Not Bipartite\n";
    }
    return 0;
}