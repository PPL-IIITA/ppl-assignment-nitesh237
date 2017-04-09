/**
 * CLASS ESSENTIAL
 * inherits class GIFT
 * containing detail about essential gift
 */
#include "gift.h"
class essential: public gift {
public:
	essential(int pr, int val)
	{						//! Initialises the values 
		type = 1;
		price = pr;
		value = val;
	}
};