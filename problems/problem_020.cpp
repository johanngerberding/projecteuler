#include <iostream> 
#define MAX 1000

int multiply(int n, int res[], int res_size) {
    int carry = 0;
    for (int i = 0; i < res_size; i++) {
        int p = res[i] * n + carry;
        res[i] = p % 10;
        carry = p / 10;
    }

    while (carry) {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }

    return res_size;
}

void factorial(int x) {
    int res[MAX];
    res[0] = 1;
    int res_size = 1;

    for (int n = 2; n <= x; n++) {
        res_size = multiply(n, res, res_size);
    }

    std::cout << "Factorial of " << x << "\n";
    int sum = 0;
    for (int i = res_size -1; i >= 0; i--) {
        sum = sum + res[i];
        std::cout << res[i];
    }
    std::cout << "\n";
    std::cout << "Sum: " << sum << "\n";
}


int main() {
    factorial(100);    
}
