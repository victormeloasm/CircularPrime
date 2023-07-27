#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define NUM_MAX 10000000

bool is_prime(unsigned long long int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (unsigned long long int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

unsigned long long int rotate_digits(unsigned long long int n) {
    unsigned long long int last_digit = n % 10;
    n /= 10;
    unsigned long long int num_digits = log10(n) + 1;
    return n + last_digit * pow(10, num_digits);
}

bool is_circular_prime(unsigned long long int n) {
    if (n < 2)
        return false;

    unsigned long long int num_digits = log10(n) + 1;
    unsigned long long int rotated = n;

    for (unsigned long long int i = 0; i < num_digits; i++) {
        if (!is_prime(rotated))
            return false;

        rotated = rotate_digits(rotated);
    }

    return true;
}

void find_circular_primes_below(unsigned long long int limit) {
    printf("Circular Primes below %llu: ", limit);

    int count = 0;
    for (unsigned long long int i = 2; i < limit; i++) {
        if (is_circular_prime(i)) {
            count++;
            if (count > 1) {
                printf(", ");
            }
            printf("%llu", i);
        }
    }

    printf(".\nTotal: %d\n", count);
}

int main() {
    unsigned long long int limit = NUM_MAX;
    find_circular_primes_below(limit);

    return 0;
}
