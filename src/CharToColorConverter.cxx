//
// Created by Onat Bas on 07/01/17.
//

#include "CharToColorConverter.hxx"
#include "Colors.hxx"

Colors CharToColorConverter::convert(char choice) {
    switch (choice)
    {
        case 'r':
        case 'R':
            return RED;
        case 'g':
        case 'G':
            return GREEN;
        case 'b':
        case 'B':
        default:
            return BLUE;
    }
}
