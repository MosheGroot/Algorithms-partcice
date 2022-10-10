# Union-find problem

## About the problem
The union-find problem is concerned with determining whether two nodes in a dynamically updating graph are connected by some path (i.e., contained in the same graph component).

The allowed commands in this problem are:
* `union(X, Y)` - directly connect nodes X and Y.
* `linked (X, Y)` – true or false: Is there a path connecting nodex X and Y?

Also, we assume that the `union(X, Y)` command is an equivalence relation.

## Goal
The goal is to build an efficient data structure that will dynamically simulate the commands above.

## Results
### Quick-find (eager approach)

The easiest method is to assign every node its own graph component at the start and then union nodes in these components. For example:
```
Initial state
-------------
Nodes:       0  1  2  3  4
Components: [0][1][2][3][4]

After `union(0, 3)`
-------------
Nodes:       0  1  2  3  4
Components: [0][1][2][0][4]

After `union(3, 4)`
-------------
Nodes:       0  1  2  3  4
Components: [0][1][2][0][0]

After `union(2, 1)`
-------------
Nodes:       0  1  2  3  4
Components: [0][2][2][0][0]

connected(0, 3) is true
connected(0, 1) is false
```

**Complexity**: `O(1)` for `connected` command and `O(N)` for `union` command, so the worst-case complexity of `N` `union` commands is `O(N^2)`.

**See the implementation** of this method in the `0_quick-find.cpp` file.

### Quick-union (lazy approach)

This method also uses an array, but interprets it in another way: we consider that by using the `union` command, we make a tree,
so the question "Are two nodes contained in the same graph component?" becomes "Are two nodes contained in the same tree?" 
In this way, we store the roots of trees in an array for each node (with some optimizations, of course).

Example:
```
Initial state                   |   Union(0, 1)         |   Union(2, 0)         |   Union(1, 3)         |  Union(2, 4)              |   Connetted(0, 3):                            
                                |                       |                       |                       |                           |       root(0) = 4     // 0 -> 1 -> 3 -> 4     
Trees:  [0]  [1]  [2]  [3]  [4] |   [1]  [2]  [3]  [4]  |   [1]      [3]  [4]   |       [3]      [4]    |     [4]                   |       root(3) = 4     // 3 -> 4               
                                |    |                  |    | \                |        |              |      |                    |   Result = true                               
                                |   [0]                 |   [0][2]              |       [1]             |     [3]                   |                                               
                                |                       |                       |       / \             |      |                    |   Connected(2, 1)                             
                                |                       |                       |     [0] [2]           |     [1]                   |       root(2) = 4     // 2 -> 1 -> 3 -> 4     
                                |                       |                       |                       |     / \                   |       root(1) = 3     // 1 -> 3 -> 4          
                                |                       |                       |                       |   [0] [2]                 |   Result = true                               
                                |                       |                       |                       |                           |                                               
Nodes:   0  1  2  3  4          |    0  1  2  3  4      |    0  1  2  3  4      |    0  1  2  3  4      |   0  1  2  3  4           |                                               
Roots:  [0][1][2][3][4]         |   [1][1][2][3][4]     |   [1][1][1][3][4]     |   [1][3][1][3][4]     |  [1][3][1][4][4]          |                                                
```

**Complexity**: up to `O(N)` for `union` and `connected` commands (due to the finding of roots). 
More rapid in general, but still `O(N^2)` in the worst case.

**See the implementation** of this method in the `1_quick-union.cpp` file.

### Weighted quick-union

Same as `Quick-union`, but with one improvement: we will link smaller trees to the roots of larger trees to avoid long linear trees.
We would do that by calculating size of each tree.

Example (same as in previous method):
```
Initial state                   |   Union(0, 1)         |   Union(2, 0)         |   Union(1, 3)         |  Union(2, 4)              |   Connetted(0, 3):                            
                                |                       |                       |                       |                           |       root(0) = 1     // 0 -> 1               
Trees:  [0]  [1]  [2]  [3]  [4] |   [1]  [2]  [3]  [4]  |   [1]      [3]  [4]   |       [1]      [4]    |      [1]---[4]            |       root(3) = 1     // 3 -> 1               
                                |    |                  |    | \                |      / | \            |     / | \                 |   Result = true                               
                                |   [0]                 |   [0][2]              |    [0][2][3]          |   [0][2][3]               |                                               
                                |                       |                       |                       |                           |   Connected(2, 1)                             
                                |                       |                       |                       |                           |       root(2) = 1     // 2 -> 1               
                                |                       |                       |                       |                           |       root(1) = 1     // reflexivity            
                                |                       |                       |                       |                           |   Result = true                               
                                |                       |                       |                       |                           |                                               
Nodes:   0  1  2  3  4          |    0  1  2  3  4      |    0  1  2  3  4      |    0  1  2  3  4      |   0  1  2  3  4           |                                               
Roots:  [0][1][2][3][4]         |   [1][1][2][3][4]     |   [1][1][1][3][4]     |   [1][3][1][3][4]     |  [1][3][1][4][4]          |                                                
Sizes:  [1][1][1][1][1]         |   [1][2][1][1][1]     |   [1][3][1][1][1]     |   [1][4][1][1][1]     |  [1][5][1][1][1]          |                                                
```

**Complexity**: up to `O(lgN)` for `union` and `connected` commands (due to the finding of roots, but it's faster with a "balanced" tree), or `O(N lgN)` in the worst case.

**See the implementation** of this method in the `2_weighted-quick-union.cpp` file.

### Weighted quick-union with path compression

Same as `Quick-union`, but with another improvement: we will compress the path while *searching the tree root* for some node.
In that case, we get almost completely flat trees.

(there is no example, sorry)

**Complexity**: up to `O(lg*N)` (note that `lg*N` is a kind of little-improved logarithm function) for `union` and `connected` commands (due to the finding of roots, but it's faster with a "balanced" tree), or `O(N lg*N)` in the worst case.

**See the implementation** of this method in the `3_weighted-quick-union-with-path-compression.cpp` file.
