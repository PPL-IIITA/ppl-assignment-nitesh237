/**
 * CLASS NORMAL
 * inherits properties of class GIRL 
 * contains the attributes of normal GIRLs
 */
#include "girl.h"
class normal:public girl {
	public:
		normal(char *tname, int tattract, int tintel, int tmaintainance, int tchoice) 
		{			//! initialises the values
			type = 2;
			strcpy(name, tname);
			attract = tattract;
			intel = tintel;
			maintainance = tmaintainance;
			choice = tchoice;
		}
};