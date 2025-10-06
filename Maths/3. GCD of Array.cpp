// Link --> https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/

class Solution {
public:
    int GCD(int a,int b){
        while(a!=0 && b!=0){
            if(b>a)b=b%a;
            else a=a%b;
        }
        if(a==0)return b;
        return a;
    }

    int findGCD(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto it:nums){
            mini=min(mini,it);
            maxi=max(maxi,it);
        }
        return GCD(mini,maxi);
    }
};



/*

Sure! Let's look at some examples to illustrate the difference between calculating the GCD of the minimum and maximum elements versus calculating the GCD of all elements in an array.

### Example 1

#### Given Array:
\[ \text{nums} = [12, 15, 9, 30, 21] \]

#### Smallest and Largest:
- Smallest (mini) = 9
- Largest (maxi) = 30

#### GCD of Smallest and Largest:
- GCD(9, 30):
  - Factors of 9: \( \{1, 3, 9\} \)
  - Factors of 30: \( \{1, 2, 3, 5, 6, 10, 15, 30\} \)
  - Common Factor: \( 3 \)
**Result:** GCD(9, 30) = **3**

#### GCD of All Elements:
- GCD(12, 15, 9, 30, 21):
  - GCD(12, 15) = 3
  - GCD(3, 9) = 3
  - GCD(3, 30) = 3
  - GCD(3, 21) = 3
**Result:** GCD(12, 15, 9, 30, 21) = **3**

### Example 2

#### Given Array:
\[ \text{nums} = [14, 22, 35] \]

#### Smallest and Largest:
- Smallest (mini) = 14
- Largest (maxi) = 35

#### GCD of Smallest and Largest:
- GCD(14, 35):
  - Factors of 14: \( \{1, 2, 7, 14\} \)
  - Factors of 35: \( \{1, 5, 7, 35\} \)
  - Common Factor: \( 7 \)
**Result:** GCD(14, 35) = **7**

#### GCD of All Elements:
- GCD(14, 22, 35):
  - GCD(14, 22) = 2
  - GCD(2, 35) = 1
**Result:** GCD(14, 22, 35) = **1**

### Analysis

- In **Example 1**, both methods yield the same GCD of **3**.
- In **Example 2**, the GCD of the smallest and largest (14 and 35) is **7**, while the GCD of all elements yields **1**. 

This shows that focusing solely on the smallest and largest elements can provide significant information, but it may not capture the GCD 
of the entire array in all cases. The GCD of all numbers can differ depending on the set, which illustrates that the two approaches may
yield different results depending on the contents of the array. 

Thus, the choice of which method to use should align with the specific problem requirements. In the context of the given task, the problem 
specifically wants the GCD of the smallest and largest elements.

*/
