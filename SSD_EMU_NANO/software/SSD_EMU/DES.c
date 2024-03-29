#define null 0
typedef unsigned char uchar;
typedef unsigned char uint8_t;

static const uint8_t InitialPermuteMap[64] = { 57, 49, 41, 33, 25, 17, 9, 1,
		59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55,
		47, 39, 31, 23, 15, 7, 56, 48, 40, 32, 24, 16, 8, 0, 58, 50, 42, 34,
		26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22,
		14, 6 };
static const uint8_t KeyPermuteMap[56] = { 49, 42, 35, 28, 21, 14, 7, 0, 50,
		43, 36, 29, 22, 15, 8, 1, 51, 44, 37, 30, 23, 16, 9, 2, 52, 45, 38, 31,
		55, 48, 41, 34, 27, 20, 13, 6, 54, 47, 40, 33, 26, 19, 12, 5, 53, 46,
		39, 32, 25, 18, 11, 4, 24, 17, 10, 3, };

static const uint8_t KeyRotation[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2,
		2, 2, 1 };

static const uint8_t KeyCompression[48] = { 13, 16, 10, 23, 0, 4, 2, 27, 14, 5,
		20, 9, 22, 18, 11, 3, 25, 7, 15, 6, 26, 19, 12, 1, 40, 51, 30, 36, 46,
		54, 29, 39, 50, 44, 32, 47, 43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28,
		31 };

static const uint8_t DataExpansion[48] = { 31, 0, 1, 2, 3, 4, 3, 4, 5, 6, 7, 8,
		7, 8, 9, 10, 11, 12, 11, 12, 13, 14, 15, 16, 15, 16, 17, 18, 19, 20,
		19, 20, 21, 22, 23, 24, 23, 24, 25, 26, 27, 28, 27, 28, 29, 30, 31, 0 };

