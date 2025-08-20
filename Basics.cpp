// Count Primes less than n - https://leetcode.com/problems/count-primes/

//TLE --> O(N * N^1/2) o n root n
class Solution {
public:
    bool isPrime(int n){
        if(n<2)return false;
        if(n==2)return true;
        for(int i=2;i*i<=n;i++)if(n%i==0)return false;
        return true;
    }
      
    int countPrimes(int n) {
        int count=0;
        for(int i=1;i<n;i++)if(isPrime(i))count++;
        return count;
    }
};

// Sieve of eranthosis
class Solution {
public:
    int countPrimes(int n) {
        vector<int>p(n,1);
        for(int i=2;i<=sqrt(n);i++){
            if(p[i]==1){
                for(int j=i*i;j<n;j+=i){
                    p[j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(p[i]==1){
                cnt++;
            }
        }
        return cnt;
    }
};

