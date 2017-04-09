/**
 * CLASS DESPARATE
 * inherits properties of class GIRL 
 * contains the attributes of desparate GIRLS
 */
#include "girl.h"
class desparate:public girl {
	public:
		desparate(char *tname, int tattract, int tintel, int tmaintainance, int tchoice) 
		{											//! Initialises the values  
			type = 3;
			strcpy(name, tname);
			attract = tattract;
			intel = tintel;
			maintainance = tmaintainance;
			choice = tchoice;
		}

};