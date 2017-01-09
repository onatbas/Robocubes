//
// Created by Onat Bas on 08/01/17.
//

#include "TTFText.hxx"

TTFText::TTFText(std::string text) : text(text) {
}

std::string TTFText::getText() const {
    return text;
}

void TTFText::setText(std::string text) {
    this->text = text;
}
