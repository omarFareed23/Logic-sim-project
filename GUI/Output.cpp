#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}
const int Design_Bar_X = (UI.width - (ITM_DSN_COUNT * UI.ToolItemWidth)) / 2; // Design toolbar x
const int gate1_x1 = (UI.width - ITM_CNT_TOOL_BAR1 * UI.ToolItemWidth) / 2; // Gate1 x
const int gate1_x2 = (UI.width - (ITM_CNT_TOOL_BAR2 * UI.ToolItemWidth)) / 2; // Gate1 x
const int tools_x = (UI.width - (ITM_TOOL_CNT * UI.ToolItemWidth)) / 2; // tools x
const int Design_Bar_Y = UI.ToolBarHeight; // toolbarheight
const int height = UI.height - UI.ToolBarHeight - UI.StatusBarHeight;

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
void Output::printMsgOnDrawingArea(string msg, int xi, int yi)
{
	ClearStatusBar();
	ClearDrawingArea();
	pWind->SetFont(50, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(xi, yi , msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item

	//TODO: Prepare image for each menu item and add it to the list
	//(1) //images ==> not easy you have to make some photos yourself(if you didn't find it in google)

	//Draw menu item one image at a time
	/*for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);
		*/string MenuItemImages[ITM_DSN_COUNT];
	MenuItemImages[ITM_ADD_GATE] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_SIMULATE] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_TOOLSI] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_ORGANIZE] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_LOADI] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_SAVEI] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_EXITI] = "images\\Menu\\save.jpg";
	for (int i = 0; i < ITM_DSN_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth + Design_Bar_X, 0, UI.ToolItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_SIM] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_TOOLS] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_ORGANIZE] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_LOAD_SIM] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_SAVE_SIM] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_EXIT_SIM] = "images\\Menu\\save.jpg";
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth + Design_Bar_X, 0, UI.ToolItemWidth, UI.ToolBarHeight);

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//
void Output::CreateGatesToolBar(bool selected) const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	if (selected)
	{
		string MenuItemImages[ITM_CNT_TOOL_BAR1];
		MenuItemImages[ITM_BUFF] = "images\\inactive\\save.jpg";
		MenuItemImages[ITM_INV] = "images\\inactive\\save.jpg";
		MenuItemImages[ITM_AND2] = "images\\inactive\\save.jpg";
		MenuItemImages[ITM_OR2] = "images\\inactive\\save.jpg";
		MenuItemImages[ITM_NAND2] = "images\\inactive\\save.jpg";
		MenuItemImages[ITM_NOR2] = "images\\inactive\\save.jpg";
		MenuItemImages[ITM_XOR2] = "images\\inactive\\save.jpg";
		MenuItemImages[ITM_XNOR2] = "images\\inactive\\save.jpg";
		MenuItemImages[ITM_SCROLL] = "images\\inactive\\save.jpg";

		//TODO: Prepare image for each menu item and add it to the list

		//Draw menu item one image at a time
		for (int i = 0; i < ITM_CNT_TOOL_BAR1; i++)
			pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth + gate1_x1, height, UI.ToolItemWidth, UI.ToolBarHeight);
	}

	else
	{
		string Gates2[ITM_CNT_TOOL_BAR2];
		//Gates2[ITM_XNOR2] = "images\\inactive\\xnor.jpg";
		Gates2[ITM_AND3] = "images\\Menu\\save.jpg";
		Gates2[ITM_NOR3] = "images\\Menu\\save.jpg";
		Gates2[ITM_XOR3] = "images\\Menu\\save.jpg";
		Gates2[ITM_SWITCH] = "images\\Menu\\save.jpg";
		Gates2[ITM_LED] = "images\\Menu\\save.jpg";
		Gates2[ITM_SCROLL2] = "images\\Menu\\save.jpg";
		Gates2[ITM_EXIT] = "images\\Menu\\save.jpg";
		Gates2[ITM_CONNECTION] = "images\\Menu\\save.jpg";
		//TODO: Prepare image for each menu item and add it to the list

		//Draw menu item one image at a time
		for (int i = 0; i < ITM_CNT_TOOL_BAR2; i++)
			pWind->DrawImage(Gates2[i], i * UI.ToolItemWidth + gate1_x2, height, UI.ToolItemWidth, UI.ToolBarHeight);

	}
}
void Output::CreateToolsToolBar() const
{
	UI.AppMode = DESIGN;	//Simulation Mode
	string MenuItemImages[ITM_TOOL_CNT];
	MenuItemImages[ITM_LABEL] = "images\\Menu\\ANd2.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\redo.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\delete.jpg";
	MenuItemImages[ITM_WIRE] = "images\\Menu\\ANd2.jpg";
	MenuItemImages[ITM_PROBE] = "images\\Menu\\ANd2.jpg";
	for (int i = 0; i < ITM_TOOL_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth + tools_x, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
}
void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\and.jpg";
	else
		GateImage = "Images\\active\\and.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\or.jpg";
	else
		GateImage = "Images\\active\\or.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by OR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\nand.jpg";
	else
		GateImage = "Images\\active\\nand.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NAND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\not.jpg";
	else
		GateImage = "Images\\active\\not.jpg";

	//Draw INV Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by INV Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\xor.jpg";
	else
		GateImage = "Images\\active\\xor.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\xnor.jpg";
	else
		GateImage = "Images\\active\\xnor.jpg";

	//Draw XNOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XNOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\nor.jpg";
	else
		GateImage = "Images\\active\\nor.jpg";

	//Draw NOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\switch.jpg";
	else
		GateImage = "Images\\active\\switch.jpg";

	//Draw SWITCH Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by SWITCH Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\led.jpg";
	else
		GateImage = "Images\\active\\led.jpg";

	//Draw LED Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by LED Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\and3.jpg";
	else
		GateImage = "Images\\active\\and3.jpg";

	//Draw AND3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\nor3.jpg";
	else
		GateImage = "Images\\active\\nor3.jpg";

	//Draw NOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\xor3.jpg";
	else
		GateImage = "Images\\active\\xor3.jpg";

	//Draw XOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawBUFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\highlighted\\buffer.jpg";
	else
		GateImage = "Images\\active\\buffer.jpg";

	//Draw BUFFER Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by BUFFER Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
//TODO: Add similar functions to draw all components

//TODO: Add similar functions to draw all components


//(2) ==> search for images and the code is nearly the same as above
// a selected image is the same photo with a highlight

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	const int minPixels = 5;
	pWind->SetPen(BLACK, 1);
	if (r_GfxInfo.x1 == r_GfxInfo.x2 || r_GfxInfo.y1 == r_GfxInfo.y2)
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
	else
	{
		int min_x = (r_GfxInfo.x1 < r_GfxInfo.x2) ? r_GfxInfo.x1 : r_GfxInfo.x2;
		int max_x = r_GfxInfo.x1 + r_GfxInfo.x2 - min_x;
		if (max_x - min_x >= minPixels){
			pWind->DrawLine(min_x, r_GfxInfo.y1, max_x - minPixels, r_GfxInfo.y1);
			pWind->DrawLine(max_x - minPixels, r_GfxInfo.y1, max_x - minPixels, r_GfxInfo.y2);
			pWind->DrawLine(max_x - minPixels, r_GfxInfo.y2, max_x, r_GfxInfo.y2);
		}
		else
		{
			pWind->DrawLine(min_x, r_GfxInfo.y1, max_x, r_GfxInfo.y1);
			pWind->DrawLine(max_x , r_GfxInfo.y1, max_x , r_GfxInfo.y2);
		}
	}
	//TODO: Add code to draw connection
	// (4)
}

