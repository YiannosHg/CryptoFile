#include <iostream>
#include <stdlib.h>
#include<fstream>
#include <cstring> 

using namespace std;

int showMenu();
void encrypt(int k, int l, char w[]);
void decrypt(int k, int l, char w[]);

int main()
{
	int key, len, choice;
	char word[50];
	fstream inFile, outFile;

	do {
		choice = showMenu();

		if (1 == choice)
		{
			inFile.open("decrypted.txt", ios::in);
			if (inFile.fail())
			{
				cout << "File does not exist\n";
			}
			else
			{
				inFile.getline(word, 50);
				inFile.close();
				len = strlen(word);
				cout << "\nEnter value of key: ";
				cin >> key;
			}
			encrypt(key, len, word);
			outFile.open("encrypted.txt", ios::out);
			outFile << word;
			outFile.close();
		}
		else if (2 == choice)
		{
			inFile.open("encrypted.txt", ios::in);
			if (inFile.fail())
			{
				cout << "File does not exist\n";
			}
			else
			{
				inFile.getline(word, 50);
				inFile.close();
				len = strlen(word);
				cout << "\nEnter value of key: ";
				cin >> key;
			}
			decrypt(key, len, word);
			outFile.open("decrypted.txt", ios::out);
			outFile << word;
			outFile.close();
		}

	} while (choice != 3);
}

int showMenu()
{
	int ch;

	cout << "\nMenu choices";
	cout << "\n1.Encrypt";
	cout << "\n2.Decrypt";
	cout << "\n3.Exit";
	cout << "\nChoice: ";
	cin >> ch;

	if (ch < 1 || ch > 3)
	{
		cout << "\nYour choice is not valid\n";
	}
	return ch;
}

void encrypt(int k, int l, char w[])
{
	cout << endl << w << endl;
	for (int i = 0; i < l; ++i)
	{
		if (int(w[i]) > 64 && int(w[i]) < 91) // A-Z
		{
			w[i] = char((int(w[i]) + k));
			cout << w[i] << " = " << int(w[i]) << endl; //debuging

			if (int(w[i]) > 90) // bigger than Z
			{
				w[i] = char((int(w[i]) % 90) + 64);
				cout << "New: " << w[i] << " = " << int(w[i]) << endl; //debuging	
			}
		}
		else if (int(w[i]) > 96 && int(w[i]) < 123) // a-z
		{
			w[i] = char((int(w[i]) + k));
			cout << w[i] << " = " << int(w[i]) << endl; //debuging

			if (int(w[i]) > 122) // bigger than z
			{
				w[i] = char((int(w[i]) % 122) + 96);
				cout << "New: " << w[i] << " = " << int(w[i]) << endl; //debuging	
			}
		}
	}
	cout << w << endl; //encrypted
}

void decrypt(int k, int l, char w[])
{
	cout << endl << w << endl;
	for (int i = 0; i < l; ++i)
	{
		if (int(w[i]) > 64 && int(w[i]) < 91) //A-Z
		{
			w[i] = char((int(w[i]) - k));

			if (int(w[i]) < 65) //smaller than A
			{
				w[i] = char(int(w[i]) + 26);
			}
		}
		else if (int(w[i]) > 96 && int(w[i]) < 123) //a-z
		{
			w[i] = char((int(w[i]) - k));

			if (int(w[i]) < 97) //smaller than a
			{
				w[i] = char(int(w[i]) + 26);
			}
		}
	}
	cout << w << endl; //decrypted
}
