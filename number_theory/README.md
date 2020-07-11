# Number Theoru for Compettitive Programming

## Sieve of Eratosthenos
- given n, returns all the primes less than or equal to n
- how: assumes every number up until n to be prie and starts from 2 and marks its multiples as non prime
- [code here](SieveOfEratosthenos.cpp)
- O(nloglogn)

## Euler Totient Function
- given n, returns the number integers <=n which are co primes with n
- how: ![image of Euler Totient](/number_theory/images_nt/euler_totient.png)

## Modular Exponentiation
- to calc (x^y)%m, complexity: O(logy)
- how: ![iage of Mod Expo](/number_theory/images_nt/mod-expo.png)
- code [here][ModularExponentiation.cpp]