void Output::DrawGate(ActionType Act, GraphicsInfo GInfo)
{
	switch (Act)
	{
	case ADD_Buff:
		DrawBUFF(GInfo);
		PrintMsg("Buffer gate has been drawn");
		break;

	case ADD_INV:
		DrawINV(GInfo);
		PrintMsg("Inverter gate has been drawn");
		break;

	case ADD_AND_GATE_2:
		DrawAND2(GInfo);
		PrintMsg("AND-2 gate has been drawn");
		break;

	case ADD_NAND_GATE_2:
		DrawNAND2(GInfo);
		PrintMsg("NAND-2 gate has been drawn");
		break;

	case ADD_OR_GATE_2:
		DrawOR2(GInfo);
		PrintMsg("OR-2 gate has been drawn");
		break;

	case ADD_NOR_GATE_2:
		DrawNOR2(GInfo);
		PrintMsg("NOR-2 gate has been drawn");
		break;

	case ADD_XOR_GATE_2:
		DrawXOR2(GInfo);
		PrintMsg("XOR-2 gate has been drawn");
		break;

	case ADD_XNOR_GATE_2:
		DrawXNOR2(GInfo);
		PrintMsg("XNOR-2 gate has been drawn");
		break;
	case ADD_AND_GATE_3:
		DrawAND3(GInfo);
		PrintMsg("AND-3 gate has been drawn");
		break;
	case ADD_NOR_GATE_3:
		DrawNOR3(GInfo);
		PrintMsg("NOR-3 gate has been drawn");
		break;
	case ADD_XOR_GATE_3:
		DrawXOR3(GInfo);
		PrintMsg("XOR-3 gate has been drawn");
		break;
	/*case ADD_NAND_GATE_3:
		DrawNAND3(GInfo);
		PrintMsg("NAND-3 gate has been drawn");
	case ADD_OR_GATE_3:
		DrawOR3(GInfo);
		PrintMsg("OR-3 gate has been drawn");
	case ADD_XNOR_GATE_3:
		DrawXNOR3(GInfo);
	/*case ADD_CONNECTION:
		int tempX2, tempY2;
		getUsetActio
		PrintMsg("XNOR-3 gate has been drawn");*/
	default:
		break;
	}
}
Output::~Output()
{
	delete pWind;
}
/*
 1- create sim bar // fareed and asaad
 2- draw connection 
 3- drawing gates // lotfy and hamdy
 4- create design toolbar // lotfy and hamdy
*/