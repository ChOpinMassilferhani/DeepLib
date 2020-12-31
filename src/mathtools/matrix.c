# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include "mathtools.h"
# include "memory.h"


void sigmoid_pad(struct matrice *tab)
{
    for (size_t i = 0; i < tab->height; i++)
        tab->mat[i] = sigmoid(tab->mat[i]);
}


double sigmoid(double x)
{
    return 1 / ( 1 + exp(-x));
}

double sigmoid_prime(double x)
{
    return x * ( 1 - x);
}

struct matrice *matrice_init(size_t height, size_t width)
{
    struct matrice *tmp = my_calloc(1,sizeof(struct matrice));
    tmp->height = height;
    tmp->width = width;
    tmp->mat = my_calloc( height * width , sizeof(double) );
    return tmp;
}

void matrice_free(struct matrice *cur)
{
    if (cur)
    {
        free(cur->mat);
        free(cur);
    }
}


void matrice_add(struct matrice *r, struct matrice *m1, struct matrice *m2)
{
    size_t len = m1->width * m1->height;
    for (size_t i = 0; i < len; i++)
    {
        r->mat[i] = m1->mat[i] + m2->mat[i];
    }
}

void matrice_mult(struct matrice *r, struct matrice *m1, struct matrice *m2)
{
    size_t r1 = m1->height;
    size_t c1 = m1->width;
    size_t c2 = m2->width;
    for (size_t i = 0; i < r1; i++)
    {
        for (size_t j = 0; j < c2; j++)
        {
            double sum = 0;
            for (size_t k = 0; k < c1; k++)
                sum = sum + m1->mat[i * c1 + k] * m2->mat[k * c2 + j];
            r->mat[i * c2 + j] = sum;
        }
    }
}

void matrice_randomise(struct matrice *cur)
{
    size_t len = cur->width * cur->height;
    for (size_t i = 0; i < len; i++)
    {
        cur->mat[i] = (((double)rand())/(double)RAND_MAX)*2 -1;
    }
}

struct matrice *matrice_transpose(struct matrice *cur)
{
    struct matrice *final = matrice_init(cur->width,cur->height);

    for (size_t i = 0; i < cur->height; i++)
    {
        for (size_t j = 0; j < cur->width; j++)
        {
            final->mat[ j * cur->height + i] = cur->mat[i * cur->width + j]; 
        }
    }
    return final;
}

void matrice_print(struct matrice *cur)
{
    size_t rows = cur->height;
    size_t cols = cur->width;

    for(size_t i = 0; i < rows;i++)
    {
        for(size_t j = 0; j < cols;j++)
        {
            printf("%lf ",cur->mat[i*cols + j]);
        }
        printf("\n");
    }
}
