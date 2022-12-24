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
		PhillArrayMenu();
		scanf("%d", &outerSwitchFlag);
		switch (outerSwitchFlag)
		{
			case 1:
			{
				srand((unsigned int)time(NULL));
				printf("\n\t\tInput array size: ");
				scanf("%u", &gArraySize);

				gArray = (int*)malloc(sizeof(int) * gArraySize);
				if (gArray == NULL)
				{
					fprintf(stderr, "Error in line %d: malloc return NULL in line;\n", __LINE__);
					exit(1);
				}

				PhillRandArray(gArray, gArraySize);
				break;
			}

			case 2:
			{
				FILE* input = fopen("input.txt", "r");
				if (input == NULL)
				{
					fprintf(stderr, "Error in line %d: file wasn't find!\n", __LINE__);
					exit(2);
				}

				gArraySize = FindArraySize(input);

				gArray = (int*)malloc(sizeof(int) * gArraySize);
				if (gArray == NULL)
				{
					fprintf(stderr, "Error in line %d: malloc return NULL in line;\n", __LINE__);
					exit(1);
				}

				PhillArrayFile(input, gArray, gArraySize);
				fclose(input);
				break;
			}

			case 3:
			{
				exit(0);
			}
		}

		//printf("\n");
		PrintArray(gArray, gArraySize);

		SortArrayMenu(outerSwitchFlag);

		scanf("%d", &innerSwitchFlag);
		switch (innerSwitchFlag)
		{
			case  1: { BubbleSort(gArray, gArraySize); break; }
			case  2: { ShakerSort(gArray, gArraySize); break; }
			case  3: { CombSort(gArray, gArraySize); break;	}
			case  4: { InsertSort(gArray, gArraySize); break; }
			case  5: { ShellSort(gArray, gArraySize); break; }
			case  6: { /*empty */ break;	}
			case  7: { GnomeSort(gArray, gArraySize); break; }
			case  8: { SelectSort(gArray, gArraySize); break; }
			case  9: { QuickSort(gArray, gArraySize, 0, (gArraySize - 1)); break; }
			case 10: { HeapSort(gArray, gArraySize); break; }
			default: { exit(0);	}
		}

		SaveResult(gArray, gArraySize);

		free(gArray);

		system("cls");

	} while (outerSwitchFlag != 3);

	return 0;
}