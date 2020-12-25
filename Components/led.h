#pragma once
#include"Gate.h"
class led : public Gate
{
public:
	led(const GraphicsInfo &r_GfxInfo , int r_FanOut);
	void Draw(Output* pOut);
	int getInputPinStatus(int n);
	void setInputPinStatus(int n , STATUS s);
	int getOutputPinStatus();
};

