#pragma once

class intVector2 {
public:
	int first;
	int second;
	intVector2(int first = 0, int second = 0) : first(first), second(second) {};
	friend intVector2 operator +(const intVector2&, const intVector2&);
	friend intVector2 operator -(const intVector2&, const intVector2&);
	friend bool operator ==(const intVector2&, const intVector2&);
	friend bool operator !=(const intVector2&, const intVector2&);
	intVector2 operator *(const int);
	intVector2 operator /(const int);
};