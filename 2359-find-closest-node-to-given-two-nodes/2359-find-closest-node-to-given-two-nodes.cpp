class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    // Create a vector to store the distance from each node to node1
    vector<int> dist1(n, -1);
    // Create a vector to store the distance from each node to node2
    vector<int> dist2(n, -1);
    // Create a queue to store the nodes to be visited
    queue<int> q;
    // Push the starting node1 into the queue
    q.push(node1);
    // Mark the distance of node1 as 0
    dist1[node1] = 0;
    // Start BFS from node1
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        // If the current node has an outgoing edge
        if (edges[curr] != -1) {
            // If the distance to the next node is not yet calculated
            if (dist1[edges[curr]] == -1) {
                // Mark the distance to the next node
                dist1[edges[curr]] = dist1[curr] + 1;
                // Push the next node into the queue
                q.push(edges[curr]);
            }
        }
    }
    // Push the starting node2 into the queue
    q.push(node2);
    // Mark the distance of node2 as 0
    dist2[node2] = 0;
    // Start BFS from node2
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        // If the current node has an outgoing edge
        if (edges[curr] != -1) {
            // If the distance to the next node is not yet calculated
            if (dist2[edges[curr]] == -1) {
                // Mark the distance to the next node
                dist2[edges[curr]] = dist2[curr] + 1;
                // Push the next node into the queue
                q.push(edges[curr]);
            }
        }
    }
    // Initialize the result node as -1
    int result = -1;
    // Initialize the minimum distance as INT_MAX
        int minDist = INT_MAX;
    // Iterate through all the nodes
    for (int i = 0; i < n; i++) {
        // If both nodes can reach the current node
        if (dist1[i] != -1 && dist2[i] != -1) {
            // Calculate the maximum distance between the two nodes
            int maxDist = max(dist1[i], dist2[i]);
            // If the maximum distance is smaller than the current minimum distance
            if (maxDist < minDist) {
                // Update the result node and the minimum distance
                result = i;
                minDist = maxDist;
            } else if (maxDist == minDist) {
                // If the maximum distance is equal to the current minimum distance
                // Return the node with the smallest index
                result = min(result, i);
            }
        }
    }
    // Return the result node
    return result;

    }
};