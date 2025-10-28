// Behruzbek received a tree∗
//  with n
//  nodes. For a chosen root†
//  r
// , Behruzbek wants to find cuteness of the tree.

// Consider every set of k
//  distinct nodes of the tree. For each such set, compute its lowest common ancestor (LCA) in the tree when it is rooted at r
// . Let Sr
//  be the set of all distinct nodes obtained this way; then cuteness of the tree is |Sr|
// , where |S|
//  means the number of distinct elements.

// After discovering the cuteness of trees, Behruzbek became interested in finding the kawaiiness of the tree! Kawaiiness is defined as:

// ∑r=1n|Sr|=|S1|+|S2|+⋯+|Sn|

// Unfortunately, Behruzbek is feeling sleepy now. Please help Behruzbek by finding the kawaiiness of the tree!

// ∗
// A tree is a connected graph without cycles.

// †
// A rooted tree is a tree where one vertex is special and called the root.

// Input
// The first line contains the number of test cases t
//  (1≤t≤104
// ).

// The first line of each test case contains two integers n
//  and k
//  (2≤k≤n≤2⋅105
// ) — the number of vertices in the tree and the number of distinct integers to be chosen.

// The following n−1
//  lines of each test case describe the tree. Each of the lines contains two integers u
//  and v
//  (1≤u,v≤n
// , u≠v
// ) that indicate an edge between vertex u
//  and v
// . It is guaranteed that these edges form a tree.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output one integer — the value of ∑r=1n|Sr|
// .

// Example
// Input
// 4
// 2 2
// 1 2
// 5 3
// 1 2
// 1 3
// 1 4
// 1 5
// 6 3
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 10 5
// 5 6
// 4 9
// 3 9
// 2 6
// 2 8
// 8 9
// 6 10
// 1 6
// 4 7
// Output
// 2
// 9
// 17
// 35
