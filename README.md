# Randomized Quicksort 
Based on Sedgwick Quicksort’s Algorithm.

Pivot selection process is randomized.

Randomization is achieved using pseudorandom function.

In theory, selecting pivots randomly decreases the time complexity of the algorithm.

Sedgwick implementation is used for space optimization.

## Space-Time Analysis of Algorithm:
Time Complexity:
Worst Case of standard implementation: O(n^2).

Randomized Quicksort Worst Case: O(nlgn) according to amortized analysis.

Space Complexity:
Worst Case of standard implementation: θ(n).

Randomized Quicksort Worst Case: θ(lgn).

### Institution behind using the randomized approach: 
Choosing the pivot randomly reduces the probability of picking the smallest element as pivot which reduces no of swap operations required for sorting. 

#### Institution behind Sedgwick Implementation:
##### Sedgwick Quicksort Algorithm:

![image](https://user-images.githubusercontent.com/88283180/155743467-574c6a91-df14-4d3e-85d8-195b72fce280.png)

Sedgwick algorithm uses both recursion and iteration. In the algorithm, we recurse on the smaller partition first, update the relevant variables and go back to the iteration.

Lets consider a sorted array, while dry running the algorithm you will find, the depth of the call stack is only 1 element deep. 

In the worst case which will occur if we have a pivot element which partitions the array into exactly equal halves in each recursion then the call stack depth will be lgn. 




                 

