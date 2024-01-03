

#include <cmath>

bool is_prime(int number) {
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}
