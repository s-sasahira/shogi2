#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <bitset>
#include "BitBoard.hpp"
#include "Board.hpp"
#include <time.h>

int main() {
    Board board = Board();
    int* arrayTrueIndex;
    
    struct timeval start, end;
    mingw_gettimeofday(&start, NULL);
    int trueCount = board.hasPiece.getTrues(&arrayTrueIndex);
    mingw_gettimeofday(&end, NULL);
    std::cout << "duration = " << (end.tv_usec - start.tv_usec) << "usec.\n";

    mingw_gettimeofday(&start, NULL);
    for (int i = 0; i < trueCount; i++){
        printf("%d,", arrayTrueIndex[i]);
    }
    printf("\n");
    mingw_gettimeofday(&end, NULL);
    std::cout << "duration = " << (end.tv_usec - start.tv_usec) << "usec.\n";

    
    
    std::cout << "frame   : " << board.isFrame.board << std::endl;
    std::cout << "hasPiece: " << board.hasPiece.board << std::endl;
    std::cout << "Black   : " << board.playerPossession[(uint64_t)ColorType::Black].board << std::endl;
    std::cout << "White   : " << board.playerPossession[(uint64_t)ColorType::White].board << std::endl;
    std::cout << "None    : " << board.hasSpecificPiece[(uint64_t)PieceType::None].board << std::endl;
    std::cout << "King    : " << board.hasSpecificPiece[(uint64_t)PieceType::King].board << std::endl;
    std::cout << "Gold    : " << board.hasSpecificPiece[(uint64_t)PieceType::Gold].board << std::endl;
    std::cout << "Rook    : " << board.hasSpecificPiece[(uint64_t)PieceType::Rook].board << std::endl;
    std::cout << "Bichop  : " << board.hasSpecificPiece[(uint64_t)PieceType::Bichop].board << std::endl;
    std::cout << "Silver  : " << board.hasSpecificPiece[(uint64_t)PieceType::Silver].board << std::endl;
    std::cout << "Knight  : " << board.hasSpecificPiece[(uint64_t)PieceType::Knight].board << std::endl;
    std::cout << "Lance   : " << board.hasSpecificPiece[(uint64_t)PieceType::Lance].board << std::endl;
    std::cout << "Pawn    : " << board.hasSpecificPiece[(uint64_t)PieceType::Pawn].board << std::endl;

    mingw_gettimeofday(&start, NULL);
    BitBoard bitMovable = board.getAbleMoveSquares(24);
    mingw_gettimeofday(&end, NULL);
    std::cout << "duration = " << (end.tv_usec - start.tv_usec) << "usec.\n";
    int* indexs;
    int indexsCount = bitMovable.getTrues(&indexs);
    for (int i = 0; i < indexsCount; i++){
        printf("%d,", indexs[i]);
    }
    printf("\n");
    free(indexs);

    mingw_gettimeofday(&start, NULL);
    bitMovable = board.getAbleMoveSquares(90);
    mingw_gettimeofday(&end, NULL);
    std::cout << "duration = " << (end.tv_usec - start.tv_usec) << "usec.\n";
    indexs;
    indexsCount = bitMovable.getTrues(&indexs);
    printf("90: ");
    for (int i = 0; i < indexsCount; i++){
        printf("%d,", indexs[i]);
    }
    printf("\n");
    free(indexs);

    mingw_gettimeofday(&start, NULL);
    bitMovable = board.getAbleMoveSquares(41);
    mingw_gettimeofday(&end, NULL);
    std::cout << "duration = " << (end.tv_usec - start.tv_usec) << "usec.\n";
    indexs;
    indexsCount = bitMovable.getTrues(&indexs);
    printf("41: ");
    for (int i = 0; i < indexsCount; i++){
        printf("%d,", indexs[i]);
    }
    printf("\n");
    free(indexs);

    mingw_gettimeofday(&start, NULL);
    bitMovable = board.getAbleMoveSquares(16);
    mingw_gettimeofday(&end, NULL);
    std::cout << "duration = " << (end.tv_usec - start.tv_usec) << "usec.\n";
    indexs;
    indexsCount = bitMovable.getTrues(&indexs);
    printf("16: ");
    for (int i = 0; i < indexsCount; i++){
        printf("%d,", indexs[i]);
    }
    printf("\n");
    free(indexs);

    mingw_gettimeofday(&start, NULL);
    bitMovable = board.getAbleMoveSquares(101);
    mingw_gettimeofday(&end, NULL);
    std::cout << "duration = " << (end.tv_usec - start.tv_usec) << "usec.\n";
    indexs;
    indexsCount = bitMovable.getTrues(&indexs);
    printf("101: ");
    for (int i = 0; i < indexsCount; i++){
        printf("%d,", indexs[i]);
    }
    printf("\n");
    free(indexs);

    mingw_gettimeofday(&start, NULL);
    bitMovable = board.getAbleMoveSquares(107);
    mingw_gettimeofday(&end, NULL);
    std::cout << "duration = " << (end.tv_usec - start.tv_usec) << "usec.\n";
    indexs;
    indexsCount = bitMovable.getTrues(&indexs);
    printf("107: ");
    for (int i = 0; i < indexsCount; i++){
        printf("%d,", indexs[i]);
    }
    printf("\n");
    free(indexs);
}