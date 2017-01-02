//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_BOXPOPPERTESTHELPERS_HXX
#define BOXESGAME_BOXPOPPERTESTHELPERS_HXX

#include "../src/BoxStacker.hxx"
#include "../src/StackSet.hxx"

#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>

typedef boost::tokenizer<boost::char_separator<char> > tokenizer;

Stack getStackByCode(std::string colors)
{
	Stack s;
	BoxStacker stacker;
	for (char c : colors)
		switch (c)
		{
			case 'r': s = stacker.stackOn(s, RED);   break;
			case 'g': s = stacker.stackOn(s, GREEN); break;
			case 'b': s = stacker.stackOn(s, BLUE);  break;
		}
	return s;
}

StackSet getStackSetByCodeList(std::string colors) {
	StackSet set;
	boost::char_separator<char> sep(" ");
	tokenizer tokens(colors, sep);
	for (std::string s : tokens) {
		set.addStack(getStackByCode(s));
	}
	return set;
}
	

Stack getallGreenStack()
{
	return getStackByCode("ggg");
}

Stack getBlueGreenBlueStack()
{
	return getStackByCode("bgb");
}

Stack getBlueBlueGreenBlueStack()
{
	return getStackByCode("bbgb");
}


Stack get_3_Blue_5_Green_3_Blue_Stack()
{
	return getStackByCode("bbbgggggbbb");
}

Stack getSingleStack(Colors c)
{
	Stack s;
	BoxStacker stacker;
	return stacker.stackOn(s, Box(c));
}

StackSet get_3_stacks_one_box_each()
{
	StackSet set;
	for (int i=0; i<3; i++)
		set.addStack(getSingleStack(GREEN));
	return set;
}

StackSet get_4_stacks_bbrg()
{
	StackSet set;
	set.addStack(getSingleStack(BLUE));
	set.addStack(getSingleStack(BLUE));
	set.addStack(getSingleStack(RED));
	set.addStack(getSingleStack(GREEN));
	return set;
}

StackSet getGreenSquareStackSet()
{
	return getStackSetByCodeList("ggg gbg ggg");
}

#endif //BOXESGAME_BOXPOPPERTESTHELPERS_HXX
