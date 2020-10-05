#include <cstdlib>
#include <functional>
#include <unordered_map>
#include "Trit.h"

class TritSet {

public:

	/*class Proxy {

	public:
		Proxy(size_t index, TritSet* tritSet);
		operator Trit() const;
		Proxy& operator=(Trit newValue);

	private:
		size_t proxyIndex;
		Trit value;
		TritSet* setPtr;
	};*/

	class Proxy {

	public:
		Proxy& operator=(Trit newValue);
		Proxy(size_t index, TritSet* tritSet);
		operator Trit() const;
	private:
		size_t proxyIndex;
		Trit value;
		TritSet* setPtr;
	};


	explicit TritSet(size_t size);

	/// length of internal array
	unsigned int capacity();

	/// освобождение памяти до начального значения или
	/// до значения необходимого для хранения последнего установленного трита
	void shrink();

	TritSet operator & (TritSet setA);

	TritSet operator | (TritSet setA);

	TritSet operator ~ ();

	Proxy operator[](size_t index);

	/// число установленных в данное значение тритов
	/// для трита Unknown - число значений Unknown до последнего установленного трита
	size_t cardinality(Trit value);

	/// Hash для тритов
	struct TritHash {
		std::size_t operator()(Trit t) const;
	};

	std::unordered_map < Trit, int, TritSet::TritHash> cardinality();

	/// забыть содержимое от lastIndex и дальше
	void trim(size_t lastIndex);

	/// индекс последнего не Unknown трита +1
	size_t length();

private:

	unsigned int* set;
	unsigned int size;
	unsigned int lastTritIndex;
	unsigned int lastNotUnknownTritIndex;
	unsigned int trueCount;
	unsigned int falseCount;

	static void fixSizes(TritSet& a, TritSet& b);
	void changeCountVars(Trit newValue, unsigned int index);
	void resize(size_t newSize);


};