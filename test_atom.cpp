#include "catch.hpp"
#include "Atom.h"

TEST_CASE ("Atoms can be initialized, charged, and printed") {
	Atom atom1(1);
	Atom atom2;
	Atom atom3(5,-1.5);

	REQUIRE(atom1.get_name() == "hydrogen");
	REQUIRE(atom1.get_symbol() == "H");
	REQUIRE(atom2.get_name() == "unknown");
	REQUIRE(atom2.get_symbol() == "Unk");
	REQUIRE(atom3.get_name() == "boron");
	REQUIRE(atom3.get_symbol() == "B");
	
	REQUIRE(atom1.get_charge() == 0);
	REQUIRE(atom2.get_charge() == 0);
	REQUIRE(atom3.get_charge() == -1.5);
	
	SECTION("Charges can be changed") {
		atom1.set_charge(-1);
		atom3.set_charge(0);
		
		REQUIRE(atom1.get_charge() == -1);
		REQUIRE(atom3.get_charge() == 0);
	}

	SECTION("Atoms can be printed") {
		std::cout << "atom1: " << atom1 << "\n";
		std::cout << "atom2: " << atom2 << "\n";
		std::cout << "atom3: " << atom3 << "\n";
	}
}

TEST_CASE("bonds can be created and broken") {
	Atom atom1(1);
	Atom atom2(6);
	Atom atom3(8);
	
	REQUIRE(atom1.is_bonded() == false);
	REQUIRE(atom2.is_bonded() == false);
	REQUIRE(atom3.is_bonded() == false);

	SECTION("Bonds can be created (on unbound atoms)") {
		bool response;
		response = make_bond(atom1, atom2);
		REQUIRE(atom1.is_bonded() == true);
		REQUIRE(atom2.is_bonded() == true);
		REQUIRE(response == true);
		REQUIRE(are_bound(atom1, atom2) == true);
	
		response = make_bond(atom1, atom3);
		REQUIRE(atom3.is_bonded() == false);
		REQUIRE(response == false);
	
		SECTION("Bonds can be broken by supplying both atoms (if they are bound)") {
			response = break_bond(atom1,atom2);
			REQUIRE(atom1.is_bonded() == false);
			REQUIRE(atom2.is_bonded() == false);
			REQUIRE(are_bound(atom1,atom2) == false);
			REQUIRE(break_bond(atom1,atom3) == false);
		}

		SECTION("Bonds can be broken by supplying only 1 atom") {
			response = break_bond(atom1);
			REQUIRE(atom1.is_bonded() == false);
			REQUIRE(atom2.is_bonded() == false);
			REQUIRE(response == true);
			REQUIRE(are_bound(atom1,atom2) == false);
		}
	}
}

