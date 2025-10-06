//Reverse bits of a given integer
unsigned int reverseBits(unsigned int n) {
unsigned int result=0;
for(int i=0;i<32;i++){
	result<<=1;
	result|=(n&1);
	n>>=1;
}
return result;
}

// Number of bit to be flipped to convert A --> B
    int minBitFlips(int start, int goal) {
        int xr=start^goal;
        int c=0;
        while(xr){
            c+=xr&1;
            xr=xr>>1;
        }
        return c;
    }


//Number Appearing Odd Number of times
 int singleNumber(vector<int>& nums) {
        int xr=0;
        for(auto it:nums)xr^=it;
        return xr;
    }


//POWER SET  --> write intution and dry run in AI if not getting
     vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>V;
        for(int i=0;i<(1<<nums.size());i++){ // 2^n -1 = total number of subset
            vector<int>a;
            for(int j=0;j<nums.size();j++){ // element of array traversal
                if(i&(1<<j)){ // pick non pick
                   a.push_back(nums[j]);
                }
            }
            V.push_back(a);
        }
        return V;
    }
/*
Let’s dry run the code for nums = [1, 2, 3]. Here, n = 3, so there are 2^3 = 8 subsets.

Outer Loop (i)	Binary (i)	Inner Loop (j)	Bitmask Check (i & (1 << j))	Subset (a)

0	000	0	000 & 001 → 0	[]
		1	000 & 010 → 0	[]
		2	000 & 100 → 0	[]
		Result		[]
1	001	0	001 & 001 → 1	[1]
		1	001 & 010 → 0	[1]
		2	001 & 100 → 0	[1]
		Result		[1]
2	010	0	010 & 001 → 0	[]
		1	010 & 010 → 1	[2]
		2	010 & 100 → 0	[2]
		Result		[2]
3	011	0	011 & 001 → 1	[1]
		1	011 & 010 → 1	[1, 2]
		2	011 & 100 → 0	[1, 2]
		Result		[1, 2]
4	100	0	100 & 001 → 0	[]
		1	100 & 010 → 0	[]
		2	100 & 100 → 1	[3]
		Result		[3]
5	101	0	101 & 001 → 1	[1]
		1	101 & 010 → 0	[1]
		2	101 & 100 → 1	[1, 3]
		Result		[1, 3]
6	110	0	110 & 001 → 0	[]
		1	110 & 010 → 1	[2]
		2	110 & 100 → 1	[2, 3]
		Result		[2, 3]
7	111	0	111 & 001 → 1	[1]
		1	111 & 010 → 1	[1, 2]
		2	111 & 100 → 1	[1, 2, 3]
		Result		[1, 2, 3]
*/

//POWER SET variation 2 (strings)
vector<string> AllPossibleStrings(string s) {
        // Code here
        int n=s.size();
                vector<string>V;
        for(int i=0;i<=pow(2,n)-1;i++){ // 2^n -1 = total number of subset
            string a="";
            for(int j=0;j<s.size();j++){ // element of array traversal
                if(i&(1<<j)){ // pick non pick
                   a+=s[j];
                }
            }
            V.push_back(a);
        }
        
        sort(V.begin(),V.end());
        
        return V;
    }

/*
   x=10(dec) = 1010(bin) ,  -x = 10-->invert binary of 10 +1 = 0101 +1 = 0110
  -x=-10=0110  , x & -x = 0010  --> right most set bit

  since in xor operation --> 1^0=1 , hence we can segregate in two groups
*/
//Find the two numbers appearing odd number of times
// or  Repeating and missing number
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int xr=0;
        for(auto it:arr)xr^=it;
        for(int i=1;i<=arr.size();i++)xr^=i;
        
        int setBit= xr & -xr;
        int g1=0,g2=0;
        
         for(auto it:arr){
             if(setBit & it)g1^=it;
             else g2^=it;
         }
         
         for(int i=1;i<=arr.size();i++){
             if(setBit & i)g1^=i;
             else g2^=i;
         }
         
         for(auto it:arr){
             if(it==g1)return {g1,g2};
         }
         
         return {g2,g1};
    }


//POWER of x^n
// here x always +ve considered
double myPow(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn>0) {
    if (nn % 2==0) {
      x = x * x;
      nn = nn / 2;
     
    } else {
      ans = ans * x;
      nn = nn - 1;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
}

//COMPUTE XOR of numbers 1 to n
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else // n%4==3
        return 0;
}
    


