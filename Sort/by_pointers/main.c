#include "Header.h"

#include "Interface.c"
#include "Sort.c"

int main()
{
	int outerSwitchFlag = 0;
	int innerSwitchFlag = 0;

	int  gArraySize = 0;
	int* gArray = NULL;
	int** gpArray = NULL;

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
				gpArray = (int**)malloc(sizeof(int*) * gArraySize);
				if (gpArray == NULL)
				{
					fprintf(stderr, "Error in line %d: malloc return NULL in line;\n", __LINE__);
					exit(1);
				}

				PhillpArray(gArray, gpArray, gArraySize);
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

				gArray = (int*)malloc(sizeof(int*) * gArraySize);
				if (gArray == NULL)
				{
					fprintf(stderr, "Error in line %d: malloc return NULL in line;\n", __LINE__);
					exit(1);
				}
				PhillFileArray(input, gArray, gArraySize);
				fclose(input);

				gpArray = (int**)malloc(sizeof(int*) * gArraySize);
				if (gpArray == NULL)
				{
					fprintf(stderr, "Error in line %d: malloc return NULL in line;\n", __LINE__);
					exit(1);
				}
				PhillpArray(gArray, gpArray, gArraySize);
				break;
			}
			case 3:
			{
				exit(0);
			}
		}

		//PrintArray(gArray, gArraySize);

		SortArrayMenu(outerSwitchFlag);
		scanf("%d", &innerSwitchFlag);
		switch (innerSwitchFlag)
		{
			case  1:
			{
				BubbleSort(gpArray, gArraySize);
				break;
			}
			case  2:
			{
				ShakerSort(gpArray, gArraySize);
				break;
			}
			case  3:
			{
				CombSort(gpArray, gArraySize);
				break;
			}
			case  4:
			{
				InsertSort(gpArray, gArraySize);
				break;
			}
			case  5:
			{
				ShellSort(gpArray, gArraySize);
				break;
			}
			case  6:
			{
				/*empty */ break;
			}
			case  7:
			{
				GnomeSort(gpArray, gArraySize);
				break;
			}
			case  8:
			{
				SelectSort(gpArray, gArraySize);
				break;
			}
			case  9:
			{
				QuickSort(gpArray, gArraySize, 0, (gArraySize - 1));
				break;
			}
			case 10:
			{
				HeapSort(gpArray, gArraySize);
				break;
			}
			default:
			{
				exit(0);
			}
		}

		//printf("\n");
		//PrintpArray(gpArray, gArraySize);

		SaveResult(gpArray, gArraySize);

		free(gpArray);
		free(gArray);

		system("cls");
	} while (outerSwitchFlag != 3);

	return 0;
}