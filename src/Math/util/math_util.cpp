#include "../../Atlas.h"

using namespace Atlas;

template<typename T> 
T Atlas::Math::Deg2Rad(const T& deg) {
	return (deg * PI) / 180;
}

template<typename T> 
T Atlas::Math::Rad2Deg(const T& rad) {

	return (rad *  180) / PI;
}

template<typename T>
T Atlas::Math::Max(const T& a, const T& b)
{
	return (a > b) ? a : b;
}

template<typename T>
T Atlas::Math::Min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

template<typename T>
T Atlas::Math::Clamp(const T& Min, const T& Max, const T& Number)
{
	if (Number > Max) {
		return Max;
	}
	else if (Number < Min) {
		return Min;
	}
	return Number;
}

template<typename T>
T Atlas::Math::Floor(const T& Number)
{

	return Number - (Number % 1);
}

template<typename T>
T Atlas::Math::Ceil(const T& Number)
{
	return Number + (1 - (Number % 1));
}

template<typename T>
T Atlas::Math::Round(const T& Number)
{
	//Not sure how to implement, SO this is a hacky version
	int num = Number;
	return (T) num;
}

template<typename T>
T Atlas::Math::Abs(const T& Number)
{
	return (Number >= 0) ? Number : (Number * -1);
}
