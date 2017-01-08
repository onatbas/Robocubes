//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_SCORECOMPONENT_HXX
#define BOXESGAME_SCORECOMPONENT_HXX

#include <string>

class TTFText {
public:
    TTFText(std::string text);
    std::string getText() const;
    void setText(std::string text);

private:
    std::string text;
};

#endif //BOXESGAME_SCORECOMPONENT_HXX
