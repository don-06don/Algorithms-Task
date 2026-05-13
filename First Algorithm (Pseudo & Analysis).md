1. Pseudo Code (Non-Recursive Analyst)،
algorithm MissPos( A, n )
 // A: input array, n: size of the array
 {
    for i ← 0 to n-1 do
    {
       while A[i] > 0 AND A[i] <= n AND A[i] != A[A[i]-1] do
       {
          temp ← A[i]
         A[i] ← A[temp-1]
         A[temp-1] ← temp
      }
   }

   for j ← 0 to n-1 do
   {
      if A[j] != j+1 then
         return j+1
   }

   return n + 1
 }
-----------------------------------------------------------------------------
2. Complexity Analysis 
1. Time Complexity: O(n)
Step 1 (Sorting): We have a for loop from 0 to n-1 with a while loop  performs a manual swap to put each number in its correct place. Even though it's a loop inside a loop, each number is moved to its correct position only once. Therefore, the total number of operations is proportional to n. So, this step takes O(n).
Step 2 (Scanning): We use a simple for loop to check the numbers one by one, which also takes O(n).
Total Time: O(n)+O(n)=O(2n), which is O(n).
2. Space Complexity: O(1)
The algorithm is In-place. We rearrange the numbers inside the same array A.
We do not use any extra arrays or HashSets.
We only use a few simple variables like n, i and temp, so the extra space is constant.
Total Space: O(1).
