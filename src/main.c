#include <stdio.h>
#include <stdlib.h>

#include "network.h"
#include "mathtools.h"

int main(void)
{
    struct function tmp=
    { .name = "tmp", .function=sigmoid, .prime=sigmoid_prime};
    size_t input[4] = { 1, 2 , 3, 0};
    struct network *net = network_init(input,&tmp);
    network_free(net);
    printf("toto\n");
}
