/**
 * CLASS LUXURY
 * containing detail about luxury gift
 */
#include "gift.h"
class luxury: public gift {
public:
	int luuxury; //!< Luxury Value of gift(out of 10)
	int difficulty; //!< Difficulty in obtaining gift(out of 10)
	luxury(int pr, int val, int lux, int diff)
	{			//! initialises the values
		type = 2;
		price = pr;
		value = val;
		luuxury = lux;
		difficulty = diff;
	}
};