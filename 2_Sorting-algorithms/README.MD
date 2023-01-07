# Sorting algorithms

## Selection sort

Basic `N^2` sort:
* finding the minimum in an unsorted part of array
* swap it with first unsorted
* continue

Efficiency: `~N^2 / 2` compares and `N` exchanges.

![Selection sort gif from the wikipedia](https://media.tenor.com/R6mBrn0nQ1MAAAAC/sort-graph.gif)


## Insertion sort

Basic, but more efficient `N^2` sort:
* take the first element
* swap it to the left while it smaller some current
* continue for each other

Efficienty: `~N^2 / 4` compares and `~N^2 / 4` exchanges on average.

The main problem with this algorithm is the worst case, when we have to make `N` exchanges to move some element from the end to the beginning of the array. The next sort solves this problem.

![Insertion sort gif from the wikipedia](https://upload.wikimedia.org/wikipedia/commons/4/42/Insertion_sort.gif)

## Shell sort

Improved `Insertion sort` with fewer comparisons and exchanges by multiple partial sorts of the array:
* sort the array partially by swapping and comparing the current element to the over-`h` steps element.
* continue and gradually decrease size of `h` to `1`

Actually, the best way to change `h` is unspecified, but one easy way to do it is to use the `3x + 1` sequence (`1, 4, 13, 40, 121, ...`; from the closest to `N` to the smallest one).

The efficiency of this algorithm is difficult to calculate, but it is guaranteed to be better than a simple `insertion sort`. 

![Shell sort gif from the wikipedia](https://upload.wikimedia.org/wikipedia/commons/d/d8/Sorting_shellsort_anim.gif?20140912155123)

## Knuth shuffle

It is not about sorting but about permutations, but I decided to put it here, near the sorting algorithms.

The point is to shuffle the array randomly to get a uniform permutation. The best way to do it in linear time is:
* take the current element with index `i`
* take a random index `j` between `0` and `i`
* swap `i` and `j` elements
* continue with the next `i`

It is important to take a random index of an element to swap with between `0` and `i`, and not across the entire array. Otherwise, permutation will not become uniform (there is a way to prove it, but not here).

## Merge sort

Basic `N*lgN` sort with a simple idea:
* divide an array in half
* sort recursively both parts
* merge them into the one array

Efficiency: `N*lgN` compares and `6*N*lgN` array accesses, but it requires extra space with `N` size.

![Merge sort gif from the wikipedia](https://cdn.emre.me/sorting/merge_sort.gif)


## Quick sort

Favorite `QuickSort` with improved `N*lgN` efficiency. Algorithm can be described with the next steps:
* To ensure performance, shuffle the array
* Take the pivot, and move all the elements that are smaller than the pivot to the left part, and those that are larger to the right
* Sort these parts (`[l; pivot)` and `(pivot; j]`) recursively

Efficiency: `N*lgN` compares (`~1/2 N^2` in worst case, but it can be fixed by shuffling) and zero extra space.

![Quick sort gif from the wikipedia](https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif)

Also, there is a way to improve the sorting of arrays with a lot of duplicates. This case can be handled by Dijkstra's 3-way partitioning (the rest of the algorithm is the same):

![3-way partitioning](https://media.geeksforgeeks.org/wp-content/uploads/Threewaypartitioning.png)
