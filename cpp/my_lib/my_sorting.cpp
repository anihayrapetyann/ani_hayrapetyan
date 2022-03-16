#include <iostream>
#include "my_sorting.h"

void sort_min_max (int** matrix, int height, int width) {
        for (int* ptr = *matrix; ptr < *matrix + width; ptr++) {
                for (int** fpptr = matrix; fpptr < matrix + height - 1; fpptr++) {
                        for (int** spptr = fpptr + 1; spptr < matrix + height; spptr++) {
                                int a = *(*fpptr + (ptr - *matrix));
                                int b = *(*spptr + (ptr - *matrix));
                                if (a > b) {
                                        *(*fpptr + (ptr - *matrix)) = b;
                                        *(*spptr + (ptr - *matrix)) = a;
                                }
                        }
                }
        }
}


