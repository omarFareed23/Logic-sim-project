 #pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "UI_Info.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;   //Pointer to the Graphics Window
	bool FirstGatesToolBar;
	bool AddedGates;	
public:
	Input(window*);
	void set_ifAddedGates(bool x);
	void set_ifFirst(bool x);
	bool get_ifAddedGaets() const;
	bool get_ifFirst() const;
	void GetPointClicked(int &, int &);	//Get coordinate where user clicks
	string GetSrting(Output*);		//Returns a string entered by the user

	ActionType GetUserAction() const; //Reads the user click and maps it to an action
	ActionType GetUserAction(int &x ,int &y) const;
	~Input();
};
