#include <iostream>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

int matrix[ROWS][COLS] = {
    // Lab supple given matrix
    {4, 7, 1, 6},
    {6, 7, 3, 9},
    {3, 8, 1, 2},
    {7, 1, 7, 3}
};

int pathFind(int row, int column, int remain) {
    if (row >= ROWS || column >= COLS) {
        return 0;
    }

    remain = remain - matrix[row][column];
    if (remain < 0) {
        return 0;
    }

    if (row == ROWS - 1 && column == COLS - 1) {
        if (remain == 0) {
            return 1;
        }
        return 0;
    }

    int right = pathFind(row, column + 1, remain);
    int down = pathFind(row + 1, column, remain);
    return right + down;
}

int main() {
    int requiredCost;
    cout << "Enter required cost: ";
    cin >> requiredCost;

    int totalPaths = pathFind(0, 0, requiredCost);
    cout << "Number of paths with cost " << requiredCost << ": " << totalPaths << endl;

    return 0;
}