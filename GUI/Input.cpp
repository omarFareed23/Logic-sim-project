//#include "Input.h"
#include "Output.h"
#include<iostream>

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
void Input::set_ifAddedGates(bool x){ AddedGates = x; }
void Input::set_ifFirst(bool x){ FirstGatesToolBar = x; }
bool Input::get_ifAddedGaets()const{ return AddedGates; }
bool Input::get_ifFirst()const{ return FirstGatesToolBar; }
string Input::GetSrting(Output *pOut)
{
	//(4) ==> we won't use cin here (expection)
	//we will find the function in CMUgraphics (may be windowinput.cpp)
	//all of us must read all files.h in CMU to know the function we have and call it if needed ==> very important
	
	///pOut->ClearStatusBar();
	char pressedButton = '\0';
	keytype kt;
	string word;
	while (true)
	{
		kt = pWind->WaitKeyPress(pressedButton);
		switch (kt)
		{
		case ASCII:
			if ((int)pressedButton == 13)
			{
				return word;
			}
			else if (pressedButton == '\b')
			{
				int size = word.size();
				word = size >= 1 ? word.substr(0, word.size() - 1) : word;
			}
			else
			{
				word += pressedButton;
			}
			break;
		/*case ARROW:
			break;
		case FUNCTION:
			break;*/
		case ESCAPE:
			return "";
			break;
		default:
			break;
		}
		pOut->PrintMsg(word);
	}
	
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar

	return word;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = ((x - ((UI.width - ITM_DSN_COUNT * UI.ToolItemWidth) / 2) / UI.ToolItemWidth));

			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADD_GATE:
				return ADD_GATE;
			case ITM_SIMULATE:
				return SIMULATE;
			case ITM_TOOLSI:
				return ADD_TOOLS;
			case ITM_ORGANIZE:
				return ORGANIZE;
			case ITM_LOADI:
				return LOAD;
			case ITM_SAVEI:
				return SAVE;
			case ITM_EXITI:
				return EXIT;
			default:
				return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (AddedGates)
			{
				if (y < UI.height - UI.StatusBarHeight - UI.ToolBarHeight)
					return SELECT;
				else
				{
					if (FirstGatesToolBar)
					{
						int ClickedItemOrder = ((x - ((UI.width - ITM_CNT_TOOL_BAR1 * UI.ToolItemWidth) / 2) / UI.ToolItemWidth));
						switch (ClickedItemOrder)
						{
						case ITM_BUFF:
							return ADD_Buff;
						case ITM_INV:
							return ADD_INV;
						case ITM_AND2:
							return ADD_AND_GATE_2;//AND gate item in menu
						case ITM_OR2:
							return ADD_OR_GATE_2;//OR gate item in menu
						case ITM_NAND2:
							return ADD_NAND_GATE_2;
						case ITM_NOR2:
							return ADD_NOR_GATE_2;
						case ITM_XOR2:
							return ADD_XOR_GATE_2;
						case ITM_XNOR2:
							return ADD_XNOR_GATE_2;
						case ITM_SCROLL:
							return ITM_SCROLL_1;
						default:
							return DSN_TOOL;
						}
					}
					else
					{
						int ClickedItemOrder = ((x - ((UI.width - ITM_CNT_TOOL_BAR2 * UI.ToolItemWidth) / 2) / UI.ToolItemWidth));
						switch (ClickedItemOrder)
						{
						case ITM_AND3:
							return ADD_AND_GATE_3;
						case ITM_NOR3:
							return ADD_NOR_GATE_3;
						case ITM_XOR3:
							return ADD_XOR_GATE_3;//AND gate item in menu
						case ITM_SWITCH:
							return ADD_Switch;//OR gate item in menu
						case ITM_LED:
							return ADD_LED;
						case ITM_CONNECTION:
							return ADD_CONNECTION;
						case ITM_EXIT:
							return EXIT_GATE_BAR;
						case ITM_SCROLL2:
							return ITM_SCROLL_2;
						default:
							return DSN_TOOL;
						}
					}
				}
			}
			else
			{
				return SELECT;
			}//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}
ActionType Input::GetUserAction(int &x , int &y) const
{
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = ((x - (UI.width - ITM_DSN_COUNT * UI.ToolItemWidth) / 2) / UI.ToolItemWidth);
			std::cout << x << ' ' << ClickedItemOrder << std::endl;
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADD_GATE:
				return ADD_GATE;
			case ITM_SIMULATE:
				return SIMULATE;
			case ITM_TOOLSI:
				return ADD_TOOLS;
			case ITM_ORGANIZE:
				return ORGANIZE;
			case ITM_LOADI:
				return LOAD;
			case ITM_SAVEI:
				return SAVE;
			case ITM_EXITI:
				return EXIT;
			default:
				return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (AddedGates)
			{
				if (y < UI.height - UI.StatusBarHeight - UI.ToolBarHeight)
					return SELECT;
				else
				{
					if (FirstGatesToolBar)
					{
						int ClickedItemOrder = ((x - ((UI.width - ITM_CNT_TOOL_BAR1 * UI.ToolItemWidth) / 2) / UI.ToolItemWidth));
						switch (ClickedItemOrder)
						{
						case ITM_BUFF:
							return ADD_Buff;
						case ITM_INV:
							return ADD_INV;
						case ITM_AND2:
							return ADD_AND_GATE_2;//AND gate item in menu
						case ITM_OR2:
							return ADD_OR_GATE_2;//OR gate item in menu
						case ITM_NAND2:
							return ADD_NAND_GATE_2;
						case ITM_NOR2:
							return ADD_NOR_GATE_2;
						case ITM_XOR2:
							return ADD_XOR_GATE_2;
						case ITM_XNOR2:
							return ADD_XNOR_GATE_2;
						case ITM_SCROLL:
							return ITM_SCROLL_1;
						default:
							return DSN_TOOL;
						}
					}
					else
					{
						int ClickedItemOrder = ((x - ((UI.width - ITM_CNT_TOOL_BAR2 * UI.ToolItemWidth) / 2) / UI.ToolItemWidth));
						switch (ClickedItemOrder)
						{
						case ITM_AND3:
							return ADD_AND_GATE_3;
						case ITM_NOR3:
							return ADD_NOR_GATE_3;
						case ITM_XOR3:
							return ADD_XOR_GATE_3;//AND gate item in menu
						case ITM_SWITCH:
							return ADD_Switch;//OR gate item in menu
						case ITM_LED:
							return ADD_LED;
						case ITM_CONNECTION:
							return ADD_CONNECTION;
						case ITM_EXIT:
							return EXIT_GATE_BAR;
						case ITM_SCROLL2:
							return ITM_SCROLL_2;
						default:
							return DSN_TOOL;
						}
					}
				}
			}
			else
			{
				int ClickedItemOrder = ((x - (UI.width - ITM_SIM_CNT * UI.ToolItemWidth) / 2) / UI.ToolItemWidth);
				//the rest will be added after sim mode
				return SELECT;
			}//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}

Input::~Input()
{
}


/*
 1- getString ==> fareed
 2- sim mode ==> after finishing sim toolbar
*/