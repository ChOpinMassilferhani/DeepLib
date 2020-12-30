#include "mathtools.h"


struct network
{
    size_t nb_layer;
    struct function *activation;
    struct matrice **layers;
    struct matrice **biais;
    struct matrice **weights;
};
