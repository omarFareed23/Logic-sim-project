#pragma once
#include "..\Defs.h"
#include "Input.h"
class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void CreateToolsToolBar() const;
	void CreateGatesToolBar(bool selected) const;
/*	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window
	void CreateDesignToolBar() const;	//Tool bar of the first design
	void CreateGateToolBar1() const;	//Gate tool bar page 1
	void CreateGateToolBar2() const;	//Gate tool bar page 2
	void CreateToolsToolbar() const;    //tools tool bar
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar
	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area*/
	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window*/

	
	// Draws 2-input AND gate
	void DrawBUFF(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawINV(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawLED(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected = false) const;
/*	void DrawNAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;*/
	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc

	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;
	//to add any gate
	void DrawGate(ActionType Act, GraphicsInfo GInfo );
	void PrintMsg(string msg) const; 	//Print a message on Status bar
	void printMsgOnDrawingArea(string msg, int xi, int yi);
	~Output();
};
