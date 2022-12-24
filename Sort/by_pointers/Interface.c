#pragma once
#define MSG_BUF_SIZE 256

void PhillArrayMenu()
{
	printf("\t\tHow u want phill array?\n");
	printf("\t1: phill array with rand();\n");
	printf("\t2: read from file(Array size not specified);\n");
	printf("\t3: exit from programm;\n");
	printf("\tSelect one of the options: ");
	return;
}

void SortArrayMenu(int n)
{
	n == 1 ? printf("\n\t\tArray was phill with rand();\n") : printf("\n\t\tArray was read from file;\n");
	printf("\t\tHow to sort array?\n");
	printf("\t\t1: Bubble sort\n");
	printf("\t\t2: Shaker sort\n");
	printf("\t\t3: Comb sort\n");
	printf("\t\t4: Insert sort\n");
	printf("\t\t5: Shell sort\n");
	printf("\t\t6: Tree sort\n");
	printf("\t\t7: Gnome sort\n");
	printf("\t\t8: Select sort\n");
	printf("\t\t9: Quick sort\n");
	printf("\t\t10: Heap Sort\n");
	printf("\t\tSelect one of the options: ");
	return;
}

void PrintArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return;
}

void PhillRandArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 100;
	}
	return;
}

int FindArraySize(FILE* f)
{
	int count = 0;
	fseek(f, 0, SEEK_SET);
	while (!feof(f))
	{
		int value;
		if (fscanf(f, "%d", &value) == 1)
		{
			count++;
		}
	}
	return count;
}

void PhillFileArray(FILE* f, int* a, int size)
{
	fseek(f, 0, SEEK_SET);
	for (int i = 0; i < size; ++i)
	{
		fscanf(f, "%d", &a[i]);
	}
	return;
}

void PhillpArray(int* a, int** pa, int size)
{
	for (int i = 0; i < size; i++)
	{
		pa[i] = &a[i];
	}
	printf("\n");
	return;
}

void PrintpArray(int** p, int size)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(stdout, "%d ", *p[i]);
	}
}

void SaveResult(int** p, int size)
{
	int i;
	char check;
	char filename[MSG_BUF_SIZE];
	FILE* output;

	printf("\n\t\tArray was sort.\n\t\tDo u wanna save results in file? Y/N ");
	check = _getch();
	if (check == 'Y' || check == 'y')
	{
		printf("\n\t\tEnter file name: ");
		scanf("%s", &filename);
		filename[strlen(filename)] = '\0';
		if ((output = fopen(filename, "a")) == NULL)
		{
			fprintf(stderr, "\n\t\tError in line %d: Cannot create/open file!\n", __LINE__);
		}
		for (i = 0; i < size; i++)
		{
			fprintf(output, "%d ", *p[i]);
		}
		fprintf_s(output, "\n");
		fclose(output);
	}
	else
	{
		printf("\n\t\tResult will not be saved ");
		_getch();
		return;
	}
}