/*
 * morepointers.cpp
 *
 *  Created on: 23 Feb 2016
 *      Author: Dirk
 */


#include <iostream>
#include <string>
#include <sstream>
#define SIZE 128

using namespace std;

struct point{
	double x, y;

	string str(){
		stringstream ss;
		ss << "(" << x << ", " << y << ")";
		return ss.str();
	}
};

void reversepointsar (point in[], int size, point out[]);

int main(){
	point arp[SIZE], arp2[SIZE];
	point tmpp;
	int i = 0, arpsize = 0;

	do{
		cin >> tmpp.x >> tmpp.y;
		arp[i] = tmpp;
		i ++;
	}while (! ((tmpp.x == 0) && (tmpp.y == 0)));

	arpsize = i;

	reversepointsar(arp, arpsize, arp2);
	cout << "You entered the following points:" << endl;

	for (int i = 0; i < arpsize; i++){
		cout << arp[i].str() << endl;
	}

	cout << "That in reversed order are:" << endl;



}
