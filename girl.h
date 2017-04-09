/**
 * CLASS GIRL
 * contains the attributes of all GIRLs
 */
#ifndef GIRL.H_INCLUDED
#define GIRL.H_INCLUDED
class girl {
	public:
		bool commited;			//!< Status of GIRL
		char name[10];			//!< Name of GIRL
		int attract;			//!< Attraction level of GIRL(out of 50)
		int intel;				//!< Intelligence level of GIRL(out of 50)
		int maintainance;		//!< Maintainance of GIRL
		int type;				//!< TYPE of GIRL ((1)CHOOSY,(2)NORMAL,(3)DESPARATE)
		int choice;				//!< Requirement of GIRL ((1)Most Attractive, (2)Most Rich, (3)Most Intelligent)
		girl() 					
		{						//! Initially all GIRLs are set to single
			commited = false;
		}
};
#endif