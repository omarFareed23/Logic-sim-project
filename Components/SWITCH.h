#pragma once
#include "Gate.h"

class SWITCH :public Gate
{
public:
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	void Operate();
	virtual int getOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int getInputPinStatus(int n);
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

