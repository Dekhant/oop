#pragma once
#include <iostream> 

class CTVSet
{
public:
	CTVSet();
	bool TurnOn();
	bool TurnOff();
	bool SelectChannel(const int& channel);
	void Info();
	bool SelectPreviousChannel();
	int GetChannel();
private:
	bool state;
	int channel;
	int prevChannel;
};

