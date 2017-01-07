//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_CLICKHOLDER_HXX
#define BOXESGAME_CLICKHOLDER_HXX

#include "BoxPosition.hxx"

template <typename T>
class SingleDataHolder {
public:
    bool getClick(T &data){
        data = this->data;
        bool result = isSet;
        isSet = false;
        return result;
    }
    SingleDataHolder()  : isSet(false), data(T(0,0)) {}
    void operator=(const T &rhs){
        data = rhs;
        isSet = true;
    }


private:
    T data;
    bool isSet;
};

#endif //BOXESGAME_CLICKHOLDER_HXX
