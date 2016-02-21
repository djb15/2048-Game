/*
 * pointers.cpp
 *
 *  Created on: 21 Feb 2016
 *      Author: Dirk
 */


#include <iostream>
#include <fstream>
#define SIZE 128

using namespace std;

int main(){
	ifstream input_file;
	int numbers[SIZE];
	int temp;


	input_file.open("numbers.txt");
	int counter = 0;
	while (input_file >> temp){
		numbers[counter] = temp;
		counter ++;
	}

	int user_input;
	cout << "What number would you like to check?" << endl;
	cin >> user_input;
	bool check = false;
	for (int i = 0; i < SIZE - 1; i ++){
		if (numbers[i] == user_input && check == false){
			cout << "Your number is in the file on lines:" << endl;
			cout << i + 1 << endl;
			check = true;
		}
		else if (numbers[i] == user_input){
			cout << i + 1 << endl;
		}
	}

	return 0;

}

