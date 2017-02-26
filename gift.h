/**
 * CLASS GIFT
 * containing detail about all types of gifts
 */
#include "essential.h"
#include "luxury.h"
#include "utility.h"
class gift{
	public:
		int type;    //!< The type of gift((1)Essential, (2)Luxury, (3)Utility)
		essential e; //!< Essential gift
		luxury l;    //!< Luxury gift
		utility u;   //!< Utilty gift

};