//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    pair<int, int> endPoints(vector<vector<int>> matrix, int R, int C) {
        int i = 0, j = 0;
        int dir = 0;
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (i >= 0 && i < R && j >= 0 && j < C) {
            int temp = matrix[i][j];
            matrix[i][j] = 0;
            if (temp == 1) {
                dir = (dir + 1) % 4;
            }
            i += dirs[dir][0];
            j += dirs[dir][1];
        }
        i -= dirs[dir][0];
        j -= dirs[dir][1];
        return {i, j};
    }
};



//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends