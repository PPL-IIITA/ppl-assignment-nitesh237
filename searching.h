/**
* CLASS SEARCHING
* inherits matching class
* implements the various searching algorithms for a given list of boys
*/
#ifndef SEARCHING.H_INCLUDED
#define SEARCHING.H_INCLUDED
#include "matching.h"
class searching : public matching {
public:
	void search(char **names, int n); //!< search for the girlfriends of the commited boys	
};
#endif