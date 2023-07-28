#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUMBER 10000000

bool is_prime(int num) {
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    int limit = sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool is_circular_prime(int num) {
    int digits = 0, n = num, last_digit;
    while (n > 0) {
        digits++;
        n /= 10;
    }

    n = num;
    for (int i = 0; i < digits; i++) {
        if (!is_prime(n))
            return false;
        last_digit = n % 10;
        n /= 10;
        n += last_digit * pow(10, digits - 1);
    }
    return true;
}

int main() {
    printf("Circular primes up to 10 million: 1, ");
    int count = 0;
    // Considering numbers ending in 1, 3, 7, or 9 and also starting with 1, 3, 7, or 9
    for (int i = 1; i <= MAX_NUMBER; i++) {
        if ((i == 2 || i % 10 == 1 || i % 10 == 3 || i % 10 == 7 || i % 10 == 9) && (i < 10 || (i % 10 != 0 && i % 2 != 0))) {
            if (!is_prime(i))
                continue;

            if (is_circular_prime(i)) {
                count++;
                if (count > 1)
                    printf(", ");
                printf("%d", i);
            }
        }
    }
    count++;
    printf(".\nTotal circular primes: %d\n", count);

    return 0;
}
