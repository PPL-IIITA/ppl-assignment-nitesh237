/**
 * CLASS GEEK
 * inherits properties of class BOY
 * contains the attributes of geek BOYs
 */
#include "boy.h"
#include <string.h>
class geek : public boy {
	public:
	geek(char *tname, int tattract, int tintel, int tbudget, int tattr_req) 
	{														//! Initialises the values 
		strcpy(name, tname);
		attract = tattract;
		intel  = tintel;
		budget = tbudget;
		attr_req = tattr_req;
		type = 3;
	}
};
