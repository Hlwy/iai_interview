#ifndef IAI_IMPLEMENTATION_H
#define IAI_IMPLEMENTATION_H

#include <string.h>
#include <fstream> 		// For: ifstream
#include "include/iai_interface.h"

using namespace std;

/** ================================================================================
*    This class implements the IaiInterface class specifically for text file input
* ================================================================================ */
class IaiFile : public IaiInterface{
private:
     string _path;		// OS filepath of text file used for input
     string _data;		// Storage of implementation specific typed data
	ifstream _file;	// The file handle for the established data source
public:
     // Constructors & Deconstructors
     IaiFile(const string &filepath);
     ~IaiFile();

     /** ----------------------------------------------------------------------
     *    	Implement the IaiInterface functions for a text file source
     * ---------------------------------------------------------------------- */
     virtual int open();
     virtual int close();
     virtual int read();

     /** ------------------------
     *    	Getters
     * ------------------------- */
     string getReceivedData(bool verbose = true);

	/** ------------------------
     *    	Setters
     * ------------------------- */
	void setFilepath(const string &filepath);
};
#endif /** IAI_IMPLEMENTATION_H */
