## Bitwise Operations
- set ith bit by `num|=(1<<i)`
- unset ith bit by `num&=(~(1<<i))`
- toggle ith bit by `num^=(1<<pos)`
- check if ith bit is set `bool bit=num&(1<<i)`
- invert a num `num=~(num)`
- 2n's complement is (2n-1)'s complement+1
- lowest set bit appears as zero in `num=num&(num-1)`
- `x&(2's complement of x)` gives you lowest sit bit
- for of natural number from 1 to n
```cpp
int xor_n(int n){
    if(n%4==0)
        return n;
    else if(n%4==1)
        return 1;
    if(n%4==2)
        return n+1;
    if(n%4==3)
        return 0;
}
```
- Given a pos int n, find count of positive number such that 0<=i<=n and n+i=n^i `ans=pow(2, coun of zero bits)`
- find if a number is power of two `return x && (!(x & (x - 1))); `
-  Find XOR of all subsets of a set. We can do it in O(1) time. The answer is always 0 if given set has more than one elements. For set with single element, the answer is value of single element
- find num of leading and trailing zeros in bit representation
```
  Number of leading zeroes: builtin_clz(x)
  Number of trailing zeroes : builtin_ctz(x)
  Number of 1-bits: __builtin_popcount(x) 
```
- swap two num
```
a ^= b;
b ^= a; 
a ^= b;
```
- to count number of set bits
```cpp
int numOfSetBits(int n){
    int count=0;
    for(;n;count++){
        n=n&(n-1);
    }
    return count;
}
```


