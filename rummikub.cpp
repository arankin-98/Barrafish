#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include "rummimodel.h"
#include "rummilogic.h"

using namespace std;

void help(void) {
    
    cout << "\r\nTo initiate a random forest model four additonal arguments required: \r\n"; 
    cout << "   Dimension of data, number of instances, data as a .txt file, number of \r\n";
    cout << "   classes and class for each corresponding data array as a .txt file\r\n"; 
    cout << "   where classes are enumerated \r\n\n";
    cout << "Example: >./random_forest 5 200 data.txt 3 classes.txt\r\n\n";
    cout << "Following the construction of a random forest model once 'Complete!' \r\n";
    cout << "   has been printed, providing a new example to be classified is done \r\n";
    cout << "   in the following manner; provide the .txt from which data of the \r\n";
    cout << "   dimension is present, and the corresponding results will be printed\r\n";
    cout << "   to the file provide as a .txt line separated file. \r\n\n";
    cout << "Example: >Complete!\r\n \t >newData.txt, output_file_name\r\n\n";
}


void runGame(void) {

    cout << "Input your starting hand in the following style; Colour,number \r\n";
    cout << "Eg. 'black,7' \r\n\r\n";
    cout << "If it is a joker; Colour, 20 \r\n";
    cout << "Eg. 'blue,20'\r\n";

}


int main(int argc, char* argv[]) {



//    help();
//    testmodel();    
//    runGame();

    testPossible();

}
