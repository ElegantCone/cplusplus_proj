#include "Trit.h"

Trit operator&(Trit a, Trit b) {

	if (a == Trit::False || b == Trit::False)
		return Trit::False;
	else if (a == Trit::True && b == Trit::True)
		return Trit::True;
	else
		return Trit::Unknown;
}

Trit operator|(Trit a, Trit b) {

	if (a == Trit::True || b == Trit::True)
		return Trit::True;
	else if (a == Trit::False && b == Trit::False)
		return Trit::False;
	else
		return Trit::Unknown;
}

Trit operator~(Trit a) {

	if (a == Trit::True)
		return Trit::False;
	else if (a == Trit::False)
		return Trit::True;
	else
		return Trit::Unknown;
}