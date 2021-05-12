#pragma once

namespace ts {

	struct AIFactor {
		float hole;			      // how bad holes are
		float holeCovered;        // how many blocks are above a hole (bad)
		float heightVariance;     // average height differance between adjacent columns
		float averageHeight;      // average height
		float Idependency;        // number of columns with 2 adjacent columns 3 higher than the one
		float partialIdependency; // number of columns with 2 adjacent columns >=2 higher than this one
		float surfaceParity;	  // https://harddrop.com/wiki/Parity
		float attack;			  // attack
		float attackEffeciency;   // attack / lines cleared
		float clearWithoutAttack; // how bad it is to clear without attack

	} static mainFactors = {
		//-25.f, -10.f, -3.f, -4.f, -30.f, -20.f, -2.f, 20.f, 30.f, -10.f  // main with lookaheads
		-25.f, -10.f, -3.f, -30.f, -30.f, -10.f, -5.f, 20.f, 10.f, -20.f  // downstacking with lookaheads
		//-30, -20, -4, -5, -20.f, -10, -2, 0, 0, 0 // no lookaheads
	};
	
	class Globals {
	public:
		static int DAS;

		static int AI_BEST_MOVES_TO_BE_CONSIDERED;
		static int AI_LOOKAHEADS;
		static bool HOLDENABLED;
		static int AI_MOVE_DELAY_MS;
		static bool AI_FULLY_PERFORM_MOVE;

		static bool TURN_BASED;

		// unique moves are the ones that require soft dropping
		// this can be expensive, but it allows for tspins
		static bool AI_USE_UNIQUE_MOVES;

		static void InitVars();
	};


	
}
