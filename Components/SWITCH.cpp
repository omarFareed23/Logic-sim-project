#include "SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void SWITCH::Draw(Output* pOut)
{
	pOut->DrawSWITCH(m_GfxInfo);
}

void SWITCH::Operate()
{
	if (m_OutputPin.getStatus() == LOW)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}
}

int SWITCH::getOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int SWITCH::getInputPinStatus(int n)
{
	return -1;
}

void SWITCH::setInputPinStatus(int n, STATUS s)
{
	return;
}
