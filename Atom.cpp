#include "Atom.h"
#include <iostream>
#include <string>

using std::string;
Atom::Atom(int n, float c, double xc, double yc, double zc): 
	element(n), charge(c), bonded(false), x(xc), y(yc), z(zc)
{
	partner = nullptr;
}

//Move constructor
Atom::Atom(Atom && amove)
{
	element = amove.element;
	charge = amove.charge;
	bonded = amove.bonded;
	x = amove.x;
	y = amove.y;
	z = amove.z;
	partner = amove.partner;
	amove.partner = nullptr;
	amove.bonded = false;
}

Atom::~Atom()
{
}

void Atom::set_coords(double xc, double yc, double zc)
{
	x = xc;
	y = yc;
	z = zc;
}
string Atom::names[11] = {
	"unknown","hydrogen","helium","lithium","beryllium",
	"boron","carbon","nitrogen","oxygen","fluorine","neon"};
string Atom::symbols[11] = {"Unk","H","He","Li","Be","B","C","N","O","F","Ne"};

std::ostream & operator<<(std::ostream & os, const Atom & a)
{
	os << "Atom: " << a.get_name();
	return os;
}

std::ostream & operator<<(std::ostream & os, const Atom * a)
{
	os << "Atom: " << a->get_name();
	return os;
}

bool make_bond(Atom & a, Atom & b)
{
	if (a.bonded || b.bonded)
		return false;
	else
	{
		a.partner = &b;
		b.partner = &a;
		a.bonded = true;
		b.bonded = true;
		return true;
	}
}

bool break_bond(Atom & a, Atom & b)
{
	if (!are_bound(a,b))
		return false;
	else
		a.partner = nullptr;
		b.partner = nullptr;
		a.bonded = false;
		b.bonded = false;
		return true;
}

bool break_bond(Atom & a)
{
	if (a.bonded)
	{
		Atom * p_partner;
		p_partner = a.partner;
		p_partner->bonded = false;
		p_partner->partner = nullptr;
		a.partner = nullptr;
		a.bonded = false;
		return true;
	}
	else
		return false;
}

bool are_bound(Atom & a, Atom & b)
{
	if (a.partner == &b)
		return true;
	else
		return false;
}
