#include <stdio.h>

#include <stdlib.h>

void magic_product(double *v, double *w, float *z, float a, int n, double *b);


void calc_and_print(double *v, double *w, float *z, float a, int n) {

  int i;
  double buf[10] = {0};

  double *b;


  if (n < 10) {

    b = buf;

  } else {

    b = malloc(n * sizeof(float));

  }


  magic_product(v,w,z,a,n,b);


  if (n > 10) {

    free(b);

  }


  for ( i = 0; i < n; i++ ) {

    printf("%f\n", b[i]);

  }

}



void magic_product(double *v, double *w, float *z, float a, int n, double *b) {
  int i;
  for ( i = 0; i < n/2; i++ ) {

    b[i] = ( v[i] * w[i] * z[i] ) / a;

    b[n - i] = ( v[i] * z[n - i] ) / a;

  }
}

int main()
{
    float z = 1.0f;
    float a = 3.9999999f;
    double v = 1.0;
    double w = 3.9999999;
    int n=20;

    calc_and_print(&v,&w,&z,a,n);

    return 0;
}

