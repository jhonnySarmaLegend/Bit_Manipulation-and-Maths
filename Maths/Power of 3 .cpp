// LINK --> https://leetcode.com/problems/power-of-three/description/

// 3^19 is max
class Solution {
public:
    bool isPowerOfThree(int n) {
      return n > 0 && 1162261467 % n == 0; // 3^19
    }
};


//LOG approach
class Solution {
public:
    bool isPowerOfThree(int n) {
        //The calculation of e = log(INT_MAX) / log(3) determines the highest possible power of 3
      //that can fit into a 32-bit signed integer, ensuring the algorithm remains accurate and efficient across its range of valid inputs.
        int e=log(INT_MAX)/log(3);
        int N=pow(3, e);
        return n>0 && N%n==0;
    }
};



// Iteration
class Solution {
public:
    bool isPowerOfThree(int n) {
       if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};