static const uint8_t SBox[8][64] = { { /* S0 */
14, 0, 4, 15, 13, 7, 1, 4, 2, 14, 15, 2, 11, 13, 8, 1, 3, 10, 10, 6, 6, 12, 12,
		11, 5, 9, 9, 5, 0, 3, 7, 8, 4, 15, 1, 12, 14, 8, 8, 2, 13, 4, 6, 9, 2,
		1, 11, 7, 15, 5, 12, 11, 9, 3, 7, 14, 3, 10, 10, 0, 5, 6, 0, 13 }, { /* S1 */
15, 3, 1, 13, 8, 4, 14, 7, 6, 15, 11, 2, 3, 8, 4, 14, 9, 12, 7, 0, 2, 1, 13,
		10, 12, 6, 0, 9, 5, 11, 10, 5, 0, 13, 14, 8, 7, 10, 11, 1, 10, 3, 4,
		15, 13, 4, 1, 2, 5, 11, 8, 6, 12, 7, 6, 12, 9, 0, 3, 5, 2, 14, 15, 9 },
		{ /* S2 */
		10, 13, 0, 7, 9, 0, 14, 9, 6, 3, 3, 4, 15, 6, 5, 10, 1, 2, 13, 8, 12,
				5, 7, 14, 11, 12, 4, 11, 2, 15, 8, 1, 13, 1, 6, 10, 4, 13, 9,
				0, 8, 6, 15, 9, 3, 8, 0, 7, 11, 4, 1, 15, 2, 14, 12, 3, 5, 11,
				10, 5, 14, 2, 7, 12 }, { /* S3 */
		7, 13, 13, 8, 14, 11, 3, 5, 0, 6, 6, 15, 9, 0, 10, 3, 1, 4, 2, 7, 8, 2,
				5, 12, 11, 1, 12, 10, 4, 14, 15, 9, 10, 3, 6, 15, 9, 0, 0, 6,
				12, 10, 11, 1, 7, 13, 13, 8, 15, 9, 1, 4, 3, 5, 14, 11, 5, 12,
				2, 7, 8, 2, 4, 14 }, { /* S4 */
		2, 14, 12, 11, 4, 2, 1, 12, 7, 4, 10, 7, 11, 13, 6, 1, 8, 5, 5, 0, 3,
				15, 15, 10, 13, 3, 0, 9, 14, 8, 9, 6, 4, 11, 2, 8, 1, 12, 11,
				7, 10, 1, 13, 14, 7, 2, 8, 13, 15, 6, 9, 15, 12, 0, 5, 9, 6,
				10, 3, 4, 0, 5, 14, 3 }, { /* S5 */
		12, 10, 1, 15, 10, 4, 15, 2, 9, 7, 2, 12, 6, 9, 8, 5, 0, 6, 13, 1, 3,
				13, 4, 14, 14, 0, 7, 11, 5, 3, 11, 8, 9, 4, 14, 3, 15, 2, 5,
				12, 2, 9, 8, 5, 12, 15, 3, 10, 7, 11, 0, 14, 4, 1, 10, 7, 1, 6,
				13, 0, 11, 8, 6, 13 }, { /* S6 */
		4, 13, 11, 0, 2, 11, 14, 7, 15, 4, 0, 9, 8, 1, 13, 10, 3, 14, 12, 3, 9,
				5, 7, 12, 5, 2, 10, 15, 6, 8, 1, 6, 1, 6, 4, 11, 11, 13, 13, 8,
				12, 1, 3, 4, 7, 10, 14, 7, 10, 9, 15, 5, 6, 0, 8, 15, 0, 14, 5,
				2, 9, 3, 2, 12 }, { /* S7 */
		13, 1, 2, 15, 8, 13, 4, 8, 6, 10, 15, 3, 11, 7, 1, 4, 10, 12, 9, 5, 3,
				6, 14, 11, 5, 0, 0, 14, 12, 9, 7, 2, 7, 2, 11, 1, 4, 14, 1, 7,
				9, 4, 12, 10, 14, 8, 2, 13, 0, 15, 6, 12, 10, 9, 13, 0, 15, 3,
				3, 5, 5, 6, 8, 11 } };

static const uint8_t PBox[32] =
		{ 15, 6, 19, 20, 28, 11, 27, 16, 0, 14, 22, 25, 4, 17, 30, 9, 1, 7, 23,
				13, 31, 26, 2, 8, 18, 12, 29, 5, 21, 10, 3, 24 };

static const uint8_t FinalPermuteMap[64] =
		{ 7, 39, 15, 47, 23, 55, 31, 63, 6, 38, 14, 46, 22, 54, 30, 62, 5, 37,
				13, 45, 21, 53, 29, 61, 4, 36, 12, 44, 20, 52, 28, 60, 3, 35,
				11, 43, 19, 51, 27, 59, 2, 34, 10, 42, 18, 50, 26, 58, 1, 33,
				9, 41, 17, 49, 25, 57, 0, 32, 8, 40, 16, 48, 24, 56 };

#define CLRBIT( STR, IDX ) ( (STR)[(IDX)/8] &= ~(0x01 << (7 - ((IDX)%8))) )

#define SETBIT( STR, IDX ) ( (STR)[(IDX)/8] |= (0x01 << (7 - ((IDX)%8))) )

#define GETBIT( STR, IDX ) (( ((STR)[(IDX)/8]) >> (7 - ((IDX)%8)) ) & 0x01)

static void Permute(uchar *dst, const uchar *src, const uint8_t *map,
		const int mapsize);
static void KeyShift(uchar *key, const int numbits);
static void sbox(uchar *dst, const uchar *src);
static void xor(uchar *dst, const uchar *a, const uchar *b, const int count);
uchar *auth_DESkey8to7(uchar *dst, const uchar *key);

