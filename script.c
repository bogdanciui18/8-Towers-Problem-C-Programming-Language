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

    function solveTowersProblem(col) {
        if (col >= n) {
            return true;
        }

        for (let i = 0; i < n; i++) {
            if (isValid(i, col)) {
                board[i][col] = 1;

                if (solveTowersProblem(col + 1)) {
                    return true;
                }

                board[i][col] = 0;
            }
        }

        return false;
    }

    solveTowersProblem(0);

    for (let row = 0; row < n; row++) {
        for (let col = 0; col < n; col++) {
            const square = context.createElement("div");
            square.classList.add("square", (row + col) % 2 === 0 ? "even" : "odd");

            if (board[row][col] === 1) {
                const towerSpan = context.createElement("span");
                towerSpan.classList.add("tower");
                towerSpan.textContent = "TOWER";
                square.appendChild(towerSpan);
            }

            chessBoard.appendChild(square);
        }
    }
}

// Exemplu de utilizare:
initChessBoard(document);

