// iai_interface.h
#ifndef IAI_INTERFACE_H
#define IAI_INTERFACE_H

#include <string>

using namespace std;

/** ===========================================================================
*    This class should be used as an interface for any source used
* (i.e text file, serial port, etc.) for receiving a data stream for IAI.
* =========================================================================== */
class IaiInterface{
public:
     virtual ~IaiInterface();

     virtual int open() = 0;
     virtual int close() = 0;
     virtual void read() = 0;
};


#endif /** IAI_INTERFACE_H */
