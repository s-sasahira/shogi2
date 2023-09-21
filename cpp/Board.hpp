#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "BitBoard.hpp"
#include "PieceType.hpp"
#include "ColorType.hpp"
#include "Piece.hpp"
#include "Hand.hpp"
#include "Address.hpp"
#include "Move.hpp"

class Board
{
private:
    bool isAHasSpecificPiece(int index, PieceType pieceType){
        return hasSpecificPiece[(uint64_t)pieceType].board.test(index);
    }
    void drop(int index){
        hasPiece.board.reset(index);
        for (int i = 0; i < (int)ColorType::ColorNumber; i++){
            playerPossession[i].board.reset(index);
        }
        hasSpecificPiece[(int)PieceType::None].board.set(index);
        for (int i = 1; i < (int)PieceType::PieceTypeNumber; i++){
            hasSpecificPiece[i].board.reset(index);
        }
    }
    void deploy(int index, PieceType pieceType, ColorType color){
        hasPiece.board.set(index);
        for (int i = 0; i < (int)ColorType::ColorNumber; i++){
            if (color == (ColorType)i){
                playerPossession[i].board.set(index);
            }else{
                playerPossession[i].board.reset(index);
            }
        }
        for (int i = 0; i < (int)PieceType::PieceTypeNumber; i++){
            if (pieceType == (PieceType)i){
                hasSpecificPiece[i].board.set(index);
            }else{
                hasSpecificPiece[i].board.reset(index);
            }
        }
    }
    void moveToHand(int index, bool isColorReverse = true){
        using enum PieceType;
        PieceType pieceType = getPieceTypeFromIndex(index);
        if ((int)pieceType > (int)Promote){
            pieceType = (PieceType)((int)pieceType - (int)Promote);
        }

        ColorType colorType = getColorTypeFromIndex(index);
        if (isColorReverse){
            colorType = Color::getReverseColor(colorType);
        }

        drop(index);
        hand.addPiece(colorType, pieceType);
    }
    void moveFromHand(int index, PieceType pieceType, ColorType color){
        hand.decreasePiece(color, pieceType);
        deploy(index, pieceType, color);
    }
public:
    BitBoard hasPiece;
    BitBoard playerPossession[(int)ColorType::ColorNumber];
    BitBoard isFrame = BitBoard(STRING_OF_FRAME);
    BitBoard ablePro[(int)ColorType::ColorNumber] = {
        BitBoard(STRING_OF_PRO_ZONE_BLACK), 
        BitBoard(STRING_OF_PRO_ZONE_WHITE)
    };
    BitBoard lastOne[(int)ColorType::ColorNumber] = {
        BitBoard(STRING_OF_LAST1_ZONE_BLACK), 
        BitBoard(STRING_OF_LAST1_ZONE_WHITE)
    };
    BitBoard lastTwo[(int)ColorType::ColorNumber] = {
        BitBoard(STRING_OF_LAST2_ZONE_BLACK), 
        BitBoard(STRING_OF_LAST2_ZONE_WHITE)
    };
    BitBoard hasSpecificPiece[(int)PieceType::PieceTypeNumber];
    Hand hand;

