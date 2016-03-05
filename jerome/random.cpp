/*
 * random
 *
 *  Created on: 5 Mar 2016
 *      Author: Dirk
 */

/*
 * DynamicArray.cpp
 *
 *  Created on: 26 Feb 2016
 *      Author: Jerome
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


struct point {
	double x;
	double y;

	string str(){
		stringstream ss;
		ss << "(" << x << ", " << y << ") " ;
		return ss.str();
	}
};

int main() {

	string IPfilename;
	ifstream infileConfig ;
	cout << "Enter name of file: " << endl;
	cin >> IPfilename;
	infileConfig.open(IPfilename.c_str());
	if (!infileConfig.is_open()) {
			cout << "File not found" << endl;
			exit(EXIT_FAILURE);
		}


	int  size = 0;
	int  len = 2;
	point* pointArray ;
	point* auxArray ;
	pointArray = new point[len];

		while (!infileConfig.eof()){

		if (size == len){
			cout << "Resizing to " << len * 2 << endl;
			len = len * 2;
			auxArray = new point[len];
			for (int k = 0 ; k < size ; k++){
				cout << "Copy: aux (" << auxArray[k].x << "," << auxArray[k].y << ")" << endl;
				auxArray[k].x = pointArray[k].x;
				auxArray[k].y = pointArray[k].y;
				cout << "Copy: point (" << pointArray[k].x << "," << pointArray[k].y << ")" << endl;

			}
			cout << "Done with deep copy; swapping pointers." << endl;
			delete [] pointArray;
			pointArray = auxArray;
			}
		infileConfig >> pointArray[size].x >> pointArray[size].y ;
		cout << "Read new point: " << pointArray[size].x << " " << pointArray[size].y << endl;
		size++;
	}
		cout << "Finished; printing array...\n";
	for (int i = 0 ; i < size; i++){
		cout << pointArray[i].str() << endl;
	}

	cout << "Deleting auxArray..\n";
	delete[] auxArray;
	cout << "Closing infileConfig..\n";
	infileConfig.close();
	return 0;
}







