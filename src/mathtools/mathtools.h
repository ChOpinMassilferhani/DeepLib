#ifndef MATRICE_H_
#define MATRICE_H_

# include <stdio.h>
# include <time.h>

struct matrice
{
    double *mat;
    size_t height;
    size_t width;
};

void sigmoid_pad(struct matrice *cur);

double sigmoid(double x);
double sigmoid_prime(double x);

struct matrice *matrice_init(size_t height, size_t width);
void matrice_free(struct matrice *cur);
struct matrice *matrice_transpose( struct matrice *cur);
void matrice_add(struct matrice *r, struct matrice *m1, struct matrice *m2);
void matrice_mult(struct matrice *r, struct matrice *m1, struct matrice *m2);
void matrice_randomise(struct matrice *cur);
void matrice_print(struct matrice *cur);


#endif
