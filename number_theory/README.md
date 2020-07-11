# Number Theory for Competitive Programming

## Sieve of Eratosthenos
- given n, returns all the primes less than or equal to n
- how: assumes every number up until n to be prie and starts from 2 and marks its multiples as non prime
- [code here](SieveOfEratosthenos.cpp)
- O(nloglogn)

## Euler Totient Function
- given n, returns the number integers <=n which are co primes with n
- how: ![image of Euler Totient](/number_theory/images_nt/euler-totient.png)

## Modular Exponentiation
- to calc (x^y)%m, complexity: O(logy)
- how: ![iage of Mod Expo](/number_theory/images_nt/mod-expo.png)
- code [here][ModularExponentiation.cpp]

## Optimized isPrime
- check if n is divisible by primes unto sqrt(n)
- O(sqrt(n)/ln(sqrt(n)))

## GCD and LCM
- for three num gcd(a,gcd(b,c)), same with lcm
- o(logn), n=max(a,b)

## Efficient Prime Factorization
- why does it work?
    - uses a sieve, no time wasted checking if a number is prime
    - only goes upto sqrt(n)
    - uses divide and conquer, if n=pf*n', in next iteration n=n'
- O(sqrt(n)/ln(sqrt(n)))

## Modified Sieve
- if the range of quesrues for number of different prime factors of a number is large then prefer Modified Sieve algo, also applicable in Euler-Totient function