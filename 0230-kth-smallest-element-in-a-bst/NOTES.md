use a stack to simulate an inorder traversal of the binary search tree. At each step, we push all the left children of the current node onto the stack, then pop a node from the stack, and check if it is the kth smallest node. If it is, we return its value. Otherwise, we continue with the right subtree.
​
We use a variable `k` to keep track of the number of nodes we still need to visit to find the `kth` smallest node. We decrement `k` each time we pop a node from the stack, and `return` the value of the node when `k` reaches `0`.
​
If the binary search tree has less than `k` nodes, we return `-1` to indicate that `k` is out of range.