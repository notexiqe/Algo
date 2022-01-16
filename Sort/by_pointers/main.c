#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"
#include "sort.h"

int main(){
	int outerSwitchFlag = 0;
	int innerSwitchFlag = 0;

	int  gArraySize = 0;
	int* gArray = NULL;
	int** pArray = NULL;

	do {
		phill_array_menu();
		scanf("%d", &outerSwitchFlag);
		switch (outerSwitchFlag) {
			case 1: {
				srand((unsigned int)time(NULL));
				printf("\n\t\tInput array size: ");
				scanf("%u", &gArraySize);
				if ((gArray = (int*)malloc(sizeof(int) * gArraySize)) == NULL) {
					fprintf(stderr, "Error in line %d: malloc return NULL in line;\n", __LINE__);
					exit(1);
				}
				phill_rand_array(gArray, gArraySize);
				if ((pArray = (int**)malloc(sizeof(int*) * gArraySize)) == NULL) {
					fprintf(stderr, "Error in line %d: malloc return NULL in line;\n", __LINE__);
					exit(1);
				}

				phill_pArray(gArray, pArray, gArraySize);
				break;
			}
			case 2: {
				FILE* input;
				if ((input = fopen("input.txt", "r")) == NULL) {
					fprintf(stderr, "Error in line %d: file wasn't find!\n", __LINE__);
					exit(2);
				}
				gArraySize = array_find_size(input);
				if ((gArray = (int*)malloc(sizeof(int*) * gArraySize)) == NULL) {
					fprintf(stderr, "Error in line %d: malloc return NULL in line;\n", __LINE__);
					exit(1);
				}
				phill_file_array(input, gArray, gArraySize);
				fclose(input);
				break;

				if ((pArray = (int**)malloc(sizeof(int*) * gArraySize)) == NULL) {
					fprintf(stderr, "Error in line %d: malloc return NULL in line;\n", __LINE__);
					exit(1);
				}
				phill_pArray(gArray, pArray, gArraySize);
			}
			case 3: {
				exit(0);
			}
		}
		sort_array_menu(outerSwitchFlag);
		scanf("%d", &innerSwitchFlag);
		switch (innerSwitchFlag) {
			case  1: { bubble_sort(pArray, gArraySize); break; }
			case  2: { shaker_sort(pArray, gArraySize); break; }
			case  3: { comb_sort(pArray, gArraySize); break;	}
			case  4: { insert_sort(pArray, gArraySize); break; }
			case  5: { shell_sort(pArray, gArraySize); break; }
			case  6: { /*empty */ break;	}
			case  7: { gnome_sort(pArray, gArraySize); break; }
			case  8: { select_sort(pArray, gArraySize); break; }
			case  9: { quicksort(pArray, gArraySize, 0, (gArraySize - 1)); break; }
			case 10: { heap_sort(pArray, gArraySize); break; }
			default: { exit(0);	}
		}
		save_result(pArray, gArraySize);

		free(pArray);
		free(gArray);

		system("cls");
	} while (outerSwitchFlag != 3);

	return 0;
}
