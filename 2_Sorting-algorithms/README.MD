# Sorting algorithms

## Selection sort

Basic `N^2` sort:
* finding the minimum in an unsorted part of array
* swap it with first unsorted
* continue

Efficiency: `~N^2 / 2` compares and `N` exchanges 

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
