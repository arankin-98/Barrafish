/* Support header file.

*/

#ifndef MODEL_H
#include <stdio.h>
#define MODEL_H

enum Colour {red,
    black,
    blue,
    yellow
};

typedef struct {
    int value;
    Colour colour;    
} Card;

typedef struct {
    int numberKnown;
    int unknownCards;
    Card* knownCards;    
} Game; 

typedef struct {
    int cards;
    Card* hand;
} Hand;

int markov(void);

void testmodel(void);

#endif
