#include <stdio.h>
#include <stdbool.h>

#define N 8

void printBoard(int board[N][N], int solutionNumber) {
    printf("Solutia %d:\n", solutionNumber);
    printf("************************************\n");
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                printf("| T ");
            } else {
                printf("| 0 ");
            }
        }
        printf("|\n");
        for (int k = 0; k < N; k++) {
            printf("----|");
        }
        printf("\n");
    }

    printf("\n");
}
  bool isValid(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

    bool solveNTowers(int board[N][N], int col, int *solutionCount) {
    if (col == N) {
        (*solutionCount)++;
        printBoard(board, *solutionCount);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isValid(board, i, col)) {
            board[i][col] = 1;
            res = solveNTowers(board, col + 1, solutionCount) || res;
            board[i][col] = 0;
        }
    }

    return res;
}

   int main() {
    int board[N][N] = {0};
    int solutionCount = 0;

    solveNTowers(board, 0, &solutionCount);

    printf("Numar total de solutii: %d\n", solutionCount);

    return 0;
}

