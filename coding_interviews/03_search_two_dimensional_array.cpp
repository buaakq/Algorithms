#include <iostream>
#include <vector>

using namespace std;

bool helper(const vector<vector<int> > &matrix, int row, int col, int target);

// a recursive function 
bool searchMatrix_recursion(vector<vector<int> > &matrix, int target) {
        int rows = matrix.size();
        int cols = 0;
        if(rows)
            cols = matrix[0].size();
        return helper (matrix, 0, cols - 1, target);
}
    
bool helper(const vector<vector<int> > &matrix, int row, int col, int target){
    int rows = matrix.size();
    if (row >= rows || col < 0)
        return 0;
    if (matrix[row][col] == target)
        return 1;
    else if (matrix[row][col] < target)
        return helper(matrix, row + 1, col, target);
    else 
        return helper(matrix, row, col - 1, target);
}

// a iterative function
int searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows = 0, cols = 0;
        int ret = 0;
        rows = matrix.size();
        if(rows)
            cols = matrix[0].size();
        
        int i = 0;
        int j = cols - 1;

        while(j >= 0 && i <= rows - 1){
            if(matrix[i][j] == target){
                return 1;
            }
            else if(matrix[i][j] > target){
                j --;
            }
            else{
                i ++;
            }
        }
        return ret;
}

int main()
{
	vector<vector<int> > v = {{1,2,3}, {2,3,4}, {4,6,7}, {5,11,15}};
	cout << searchMatrix_recursion(v, 4) << endl;
	cout << searchMatrix_recursion(v, 13) << endl;
	cout << searchMatrix(v, 4) << endl;
	cout << searchMatrix(v, 20) << endl;
	return 0;
}