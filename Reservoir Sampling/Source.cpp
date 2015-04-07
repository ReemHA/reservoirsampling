#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
using namespace std;


void createSample(ifstream& streamFile, unsigned int k){
	string line;
	int count = 1;
	vector <string> reservoir;
	unsigned int i;
	float j;
	vector<int>::const_iterator it;
	ostream_iterator <int> output(cout);
	
	
	if (streamFile.is_open()){
		for (i = 0; i < k; i++)
		{
			getline(streamFile, line);
			reservoir.insert(reservoir.begin(), line);
		}
		streamFile.close();
	}
	while(!streamFile.eof()){
		j = float(rand() % (i + 1));
		if (j < k){
			getline(streamFile, line);
			reservoir.insert(reservoir.begin() + (rand() % k), line);
		}
		i++;
	}
	streamFile.close();

	ofstream outputFile("Sample Data - result.txt");
	ostream_iterator <string> output_it(outputFile, " ");
	copy(reservoir.begin(), reservoir.end(), output_it);
	cout << "Sample file is successfully created" << endl;

};


int main(){
	int sampleSize;
	cout << "Enter your sample size value: ";
	cin >> sampleSize;
	cout << endl;
	while (sampleSize < 1){
		cout << "Error in sample size. Please try again: ";
		cin >> sampleSize;

	} 
		ifstream myFile("Stream Data.txt");
		createSample(myFile, sampleSize);

	system("pause");
	return 0;
}





