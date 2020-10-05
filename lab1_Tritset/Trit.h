#pragma once
enum class Trit { False = 1, True = 2, Unknown = 0 };

Trit operator&(Trit a, Trit b);
Trit operator|(Trit a, Trit b);
Trit operator~(Trit a);
