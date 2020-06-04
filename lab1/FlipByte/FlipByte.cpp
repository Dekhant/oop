#include <iostream>
#include <string>
using namespace std;

const int Byte = 8;
const int Number_System = 10;

unsigned char Flipbyte(unsigned char* inputNumber) {
	unsigned char flippedNumber = 0;
	for (int j = 0; j != Byte; j++, *inputNumber >>= 1) {
		unsigned char transfer = *inputNumber;
		transfer = transfer << (Byte - 1);
		transfer = transfer >> j;
		flippedNumber = flippedNumber | transfer;
	}
	return flippedNumber;
}

bool Check(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Invalid agruments count" << endl;;
		cout << "Usage Flipbyte.exe <number>(0-255)" << endl;
		return false;
	}
	return true;
}

bool Converting(const char *strNum, unsigned char *byte)
{
	if (!isdigit(*strNum))
	{
		return false;
	}
	char* End = NULL;
	int tempNum = strtol(strNum, &End, Number_System);
	if (tempNum == 0 && (*strNum == '\0' || *End != '\0'))
	{
		return false;
	}
	if (tempNum >= 0 && tempNum <= 255)
	{
		*byte = (unsigned char)tempNum;
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char* argv[])
{
	if (!Check(argc, argv))
	{
		return 1;
	}
	unsigned char inputNumber;
	if (!Converting(argv[1], &inputNumber))
	{
		cout << "Invalid first argument" << endl;
		return 1;
	}
	unsigned char flippedNumber = Flipbyte(&inputNumber);
	cout << (int)flippedNumber << endl;
	return 0;
}