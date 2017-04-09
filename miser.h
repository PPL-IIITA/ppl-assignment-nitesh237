/**
 * CLASS MISER
 * inherits properties of class BOY
 * contains the attributes of miser BOYs
 */

#include "boy.h"
#include <string.h>
class miser : public boy {
public:
	miser(char *tname, int tattract, int tintel, int tbudget, int tattr_req) 
	{					//! initialises the values
		strcpy(name, tname);
		attract = tattract;
		intel  = tintel;
		budget = tbudget;
		attr_req = tattr_req;
		type = 1;
	}
};