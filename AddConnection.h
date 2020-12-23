#pragma once
#include "Actions/action.h"
#include "Actions/../Components\AND2.h"
class AddConnection : public Action
{
private:
	int x1, x2, y1, y2;
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection();
	virtual void ReadActionParameters();
	//virtual void Execute();
	//virtual void Undo();
	//virtual void Redo();
};

