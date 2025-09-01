// LINK --> https://leetcode.com/problems/power-of-three/description/

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
