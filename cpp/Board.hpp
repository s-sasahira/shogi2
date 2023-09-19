#ifndef BOARD_HPP
#define BOARD_HPP
#include "BitBoard.hpp"
#include "PieceType.hpp"
#include "ColorType.hpp"
#include "Piece.hpp"

#define STRING_OF_START_PIECE "00000000000" \
                              "01111111110" \
                              "00100000100" \
                              "01111111110" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "01111111110" \
                              "00100000100" \
                              "01111111110" \
                              "00000000000"
#define STRING_OF_START_BLACK "00000000000" \
                              "01111111110" \
                              "00100000100" \
                              "01111111110" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000"
#define STRING_OF_START_WHITE "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "01111111110" \
                              "00100000100" \
                              "01111111110" \
                              "00000000000"
#define STRING_OF_START_NONE  "00000000000" \
                              "00000000000" \
                              "01011111010" \
                              "00000000000" \
                              "01111111110" \
                              "01111111110" \
                              "01111111110" \
                              "00000000000" \
                              "01011111010" \
                              "00000000000" \
                              "00000000000"
#define STRING_OF_START_KING  "00000000000" \
                              "00000100000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000100000" \
                              "00000000000"
#define STRING_OF_START_GOLD  "00000000000" \
                              "00001010000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00001010000" \
                              "00000000000"
#define STRING_OF_START_ROOK "00000000000" \
                               "00000000000" \
                               "00000000100" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00100000000" \
                               "00000000000" \
                               "00000000000"
#define STRING_OF_START_BICHOP  "00000000000" \
                              "00000000000" \
                              "00100000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000100" \
                              "00000000000" \
                              "00000000000"
#define STRING_OF_START_SILVER "00000000000" \
                               "00010001000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00010001000" \
                               "00000000000"
#define STRING_OF_START_KNIGHT "00000000000" \
                               "00100000100" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00100000100" \
                               "00000000000"
#define STRING_OF_START_LANCE "00000000000" \
                              "01000000010" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "01000000010" \
                              "00000000000"
#define STRING_OF_START_PAWN "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "01111111110" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000" \
                             "01111111110" \
                             "00000000000" \
                             "00000000000" \
                             "00000000000"
#define STRING_OF_START_DRAGON "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000" \
                               "00000000000"
#define STRING_OF_START_HORSE "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000" \
                              "00000000000"
#define STRING_OF_START_PROSILVER "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000"
#define STRING_OF_START_PROKNIGHT "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000" \
                                  "00000000000"
#define STRING_OF_START_PROLANCE "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000" \
                                 "00000000000"
#define STRING_OF_START_PROPAWN "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000" \
                                "00000000000"

