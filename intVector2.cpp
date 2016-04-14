#include "intVector2.h"

intVector2 operator +(const intVector2& l, const intVector2& r) {
	return intVector2(l.first + r.first, l.second + r.second);
}

intVector2 operator -(const intVector2& l, const intVector2& r) {
	return intVector2(l.first - r.first, l.second - r.second);
}

bool operator ==(const intVector2& l, const intVector2& r) {
	return (l.first == r.first && l.second == r.second);
}

bool operator !=(const intVector2& l, const intVector2& r) {
	return (l.first != r.first || l.second != r.second);
};

intVector2 intVector2::operator *(const int a) {
	return intVector2(first * a, second * a);
}

intVector2 intVector2::operator /(const int a) {
	if (a == 0) {
		throw "Dividing by zero";
	}
	return intVector2(first / a, second / a);
}