    Board(){
        hasPiece = BitBoard();
        using enum PieceType;
        for (int i = 0; i < (int)ColorType::ColorNumber; i++){
            playerPossession[i] = BitBoard();
        }
        hasSpecificPiece[(int)None] = BitBoard(isFrame);
        hasSpecificPiece[(int)None].board.flip();
        for (int i = 1; i < (int)PieceTypeNumber; i++){
            hasSpecificPiece[i] = BitBoard();
        }
        deploy(Address::addressToIndex(Address(1,1)), Lance, ColorType::White);
        deploy(Address::addressToIndex(Address(2,1)), Knight, ColorType::White);
        deploy(Address::addressToIndex(Address(3,1)), Silver, ColorType::White);
        deploy(Address::addressToIndex(Address(4,1)), Gold, ColorType::White);
        deploy(Address::addressToIndex(Address(5,1)), King, ColorType::White);
        deploy(Address::addressToIndex(Address(6,1)), Gold, ColorType::White);
        deploy(Address::addressToIndex(Address(7,1)), Silver, ColorType::White);
        deploy(Address::addressToIndex(Address(8,1)), Knight, ColorType::White);
        deploy(Address::addressToIndex(Address(9,1)), Lance, ColorType::White);
        deploy(Address::addressToIndex(Address(2,2)), Bichop, ColorType::White);
        deploy(Address::addressToIndex(Address(8,2)), Rook, ColorType::White);
        deploy(Address::addressToIndex(Address(1,3)), Pawn, ColorType::White);
        deploy(Address::addressToIndex(Address(2,3)), Pawn, ColorType::White);
        deploy(Address::addressToIndex(Address(3,3)), Pawn, ColorType::White);
        deploy(Address::addressToIndex(Address(4,3)), Pawn, ColorType::White);
        deploy(Address::addressToIndex(Address(5,3)), Pawn, ColorType::White);
        deploy(Address::addressToIndex(Address(6,3)), Pawn, ColorType::White);
        deploy(Address::addressToIndex(Address(7,3)), Pawn, ColorType::White);
        deploy(Address::addressToIndex(Address(8,3)), Pawn, ColorType::White);
        deploy(Address::addressToIndex(Address(9,3)), Pawn, ColorType::White);

        deploy(Address::addressToIndex(Address(1,9)), Lance, ColorType::Black);
        deploy(Address::addressToIndex(Address(2,9)), Knight, ColorType::Black);
        deploy(Address::addressToIndex(Address(3,9)), Silver, ColorType::Black);
        deploy(Address::addressToIndex(Address(4,9)), Gold, ColorType::Black);
        deploy(Address::addressToIndex(Address(5,9)), King, ColorType::Black);
        deploy(Address::addressToIndex(Address(6,9)), Gold, ColorType::Black);
        deploy(Address::addressToIndex(Address(7,9)), Silver, ColorType::Black);
        deploy(Address::addressToIndex(Address(8,9)), Knight, ColorType::Black);
        deploy(Address::addressToIndex(Address(9,9)), Lance, ColorType::Black);
        deploy(Address::addressToIndex(Address(2,8)), Bichop, ColorType::Black);
        deploy(Address::addressToIndex(Address(8,8)), Rook, ColorType::Black);
        deploy(Address::addressToIndex(Address(1,7)), Pawn, ColorType::Black);
        deploy(Address::addressToIndex(Address(2,7)), Pawn, ColorType::Black);
        deploy(Address::addressToIndex(Address(3,7)), Pawn, ColorType::Black);
        deploy(Address::addressToIndex(Address(4,7)), Pawn, ColorType::Black);
        deploy(Address::addressToIndex(Address(5,7)), Pawn, ColorType::Black);
        deploy(Address::addressToIndex(Address(6,7)), Pawn, ColorType::Black);
        deploy(Address::addressToIndex(Address(7,7)), Pawn, ColorType::Black);
        deploy(Address::addressToIndex(Address(8,7)), Pawn, ColorType::Black);
        deploy(Address::addressToIndex(Address(9,7)), Pawn, ColorType::Black);

        hand = Hand();
    }
    Board(int code){
        hasPiece = BitBoard();
        using enum PieceType;
        for (int i = 0; i < (int)ColorType::ColorNumber; i++){
            playerPossession[i] = BitBoard();
        }
        hasSpecificPiece[(int)None] = BitBoard(isFrame);
        hasSpecificPiece[(int)None].board.flip();
        for (int i = 1; i < (int)PieceTypeNumber; i++){
            hasSpecificPiece[i] = BitBoard();
        }
        deploy(Address::addressToIndex(Address(8,1)), ProPawn, ColorType::Black);
        deploy(Address::addressToIndex(Address(7,3)), Bichop, ColorType::Black);
        deploy(Address::addressToIndex(Address(9,4)), Knight, ColorType::Black);
        deploy(Address::addressToIndex(Address(7,5)), Lance, ColorType::White);
        deploy(Address::addressToIndex(Address(8,7)), Pawn, ColorType::Black);

        hand = Hand();
        hand.addPiece(ColorType::Black, PieceType::Pawn);
        hand.addPiece(ColorType::Black, PieceType::Silver);
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

                    BitBoard bn1 = shiftNumber > 0 ? bitBoard << shiftNumber : bitBoard >> abs(shiftNumber);

                    if ((isFrame & bn1).board.any()){
                        isInBoard.reset(j);
                    }else if ((playerPossession[(int)Color::getReverseColor(colorType)] & bn1).board.any()){
                        isInBoard.reset(j);
                        bitMovable = bitMovable | bn1;
                    }else if ((playerPossession[(int)colorType] & bn1).board.any()){
                        isInBoard.reset(j);
                    }else{
                        bitMovable = bitMovable | bn1;
                    }

                    if (moveTypes[j] != MoveType::Long){
                        isInBoard.reset(j);
                    }
                }
            }
        }
        return bitMovable;
    }

    BitBoard getAbleProMoveSquares(int index, BitBoard bitMovable){
        BitBoard result = BitBoard();
        PieceType pieceType = getPieceTypeFromIndex(index);
        ColorType colorType = getColorTypeFromIndex(index);
        BitBoard bitBoard = BitBoard();
        bitBoard.board.set(index);
        bool isAblePro = Piece::ablePro(pieceType);
        if (!isAblePro){
            return result;
        }

        BitBoard proArea = ablePro[(int)colorType];

        if ((bitBoard & proArea).board.any()){
            return bitMovable;
        }

        return bitMovable & proArea;
    }

    BitBoard getAbleDropSquares(ColorType color, PieceType pieceType){
        BitBoard ableDrop;
        BitBoard none, last, notlast, pawn, doublepawn, notdoublepawn;
        int* pawnIndexs;
        int pawnIndexCount;
        using enum PieceType;
        switch (pieceType){
        case Gold:
        case Rook:
        case Bichop:
        case Silver:
            return BitBoard(hasSpecificPiece[(int)None]);
        case Knight:
            none = BitBoard(hasSpecificPiece[(int)None]);
            last = BitBoard(lastTwo[(int)color]);
            notlast = BitBoard(last.board.flip());
            return BitBoard(none & notlast);
        case Lance:
            none = BitBoard(hasSpecificPiece[(int)None]);
            last = BitBoard(lastOne[(int)color]);
            notlast = BitBoard(last.board.flip());
            return BitBoard(none & notlast);
        case Pawn:
            pawn = BitBoard(hasSpecificPiece[(int)Pawn] & playerPossession[(int)color]);
            pawnIndexCount = pawn.getTrues(&pawnIndexs);
            doublepawn = BitBoard();

            for (int i = 0; i < pawnIndexCount; i++){
                doublepawn = doublepawn | BitBoard::generateColumn(Address::indexToAddress(pawnIndexs[i]).column);
            }

            notdoublepawn = BitBoard(doublepawn);
            notdoublepawn.board.flip();
            none = BitBoard(hasSpecificPiece[(int)None]);
            last = BitBoard(lastOne[(int)color]);
            notlast = BitBoard(last.board.flip());
            return BitBoard(none & notlast & notdoublepawn);
        default:
            return BitBoard();
        }
    }
    int serchMoves(Move** moves, ColorType color){
        std::vector<Move> vectorMove;

        BitBoard playerBoard = (bool)color ? playerPossession[(int)ColorType::White] : playerPossession[(int)ColorType::Black];
        int* playerBoardIndexs;
        int playerBoardIndexsCount = playerBoard.getTrues(&playerBoardIndexs);
        for (int i = 0; i < playerBoardIndexsCount; i++){
            int* moveIndexs;
            int moveIndexsCount;

            /*成らない手*/
            BitBoard moveBoard = getAbleMoveSquares(playerBoardIndexs[i]);
            moveIndexsCount = moveBoard.getTrues(&moveIndexs);
            for (int j = 0; j < moveIndexsCount; j++){
                Address from = Address(playerBoardIndexs[i]);
                Address to = Address(moveIndexs[j]);
                Move move = Move(from, to, false);
                vectorMove.push_back(move);
            }

            /*成る手*/
            BitBoard proBoard = getAbleProMoveSquares(playerBoardIndexs[i], moveBoard);
            moveIndexsCount = moveBoard.getTrues(&moveIndexs);
            for (int j = 0; j < moveIndexsCount; j++){
                Address from = Address(playerBoardIndexs[i]);
                Address to = Address(moveIndexs[j]);
                Move move = Move(from, to, true);
                vectorMove.push_back(move);
            }
        }

        Piece* playerHandPieces;
        int playerHandPiecesCount = hand.getPlayerPieces(&playerHandPieces, color);
        for (int i = 0; i < playerHandPiecesCount; i++){
            int* moveIndexs;
            int moveIndexsCount;
            BitBoard moveBoard = getAbleDropSquares(playerHandPieces[i].owner, playerHandPieces[i].type);
            moveIndexsCount = moveBoard.getTrues(&moveIndexs);
            for (int j = 0; j < moveIndexsCount; j++){
                Address to = Address(moveIndexs[j]);
                Move move = Move(playerHandPieces[i], to);
                vectorMove.push_back(move);
            }
        }

        (*moves) = vectorMove.data(); 
        return vectorMove.size();
    }
    void executeMove(Move move){

    }
};
#endif