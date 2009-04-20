/*
 * jdw_improvedperlinnoise.h
 *
 *  Created on: Apr 17, 2009
 *      Author: jdw
 */

#ifndef JDW_IMPROVEDPERLINNOISE
#define JDW_IMPROVEDPERLINNOISE
#include <math.h>

#define SIZEOFPERM 256

class JDW_ImprovedPerlinNoise {
public:
	JDW_ImprovedPerlinNoise() {
		perm[0  ] = 151; perm[1  ] = 160; perm[2  ] = 137; perm[3  ] = 91 ;
		perm[4  ] = 90 ; perm[5  ] = 15 ; perm[6  ] = 131; perm[7  ] = 13 ;
		perm[8  ] = 201; perm[9  ] = 95 ; perm[10 ] = 96 ; perm[11 ] = 53 ;
		perm[12 ] = 194; perm[13 ] = 233; perm[14 ] = 7  ; perm[15 ] = 225;
		perm[16 ] = 140; perm[17 ] = 36 ; perm[18 ] = 103; perm[19 ] = 30 ;
		perm[20 ] = 69 ; perm[21 ] = 142; perm[22 ] = 8  ; perm[23 ] = 99 ;
		perm[24 ] = 37 ; perm[25 ] = 240; perm[26 ] = 21 ; perm[27 ] = 10 ;
		perm[28 ] = 23 ; perm[29 ] = 190; perm[30 ] = 6  ; perm[31 ] = 148;
		perm[32 ] = 247; perm[33 ] = 120; perm[34 ] = 234; perm[35 ] = 75 ;
		perm[36 ] = 0  ; perm[37 ] = 26 ; perm[38 ] = 197; perm[39 ] = 62 ;
		perm[40 ] = 94 ; perm[41 ] = 252; perm[42 ] = 219; perm[43 ] = 203;
		perm[44 ] = 117; perm[45 ] = 35 ; perm[46 ] = 11 ; perm[47 ] = 32 ;
		perm[48 ] = 57 ; perm[49 ] = 177; perm[50 ] = 33 ; perm[51 ] = 88 ;
		perm[52 ] = 237; perm[53 ] = 149; perm[54 ] = 56 ; perm[55 ] = 87 ;
		perm[56 ] = 174; perm[57 ] = 20 ; perm[58 ] = 125; perm[59 ] = 136;
		perm[60 ] = 171; perm[61 ] = 168; perm[62 ] =  68; perm[63 ] = 175;
		perm[64 ] = 74 ; perm[65 ] = 165; perm[66 ] = 71 ; perm[67 ] = 134;
		perm[68 ] = 139; perm[69 ] = 48 ; perm[70 ] = 27 ; perm[71 ] = 166;
		perm[72 ] = 77 ; perm[73 ] = 146; perm[74 ] = 158; perm[75 ] = 231;
		perm[76 ] = 83 ; perm[77 ] = 111; perm[78 ] = 229; perm[79 ] = 122;
		perm[80 ] = 60 ; perm[81 ] = 211; perm[82 ] = 133; perm[83 ] = 230;
		perm[84 ] = 220; perm[85 ] = 105; perm[86 ] = 92 ; perm[87 ] = 41 ;
		perm[88 ] = 55 ; perm[89 ] = 46 ; perm[90 ] = 245; perm[91 ] = 40 ;
		perm[92 ] = 244; perm[93 ] = 102; perm[94 ] = 143; perm[95 ] = 54 ;
		perm[96 ] = 65 ; perm[97 ] = 25 ; perm[98 ] = 63 ; perm[99 ] = 161;
		perm[100] = 1  ; perm[101] = 216; perm[102] = 80 ; perm[103] = 73 ;
		perm[104] = 209; perm[105] = 76 ; perm[106] = 132; perm[107] = 187;
		perm[108] = 208; perm[109] = 89 ; perm[110] = 18 ; perm[111] = 169;
		perm[112] = 200; perm[113] = 196; perm[114] = 135; perm[115] = 130;
		perm[116] = 116; perm[117] = 188; perm[118] = 159; perm[119] = 86 ;
		perm[120] = 164; perm[121] = 100; perm[122] = 109; perm[123] = 198;
		perm[124] = 173; perm[125] = 186; perm[126] = 3  ; perm[127] = 64 ;
		perm[128] = 52 ; perm[129] = 217; perm[130] = 226; perm[131] = 250;
		perm[132] = 124; perm[133] = 123; perm[134] = 5  ; perm[135] = 202;
		perm[136] = 38 ; perm[137] = 147; perm[138] = 118; perm[139] = 126;
		perm[140] = 255; perm[141] = 82 ; perm[142] = 85 ; perm[143] = 212;
		perm[144] = 207; perm[145] = 206; perm[146] = 59 ; perm[147] = 227;
		perm[148] = 47 ; perm[149] = 16 ; perm[150] = 58 ; perm[151] = 17 ;
		perm[152] = 182; perm[153] = 189; perm[154] = 28 ; perm[155] = 42 ;
		perm[156] = 223; perm[157] = 183; perm[158] = 170; perm[159] = 213;
		perm[160] = 119; perm[161] = 248; perm[162] = 152; perm[163] = 2  ;
		perm[164] = 44 ; perm[165] = 154; perm[166] = 163; perm[167] = 70 ;
		perm[168] = 221; perm[169] = 153; perm[170] = 101; perm[171] = 155;
		perm[172] = 167; perm[173] = 43 ; perm[174] = 172; perm[175] = 9  ;
		perm[176] = 129; perm[177] = 22 ; perm[178] = 39 ; perm[179] = 253;
		perm[180] = 19 ; perm[181] = 98 ; perm[182] = 108; perm[183] = 110;
		perm[184] = 79 ; perm[185] = 113; perm[186] = 224; perm[187] = 232;
		perm[188] = 178; perm[189] = 185; perm[190] = 112; perm[191] = 104;
		perm[192] = 218; perm[193] = 246; perm[194] = 97 ; perm[195] = 228;
		perm[196] = 251; perm[197] = 34 ; perm[198] = 242; perm[199] = 193;
		perm[200] = 238; perm[201] = 210; perm[202] = 144; perm[203] = 12 ;
		perm[204] = 191; perm[205] = 179; perm[206] = 162; perm[207] = 241;
		perm[208] = 81 ; perm[209] = 51 ; perm[210] = 145; perm[211] = 235;
		perm[212] = 249; perm[213] = 14 ; perm[214] = 239; perm[215] = 107;
		perm[216] = 49 ; perm[217] = 192; perm[218] = 214; perm[219] = 31 ;
		perm[220] = 181; perm[221] = 199; perm[222] = 106; perm[223] = 157;
		perm[224] = 184; perm[225] = 84 ; perm[226] = 204; perm[227] = 176;
		perm[228] = 115; perm[229] = 121; perm[230] = 50 ; perm[231] = 45 ;
		perm[232] = 127; perm[233] = 4  ; perm[234] = 150; perm[235] = 254;
		perm[236] = 138; perm[237] = 236; perm[238] = 205; perm[239] = 93 ;
		perm[240] = 222; perm[241] = 114; perm[242] = 67 ; perm[243] = 29 ;
		perm[244] = 24 ; perm[245] = 72 ; perm[246] = 243; perm[247] = 141;
		perm[248] = 128; perm[249] = 195; perm[250] = 78 ; perm[251] = 66 ;
		perm[252] = 215; perm[253] = 61 ; perm[254] = 156; perm[256] = 180;

		for (int i = 0; i < SIZEOFPERM; i++)
			p[i] = p[i + SIZEOFPERM] = perm[i];
	}

