// https://leetcode.com/problems/check-if-it-is-a-good-array/

/*
To determine if an array is "good," we need to check whether there exists a subset of integers from the given array 
such that their greatest common divisor (GCD) is 1. This is based on the Bézout's Identity, which states that for any 
integers a and b, there exist integers x and y such that a*x + b*y = gcd(a, b). Extending this logic to multiple integers,
we can conclude that the array is "good" if the GCD of all its elements is 1.

Steps to Solve:
Calculate the GCD of the Entire Array:

We compute the GCD of all elements in the nums array.
If the GCD is 1, it means we can form a sum of 1 using some subset of nums and integer multiplicands.
Return the Result:

Return true if the GCD is 1; otherwise, return false.
*/

class Solution {
private:
    int gcd(int a,int b){
        while(a!=0&&b!=0){
            if(a>b)a=a%b;
            else b=b%a;
        }
        if(a==0)return b;
        return a;
    }
public:
    bool isGoodArray(vector<int>& nums) {
        int curr_gcd=nums[0];
        for(int i=1;i<nums.size();i++){
            curr_gcd=gcd(curr_gcd,nums[i]);
            if(curr_gcd==1)return true;
        }
        return curr_gcd==1;
    }
};

/*
**Intuition**:

The problem revolves around determining if we can form a sum of `1` by selecting a subset of numbers from the array and 
multiplying each selected number by an integer. This is equivalent to checking if **the greatest common divisor (GCD)** 
of all elements in the array is `1`. If the GCD of the array is `1`, it means there exists a linear combination of the 
elements that sums to `1`. Conversely, if the GCD is greater than `1`, no such combination exists.

---

### Approach:

#### Step 1: Understand Bézout's Identity
Bézout's Identity states that for any integers `a` and `b`, there exist integers `x` and `y` such that:
```
a * x + b * y = gcd(a, b)
```
Extending this to multiple integers, the GCD of an entire array represents the smallest positive integer that can be expressed as a
linear combination of the array's elements.

#### Step 2: Problem Transformation
To solve the problem, we need to check if **the GCD of the entire array is `1`**. If it is, we can select a subset of the array and
find integer coefficients to sum to `1`. If the GCD is greater than `1`, no such subset exists.

#### Step 3: Compute GCD of the Array
1. Initialize `current_gcd` with the first element of the array.  
2. Iterate through the array, updating `current_gcd` by computing the GCD of `current_gcd` and the current element.  
3. If `current_gcd` becomes `1` at any point, we can stop early, as the GCD of any number with `1` is `1`.  

#### Step 4: Check Result
- If the final `current_gcd` is `1`, return `true`.  
- Otherwise, return `false`.

---

### Why This Works:

1. **GCD as the Key Property**:
   - The GCD of the array determines whether a combination summing to `1` is possible.  
   - If the GCD is `1`, Bézout's Identity guarantees that such a combination exists.  

2. **Efficient GCD Computation**:
   - Using the Euclidean algorithm, we compute the GCD iteratively.  
   - This ensures the solution is efficient even for large inputs (`nums.length <= 10^5`).

3. **Early Exit Optimization**:
   - If `current_gcd` becomes `1` at any step, we can immediately conclude that the array is "good."  
   - This avoids unnecessary computations.

---

### Example Walkthrough:

**Input:** `nums = [12, 5, 7, 23]`  
**Output:** `true`

1. Initialize `current_gcd = 12`.
2. Compute `gcd(12, 5) = 1`.  
   - Early exit since the GCD is `1`.  
3. Return `true`.

---

**Input:** `nums = [3, 6]`  
**Output:** `false`

1. Initialize `current_gcd = 3`.
2. Compute `gcd(3, 6) = 3`.  
3. Return `false` since `current_gcd != 1`.

---

### Complexity:

- **Time Complexity:**  
  - Computing GCD for each element takes **O(log(min(a, b)))**.  
  - Overall complexity: **O(n * log(max(nums)))**.

- **Space Complexity:**  
  - Only a few extra variables are used.  
  - Space complexity: **O(1)**.

---

### Approach Summary:

1. Compute the GCD of the entire array.
2. Return `true` if the GCD is `1`; otherwise, return `false`.

This approach is intuitive, efficient, and leverages the mathematical properties of GCD to solve the problem elegantly. Let me know if you need further clarification!
*/
