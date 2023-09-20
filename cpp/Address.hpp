#ifndef ADDRESS_HPP
#define ADDRESS_HPP

class Address{
private:
public:
    int column; //アラビア数字の方
    int row; //漢数字の方
    Address(int c, int r){
        column = c;
        row = r;
    }

    static Address indexToAddress(int index){
        return Address(index % 11, index / 11);
    }
    static int addressToIndex(Address address){
        return address.row * 11 + address.column;
    }
};

#endif