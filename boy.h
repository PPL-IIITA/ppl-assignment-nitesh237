/**
 * CLASS BOY 
 * containing the attributes of all boys
 */
class boy {
	public:
		bool commited;  //!< Status of BOY
		char name[10];	//!< Name of BOY
		int attract;	//!< Attraction level of BOY(out of 50)
		int intel;		//!< Intelligence level of BOY(out of 50)
		int budget;		//!< Budget of BOY
		int attr_req;	//!< Attraction req of BOY(out of 50)
		int type;		//!< TYPE of BOY ((1)MISER,(2)GENEROUS,(3)GEEKS)
		
		boy()			
		{				//! Initially all BOYs are set to single
			commited = false;
		}
};