#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x[] = {1, 2, 4, 3, 5};
    double y[] = {1, 3, 3, 2, 5};

    double b0 = 0;
    double b1 = 0;
    double alpha = 0.01;

for (int i = 0; i < 20; i ++) {
    double err;
    printf("\n %f      %f      %f\n", b0, b1, err);
    int idx = i % 5;
    double p = b0 + b1 * x[idx];
    err = p - y[idx];
    b0 = b0 - alpha * err;
    b1 = b1 - alpha * err * x[idx];
}

    return 0;
}
