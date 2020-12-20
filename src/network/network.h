#include "mathtools.h"


struct network
{
    size_t nb_layer;

    struct matrice **layers;
    struct matrice **biais;
    struct matrice **weights;
}
