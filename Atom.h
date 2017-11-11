#ifndef ATOM_H_
#define ATOM_H_
#include <iostream>
#include <string>

using std::string;

class Atom
{
private:
	enum {unknown, hydrogen, helium, lithium, beryllium, boron, carbon,
	      nitrogen, oxygen, fluorine, neon};
	static string names[11];
	static string symbols[11];
	float charge;
	double x;
	double y;
	double z;
	Atom * partner;
	int element;
	bool bonded;
public:
	Atom(int n = 0, float c = 0, double xc = 0, double yc = 0, double zc = 0);
	Atom(Atom && amove); //Move constructor
	~Atom();
	float get_charge() const {return charge;}
	string get_name() const {return names[element];}
	string get_symbol() const {return symbols[element];}
	void set_charge(float c) {charge = c;}
	Atom * get_partner() const {return partner;}
	bool is_bonded() const {return bonded;}
	void set_coords(double xc, double yc, double zc);
	friend std::ostream & operator<<(std::ostream & os, const Atom &);
	friend std::ostream & operator<<(std::ostream & os, const Atom *);
	friend bool make_bond(Atom & a, Atom & b);
	friend bool are_bound(Atom & a, Atom & b);
	friend bool break_bond(Atom & a, Atom & b);
	friend bool break_bond(Atom & a);
};

#endif	