static void Permute(uchar *dst, const uchar *src, const uint8_t *map,
		const int mapsize) {
	int bitcount;
	int i;

	/* Clear all bits in the destination.
	 */
	for (i = 0; i < mapsize; i++)
		dst[i] = 0;

	/* Set destination bit if the mapped source bit it set. */
	bitcount = mapsize * 8;
	for (i = 0; i < bitcount; i++) {
		if (GETBIT( src, map[i] ))
			SETBIT( dst, i );
	}
} /* Permute */

static void KeyShift(uchar *key, const int numbits)

{
	int i;
	uchar keep = key[0]; /* Copy the highest order bits of the key. */

	/* Repeat the shift process <numbits> times.
	 */
	for (i = 0; i < numbits; i++) {
		int j;

		/* Shift the entire thing, byte by byte.
		 */
		for (j = 0; j < 7; j++) {
			if (j && (key[j] & 0x80)) /* If the top bit of this byte is set. */
				key[j - 1] |= 0x01; /* ...shift it to last byte's low bit. */
			key[j] <<= 1; /* Then left-shift the whole byte.     */
		}

		/* Now move the high-order bits of each 28-bit half-key to their
		 * correct locations.
		 * Bit 27 is the lowest order bit of the first half-key.
		 * Before the shift, it was the highest order bit of the 2nd half-key.
		 */
		if (GETBIT( key, 27 )) /* If bit 27 is set... */
		{
			CLRBIT( key, 27 ); /* ...clear bit 27. */
			SETBIT( key, 55 ); /* ...set lowest order bit of 2nd half-key. */
		}

		/* We kept the highest order bit of the first half-key in <keep>.
		 * If it's set, copy it to bit 27.
		 */
		if (keep & 0x80)
			SETBIT( key, 27 );

		/* Rotate the <keep> byte too, in case <numbits> is 2 and there's
		 * a second round coming.
		 */
		keep <<= 1;
	}
} /* KeyShift */

static void sbox(uchar *dst, const uchar *src)

{
	int i;

	/* Clear the destination array.
	 */
	for (i = 0; i < 4; i++)
		dst[i] = 0;

	/* For each set of six input bits...
	 */
	for (i = 0; i < 8; i++) {
		int j;
		int Snum;
		int bitnum;

		/* Extract the 6-bit integer from the source.
		 * This will be the lookup key within the SBox[i] array.
		 */
		for (Snum = j = 0, bitnum = (i * 6); j < 6; j++, bitnum++) {
			Snum <<= 1;
			Snum |= GETBIT( src, bitnum );
		}

		/* Find the correct value in the correct SBox[]
		 * and copy it into the destination.
		 * Left shift the nibble four bytes for even values of <i>.
		 */
		if (0 == (i % 2))
			dst[i / 2] |= ((SBox[i][Snum]) << 4);
		else
			dst[i / 2] |= SBox[i][Snum];
	}
} /* sbox */

static void xor(uchar *dst, const uchar *a, const uchar *b, const int count)

{
	int i;

	for (i = 0; i < count; i++)
		dst[i] = a[i] ^ b[i];
} /* xor */

/* -------------------------------------------------------------------------- **
 * Functions:
 */

uchar *auth_DESkey8to7(uchar *dst, const uchar *key)

{
	int i;
	uchar tmp[7];
	static const uint8_t map8to7[56] = { 0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12,
			13, 14, 16, 17, 18, 19, 20, 21, 22, 24, 25, 26, 27, 28, 29, 30, 32,
			33, 34, 35, 36, 37, 38, 40, 41, 42, 43, 44, 45, 46, 48, 49, 50, 51,
			52, 53, 54, 56, 57, 58, 59, 60, 61, 62 };

	if ((null == dst) || (null == key))
		return (null);

	Permute(tmp, key, map8to7, 7);
	for (i = 0; i < 7; i++)
		dst[i] = tmp[i];

	return (dst);
} /* auth_DESkey8to7 */
#define IP_FP_ON
#undef IP_FP_ON

