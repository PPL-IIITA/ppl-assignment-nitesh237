/**
 * CLASS CHOOSY
 * inherits properties of class GIRL 
 * contains the attributes of choosy GIRLs
 */
#include "girl.h"
#include <string.h>
class choosy:public girl {
	public:
		choosy(char *tname, int tattract, int tintel, int tmaintainance, int tchoice) 
		{															//! Initialises the values 
			type = 1;
			strcpy(name, tname);
			attract = tattract;
			intel = tintel;
			maintainance = tmaintainance;
			choice = tchoice;
		}

};