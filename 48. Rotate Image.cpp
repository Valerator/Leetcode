// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Example 1:

// 1 2 3    7 4 1
// 4 5 6 -> 8 5 2
// 7 8 9    9 6 3

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Example 2:

// 1  2  3  4      15 13  2  5
// 5  6  7  8  =>  14  3  4  1
// 9 10 11 12  =>  12  6  8  9
//13 14 15 16      16  7 10 11

// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(size_t i = 0; i < matrix.size(); ++i) {
            for(size_t j = i; j < matrix.size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }    
        }
        for(size_t i = 0; i < matrix.size(); ++i) {
            for(size_t j = 0; j < matrix.size() / 2; ++j) {
                swap(matrix[i][j], matrix[i][matrix.size() - j - 1]);
            }
        }
    }
};

//сначала транспанируем матрицу, а потом меняем местами солбцы

// 1 2 3    1 4 7    7 4 1
// 4 5 6 -> 2 5 8 -> 8 5 2
// 7 8 9    3 6 9    9 6 3
