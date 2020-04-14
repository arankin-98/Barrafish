#include <iostream>
#include <new>
#include <cmath>
#include <map>
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
    
    vector<Card> testSet, playSet;

    int moveSet = 0;
    int newM = 0;
        
    uint32_t upperLim = pow(2,playHand->cards);
    int indexBit;

    for (uint32_t j = 1; j < upperLim; j++) { 
        
       
        for (indexBit = 0; indexBit < playHand->cards - 1; indexBit++) {
            if ((j >> indexBit) & 1) {
                testSet.push_back(playHand->hand[indexBit]);
            }
        }        
    

        if (legalMove(game,testSet)) {
            cardSet.push_back(testSet);
        }

        testSet.clear();
    }

    //legalMove(game,cardSet[16380],collectedSet);

    return cardSet;
}


/*
 * Calculates the factorial of an integer.
 * @arg: value; To have factorial of calculated.
 * @return: long result.  
 */
long factorial(int value) {
    
    if (value <= 1) {
        return 1;
    } else {
        return value*factorial(value-1);
    }
}

/*
 * Determines possible hands a player can make based on the current board state.
 * @arg: cards; reference to the cards being sorted.
 * @arg: low; lower index.
 * @arg: high; upper index.
 * @return: vector<vector<Card>> Vector containing the possible new board state, 
 *          represented as a vector.  
 */
void quickSort(vector<Card>& cards, int low, int high) {
    if (low < high) {
        int pi = partition(cards, low, high);
        quickSort(cards, low, pi - 1);
        quickSort(cards, pi + 1, high);
       
    }
}

/*
 * Determines possible hands a player can make based on the current board state.
 * @arg: cards; reference to the cards being sorted.
 * @arg: low; index of the lower bound. 
 * @arg: high; index of the upper bound.
 * @return: int Vector containing the possible new board state, 
 *          represented as a vector.  
 */
int partition (vector<Card>& cards, int low, int high)  {  
    int pivot = cards[high].value; 
    int i = (low - 1);   
    
    for (int j = low; j <= high - 1; j++)  {  
  
        if (cards[j].value < pivot)  {  
            i++;  
            swap(cards[i], cards[j]);   
        }
    }  
    
    swap(cards[i + 1], cards[high]);  

    return (i + 1);  
} 


/*
 * Determines possible hands a player can make based on the current board state.
 * Assume the current board state is legal.
 */
void testPossible(void) {
 
    Hand playHand;
    Game game;

    playHand.cards = 14;

    for (int j = 1; j < 7; j++) {
        Card card;
        card.value = j;    
        if (j % 2 == 0) {

            card.colour = red;
        } else if (j % 3 == 0) {

            card.colour = black;

        } else {

            card.colour = yellow;
        }

        cout << card.value << " ";
        game.knownCards.push_back(card);
    }
    
    for (int j = 1; j < 7; j++) {
        Card card;
        card.value = j;    
        if (j % 2 == 0) {

            card.colour = blue;
        } else if (j % 3 == 0) {

            card.colour = red;

        } else {

            card.colour = black;
        }

        cout << card.value << " ";
        game.knownCards.push_back(card);
    }
    cout << endl;
    for (int i = 1; i < 14; i++) {
        
        Card card;
        if (i%2 == 0) {
            
            card.value = 14 - i;
            card.colour = blue;
            playHand.hand.push_back(card);
        } else {
            if ((i == 7) || (i == 9)) {
                card.value = 8;
            } else if ((i == 11) || (i ==13)) {
                card.value = i;
            } else {
                card.value = i;
            }
            card.colour = red;
            playHand.hand.push_back(card);
        }        
    
        cout << card.value << " ";
    }
    cout << endl;
    possibleHands(&game, &playHand);

}

/*
 * Determines possible hands a player can make based on the current board state.
 * Assume the current board state is legal.
 * @arg: Game* game; Pointer to the Game structure.
 * @arg: move; referene to the test hand structure.
 * @arg: redSet; reference to the red set of hand cards.
 * @arg: blueSet; reference to the blue set of hand cards.
 * @arg: blackSet; reference to the black set of hand cards.
 * @arg: yellowSet; reference to the yellow set of hand cards.
 * @return: bool indicating legal move exists.
 */
