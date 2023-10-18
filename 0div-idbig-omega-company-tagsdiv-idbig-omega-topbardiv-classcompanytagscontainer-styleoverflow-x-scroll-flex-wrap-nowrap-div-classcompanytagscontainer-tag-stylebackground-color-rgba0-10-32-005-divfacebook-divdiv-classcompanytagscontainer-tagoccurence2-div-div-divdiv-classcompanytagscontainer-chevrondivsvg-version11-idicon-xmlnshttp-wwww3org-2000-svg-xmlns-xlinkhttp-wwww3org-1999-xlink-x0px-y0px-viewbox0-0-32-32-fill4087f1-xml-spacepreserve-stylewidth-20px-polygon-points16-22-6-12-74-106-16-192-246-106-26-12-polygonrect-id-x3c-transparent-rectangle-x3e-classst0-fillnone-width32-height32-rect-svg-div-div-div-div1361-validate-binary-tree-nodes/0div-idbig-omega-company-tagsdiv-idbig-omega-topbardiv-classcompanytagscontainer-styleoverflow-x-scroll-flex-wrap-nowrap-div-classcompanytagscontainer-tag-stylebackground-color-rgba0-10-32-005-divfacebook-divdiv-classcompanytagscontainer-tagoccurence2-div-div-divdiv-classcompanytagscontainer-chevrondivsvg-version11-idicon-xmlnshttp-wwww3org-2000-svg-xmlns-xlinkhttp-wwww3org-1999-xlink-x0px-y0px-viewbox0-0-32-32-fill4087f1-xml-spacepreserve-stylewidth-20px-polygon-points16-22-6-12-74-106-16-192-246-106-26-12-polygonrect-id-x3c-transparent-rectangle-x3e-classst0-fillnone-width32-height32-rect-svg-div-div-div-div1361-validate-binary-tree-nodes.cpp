class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                inDegree[leftChild[i]]++;
                if (inDegree[leftChild[i]] > 1)
                    return false;
            }
            if (rightChild[i] != -1) {
                inDegree[rightChild[i]]++;
                if (inDegree[rightChild[i]] > 1)
                    return false;
            }
        }

        int rootCount = 0;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                if (rootCount == 1)
                    return false;
                rootCount++;
            } else if (inDegree[i] != 1) {
                return false;
            }
        }
        if (rootCount != 1)
            return false; 

        if (!isTree(0, leftChild, rightChild, visited))
            return false; 

        return true;
    }

    bool isTree(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited) {
        if (node == -1)
            return true;

        if (visited[node])
            return false;

        visited[node] = true;

        bool leftSubtree = isTree(leftChild[node], leftChild, rightChild, visited);
        bool rightSubtree = isTree(rightChild[node], leftChild, rightChild, visited);

        return leftSubtree && rightSubtree;
    }
};
