/*
 * dynamic.cpp
 *
 *  Created on: 27 Feb 2016
 *      Author: Dirk
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#define SIZE 128

using namespace std;

struct point{
	double x;
	double y;

	string str(){
		stringstream ss;
		ss << "(" << x << ", " << y << ")";
		return ss.str();
	}
};

int main (){
	ifstream inputfile;
	point temp;

	inputfile.open("input.txt");

	point* pointer;
	pointer = new point[SIZE];
	int count = 0;

	while (!inputfile.eof()){
		inputfile >> pointer[count].x >> pointer[count].y;
		count ++;
	}
	cout << count << endl;
	for (int i = 0; i < count; i++){
		cout << pointer[count].str() << endl;
	}

	inputfile.close();
	delete[] pointer;
	return 0;





}


