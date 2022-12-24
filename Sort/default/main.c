#include "Header.h"

#include "Interface.c"
#include "Sort.c"

int main()
{
	int outerSwitchFlag = 0;
	int innerSwitchFlag = 0;

	int* gArray = NULL;
	int  gArraySize = 0;
	do
	{
		phill_array_menu();
		scanf("%d", &outerSwitchFlag);
		switch (outerSwitchFlag)
		{
			case 1:
			{
				srand((unsigned int)time(NULL));
				printf("\n\t\tInput array size: ");
				scanf("%u", &gArraySize);
				if ((gArray = (int*)malloc(sizeof(int) * gArraySize)) == NULL)
				{
					fprintf(stderr, "Error in line %d: malloc return NULL in line;\n", __LINE__);
					exit(1);
				}

				array_phill_rand(gArray, gArraySize);
				break;
			}
		case 2:
			{
				FILE* input;
				if ((input = fopen("input.txt", "r")) == NULL)
				{
					fprintf(stderr, "Error in line %d: file wasn't find!\n", __LINE__);
					exit(2);
				}

				gArraySize = array_find_size(input);
				if ((gArray = (int*)malloc(sizeof(int) * gArraySize)) == NULL)
				{
					fprintf(stderr, "Error in line %d: malloc return NULL in line;\n", __LINE__);
					exit(1);
				}

				array_phill_file(input, gArray, gArraySize);
				fclose(input);
				break;
			}
		case 3:
			{
				exit(0);
			}
		}

		array_print(gArray, gArraySize);
		sort_array_menu(outerSwitchFlag);
		scanf("%d", &innerSwitchFlag);
		switch (innerSwitchFlag) {
		case  1: { bubble_sort(gArray, gArraySize); break; }
		case  2: { shaker_sort(gArray, gArraySize); break; }
		case  3: { comb_sort(gArray, gArraySize); break;	}
		case  4: { insert_sort(gArray, gArraySize); break; }
		case  5: { shell_sort(gArray, gArraySize); break; }
		case  6: { /*empty */ break;	}
		case  7: { gnome_sort(gArray, gArraySize); break; }
		case  8: { select_sort(gArray, gArraySize); break; }
		case  9: { quicksort(gArray, gArraySize, 0, (gArraySize - 1)); break; }
		case 10: { heap_sort(gArray, gArraySize); break; }
		default: { exit(0);	}
		}
		save_result(gArray, gArraySize);

		free(gArray);

		system("cls");

	} while (outerSwitchFlag != 3);

	return 0;
}
