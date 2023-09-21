#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <bitset>
#include "BitBoard.hpp"
#include "Board.hpp"
#include "Address.hpp"
#include <time.h>

int main() {
    
    Board board = Board();
    int* arrayTrueIndex;
    
    struct timeval start, end;
    mingw_gettimeofday(&start, NULL);
    int trueCount = board.playerPossession[0].getTrues(&arrayTrueIndex);
    mingw_gettimeofday(&end, NULL);
    std::cout << "duration = " << (end.tv_usec - start.tv_usec) << "usec.\n";

    for (int i = 0; i < trueCount; i++){
        printf("%s,", Address(arrayTrueIndex[i]).toString());
    }
    printf("\n");

    Move* moves;
    mingw_gettimeofday(&start, NULL);
    int moveCount = board.serchMoves(&moves, ColorType::Black);
    mingw_gettimeofday(&end, NULL);
    printf("%s\n", moves[0].toString());
    // for (int i = 0; i < moveCount; i++){
    //     printf("%s,", moves[i].toString());
    // }
    printf("size: %d\n", moveCount);
    std::cout << "time is " << (end.tv_usec - start.tv_usec) << "usec.\n";
}