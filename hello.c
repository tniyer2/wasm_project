
#include <stdio.h>
#include <emscripten.h>
#include <time.h>

int EMSCRIPTEN_KEEPALIVE calc_fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return calc_fibonacci(n - 1) + calc_fibonacci(n - 2);
    }
}

int main() {
    printf("Hello From WASM!\n");

    int result = calc_fibonacci(7);
    printf("FROM WASM - The 7th Fibonacci number is %d\n", result);

    double times[100];
    for (int i = 0; i < 100; i++) {
    	clock_t start_time = clock();
    	calc_fibonacci(23);
  		double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
  	}

  	double benchmark = 0;
  	for (int i = 0; i < 100; i++) {
  		benchmark += times[i];
  	}
  	benchmark /= 100;

    printf("Calling WASM internally 100 times has an average benchmark of: %f milliseconds.\n", benchmark);

    return 0;
}
