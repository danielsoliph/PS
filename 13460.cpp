// Import required libraries for problem solving
#include <iostream>
#include <vector>
#include <algorithm>

enum Direction
{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

int tilt(char board[][10], int N, int M, int r_i, int r_j, int b_i, int b_j, int h_i, int h_j, int direction)
{
    int blocked_by_blue = false;
    int goal_in = false;
    int failed = false;
    int new_r_i = r_i;
    int new_r_j = r_j;
    int new_b_i = b_i;
    int new_b_j = b_j;

    switch (direction)
    {
        case UP:
            
            // Move red ball
            for (int i=r_i-1; i>0; i--){
                if (board[i][r_j] == '#'){
                    break;
                }
                else if (board[i][r_j] == '.'){
                    new_r_i = i;
                }
                else if (board[i][r_j] == 'O'){
                    new_r_i = i;
                    goal_in = true;
                    break;
                }else{ // board[i][r_j] == 'B'
                    blocked_by_blue = true;
                    break;
                }
            }
            // Move blue ball
            for (int i=b_i-1; i>0; i--){
                if (board[i][b_j] == '#'){
                    break;
                }
                else if (board[i][b_j] == '.'){
                    new_b_i = i;
                }
                else if (board[i][b_j] == 'O'){
                    new_b_i = i;
                    failed = true;
                    break;
                }else{ // board[i][b_j] == 'R'
                    break;
                }
            }
            if (blocked_by_blue){
                new_r_i = new_b_i + 1;
            }
            break;
    }
    // Update board to new state
    board[r_i][r_j] = '.';
    board[b_i][b_j] = '.';
    board[new_r_i][new_r_j] = 'R';
    board[new_b_i][new_b_j] = 'B';

    return 0;
}


// Main function
int main()
{
    using namespace std;
    // Get inputs
    int N, M;
    cin >> N >> M;
    cout << "Input: " << N << " " << M << "\n";

    char board[10][10] = {0};
    int r_i, r_j, b_i, b_j, h_i, h_j;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                r_i = i;
                r_j = j;
            }
            else if (board[i][j] == 'B')
            {
                b_i = i;
                b_j = j;
            }
            else if (board[i][j] == 'O')
            {
                h_i = i;
                h_j = j;
            }
        }
    }

    // Solve the problem
    tilt(board, N, M, r_i, r_j, b_i, b_j, h_i, h_j, UP);

    // Print board
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }


    return 0;
}