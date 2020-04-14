/* Support header file.

*/

#ifndef MODEL_H
#include <stdio.h>
#include <vector>
#define MODEL_H

enum Colour {red,
    blue,
    black,
    yellow
};

typedef struct {
    int value;
    Colour colour;    
} Card;

typedef struct {
    int numberKnown;
    int unknownCards;
    std::vector<Card> knownCards;    
} Game; 

typedef struct {
    int cards;
    std::vector<Card> hand;
} Hand;

int markov(void);

void testmodel(void);

#endif
