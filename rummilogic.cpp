
#include <iostream>
#include <new>
#include <cmath>
#include "rummimodel.h"
#include "rummilogic.h"

using namespace std;

/*
 * Determines possible hands a player can make based on the current board state.
 * Assume the current board state is legal.
 * @arg: Game* game; Pointer to the Game structure.
 * @arg: Hand* hand; Pointer to the player's hand structure.
 * @return: vector<vector<Card>> Vector containing the possible new board state, 
 *          represented as a vector.  
 */
vector<vector<Card>> possibleHands(Game* game,Hand* playHand) {
    vector<vector<Card>> cardSet;
    
    vector<Card> testSet;
    int moveSet = 0;
    int newM = 0;
        
    uint32_t upperLim = pow(2,playHand->cards);
    int indexBit;

    for (uint32_t j = 1; j < upperLim; j++) {        
        for (indexBit = 0; indexBit < playHand->cards; indexBit++) {
            if ((j >> indexBit) & 1) {
                testSet.push_back(playHand->hand[indexBit]);
            
//                cout << "Card: " << playHand->hand[indexBit].value << " c: " << playHand->hand[indexBit].colour << " ";
//                cout << "\r\n"; 
            }
        }        
                
        cardSet.push_back(testSet);
        testSet.clear();       
    }    
       

    quickSort(cardSet[16300],0,playHand->cards);
    //moveSet = (factorial(hand->cards)/(factorial(i)*(factorial(hand->cards-i))));                
    
    return cardSet;

}

long factorial(int value) {
    
    if (value <= 1) {
        return 1;
    } else {
        return value*factorial(value-1);
    }
}


/* low  --> Starting index,  high  --> Ending index */
void quickSort(vector<Card>& cards, int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        int pi = partition(cards, low, high);
        quickSort(cards, low, pi - 1);  // Before pi
        quickSort(cards, pi + 1, high); // After pi
       
    }
}

int partition (vector<Card>& cards, int low, int high)  {  
    int pivot = cards[high].value; // pivot  
    int i = (low - 1); // Index of smaller element  
    for (int j = low; j <= high - 1; j++)  {  
        // If current element is smaller than the pivot  
        if (cards[j].value < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(cards[i], cards[j]);   
        }
    }  
    swap(cards[i + 1], cards[high]);  



    return (i + 1);  
} 

void testPossible(void) {
 
    Hand playHand;
    Game game;

    playHand.cards = 14;
    
    for (int i = 0; i < 14; i++) {
        
        Card card;
        if (i%2 == 0) {
            
            card.value = 14 - i;
            card.colour = blue;
            playHand.hand.push_back(card);
        } else {
            if (i == 7) {
                card.value = 8;
            } else {
                card.value = i;
            }
            card.colour = red;
            playHand.hand.push_back(card);
        }        
    }

    possibleHands(&game, &playHand);

}

bool legalMove(Game* game, vector<Card> move) {

    
    
    return false;

}

