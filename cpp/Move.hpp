#ifndef MOVE_HPP
#define MOVE_HPP

#include <bitset>
#include <stdint.h>
#include "Address.hpp"
#include "Piece.hpp"
#include "PieceType.hpp"
#include "ColorType.hpp"

class Move{
private:
public:
    std::bitset<16> value;
    /*
    00000000 00000000
    1bit: is drop
    1bit: is promote
    7bit: target index
    7bit: from index / piece type and color type
    */
    Move(){
        value = std::bitset<16>(0);
    }
    Move(Address from, Address to, bool promote){
        std::bitset<16> bitFrom(from.toIndex());
        std::bitset<16> bitTo(to.toIndex());
        std::bitset<16> bitPro(promote);
        std::bitset<16> bitDrop(0);
        bitDrop <<= 15;
        bitPro <<= 14;
        bitTo <<= 7;
        value = bitFrom | bitTo | bitPro | bitDrop;
    }
    Move(Piece piece, Address to){
        std::bitset<16> bitFrom(piece.toInt());
        std::bitset<16> bitTo(to.toIndex());
        std::bitset<16> bitPro(0);
        std::bitset<16> bitDrop(0);
        bitDrop <<= 15;
        bitPro <<= 14;
        bitTo <<= 7;
        value = bitFrom | bitTo | bitPro | bitDrop;
    }

    bool getIsDrop(){
        return value.test(15);
    }
    bool getIsPromote(){
        return value.test(14);
    }
    Address getFrom(){
        std::bitset<16> copy(value);
        copy <<= 9;
        copy >>= 9;
        return Address((int)copy.to_ulong());
    }
    Address getTo(){
        std::bitset<16> copy(value);
        copy <<= 2;
        copy >>= 9;
        return Address((int)copy.to_ulong());
    }
    Piece getPiece(){
        std::bitset<16> copy(value);
        copy <<= 9;
        copy >>= 9;
        return Piece((int)copy.to_ulong());
    }

    char* toString(){
        char* first = new char[2];
        if (getIsDrop()){
            Piece piece = getPiece();
            sprintf(first, "%s%s", piece.toString(), "*");
        }else{
            Address from = getFrom();
            first = from.toString();
        }
        Address to = getTo();
        bool isPro = getIsPromote();
        char* result = new char[5];
        sprintf(result, "%s%s%s", first, to.toString(), isPro ? "+" : "");
        return result;
    }
};

#endif