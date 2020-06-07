#include "CTVSet.h"

using namespace std;

CTVSet:: CTVSet()
{
	CTVSet::state = false;
	CTVSet::channel = 0;
	CTVSet::prevChannel = 0;
}

bool CTVSet::TurnOn()
{
	if (CTVSet::state == false && CTVSet::channel == 0 && CTVSet::prevChannel == 0)
	{
		CTVSet::state = true;
		CTVSet::channel = 1;
		return true;
	}
	if (CTVSet::state == false)
	{
		CTVSet::state = true;
		CTVSet::channel = CTVSet::prevChannel;
		CTVSet::prevChannel = 0;
		return true;
	}
		cout << "TV alreadey turned on" << endl;
		return false;
}

bool CTVSet::TurnOff()
{
	if (CTVSet::state == true)
	{
		CTVSet::state = false;
		CTVSet::prevChannel = CTVSet::channel;
		CTVSet::channel = 0;
		return true;
	}
	cout << "TV already turned off" << endl;
	return false;
}

bool CTVSet::SelectChannel(const int& channel)
{
	if (CTVSet::state == true)
	{
		if (channel > 0 && channel < 100)
		{
			CTVSet::prevChannel = CTVSet::channel;
			CTVSet::channel = channel;
			return true;
		}
		else
		{
			cout << "Channel out of range" << endl;
			return false;
		}
	}
	else
	{
		cout << "TV is turned off" << endl;
		return false;
	}
}

void CTVSet::Info()
{
	if (CTVSet::state == false)
	{
		cout << "TV is turned off" << "Channel is " << CTVSet::prevChannel << endl;
	}
	else
	{
		cout << "TV is turned on" << endl << "Channel is " << CTVSet::channel << endl;
	}
}

bool CTVSet::SelectPreviousChannel()
{
	if (CTVSet::state == true)
	{
		if (CTVSet::prevChannel != 0)
		{
			int store;
			store = CTVSet::channel;
			CTVSet::channel = CTVSet::prevChannel;
			CTVSet::prevChannel = store;
			return true;
		}
		else
		{
			cout << "Previous channel is not available" << endl;
			return false;
		}
	}
	else
	{
		cout << "TV is turned off" << endl;
		return false;
	}
}

int CTVSet::GetChannel()
{
	return CTVSet::channel;
}