uchar *auth_DEShash(uchar *dst, const uchar *key, const uchar *src)

{
	int i; /* Loop counter. */
	uchar K[7]; /* Holds the 7-byte key, as we manipulate it.          */
	uchar D[8]; /* The data block, as we manipulate it.         */
	uchar KTemp[7];

	/* Create the permutations of the key and the source.
	 */
	auth_DESkey8to7(KTemp, key);
	Permute(K, KTemp, KeyPermuteMap, 7);

	// skipping IP
#ifdef IP_FP_ON
	Permute( D, src, InitialPermuteMap, 8 );
#else
	int temp = 0;
	for (temp = 0; temp < 8; temp = temp + 1)
	{
		D[temp] = src[temp];
	} // copy src into Data array

#endif

#if debug
	printf("Round %i:\t", 0);
	for (temp = 0; temp < 8; temp = temp + 1)
	{
		printf("%02x ", D[temp]);
	}
	printf("\n");
#endif

	/* DES encryption proceeds in 16 rounds.
	 * The stuff inside the loop is known in the literature as "function f".
	 */
	for (i = 0; i < 16; i++)
	{
		int j;
		uchar *L = D; /* The left 4 bytes (half) of the data block.   */
		uchar *R = &(D[4]); /* The right half of the ciphertext block.      */
		uchar Rexp[6]; /* Expanded right half.                         */
		uchar Rn[4]; /* New value of R, as we manipulate it.         */
		uchar SubK[6]; /* The 48-bit subkey.                           */

		/* Generate the subkey for this round.
		 */
		KeyShift(K, KeyRotation[i]);
		Permute(SubK, K, KeyCompression, 6);

		/* Expand the right half (R) of the data block to 48 bytes,
		 * then XOR the result with the Subkey for this round.
		 */
		Permute(Rexp, R, DataExpansion, 6);
		xor(Rexp, Rexp, SubK, 6);

		/* S-Box substitutions, P-Box permutation, and final XOR.
		 * The S-Box substitutions return a 32-bit value, which is then
		 * run through the 32-bit to 32-bit P-Box permutation.  The P-Box
		 * result is then XOR'd with the left-hand half of the key.
		 * (Rexp is used as a temporary variable between the P-Box & XOR).
		 */
		sbox(Rn, Rexp);
		Permute(Rexp, Rn, PBox, 4);
		xor(Rn, L, Rexp, 4);

		/* The previous R becomes the new L,
		 * and Rn is moved into R ready for the next round.
		 */
		for (j = 0; j < 4; j++) {
			L[j] = R[j];
			R[j] = Rn[j];
		}

#ifdef debug
		printf("Round %i:\t", i);
		for (temp = 0; temp < 8; temp = temp + 1) {
			printf("%02x ", D[temp]);
		}
		printf("\n");
#endif
	}

	/* The encryption is complete.
	 * Now reverse-permute the ciphertext to produce the final result.
	 * We actually combine two steps here.  The penultimate step is to
	 * swap the positions of L and R in the result of the 16 rounds,
	 * after which the reverse of the Initial Permutation is applied.
	 * To save a step, the FinalPermuteMap applies both the L/R swap
	 * and the inverse of the Initial Permutation.
	 */
	// Skipping FP
#ifdef IP_FP_ON
	Permute( dst, D, FinalPermuteMap, 8 );
#else
	// since not doing FP these must be swapped
	dst[0] = D[4];
	dst[1] = D[5];
	dst[2] = D[6];
	dst[3] = D[7];
	dst[4] = D[0];
	dst[5] = D[1];
	dst[6] = D[2];
	dst[7] = D[3];
#endif

#ifdef debug
	int j = 0;
	printf("Round %i:\t", 16);
	for(j = 0; j < 8; j = j + 1)
	{
		printf("%02x ", dst[j]);
	}
	printf("\n");
#endif
	return (dst);
} /* auth_DEShash */

/* ========================================================================== */
