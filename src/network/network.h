#include "mathtools.h"


struct network
{
    size_t nb_layer;
    size_t *layers_size;
    void (*activation)(struct matrice *);
    double (*derivative)(double);
    struct matrice **layers;
    struct matrice **biais;
    struct matrice **weights;
};


struct network *network_init(size_t *layers, void (*func)(struct matrice *));
void network_free(struct network *net);

void feed_forward(struct network *net);
