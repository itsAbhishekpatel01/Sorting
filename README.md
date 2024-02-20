# Sorting
12 11 13 5 6 7
n = 6
l=0,r=5
m = l+(r-l)/2
m = 0+(5-0)/2 = 2 
mergesort(arr,l,m)
mergesort(arr,m+1,r)
merge(arr,l,m,r);


Algo of recursive mergeSort sort
1. Find mid.
2. Recursive call from left to mid
3. Recursive call from mid+1 to right
4. Merge both the array left to right with mid 
5. Base case is left<right

Algo of merging two sorted vector in single sorted vector
1. Create a vector "left" and insert all values from left to mid
2. Create a vector "right" and insert all values from right to right
3. Create a vector "temp" in which we will store sorted of these two vectors "left" and    "right"
4. Now take two pointers i to point "left" and j to point "right".
5. Run a while loop untill i and j both are under their respective index limits.
6. Now compare the two values left[i] and right[j]
   - If left[i] is smaller or equal
   = then insert it into the original array ie arr[l+i] = left[i]; 
   = i++; and k++;
   - else right[i] is smaller 
   = then insert it to the original array ie arr[k]=arr[j];
   = j++; and k++;
7. When either of i or j reached to their corresponding last index
   then run while loop from i to n-1  and j to n-1 and insert their values 
   in the original arrays.




