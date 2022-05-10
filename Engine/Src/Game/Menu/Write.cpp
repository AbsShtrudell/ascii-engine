#include "Write.h"

Write::Write()
{
	text = new Text(L"", 159);
	AttachChild(text);
}

Write::~Write()
{
	delete text;
}

void Write::OnKeyUp(int key)
{
	if (!end)
	{
		switch (key)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			text->AddSymbol(key);
			break;
		case 8: //backspace
			text->RemoveLastSymbol();
			break;
		case 13: //enter  
			end = true;
			onEndWrite.Call(text->getText());
			break;
		}
	}
}

void Write::Clear()
{
	text->setText(L"");
}

void Write::setWriteState(bool value)
{
	this->end = !value;
}

bool Write::getWriteState()
{
	return end;
}
