#include <stdio.h>
using namespace std;

int main(void) {
	for (int i = 0; i < 5; ++i) {
		int row = i > 2 ? 4 - i : i;
        int paddings = !i ? 0 : (1 << row) - 1;
		for (int j = 0; j < paddings; ++j) printf(" ");
		for (int j = 0; j < 8 - paddings * 2; ++j) printf("*");
		printf("\n");
	}
	return 0;
}