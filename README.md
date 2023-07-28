# Circular Primes Finder

This C program finds and lists all circular primes below 10,000,000 using the Miller-Rabin primality test. Circular primes are prime numbers that remain prime when their digits are rotated. You can easily change the number modifying the #define NUM_MAX. 

This was another exercise from Professor @Bernd-Ulmann

## Requirements

- C compiler (e.g., GCC)

## Getting Started

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/victormeloasm/CircularPrimes.git
   ```

2. Navigate to the project directory:

   ```bash
   cd CircularPrimes
   ```

3. Compile the program:

   ```bash
   gcc CircularPrimes.c -o CircularPrimes -lm
   ```

4. Run the executable:

   ```bash
   ./CircularPrimes
   ```

## How it Works

The program uses the Miller-Rabin primality test to efficiently determine whether a number is prime or not. The Miller-Rabin test is a probabilistic algorithm that provides a high level of accuracy in determining primality.

The program iterates over all numbers from 2 to 9,999,999. For each number, it checks whether it is a circular prime using the following steps:

1. Check if the number is less than 2. If it is, it is not a circular prime.

2. Compute the number of digits in the number.

3. For each digit position, rotate the digits and check if the rotated number is prime using the Miller-Rabin primality test. If any of the rotated numbers are not prime, the number is not a circular prime.

4. If all rotations are prime, the number is a circular prime.

The program then prints all the circular primes found below 10,000,000 in a row, separated by commas. It also displays the total count of circular primes.

## Sample Output

Here's a sample output of the program:

```
Circular Primes below 10000000: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991, 1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 11939, 19391, 19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 193939, 199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 939391, 993319, 999331, 9999997.
Total: 55
```

## Limitations

The program is designed to efficiently find circular primes using the Miller-Rabin test. However, it might still take some time to compute all circular primes below 10,000,000, depending on your machine's performance. For larger limits, the execution time might increase significantly.

## Contributing

If you find any issues or have suggestions for improvements, feel free to open an issue or create a pull request. Contributions are welcome!

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
```
Sure, here's a sample description of the 1.2 version of the program with major corrections:

---

# Circular Primes Finder - Version 1.2

This program is designed to find and count circular primes up to 10 million, with major corrections and optimizations.

### Major Corrections:
1. **Inclusion of Circular Primes**: In version 1.0, the numbers 1, 2, 3, 5, and 7 were unintentionally excluded from the list and count of circular primes. These numbers are circular primes and have been added back to the results.

2. **Optimizations for Numbers Less Than 10**: The optimizations that exclude numbers ending in 5 and numbers with a sum of digits divisible by 3 are now applied only to numbers greater than 9. Numbers less than 10 are now checked normally for circular primality.

### How the Program Works:
The program implements two main functions:
- `bool is_prime(int num)`: This function checks whether a given number is a prime number. It uses basic primality checking by eliminating even numbers and checking for factors up to the square root of the number.
- `bool is_circular_prime(int num)`: This function checks whether a number is a circular prime. It rotates the digits of the number and verifies if all rotations are prime numbers using the `is_prime` function.

### Usage:
To use the program, simply compile and run it. It will display the list of circular primes up to 10 million, separated by commas, and ending with a period (full stop). Additionally, it will print the total count of circular primes found.

We hope this version provides accurate and complete results. Happy prime hunting!

--- 