bool legalMove(Game* game, vector<Card> move) {

    multimap<int, int> handMap;
    move.insert(move.end(), game->knownCards.begin(), game->knownCards.end());
    
    quickSort(move,0,move.size()-1);

    for (int i = 0; i < move.size(); i++) {
        handMap.insert(pair<int, int>(move[i].value, move[i].colour));
    }    

    return combinationSet(handMap);

}

/*
 * Determines combinations of legal moves within the current hand.
 * @arg: redSet; reference to the red set of hand cards.
 * @arg: blueSet; reference to the blue set of hand cards.
 * @arg: blackSet; reference to the black set of hand cards.
 * @arg: yellowSet; reference to the yellow set of hand cards.
 * @return: bool indicating legal combination for move exists.  
 */
bool combinationSet(multimap<int, int> handMap) {
    vector<vector<Card>> returnSet; 
    
    Card redCard, blueCard, blackCard, yellowCard;
    
    redCard.colour = red;
    blueCard.colour = blue;
    blackCard.colour = black;
    yellowCard.colour = yellow;

    vector<int> cardCount = {0,0,0,0};
    bool addAll;
    addAll = false;
    
    // Find 3+ of a kindi

    std::pair <std::multimap<int,int>::iterator, std::multimap<int,int>::iterator> ret;
    for (int i = 1; i < 14; i++) {

        redCard.value = i;
        blueCard.value = i;
        blackCard.value = i;
        yellowCard.value = i;
        
        ret = handMap.equal_range(i);
        for(multimap<int, int>::iterator its = ret.first; its != ret.second; its++) {
            cardCount[(*its).second]++;
        }
        
        if (*min_element(cardCount.begin(), cardCount.end()) == 0) {
            cout << "ZERO\r\n";
        } else if (*min_element(cardCount.begin(), cardCount.end()) == 2) {
            cout << "FULL\r\n";
            addAll = true;
        } else {
            for (int j = 0; j < 2; j++) {
                if ((cardCount[red] >= 1) && (cardCount[blue] >= 1) &&
                    (cardCount[black] >= 1) && (cardCount[yellow] >= 1)) {   
                    cardCount[red]--;
                    cardCount[blue]--;
                    cardCount[black]--;
                    cardCount[yellow]--;
                    returnSet.push_back(vector<Card> {redCard,blueCard,blackCard,yellowCard});
                } else if ((cardCount[red] >= 1) && (cardCount[blue] >= 1) &&
                    (cardCount[black] >= 1)) {
                    cardCount[red]--;
                    cardCount[blue]--;
                    cardCount[black]--;
                    returnSet.push_back(vector<Card> {redCard,blueCard,blackCard});
                } else if ((cardCount[red] >= 1) && (cardCount[blue] >= 1) &&
                    (cardCount[yellow] >= 1)) { 
                    cardCount[red]--;
                    cardCount[blue]--;
                    cardCount[yellow]--;
                    returnSet.push_back(vector<Card> {redCard,blueCard,yellowCard});
                } else if ((cardCount[red] >= 1) && (cardCount[black] >= 1) && 
                    (cardCount[yellow] >= 1)) {   
                    cardCount[red]--;
                    cardCount[black]--;
                    cardCount[yellow]--;
                    returnSet.push_back(vector<Card> {redCard,blackCard,yellowCard});
                } else if ((cardCount[blue] >= 1) && (cardCount[black] >= 1) && 
                    (cardCount[yellow] >= 1)) {    
                    cardCount[blue]--;
                    cardCount[black]--;
                    cardCount[yellow]--;
                    returnSet.push_back(vector<Card> {blueCard,blackCard,yellowCard});
                }   
            }
        }
/*                
        cout << "sz " << returnSet.size() << endl; 
        
        for (int p = 0; p < returnSet.size(); p++) {
            for (int k = 0; k < returnSet[p].size(); k++) {
                cout << " cl " << returnSet[p][k].colour << " vl " << returnSet[p][k].value;
            }
            cout << endl; 
        }
*/
    }

    // Run

    for (multimap<int, int>::iterator vals = handMap.begin();
        vals != handMap.end(); ++vals) {
        //    cout << (*vals).first << " card colour is " << (*vals).second << endl;
        }     


    return false;

}


