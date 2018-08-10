#include <iostream>
#include "include/iai_implementation.h"

using namespace std;

int main(int argc, char *argv[]){
	// Default variable declarations
	string data_path = "/home/hunter/devel/misc/iai_interview/data/datalog-navigation.txt";

	// Allow commandline arguments to be passed in to dynamically change target text file path at runtime
	if(argc < 2){
		printf("INFO: Using default filepath: %s\r\n", data_path);
	}else if(argc == 2){
		data_path = argv[1];
		printf("INFO: Using custom defined filepath: %s\r\n", data_path);
	}

	// Initialize IAI text file object
	IaiFile inputFile(data_path);


	printf("Code Exit\n\r");
	return 0;
}