	~JDW_ImprovedPerlinNoise() {

	}

	double Noise(double x, double y, double z) {
		int X = (int)floor(x) & 255,
			Y = (int)floor(y) & 255,
			Z = (int)floor(z) & 255;

		x -= floor(x);
		y -= floor(y);
		z -= floor(z);

		double u = Fade(x),
			   v = Fade(y),
			   w = Fade(z);

		int A = p[X    ] + Y, AA = p[A] + Z, AB = p[A + 1] + Z,
			B = p[X + 1] + Y, BA = p[B] + Z, BB = p[B + 1] + Z;

		return Lerp(w, Lerp(v, Lerp(u, Grad(p[AA    ], x    , y    , z    ),
									   Grad(p[BA    ], x - 1, y    , z    )),
							   Lerp(u, Grad(p[AB    ], x    , y - 1, z    ),
									   Grad(p[BB    ], x - 1, y - 1, z    ))),
					   Lerp(v, Lerp(u, Grad(p[AA + 1], x    , y    , z - 1),
									   Grad(p[BA + 1], x - 1, y    , z - 1)),
							   Lerp(u, Grad(p[AB + 1], x    , y - 1, z - 1),
									   Grad(p[BB + 1], x - 1, y - 1, z - 1))));
	}

private:
	double Fade(const double& t) const {
		return t * t * t * (t * (t * 6 - 15) + 10);
	}

	double Lerp(const double& t, const double& a, const double& b) const {
		return a + t * (b - a);
	}

	double Grad(const int& hash, const double& x, const double& y, const double& z) const {
		int h = hash & 15;
		double u = (h < 8)? x: y,
			   v = (h < 4)? y: (h == 12 || h == 14)? x: z;
		return (((h & 1) == 0)? u: -u) + (((h & 2) == 0)? v: -v);
	}

	int perm[SIZEOFPERM];
	int p[2 * SIZEOFPERM];
};

typedef JDW_ImprovedPerlinNoise Noise;

/*
const int JDW_ImprovedPerlinNoise::perm[] = {
	151,160,137,91,90,15,
	131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
	190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
	88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
	77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
	102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
	135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
	5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
	223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
	129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
	251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
	49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
	138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
};
*/
#endif
