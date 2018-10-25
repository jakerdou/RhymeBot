#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// NEED TO FIX OUTPUT OF RHYMES

int main() {

	using namespace std;
	string main;
	string lastLets;
	string Rhyme;
	ifstream Words;
	bool quit = false;
	int choice;
	char YorN;
	int j = 0;
	int k = 0;
	vector<string> saveWords;

	while (quit == false) {

		Words.clear();
		Words.open("C:\\Users\\James Robinson\\Documents\\AllWords.txt");
		
		cout << "What would you like to do?" << endl << endl;
		cout << "1 - Rhyme finder" << endl;
		cout << "2 - Rhyme finder with saved words" << endl;
		cout << "3 - Look at saved words" << endl;
		cout << "4 - Quit" << endl;
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1: 
			k = 1;

			cout << "What letters are at the end of the word? ";
			cin >> lastLets;

			while (getline(Words, Rhyme)) {
				int count = 0;
				for (int i = Rhyme.length() - lastLets.length(); i < Rhyme.length(); i++) { // need to find way to get length of vecotr
					if (Rhyme[i] == lastLets[i - (Rhyme.length() - lastLets.length())]) {
						count++;
					}
					else {
						break;
					}
					if (count == lastLets.length()) {
						cout << Rhyme << ", ";
						k++;
					}
					if (k % 7 < .01) {
						k++;
						cout << endl;
					}
				}
			}
			cout << endl;

			Words.close();

			cout << "Are there any words you'd like to save? (y/n) ";
			cin >> YorN;
			cout << endl;

			if (YorN == 'n') {
				break;
			}
			else if (YorN == 'y') {
				string saved;
				cout << "What words? (Enter '0' to stop entering)" << endl;
				while (saved != "0") {
					cin >> saved;
					if (saved != "0") {
						saveWords.push_back(saved);
					}
					else {
						break;
					}
				}
			}
			cout << endl;

			break;

		case 2:
			k = 1;

			cout << "Saved Words:" << endl;
			for (int i = 0; i < saveWords.size(); i++) {
				cout << saveWords[i] << " ";
				j++;
				if (j % 9 == 0) {
					cout << endl;
				}
			}
			cout << endl;


			cout << "What letters are at the end of the word? ";
			cin >> lastLets;

			while (getline(Words, Rhyme)) {
				int count = 0;
				for (int i = Rhyme.length() - lastLets.length(); i < Rhyme.length(); i++) { // need to find way to get length of vecotr
					if (Rhyme[i] == lastLets[i - (Rhyme.length() - lastLets.length())]) {
						count++;
					}
					else {
						break;
					}
					if (count == lastLets.length()) {
						cout << Rhyme << ", ";
						k++;
					}
					if (k % 7 < .01) {
						k++;
						cout << endl;
					}
				}
			}
			cout << endl;

			Words.close();

			cout << "Are there any words you'd like to save? (y/n) ";
			cin >> YorN;
			cout << endl;

			if (YorN == 'n') {
				break;
			}
			else if (YorN == 'y') {
				string saved;
				cout << "What words? (Enter '0' to stop entering)" << endl;
				while (saved != "0") {
					cin >> saved;
					if (saved != "0" || saved == "\0") {
						saveWords.push_back(saved);
					}
					else {
						break;
					}
				}
			}
			cout << endl;

			break;

		case 3:
			cout << "Saved Words:" << endl;
			for (int i = 0; i < saveWords.size(); i++) {
				cout << saveWords[i] << " ";
				j++;
				if (j % 9 == 0) {
					cout << endl;
				}
			}
			cout << endl;

			break;

		case 4:
			quit = true;
			break;
		}

	}

	Words.close(); 

	return 0; 
}