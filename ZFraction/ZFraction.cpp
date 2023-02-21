#include <ostream>

#include "ZFraction.h"
#include <iostream>

using namespace std;

ZFraction::ZFraction() : _numerator(0), _denominator(1)
{
}

ZFraction::ZFraction(int p_interger): _numerator(p_interger), _denominator(1)
{
}

ZFraction::ZFraction(int p_numerator, int p_denominator): _numerator(p_numerator), _denominator(p_denominator)
{
	simplify();
}

void ZFraction::display(ostream& p_flux) const
{
	if (_numerator == 0)
		p_flux << 0;
	else if (_denominator == 1)
		p_flux << _numerator;
	else
		p_flux << _numerator << " / " << _denominator;
}

ZFraction& ZFraction::operator+=(ZFraction const& p_zFraction)
{
	if (_denominator != p_zFraction._denominator)
	{
		int lv_oldDeno = _denominator;

		_numerator *= p_zFraction._denominator;
		_denominator *= p_zFraction._denominator;

		_numerator += p_zFraction._numerator * lv_oldDeno;
	}
	else
		_numerator += p_zFraction._numerator;

	simplify();

	return *this;
}

ZFraction& ZFraction::operator-=(ZFraction const& p_zFraction)
{
	if (_denominator != p_zFraction._denominator)
	{
		int lv_oldDeno = _denominator;

		_numerator *= p_zFraction._denominator;
		_denominator *= p_zFraction._denominator;

		_numerator -= p_zFraction._numerator * lv_oldDeno;
	}
	else
		_numerator -= p_zFraction._numerator;

	simplify();

	return *this;
}

ZFraction& ZFraction::operator*=(ZFraction const& p_zFraction)
{
	_numerator *= p_zFraction._numerator;
	_denominator *= p_zFraction._denominator;

	simplify();

	return *this;
}

ZFraction& ZFraction::operator/=(ZFraction const& p_zFraction)
{
	_numerator *= p_zFraction._denominator;
	_denominator *= p_zFraction._numerator;

	simplify();

	return *this;
}

bool ZFraction::isEqual(ZFraction const& p_zFraction) const
{
	if (_numerator == p_zFraction._numerator && _denominator == p_zFraction._denominator)
		return true;
	return false;
}

bool ZFraction::isGreater(ZFraction const& p_zFraction) const
{
	return (_numerator / _denominator) > (p_zFraction._numerator / p_zFraction._denominator);
}

void ZFraction::simplify()
{
	if (_numerator != 0 && _denominator != 1)
	{
		int lv_pgcd = pgcd();
		_numerator /= lv_pgcd;
		_denominator /= lv_pgcd;
	}
}

int ZFraction::pgcd() const
{
	if (_numerator == _denominator)
		return _numerator;

	int lv_diviseur(0);
	int lv_reste(_numerator < _denominator ? _numerator : _denominator);
	int lv_toDivide(_numerator > _denominator ? _numerator : _denominator);
	
	do
	{
		lv_diviseur = lv_reste;
		lv_reste = lv_toDivide % lv_diviseur;
		lv_toDivide = lv_diviseur;

	} while (lv_reste != 0);

	return lv_diviseur;
}

std::ostream& operator<<(std::ostream& p_flux, ZFraction const& p_zfraction)
{
	p_zfraction.display(p_flux);
	return p_flux;
}

ZFraction operator+(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2)
{
	ZFraction lv_result(p_zFraction1);
	lv_result += p_zFraction2;
	return lv_result;
}

ZFraction operator-(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2)
{
	ZFraction lv_result(p_zFraction1);
	lv_result -= p_zFraction2;
	return lv_result;
}

ZFraction operator*(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2)
{
	ZFraction lv_result(p_zFraction1);
	lv_result *= p_zFraction2;
	return lv_result;
}

ZFraction operator/(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2)
{
	ZFraction lv_result(p_zFraction1);
	lv_result /= p_zFraction2;
	return lv_result;
}

bool operator==(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2)
{
	return p_zFraction1.isEqual(p_zFraction2);
}

bool operator!=(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2)
{
	return !p_zFraction1.isEqual(p_zFraction2);
}

bool operator<=(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2)
{
	return p_zFraction1.isEqual(p_zFraction2) || !p_zFraction1.isGreater(p_zFraction2);
}

bool operator>=(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2)
{
	return p_zFraction1.isEqual(p_zFraction2) || p_zFraction1.isGreater(p_zFraction2);
}

bool operator>(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2)
{
	return p_zFraction1.isGreater(p_zFraction2);
}

bool operator<(ZFraction const& p_zFraction1, ZFraction const& p_zFraction2)
{
	return !p_zFraction1.isGreater(p_zFraction2);
}


