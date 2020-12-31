#include "mathtools.h"
#include "network.h"
#include "memory.h"
#include <stdlib.h>
#include <err.h>
#include <string.h>

static size_t tab_size(size_t *tab)
{
    size_t len = 0;
    while (*tab++)
        len++;
    return len;
}

struct network *network_init(size_t *layers, void (*func)(struct matrice *))
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
        matrice_randomise(init->weights[i]);
        matrice_randomise(init->biais[i]);
        init->layers[i] = matrice_init(layers[i], 1);
    }
    return init;
}

void network_free(struct network *net)
{
    for (size_t i = 0; i < net->nb_layer; i++)
    {
        matrice_free(net->weights[i]);
        matrice_free(net->biais[i]);
        matrice_free(net->layers[i]);
    }
    free(net->weights);
    free(net->biais);
    free(net->layers);

    free(net);
}

void set_input(struct network *net, double *tab)
{
    for (size_t i = 0; i < net->layers[0]->height;i++)
        net->layers[0]->mat[i] = tab[i];
}

void feed_forward(struct network *net)
{
    for (size_t i = 1; i < net->nb_layer; i++)
    {
        matrice_mult(net->layers[i], net->weights[i], net->layers[i-1]);
        matrice_add(net->layers[i], net->layers[i], net->biais[i]);
        net->activation(net->layers[i]);
    }
}

void back_propagation(struct network *net, size_t expected)
{
    double **errors = calloc(net->nb_layer, sizeof(double *));
    errors[0] = calloc(net->layers[0]->height, sizeof(double));
    for (size_t i = 0 ; i < net->layers[net->nb_layer-1]->height; i++)
    {
        double off_set = ((i == expected) ? 1 : 0) - net->layers[net->nb_layer-1]->mat[i];
        errors[0][i] = net->derivative(net->layers[net->nb_layer-1]->mat[i]) *
                       off_set; //output
    }

    for (ssize_t i = net->nb_layer-2; i >= 0; i--)
    {
        struct matrice *trans = matrice_transpose(net->weights[i]);
    }

    for (size_t i = 0; i < net->nb_layer; i++)
        free(errors[i]);
    free(errors);
}
