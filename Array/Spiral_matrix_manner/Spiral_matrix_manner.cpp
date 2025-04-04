/*

To print a matrix in spiral order, we need to traverse the matrix in a spiral fashion, starting from the top-left corner,
and moving along the outer edges, gradually narrowing the boundaries as we move inward.

Steps:
    Start from the top-left corner and move right across the top row.
    Move down the last column.
    Move left across the bottom row.
    Move up the first column.

    Repeat the process by narrowing the boundaries of the matrix (i.e., move the starting row and column inward and repeat the steps).

Conditions:
    We keep track of the boundaries using four variables:
   
    top: the upper boundary.
    bottom: the lower boundary.
    left: the left boundary.
    right: the right boundary.

As we traverse, we update these boundaries after processing each side of the matrix.


*/


#include <iostream>
#include <vector>

using namespace std;

void printSpiral(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Print top row (left to right)
        for (int j = left; j <= right; j++) {
            cout << matrix[top][j] << " ";
        }
        top++;

        // Print right column (top to bottom)
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            // Print bottom row (right to left)
            for (int j = right; j >= left; j--) {
                cout << matrix[bottom][j] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            // Print left column (bottom to top)
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Spiral order of matrix: ";
    printSpiral(matrix);

    return 0;
}

/*
---------- Explanation -----------------

Explanation:
Initialize Boundaries:

top = 0, bottom = n - 1 (where n is the number of rows)

left = 0, right = m - 1 (where m is the number of columns)

Traverse the Matrix in Spiral Order:

First, print the top row from left to right, then move the top boundary down.

Next, print the right column from top to bottom, then move the right boundary left.

Then, print the bottom row from right to left, and move the bottom boundary up.

Finally, print the left column from bottom to top, and move the left boundary right.

Repeat until all elements are printed, i.e., until top > bottom or left > right.
*/


/*
 --- Dry Run --------

1.  Initial Matrix :      
        1 2 3
        4 5 6
        7 8 9

2.  First iteration:

    Print top row: 1 2 3
    Print right column: 6 9
    Print bottom row: 8 7
    Print left column: 4

    Update boundaries: top = 1, bottom = 1, left = 1, right = 1

3.  Second iteration:

    Print top row: 5
    Update boundaries: top = 2, bottom = 1, left = 2, right = 0

End of loop: All elements have been printed.

*/