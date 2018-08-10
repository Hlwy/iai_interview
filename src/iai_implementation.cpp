#include <string.h>
#include "include/iai_interface.h"

using namespace std;

class IaiFile : public IaiInterface{
private:
     const char* _path;
     string data;
public:
     // Constructors & Deconstructors
     IaiFile(const char* filepath);
     ~IaiFile();

     /** ----------------------------------------------------------------------
     *    Implement the IaiInterface functions specific for a text file source
     * ---------------------------------------------------------------------- */
     virtual int open();
     virtual int close();

     /** ------------------------------
     *    IaiFile specific functions
     * ------------------------------ */
     string read(IaiInterface source);
};
