#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <bitset>
#include "BitBoard.hpp"
#include "Board.hpp"
#include "Address.hpp"
#include <time.h>

int main() {
    Board board = Board(1);
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
    std::cout << "ableProB: " << board.ablePro[0].board << std::endl;
    std::cout << "ableProW: " << board.ablePro[1].board << std::endl;
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
    std::cout << "Dragon  : " << board.hasSpecificPiece[(uint64_t)PieceType::Dragon].board << std::endl;
    std::cout << "Horse   : " << board.hasSpecificPiece[(uint64_t)PieceType::Horse].board << std::endl;
    std::cout << "ProSilve: " << board.hasSpecificPiece[(uint64_t)PieceType::ProSilver].board << std::endl;
    std::cout << "ProKnigh: " << board.hasSpecificPiece[(uint64_t)PieceType::ProKnight].board << std::endl;
    std::cout << "ProLance: " << board.hasSpecificPiece[(uint64_t)PieceType::ProLance].board << std::endl;
    std::cout << "ProPawn : " << board.hasSpecificPiece[(uint64_t)PieceType::ProPawn].board << std::endl;

    int array[5] = {19, 40, 53, 62, 85};
    for (int j = 0; j < 5; j++){
        mingw_gettimeofday(&start, NULL);
        BitBoard bitMovable = board.getAbleMoveSquares(array[j]);
        BitBoard bitProMovable = board.getAbleProMoveSquares(array[j], bitMovable);
        mingw_gettimeofday(&end, NULL);
        std::cout << "duration = " << (end.tv_usec - start.tv_usec) << "usec.\n";
        int* indexs1;
        int* indexs2;
        int indexsCount1 = bitMovable.getTrues(&indexs1);
        int indexsCount2 = bitProMovable.getTrues(&indexs2);
        Address fromAddress = Address::indexToAddress(array[j]);
        printf("%d%d: ", fromAddress.column, fromAddress.row);
        for (int i = 0; i < indexsCount1; i++){
            Address toAddress = Address::indexToAddress(indexs1[i]);
            printf("%d%d,", toAddress.column, toAddress.row);
        }
        printf(" pro: ");
        for (int i = 0; i < indexsCount2; i++){
            Address toAddress = Address::indexToAddress(indexs2[i]);
            printf("%d%d,", toAddress.column, toAddress.row);
        }
        printf("\n");
        free(indexs1);
        free(indexs2);
    }
    

}