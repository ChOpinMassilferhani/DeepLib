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

struct function
{
    char *name;
    double (*function)(double);
    double (*prime)(double);

};

double sigmoid(double x);
double sigmoid_prime(double x);

struct matrice *matrice_init(size_t height, size_t width);
struct matrice *transpose( struct matrice *cur);
void add(struct matrice *r, struct matrice *m1, struct matrice *m2);
void mult(struct matrice *r, struct matrice *m1, struct matrice *m2);
void randomise_mat(struct matrice *cur);
void print_matrix(struct matrice *cur);


#endif
