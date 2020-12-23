#include "AddConnection.h"
#include "Actions\..\ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp) : Action(pApp) {}

AddConnection::~AddConnection()
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Connection : please choose output and input pen");
	pIn->GetPointClicked(x1, y1);
	pIn->GetPointClicked(x2, y2);
}
