

#ifndef LOGIC_H
#include <stdio.h>
#include <vector>
#include <map>
#define LOGIC_H

    std::vector<std::vector<Card>> possibleHands(Game*, Hand*);

    void quickSort(std::vector<Card>&, int, int);

    int partition(std::vector<Card>&, int, int);

    long factorial(int);

    void testPossible();

    bool legalMove(Game*,std::vector<Card>);

    bool combinationSet(std::multimap<int, int>);

#endif
