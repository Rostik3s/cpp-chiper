#include <iostream>
#include <string>

using namespace std;

string vigenereEncrypt(string text, string key)
{
	int TxtLength = text.length();
	int KeyLength = key.length();

	string ChipperText;
	for (int i = 0; i < TxtLength; i++)
	{
		char currentChar = text[i];

		if (!isalpha(currentChar))
		{
			ChipperText += currentChar;
			continue;
		}

		currentChar = toupper(currentChar);
		int charCode = (int)currentChar;

		char CurrentKeyChar = key[i % KeyLength];
		int KeyIndex = toupper(CurrentKeyChar) - 'A';
		int KeyCode = KeyIndex;

		int shift = (charCode + KeyCode) % 26;
		char EncryptedChar = (char)('A' + shift);

		if (islower(text[i]))
		{
			ChipperText += tolower(EncryptedChar);
		}
		else
		{
			ChipperText += EncryptedChar;
		}
	}
	return ChipperText;
}

string vigenereDecrypt(string chipperText, string key)
{
	int TxtLength = chipperText.length();
	int KeyLength = key.length();

	string NonChipperText;
	for (int i = 0; i < TxtLength; i++)
	{
		char currentChar = chipperText[i];

		if (!isalpha(currentChar))
		{
			NonChipperText += currentChar;
			continue;
		}

		currentChar = toupper(currentChar);
		int charCode = (int)currentChar;

		char CurrentKeyChar = key[i % KeyLength];
		int KeyIndex = toupper(CurrentKeyChar) - 'A';
		int KeyCode = KeyIndex;

		int shift = (charCode - KeyCode + 26) % 26;
		char DecryptedChar = (char)('A' + shift);

		if (islower(chipperText[i]))
		{
			NonChipperText += tolower(DecryptedChar);
		}
		else
		{
			NonChipperText += DecryptedChar;
		}
	}
	return NonChipperText;
}

pair<string,string> input()
{
	string text, key;

	cout << "Enter a text: "; 
	getline(cin, text);
	cout << "Enter a key: ";
	getline(cin, key);
	cout<<endl;
	

	return make_pair(text,key);
}

int main()
{
	while (true)
	{
		bool check;
		short answer;
		
		cout << "\n1.Encrypt\n2.Decrypt\n3.Exit" << endl<<"what are you choosing?\n"; cin >> answer;
		cin.ignore(32767, '\n');

		if (answer == 1)
		{
			pair<string,string> input_text = input();
			string ChipperText=vigenereEncrypt(input_text.first,input_text.second);

			cout << ChipperText;
		}
		else if (answer == 2)
		{
			pair<string,string> input_text = input();
			string NonChipperText = vigenereDecrypt(input_text.first,input_text.second);
			cout << NonChipperText;
		}
		else if (answer == 3)
		{
			check = false;
			break;
		}
	}
	return 0;
}