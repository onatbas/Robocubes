//
// Created by Onat Bas on 01/01/17.
//

#ifndef BOXESGAME_BOXPOPPERTESTHELPERS_HXX
#define BOXESGAME_BOXPOPPERTESTHELPERS_HXX

#include <BoxStacker.hxx>
#include <StackSet.hxx>

Stack getallGreenStack()
{
	Stack s;
	BoxStacker stacker;
	s = stacker.stackOn(s, Box(GREEN));
	s = stacker.stackOn(s, Box(GREEN));
	s = stacker.stackOn(s, Box(GREEN));
	return s;
}



Stack getBlueGreenBlueStack()
{
	Stack s;
	BoxStacker stacker;
	s = stacker.stackOn(s, Box(BLUE));
	s = stacker.stackOn(s, Box(GREEN));
	s = stacker.stackOn(s, Box(BLUE));
	return s;
}

Stack getBlueBlueGreenBlueStack()
{
	Stack s;
	BoxStacker stacker;
	s = stacker.stackOn(s, Box(BLUE));
	s = stacker.stackOn(s, Box(BLUE));
	s = stacker.stackOn(s, Box(GREEN));
	s = stacker.stackOn(s, Box(BLUE));
	return s;
}


Stack get_3_Blue_5_Green_3_Blue_Stack()
{
	Stack s;
	BoxStacker stacker;
	for (int i=0;i<3;i++)
		s = stacker.stackOn(s, Box(BLUE));
	for (int i=0;i<5;i++)
		s = stacker.stackOn(s, Box(GREEN));
	for (int i=0;i<3;i++)
		s = stacker.stackOn(s, Box(BLUE));
	return s;
}

StackSet get_3_stacks_one_box_each()
{
	return StackSet();
}

StackSet get_4_stacks_bbrg()
{
	return StackSet();
}

#endif //BOXESGAME_BOXPOPPERTESTHELPERS_HXX
