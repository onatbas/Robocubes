//
// Created by Onat Bas on 07/01/17.
//

#ifndef BOXESGAME_CLICKHOLDER_HXX
#define BOXESGAME_CLICKHOLDER_HXX

#include "components/BoxPosition.hxx"

template<typename T>
class SingleDataHolder {
public:
    bool getClick(T &data) {
        data = this->data;
        bool result = isSet;
        isSet = false;
        return result;
    }

    SingleDataHolder() : isSet(false) {
    }

    void operator=(const T &rhs) {
        data = rhs;
        isSet = true;
    }

private:
    T data;
    bool isSet;
};

#endif //BOXESGAME_CLICKHOLDER_HXX
