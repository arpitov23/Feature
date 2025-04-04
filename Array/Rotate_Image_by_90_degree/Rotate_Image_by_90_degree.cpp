// Rotate_Image_by_90_degree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*
        -------- approach -----------

      -> Transpose of the matrix
      -> Reverse each row 

      Ques: How do we transpose ?
      Ans:  The transpose of a matrix is obtained by swapping rows and columns. For an element at position [i][j], after the transpose, it will be at position [j][i].

      Ques: Reverse each row:
      Ans:  After transposing the matrix, reverse each row to get the final rotated matrix.

*/
#include <iostream>
#include<vector>

using namespace std;

void rotate_matrix(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    // step 1: Transpose the matrix 

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]); // swap elements (i,j) with (j,i)
        }
    }

    // Step 2: Reverse each row

    for (int i = 0; i < n; i++)
    {
        // in-build reverse() 

      //  reverse(matrix[i].begin(), matrix[i].end()); 
        
        // -- if you don't want to use above in-build reverse() then use below code

        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            swap(matrix[i][left], matrix[i][right]);
            left++;
            right--;
        }
    }

}


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {
         {1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}
    };

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    rotate_matrix(matrix);

    cout << "Matrix after rotation by 90 degrees:" << endl;
    printMatrix(matrix);
    return 0;
}

