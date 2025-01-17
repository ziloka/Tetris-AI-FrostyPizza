#pragma once
#include <iostream>
#include <vector>
#include <array>

#define TETROMINO_START_Y 1 // starting position for the tetromino, default zero, increase to spawn the tetromino lower

// Tetris namespace
namespace ts {

	constexpr int WIDTH{ 10 };
	constexpr int HEIGHT{ 25 }; //25
	constexpr int YMARGIN{ HEIGHT - 20 };

	constexpr int comboTable[14]{
		0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5
	};

	struct Point {
		int x, y;
	};

	static constexpr const Point tetrominoData[7][4]{
		{{1, 0}, {0, 0}, {-1, 0}, {1, -1}},   // L
		{{1, 0}, {0, 0}, {-1, 0}, {-1, -1}},  // J
		{{1, 0}, {0, 0}, {0, -1}, {-1, -1}},  // Z
		{{1, -1}, {0, -1}, {0, 0}, {-1, 0}},  // S
		{{-1, 0}, {0, -1}, {0, 0}, {1, 0}},   // T
		{{1, 0}, {0, 0}, {-1, 0}, {-2, 0}},   // I
		{{-1, -1}, {0, -1}, {-1, 0}, {0, 0}}, // O
	};


	static constexpr const Point IrotationData[4][4]{
		{{1, 0}, {0, 0}, {-1, 0}, {-2, 0}},   // 0 (no rotation)
		{{0, -1}, {0, 0}, {0, 1}, {0, 2}},    // 1 (CW rotation)
		{{1, 1}, {0, 1}, {-1, 1}, {-2, 1}},   // 2 (180 rotation)
		{{-1, -1}, {-1, 0}, {-1, 1}, {-1, 2}} // 3 (CCW rotation
	};


	static constexpr const Point wallKickData[4][5]{
		{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
		{{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}},
		{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
		{{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}}
	};



	static constexpr const Point IwallKickData[4][2][5]{
		{ // 0
			{{0, 0}, {-2, 0}, {1, 0}, {-2, 1}, {1, -2}}, // R
			{{0, 0}, {-1, 0}, {2, 0}, {-1, -2}, {2, 1}}  // L
		},
		{ // R
			{{0, 0}, {-1, 0}, {2, 0}, {-1, -2}, {2, 1}}, // 2
			{{0, 0}, {2, 0}, {-1, 0}, {2, -1}, {-1, 2}}  // 0
		},
		{ // 2
			{{0, 0}, {2, 0}, {-1, 0}, {2, -1}, {1, 2}},  // L
			{{0, 0}, {1, 0}, {-2, 0}, {1, 2}, {-2, -1}}  // R
		},
		{ // L
			{ {0, 0}, {1, 0}, {-2, 0}, {1, 2}, {-2, -1}},// 0
			{{0, 0}, {-2, 0}, {1, 0}, {-2, 1}, {1, -2}}  // 2
		}
	};

	static constexpr const Point ZSTLJwallKickData[4][2][5]{
		{ // 0
			{{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}}, // R
			{{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}}     // L
		},
		{ // R
			{{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}},  // 2
			{{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}}  // 0
		},
		{ // 2
			{{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}},  // L
			{{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}}  // R
		},
		{ // L
			{{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}},// 0
			{{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}}  // 2
		}
	};


	enum Tetrominos {
		MINO_L,
		MINO_J,
		MINO_Z,
		MINO_S,
		MINO_T,
		MINO_I,
		MINO_O,
		GARBAGE,
		UNCLEARABLE_GARBAGE // unclearable garbage is used for the ai so that when it looks ahead there can be garbage without it planning poorly
	};
	


	struct Tetromino {
		Tetromino() = delete; // no default constructor

		Tetromino(int minoIndex);

		void setTetromino(int minoIndex);

		//std::vector<Point> data;
		std::array<Point, 4> data;
		int x, y;
		int mino;
		int rotation;

	};

}

