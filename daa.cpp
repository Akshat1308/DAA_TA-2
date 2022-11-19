#include <bits/stdc++.h>
using namespace std;

int ans_max = INT_MIN;
int ans_min = INT_MAX;
vector<int> vmax;
vector<int> vmin;
const int n = 10;
void bfs(int arr[n][n], int visited[n][n], int i, int j, int sum, int fi, int fj, vector<int> v1)
{
    if (i < 0 || j < 0 || i > n - 1 || j > n - 1)
    {
        return;
    }
    sum += arr[i][j];
    v1.push_back(arr[i][j]);
    visited[i][j] = 1;

    // cout << "index i-->" << i << "    index j-->" << j << endl;
    // cout << "current vivisted matrix : \n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {

    //         cout << visited[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    if (i == fi && j == fj)
    {

        if (sum > ans_max)
        {
            ans_max = sum;
            vmax = v1;
        }
        if (sum < ans_min)
        {
            ans_min = sum;
            vmin = v1;
        }
        visited[i][j] = 0;
        return;
    }

    if (visited[i + 1][j] == 0)
    {
        bfs(arr, visited, i + 1, j, sum, fi, fj, v1);
    }
    if (visited[i][j + 1] == 0)
    {
        bfs(arr, visited, i, j + 1, sum, fi, fj, v1);
    }
    if (visited[i - 1][j] == 0)
    {
        bfs(arr, visited, i - 1, j, sum, fi, fj, v1);
    }
    if (visited[i][j - 1] == 0)
    {
        bfs(arr, visited, i, j - 1, sum, fi, fj, v1);
    }
    visited[i][j] = 0;
}
int main()
{
    // initializing matrix
    vector<int> v1;
    int matrix[n][n];

    // generating ramdom matrix in a given range
    // using { random = rand()%(max-min+1) + min; }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int random = rand() % (25 - -25 + 1) + -25;
            matrix[i][j] = random;
        }
    }

    int visited[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    int initial_x = 0, initial_y = 0, final_x = 0, final_y = 0;
    cout << "\n enter initial x : ";
    cin >> initial_x;
    cout << "\n enter initial y : ";
    cin >> initial_y;
    cout << "\n enter final x : ";
    cin >> final_x;
    cout << "\n enter final y : ";
    cin >> final_y;

    bfs(matrix, visited, initial_x, initial_y, 0, final_x, final_y, v1);
    cout << "max --> " << ans_max << endl;
    cout << "path --> ";
    for (auto i : vmax)
        cout << i << " -> ";
    cout << endl;
    cout << " min-->" << ans_min;
    cout << endl;
    cout << "path --> ";
    for (auto i : vmin)
        cout << i << " -> ";

    return 0;
}
