DAA TA-2


Name : Akshat Surana


Roll : 34 (A2 batch)

<p align="center">Code:</p>

<pre>
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

<p align="center">Test cases:</p>

case 1)

    (0,0) to (5,5)
    
Output:

enter initial x : 0 
enter initial y : 0
enter final x : 5
enter final y : 5

max --> 187
path --> -15 -> 24 -> 23 -> 12 -> -5 -> 15 -> 6 -> 10 -> 4 -> 20 -> -6 -> 9 -> 7 -> 12 -> 6 -> 5 -> 20 -> 11 -> 14 -> 3 -> 6 -> -2 -> 8

min-->-141
path --> -15 -> 24 -> -16 -> 9 -> 7 -> -20 -> -6 -> -3 -> -17 -> -21 -> -17 -> -20 -> -11 -> -8 -> -10 -> 2 -> -25 -> -2 -> 8

case 2)

    (0,1) to (5,4)

Output:

max --> 196
path --> 24 -> 23 -> 12 -> -5 -> 15 -> 6 -> 10 -> 4 -> 20 -> -6 -> 9 -> 7 -> 12 -> 6 -> 5 -> 20 -> 11 -> 14 -> 3 -> 8 -> -2

min-->-134
path --> 24 -> -16 -> 9 -> 7 -> -20 -> -6 -> -3 -> -17 -> -21 -> -17 -> -20 -> -11 -> -8 -> -10 -> 2 -> -25 -> -2


<p align="center">Logic:</p>

Here we are using the concept of back tracking. We are maintaining a visited array in which all the elements of the array are initially initialized to zero and after visiting a vertex in the original matrix we set the value of same position in the visited array to one. More two vectors are being maintained namely “vmax “and “vmin”, these two are globally initialized and are saving the vertex which is visited and is contributing in the path. To check which vertex is contributing in the path and which is not, there are several if conditions. The "bfs" function is repeatedly calling itself. Here it first takes the initial position and checks whether it is a valid position or not and if it is a valid position, it adds its value in sum which was initially initialized to 0. After that it checks whether the vertices adjacent to this vertex are visited or not and if not visited, it ads it to sum and checks whether it is greater (for max sum case) and smaller for (min sum case) and if the respective conditions are satisfied then it updates the sum and ads the vertex in “vmax” and “vmin” array respectively.

Time complexity: n(2^n)
</pre>

