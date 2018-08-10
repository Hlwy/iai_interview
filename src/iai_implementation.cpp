#include "iai_implementation.h"
#include <iostream>

using namespace std;

IaiFile::IaiFile(string filepath){
	this->_path = filepath;
	this->open();
}

/**
* @description: Close file upon deconstruction
*/
IaiFile::~IaiFile(){
	this->close();
}

/**
* @description: Attempt to open target data source text file
*/
int IaiFile::open(){
	// Attempt to open specified text file
	this->_file.open(this->_path.c_str());
	// If stream appears to be good then store stream handle internally
	if(this->_file.good()){
		printf("INFO: Successfully opened the text file, %s!\r\n", this->_path.c_str());
	} else{
		printf("ERROR: Could not open the text file, %s!\r\n", this->_path.c_str());
		return -1;
	}
	return 0;
}

/**
* @description: Be sure to close the data source text file
*/
int IaiFile::close(){
	printf("WARNING: About to close the text file '%s'!\r\n", this->_path.c_str());
	this->_file.close();
	return 0;
}

/**
* @description: Read in every line from a text file. Functionality of this can change depending on specific needs.
*/
int IaiFile::read(){
	// Empty declaration of temp string variable for storing data read in from text file
	string tmpData;

	// Check to make sure text file is open before attempting to read in data
	if(this->_file.is_open()){
		// Read in a single line from text file
		while(getline(this->_file, tmpData)){
			// Store received data internally somehow (either single line, vector of all lines, etc.)
			this->_data.push_back(tmpData);
		}
		printf("----------\r\nINFO: Finished reading file.\r\n");
	} else{
		printf("ERROR: %s file is not opened\r\n", this->_path.c_str());
		return -2;
	}
	return 0;
}

/**
* @description: Do nothing for now
*/
int IaiFile::read(){
	return 0;
}


vector<string> IaiFile::getReceivedData(bool verbose){
	// Print out all the lines read in from file if
	if(verbose){
		int n = this->_data.size();
		for(int i = 0;i<n;i++){
	          cout << this->_data.at(i) << ", ";
	     }
	     cout << endl;
	}
	return this->_data;
}

void IaiFile::setFilepath(const string &filepath){ this->_path = filepath;}
