#include "mathtools.h"
#include "network.h"
#include "memory.h"
#include <stdlib.h>
#include <err.h>

size_t tab_size(size_t *tab)
{
    size_t len = 0;
    while (*tab++)
        len++;
    return len;
}

struct network *init_network(size_t *layers, struct function *func)
{
    size_t nb_layers = tab_size(layers);
    if (nb_layers < 3)
        errx(1,"network need at least 3 layer et the tab must be NULL terminated");
    struct network *init = my_calloc(1, sizeof(struct network));
    init->nb_layer = nb_layers;
    init->activation = func;

    init->layers = my_calloc(nb_layers, sizeof(struct matrice *));
    init->biais = my_calloc(nb_layers, sizeof(struct matrice *));
    init->weights = my_calloc(nb_layers, sizeof(struct matrice *));

    init->layers[0] = matrice_init(layers[0], 1);
    for (size_t i = 1; i < nb_layers; i++)
    {
        init->weights[i] = matrice_init(layers[i], layers[i-1]);
        init->biais[i] = matrice_init(layers[i], 1);
        init->layers[i] = matrice_init(layers[i], 1);
    }
    return init;
}
