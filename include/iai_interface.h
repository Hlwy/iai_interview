#ifndef IAI_INTERFACE_H
#define IAI_INTERFACE_H

/** ===========================================================================
*    This class should be used for interfacing with an unknown source stream
* (i.e text file, serial port, etc.) that is used to recieve some kind of data input.
* =========================================================================== */
class IaiInterface{
public:
	// Dummy Deconstructor
     virtual ~IaiInterface();

	/** 	@description: This function should perform the necessary steps needed for
	* initializing and opening a line of connection, or interactability, with an IAI data
	* source.
	*
	* 	@return: Should return a 0 upon successfully opening an IAI data source,
	* otherwise a negative int should be returned representing a specific ERROR code.
	*/
     virtual int open() = 0;

	/** 	@description: This function should perform the necessary steps needed for
	* closing a line of connection, or shutting down an IAI data source.
	*
	* 	@return: Should return a 0 upon successfully closing an IAI data source,
	* otherwise a negative int should be returned representing a specific ERROR code.
	*/
     virtual int close() = 0;

	/** 	@description: This function should execute the necessary methods for
	* reading/receiving data from the input source, storing the recieved data
	* (potentially different typed) within the derived class implementations
	*
	* 	@return: Should return a 0 upon successfully recieving IAI data from an IAI
	*  data source, otherwise a negative int should be returned representing a specific
	*  ERROR code.
	*/
	virtual int read() = 0;
};


#endif /** IAI_INTERFACE_H */
