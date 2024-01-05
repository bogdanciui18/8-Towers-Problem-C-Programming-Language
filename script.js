const { JSDOM } = require('jsdom');
const dom = new JSDOM('<!DOCTYPE html><html lang="en"><body></body></html>');
global.document = dom.window.document;

const chessBoard = document.getElementById("chessBoard");
const n = 8;
const board = Array.from({ length: n }, () => Array(n).fill(0));

function isValid(row, col) {
    for (let i = 0; i < n; i++) {
        if (board[row][i] === 1 || board[i][col] === 1) {
            return false;
        }
    }

    for (let i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] === 1) {
            return false;
        }
    }

    for (let i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] === 1) {
            return false;
        }
    }

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
        const square = document.createElement("div");
        square.classList.add("square", (row + col) % 2 === 0 ? "even" : "odd");

        if (board[row][col] === 1) {
            square.innerHTML = '<span class="tower">TOWER</span>';
        }

        chessBoard.appendChild(square);
    }
}
