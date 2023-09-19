#ifndef PIECE_HPP
#define PIECE_HPP

#include "PieceType.hpp"
#include "PieceName.hpp"
#include "HandPiece.hpp"
#include "MoveType.hpp"
#include "Direction.hpp"

class Piece
{
private:
public:
    PieceType type;
    PieceName name;
    static void getMoveType(MoveType moveTypes[(int)DirectionName::DirectionNameNumber], PieceType pieceType){
        using enum PieceType;
        switch (pieceType){
        case None:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = None;
            moveTypes[(int)UP_LEFT] = None;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = None;
            break;
            }
        case King:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = Short;
            moveTypes[(int)DOWN_LEFT] = Short;
            moveTypes[(int)DOWN] = Short;
            moveTypes[(int)DOWN_RIGHT] = Short;
            moveTypes[(int)RIGHT] = Short;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        case Gold:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = Short;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = Short;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = Short;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        case Rook:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Long;
            moveTypes[(int)UP_LEFT] = None;
            moveTypes[(int)LEFT] = Long;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = Long;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = Long;
            moveTypes[(int)UP_RIGHT] = None;
            break;
            }
        case Bichop:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = None;
            moveTypes[(int)UP_LEFT] = Long;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = Long;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = Long;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = Long;
            break;
            }
        case Silver:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = Short;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = Short;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        case Knight:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = None;
            moveTypes[(int)UP_LEFT] = Hop;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = Hop;
            break;
            }
        case Lance:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Long;
            moveTypes[(int)UP_LEFT] = None;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = None;
            break;
            }
        case Pawn:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = None;
            moveTypes[(int)LEFT] = None;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = None;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = None;
            moveTypes[(int)UP_RIGHT] = None;
            break;
            }
        case Dragon:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Long;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = Long;
            moveTypes[(int)DOWN_LEFT] = Short;
            moveTypes[(int)DOWN] = Long;
            moveTypes[(int)DOWN_RIGHT] = Short;
            moveTypes[(int)RIGHT] = Long;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        case Horse:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Long;
            moveTypes[(int)LEFT] = Short;
            moveTypes[(int)DOWN_LEFT] = Long;
            moveTypes[(int)DOWN] = Short;
            moveTypes[(int)DOWN_RIGHT] = Long;
            moveTypes[(int)RIGHT] = Short;
            moveTypes[(int)UP_RIGHT] = Long;
            break;
            }
        case ProSilver:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = Short;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = Short;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = Short;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        case ProKnight:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = Short;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = Short;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = Short;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        case ProLance:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = Short;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = Short;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = Short;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        case ProPawn:
            {
            using enum DirectionName;
            using enum MoveType;
            moveTypes[(int)UP] = Short;
            moveTypes[(int)UP_LEFT] = Short;
            moveTypes[(int)LEFT] = Short;
            moveTypes[(int)DOWN_LEFT] = None;
            moveTypes[(int)DOWN] = Short;
            moveTypes[(int)DOWN_RIGHT] = None;
            moveTypes[(int)RIGHT] = Short;
            moveTypes[(int)UP_RIGHT] = Short;
            break;
            }
        }
    }
};
#endif