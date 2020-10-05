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

	/// ������������ ������ �� ���������� �������� ���
	/// �� �������� ������������ ��� �������� ���������� �������������� �����
	void shrink();

	TritSet operator & (TritSet setA);

	TritSet operator | (TritSet setA);

	TritSet operator ~ ();

	Proxy operator[](size_t index);

	/// ����� ������������� � ������ �������� ������
	/// ��� ����� Unknown - ����� �������� Unknown �� ���������� �������������� �����
	size_t cardinality(Trit value);

	/// Hash ��� ������
	struct TritHash {
		std::size_t operator()(Trit t) const;
	};

	std::unordered_map < Trit, int, TritSet::TritHash> cardinality();

	/// ������ ���������� �� lastIndex � ������
	void trim(size_t lastIndex);

	/// ������ ���������� �� Unknown ����� +1
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