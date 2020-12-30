#include "mathtools.h"


struct network
{
    size_t nb_layer;
    struct function *activation;
    struct matrice **layers;
    struct matrice **biais;
    struct matrice **weights;
};


struct network *network_init(size_t *layers, struct function *func);

void network_free(struct network *net);
