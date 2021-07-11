# Median-of-two-sorted-arrays-of-same-size

>>Question

There are 2 sorted arrays A and B of size n each. 
Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). 
The complexity should be O(log(n)). [[Divide and conquer use karna padega matlab]]

>> Example

https://media.geeksforgeeks.org/wp-content/cdn-uploads/median-of-two-arrays.jpg

>> Approach 1: Merge 2 arrays using 2 iterators  TC = O(n+n)= O(2n)= O(n)
               Median = (a1[n-1]+a2[0])/2
               
   
