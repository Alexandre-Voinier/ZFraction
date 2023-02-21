#pragma once

#include <ostream>

class ZFraction
{
public:
	ZFraction();
	ZFraction(int p_interger);
	ZFraction(int p_numerator, int p_denominator);

	void display(std::ostream& p_flux) const;

	// operators
	ZFraction& operator+=(ZFraction const& p_zFraction);
	ZFraction& operator-=(ZFraction const& p_zFraction);
	ZFraction& operator*=(ZFraction const& p_zFraction);
	ZFraction& operator/=(ZFraction const& p_zFraction);

	bool isEqual(ZFraction const& p_zFraction) const;
	bool isGreater(ZFraction const& p_zFraction) const;

private:
	void simplify();
	int pgcd() const;

private:
	int _denominator;
	int _numerator;
};

std::ostream& operator<<(std::ostream& p_flux, ZFraction const& p_zfraction);

ZFraction operator+(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2);
ZFraction operator-(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2);
ZFraction operator*(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2);
ZFraction operator/(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2);

bool operator==(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2);
bool operator!=(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2);
bool operator<=(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2);
bool operator>=(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2);
bool operator>(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2);
bool operator<(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2);