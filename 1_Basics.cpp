//ith bit is set or not
  bool checkIthBit(int n, int i) {
        // Your code goes here
        return n & 1<<i;
    }


// N is odd
 return N&1;


// Number is power of 2
  if(N<=0)return false;
  return (N & (N-1))==0;


// Count Number of Set Bits
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);
        n >>= 1; 
    }
    return count; 
}


// SWAP two numbers

Method 1 --> swap(a,b)
  
Method 2 -->  a=a+b;
              b=a-b;
              a=a-b;
Method 3 -->  a=a^b;
              b=a^b;
              a=a^b;


// Set right most UNSET bit in an number N
   retun N|(N+1);

// Unset rightmost SET bit
   return N &(N-1);

