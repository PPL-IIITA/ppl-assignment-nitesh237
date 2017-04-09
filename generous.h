/**
 * CLASS GENEROUS
 * inherits properties of class BOY
 * contains the attributes of generous BOYs
 */
#include "boy.h"
#include <string.h>
class generous: public boy {
public:
	generous(char *tname, int tattract, int tintel, int tbudget, int tattr_req) 
	{			//! Initialises the values 
		strcpy(name, tname);
		attract = tattract;
		intel  = tintel;
		budget = tbudget;
		attr_req = tattr_req;
		type = 2;
	}
};