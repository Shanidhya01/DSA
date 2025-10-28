// khba has n
//  friends, each standing on a line at position ai
// , and each of them is in the range [0,x]
// .

// They all want to come to him. One of his friends, Isamatdin, gave him k
//  teleports. Each friend will walk to the nearest teleport (choosing the shortest distance). Once a friend reaches a teleport, khba and the friend can instantly meet.

// But khba is so tired that he'll be sleeping while his friends are walking toward him. Now he wants to choose k
//  teleport positions so that their positions are distinct and lie within the range [0,x]
// , in order to maximize the time it takes for the first friend who reaches a teleport to reach it. Assume that friends move at the same speed.

// Since khba isn't good at calculations, you should output the k
//  chosen teleport positions.

// Input
// Each test contains multiple test cases. The first line contains a single integer t
//  (1≤t≤104
// ) — the number of test cases. The description of the test cases follows.

// The first line of each test case contains three integers n
// , k
// , and x
//  (1≤n,k≤2⋅105
// , k−1≤x≤109
// ) — the number of friends, the number of teleports, and the range of possible positions for the teleports.

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (0≤ai≤x
// ) — the positions of khba's friends.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// It is guaranteed that the sum of k
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output a single line containing k
//  integers — the k
//  chosen teleport positions. The positions must be distinct and lie within the range [0,x]
// . The positions may be output in any order.

// If there are multiple optimal choices, output any of them.

// Example
// Input
// 10
// 4 1 4
// 1 0 2 4
// 5 5 4
// 0 1 2 3 4
// 2 1 4
// 4 0
// 3 4 6
// 2 4 3
// 3 2 12
// 6 12 0
// 4 3 12
// 8 12 0 4
// 1 1 1000000000
// 0
// 1 1 1000000000
// 1000000000
// 3 4 9
// 8 7 9
// 3 4 9
// 2 0 1
// Output
// 3 
// 0 1 2 3 4 
// 2 
// 0 1 5 6 
// 3 9 
// 2 6 10 
// 1000000000 
// 0 
// 0 1 2 3 
// 6 7 8 9 


