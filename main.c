#include <stdio.h>

#include <stdlib.h>

void magic_product(double *v, double *w, float *z, float a, int n, double *b) {
    int i;
    for ( i = 0; i < n/2; i++ ) {
        printf("n = [%d], v,w,z[%d]=[%f,%f,%f] \n", n, i,v[i],w[i],z[i]);
        b[i] = ( v[i] * w[i] * z[i] ) / a;
        b[n - i] = ( v[i] * z[n - i] ) / a;
    }
}

void calc_and_print(double *v, double *w, float *z, float a, int n) {
    int i;
    double buf[10] = {0};
    double *b;

    if (n < 10) {
        b = buf;
    } else {
        b = malloc(n * sizeof(double));
    }

    magic_product(v,w,z,a,n,b);

    for ( i = 0; i < n; i++ ) {
        printf("b[%d] = %f\n", i, b[i]);
    }

    if (n > 10) {
        free(b);
    }
}

int main()
{
    int i;
    double v[12];
    double w[12];
    float z[12];
    int n = 12;
    float a = 7.3f;

    for(i = 0; i < n; i++) {
        v[i] = ((float)rand()/(float)(RAND_MAX)) * 39.73;
        w[i] = ((float)rand()/(float)(RAND_MAX)) * 23.31;
        z[i] = ((float)rand()/(float)(RAND_MAX)) * 19.17;
    }

    calc_and_print(v,w,z,a,n);

    return 0;
}
