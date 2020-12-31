#include <stdio.h>
#include <stdlib.h>

#include "network.h"
#include "mathtools.h"


int main(void)
{
    size_t input[4] = { 2, 3 , 2, 0};
    struct network *net = network_init(input,sigmoid_pad);
    feed_forward(net);
    network_free(net);
}
