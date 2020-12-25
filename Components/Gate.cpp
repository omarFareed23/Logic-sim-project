#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	isConnected = new bool[r_Inputs];
	for (int i = 0; i < r_Inputs; i++) isConnected[i] = 0;
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

int Gate::getTheFirstUnconnectedPin()
{
	return 0;
}

bool Gate::ClickedHere(int x, int y)
{
	return false;
}

/*int Gate::getTheFirstUnconnectedPin()
{
	for (int i = 0; i < m_Inputs; i++)
	{
		if (!isConnected[i]) return i + 1;
	}
	return -1;
}*/

