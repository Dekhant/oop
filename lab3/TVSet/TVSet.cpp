#include "CTVSet.h"

using namespace std;

int main()
{
	CTVSet* TV = new CTVSet();
	int choice = 0;
	while (choice != 6)
	{
		cout << "Turn on : 1" << endl;
		cout << "Turn off : 2" << endl;
		cout << "Select channel : 3" << endl;
		cout << "Get info : 4" << endl;
		cout << "Get previous channel : 5" << endl;
		cout << "Exit : 6" << endl;
		cin >> choice;
		if (choice == 1)
			TV->TurnOn();
		if (choice == 2)
			TV->TurnOff();
		if (choice == 3)
		{
			int channel;
			cout << "enter a channel: ";
			cin >> channel;
			TV->SelectChannel(channel);
		}
		if (choice == 4)
			TV->Info();
		if (choice == 5)
			TV->SelectPreviousChannel();
	}
}