class Board
{
private:
    bool isAHasSpecificPiece(int index, PieceType pieceType){
        return hasSpecificPiece[(uint64_t)pieceType].board.test(index);
    }
public:
    BitBoard hasPiece;
    BitBoard playerPossession[(uint64_t)ColorType::ColorNumber];
    BitBoard isFrame = BitBoard(STRING_OF_FRAME);
    BitBoard ablePro = BitBoard(STRING_OF_PRO_ZONE);
    BitBoard lastOne = BitBoard(STRING_OF_LAST1_ZONE);
    BitBoard lastTwo = BitBoard(STRING_OF_LAST2_ZONE);
    BitBoard hasSpecificPiece[(uint64_t)PieceType::PieceTypeNumber];
    Board(){
        hasPiece = BitBoard(STRING_OF_START_PIECE);
        {
        using enum ColorType;
        playerPossession[(uint64_t)Black] = BitBoard(STRING_OF_START_BLACK);
        playerPossession[(uint64_t)White] = BitBoard(STRING_OF_START_WHITE);
        }{
        using enum PieceType;
        hasSpecificPiece[(uint64_t)None] = BitBoard(STRING_OF_START_NONE);
        hasSpecificPiece[(uint64_t)King] = BitBoard(STRING_OF_START_KING);
        hasSpecificPiece[(uint64_t)Gold] = BitBoard(STRING_OF_START_GOLD);
        hasSpecificPiece[(uint64_t)Rook] = BitBoard(STRING_OF_START_ROOK);
        hasSpecificPiece[(uint64_t)Bichop] = BitBoard(STRING_OF_START_BICHOP);
        hasSpecificPiece[(uint64_t)Silver] = BitBoard(STRING_OF_START_SILVER);
        hasSpecificPiece[(uint64_t)Knight] = BitBoard(STRING_OF_START_KNIGHT);
        hasSpecificPiece[(uint64_t)Lance] = BitBoard(STRING_OF_START_LANCE);
        hasSpecificPiece[(uint64_t)Pawn] = BitBoard(STRING_OF_START_PAWN);
        hasSpecificPiece[(uint64_t)Dragon] = BitBoard(STRING_OF_START_DRAGON);
        hasSpecificPiece[(uint64_t)Horse] = BitBoard(STRING_OF_START_HORSE);
        hasSpecificPiece[(uint64_t)ProSilver] = BitBoard(STRING_OF_START_PROSILVER);
        hasSpecificPiece[(uint64_t)ProKnight] = BitBoard(STRING_OF_START_PROKNIGHT);
        hasSpecificPiece[(uint64_t)ProLance] = BitBoard(STRING_OF_START_PROLANCE);
        hasSpecificPiece[(uint64_t)ProPawn] = BitBoard(STRING_OF_START_PROPAWN);
        }
    }
    PieceType getPieceTypeFromIndex(int index){
        using enum PieceType;
        if (isAHasSpecificPiece(index, None)) return None;
        else if (isAHasSpecificPiece(index, King)) return King;
        else if (isAHasSpecificPiece(index, Gold)) return Gold;
        else if (isAHasSpecificPiece(index, Rook)) return Rook;
        else if (isAHasSpecificPiece(index, Bichop)) return Bichop;
        else if (isAHasSpecificPiece(index, Silver)) return Silver;
        else if (isAHasSpecificPiece(index, Knight)) return Knight;
        else if (isAHasSpecificPiece(index, Lance)) return Lance;
        else if (isAHasSpecificPiece(index, Pawn)) return Pawn;
        else if (isAHasSpecificPiece(index, Dragon)) return Dragon;
        else if (isAHasSpecificPiece(index, Horse)) return Horse;
        else if (isAHasSpecificPiece(index, ProSilver)) return ProSilver;
        else if (isAHasSpecificPiece(index, ProKnight)) return ProKnight;
        else if (isAHasSpecificPiece(index, ProLance)) return ProLance;
        else /*if (isAHasSpecificPiece(index, ProPawn))*/ return ProPawn;
    }
    ColorType getColorTypeFromIndex(int index){
        using enum ColorType;
        bool hasAPiece = hasPiece.board.test(index);
        bool isBlack = playerPossession[(uint64_t)Black].board.test(index);
        if (!hasAPiece) return None;
        else if (isBlack) return Black;
        else return White;
    }
    BitBoard getAbleMoveSquares(int index){
        using enum DirectionName;
        PieceType pieceType = getPieceTypeFromIndex(index);
        ColorType colorType = getColorTypeFromIndex(index);
        MoveType moveTypes[(int)DirectionNameNumber];
        Piece::getMoveType(moveTypes, pieceType);
        std::bitset<(int)DirectionNameNumber> isInBoard(255);
        BitBoard bitBoard = BitBoard();
        bitBoard.board.set(index);
        BitBoard bitMovable = BitBoard();
        for (int i = 1; i < LENGTH_OF_EDGE; i++){
             for (int j = 0; j < (int)DirectionNameNumber; j++){
                if (moveTypes[j] == MoveType::None){
                    continue;
                }

                if (isInBoard[j]){
                    Direction direction = Direction((DirectionName)j);
                    Direction up = Direction(UP);
                    if (colorType == ColorType::White){
                        direction.reverse();
                        up.reverse();
                    }
                    int v = direction.verticalVector * i;
                    int h = direction.horizonVector * i;
                    if (moveTypes[j] == MoveType::Hop){
                        v += up.verticalVector;
                    }
                    int shiftNumber = LENGTH_OF_FRAME * v + h;
                    std::bitset<LENGTH_OF_BOARD> bn1 = shiftNumber > 0 ? bitBoard.board << shiftNumber : bitBoard.board >> abs(shiftNumber);
                    if ((isFrame.board & bn1).any()){
                        isInBoard.reset(j);
                    }else if ((playerPossession[(int)Color::getReverseColor(colorType)].board & bn1).any()){
                        isInBoard.reset(j);
                        bitMovable.board = bitMovable.board | bn1;
                    }else if ((playerPossession[(int)colorType].board & bn1).any()){
                        isInBoard.reset(j);
                    }else{
                        bitMovable.board = bitMovable.board | bn1;
                    }
                    if (moveTypes[j] != MoveType::Long){
                        isInBoard.reset(j);
                    }
                }
            }
        }
        return bitMovable;
    }
};
#endif