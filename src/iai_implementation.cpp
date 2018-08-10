#include <iostream>
#include "include/iai_implementation.h"

using namespace std;

IaiFile::IaiFile(const string &filepath){
	this->_path = filepath;
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
	ifstream tmpFile(this->_path.c_str());
	// If stream appears to be good then store stream handle internally
	if(tmpFile.good()){
		this->_file = tmpFile;
	} else{
		printf("ERROR: Could not open the text file, %s!\r\n", this->_path);
		return -1;
	}
	return 0;
}

/**
* @description: Be sure to close the data source text file
*/
int IaiFile::close(){
	printf("WARNING: Closing text file '%s'!\r\n", this->_path);
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
		if(getline(this->_file, tmpData)){
			// Store received data internally
			this->_data = tmpData;
			printf("INFO: Successfully read line of text file %s.\r\n",this->_path);
		} else{
			printf("INFO: Could not read any more\r\n");
			return -3;
		}
	} else{
		printf("ERROR: %s file is not opened\r\n", this->_path);
		return -2;
	}
	return 0;
}


string IaiFile::getReceivedData(bool verbose){
	if(verbose) printf("INFO: Currently stored data: %s\r\n",this->_data);
	return this->_data;
}

void setFilepath(const string &filepath){ this->_path = filepath;}
