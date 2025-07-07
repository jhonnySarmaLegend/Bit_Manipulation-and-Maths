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

