#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <bit>

using namespace std;
inline int ran(int n) {
	return 1ll * rand() * rand() % n + 1;
}
int absVal(int x) {
	int tmp = (x >> 31);
	return (x ^ tmp) + (~tmp) + 1;
}
int absVal_standard(int x) {
	return (x < 0) ? -x : x;
}
void test_absVal() {
	int n = 10,lim = 100;
	while (n--) {
		int x = ran(2 * lim) - lim;
		// if (absVal(x) != absVal_standard(x)) {
		// 	// cout << x << " " << absVal(x) << " " << absVal_standard(x) << endl;
		// }
        cout << "x: " << x << " absVal: " << absVal(x) << " absVal_standard: " << absVal_standard(x) << endl;
	}
}

int Negat(int x) {
	return (~x) + 1;
}
int Negat_standard(int x) {
	return -x;
}
void test_Negat() {
	int n = 10, lim = 100;
	while (n--) {
		int x = ran(2 * lim) - lim;
		if (Negat(x) != Negat_standard(x)) {
			cout << x << " " << Negat(x) << " " << Negat_standard(x) << endl;
		}
	}
}


int bitAnd(int x, int y) {
	return ~((~x) | (~y));
}
int bitAnd_standard(int x, int y) {
	return x & y;
}
void test_bitAnd() {
	int n = 10, lim = 100;
	while (n--) {
		int x = ran(2 * lim) - lim, y = ran(2 * lim) - lim;
		if (bitAnd(x,y) != bitAnd_standard(x,y)) {
			cout << x << " " << y << " " << bitAnd(x, y) << " " << bitAnd_standard(x, y) << endl;
		}
	}
}

int bitOr(int x, int y) {
	return ~((~x) & (~y));
}
int bitOr_standard(int x, int y) {
	return x | y;
}
void test_bitOr() {
	int n = 10, lim = 100;
	while (n--) {
		int x = ran(2 * lim) - lim, y = ran(2 * lim) - lim;
		if (bitOr(x, y) != bitOr_standard(x, y)) {
			cout << x << " " << y << " " << bitOr(x, y) << " " << bitOr_standard(x, y) << endl;
		}
	}
}


int bitXor(int x, int y) {
	return ~( (~(x & (~y) ) ) & (~( (~x) & y) ) );
}
int bitXor_standard(int x, int y) {
	return x ^ y;
}
void test_bitXor() {
	int n = 10, lim = 100;
	while (n--) {
		int x = ran(2 * lim) - lim, y = ran(2 * lim) - lim;
		if (bitXor(x, y) != bitXor_standard(x, y)) {
			cout << x << " " << y << " " << bitXor(x, y) << " " << bitXor_standard(x, y) << endl;
		}
	}
}


int isTmax(int x) {
	return (~(x + 1)) == x;
}

int bitCount(int x) {
	x = ((x & (x >> 1) ) & 0x55555555) + ((x | (x>>1)) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
	x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
	x += (x >> 16) & 0x0000ffff;
	return x&0x0000ffff;

}
int bitCount_standard(int x) {
	unsigned int y = x;
	return __popcount(y);
}
void test_bitCount() {
	int n = 10, lim = 100000000;
	while (n--) {
		int x = ran(2 * lim) * ran(2 * lim) * ran(2 * lim);
		cout << "x: " << x << " bitCount: " << bitCount(x) << " bitCount_standard: " << bitCount_standard(x) << endl;
	}

}

int bitMask(int highbit, int lowbit) {

	return (1 << (highbit + 1)) +  (~((1 << lowbit))) + 1;
}
int bitMask_standard(int highbit, int lowbit) {
	int x=0;
	for (int i = lowbit; i <= highbit; ++i) {
		x += 1 << i;
	}
	return x;
}
void test_bitMask() {
	int n = 10, lim = 32;
	while (n--) {
		int h = ran(lim) - 1, l = ran(lim) - 1;
		if (h < l)swap(h, l);
		if (bitMask(h, l) != bitMask_standard(h, l)) {
			cout << h << " " << l << " " << bitMask(h, l) << " " << bitMask_standard(h, l) << endl;
		}
	}
}

int addOK(int x, int y) {

	return (((~(x ^ y)) & (x ^ (x + y))) >> 31) & 1;
}
int addOK_standard(int x, int y) {
	return (x > 0 && y > 0 && x + y < 0) || (x < 0 && y < 0 && x + y>0);
}
void test_addOK() {
	int n = 1000000, lim = 1e9;
	while (n--) {
		int x = 1ll * ran(lim) * ran(lim) * ran(lim), y = 1ll * ran(lim) * ran(lim) * ran(lim);
		if (addOK(x, y) != addOK_standard(x, y)) {
			cout << x << " " << y << " " << addOK(x, y) << " " << addOK_standard(x, y) << endl;
		}
	}
}
int byteSwap(int x, int n, int m) {
	n *= 8, m *= 8;
	int tmp = ((x >> n) ^ (x >> m)) & 0xff;
	return (tmp << n) ^ ((tmp << m) ^ x);
}
// 改变运算顺序可以优化指令数
// 用x86不用x64
int main() {
	srand((unsigned(time(0))));
	// test_absVal();
//	test_Negat();
//	test_bitAnd();
//	test_bitOr();
//	test_bitXor();
//	cout << isTmax(0x7fffffff) << endl;
//	if (isTmax((1ll << 31) - 1))cout << "Yes" << endl;
//	else cout << "No" << endl;
	// test_bitCount();
//	bitCount_second(-1);
//	bitCount(-1);
//  test_bitMask();
//	test_addOK();
//	cout << addOK(1, -3) << endl;
	printf("input = %8x, output = %8x\n", 0x12345678, byteSwap(0x12345678, 1, 3));
	printf("input = %8x, output = %8x\n", 0xdeadbeef, byteSwap(0xdeadbeef, 0, 2));
	return 0;
}
