#pragma once
void BubbleSort(int* a, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (a[j] > a[j + 1])
			{
				a[j] ^= a[j + 1];
				a[j + 1] ^= a[j];
				a[j] ^= a[j + 1];
			}
		}
	}
}

void BubbleSortReverse(int* a, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = (size - 1); j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				a[j - 1] ^= a[j];
				a[j] ^= a[j - 1];
				a[j - 1] ^= a[j];
			}
		}
	}
}

void ShakerSort(int* a, int size)
{
	int i, start = 0, end = size - 1;
	char swap = 1;

	while ((start < end) && (swap))
	{
		swap = 0;
		// ---->
		for (i = start; i < end; i++)
		{
			if (a[i] > a[i + 1])
			{
				a[i] ^= a[i + 1];
				a[i + 1] ^= a[i];
				a[i] ^= a[i + 1];
				swap = 1;
			}
		}
		end--;

		// <----
		for (i = end; i > start; i--)
		{
			if (a[i - 1] > a[i])
			{
				a[i - 1] ^= a[i];
				a[i] ^= a[i - 1];
				a[i - 1] ^= a[i];
				swap = 1;
			}
		}
		start++;
	}

}

int CombSortNextStep(int step)
{
	step = (step * 10) / 13;
	if (step < 1)
	{
		return step;
	}
	return step;
}

void CombSort(int* a, int size)
{
	int i, step = size;
	char swap = 1;

	while (step != 1 || swap) {
		step = CombSortNextStep(step);
		swap = 0;

		for (i = 0; i < size - step; i++) {
			if (a[i] > a[i + step]) {
				a[i] ^= a[i + step];
				a[i + step] ^= a[i];
				a[i] ^= a[i + step];
				swap = 0;
			}
		}
	}
}

void InsertSort(int* a, int size)
{
	int i, j;

	for (i = 1; i < size; i++) {
		for (j = i; j > 0 && a[j - 1] > a[j]; j--) {
			a[j - 1] ^= a[j];
			a[j] ^= a[j - 1];
			a[j - 1] ^= a[j];
		}
	}
}

void ShellSort(int* a, int size)
{
	int i, j, step;

	for (step = size / 2; step > 0; step /= 2)
	{
		for (i = step; i < size; i++) {
			int tmp = a[i];

			for (j = i; j >= step; j -= step)
			{
				if (tmp < a[j - step])
				{
					a[j] = a[j - step];
				}
				else
				{
					break;
				}

			}
			a[j] = tmp;
		}
	}
}

void SelectSort(int* a, int size)
{
	int i, j;

	for (i = 0; i < size - 1; i++)
	{
		int key = i;
		for (j = i + 1; j < size; j++)
		{
			if (a[j] < a[key])
			{
				key = j;
			}
		}

		a[i] ^= a[key];
		a[key] ^= a[i];
		a[i] ^= a[key];
	}
}

void GnomeSort(int* a, int size)
{
	int i = 1, j = 2;

	while (i < size)
	{
		if (a[i - 1] < a[i])
		{
			i = j;
			j++;
		}
		else
		{
			a[i] ^= a[i - 1];
			a[i - 1] ^= a[i];
			a[i] ^= a[i - 1];
			i--;

			if (i == 0)
			{
				i = j;
				j++;
			}
		}

	}
}

void QuickSort(int* a, int size, int first, int last)
{
	int left = first,
		right = last,
		mid = a[(first + last) / 2];

	do
	{
		while ((a[left] < mid) && (left < last)) left++;
		while ((a[right] > mid) && (right > first)) right--;

		if (left <= right)
		{
			a[left] ^= a[right];
			a[right] ^= a[left];
			a[left] ^= a[right];
			left++; right--;
		}
	} while (left <= right);

	if (first < right) QuickSort(a, size, first, right);
	if (last > left) QuickSort(a, size, left, last);
}

//! heap sort

void SiftDown(int* a, int root, int bottom)
{
	int max_child;
	int	done = 0;

	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)
		{
			max_child = root * 2;
		}
		else if (a[root * 2] > a[root * 2 + 1])
		{
			max_child = root * 2;
		}
		else
		{
			max_child = root * 2 + 1;
		}

		if (a[root] < a[max_child])
		{
			a[root] ^= a[max_child];
			a[max_child] ^= a[root];
			a[root] ^= a[max_child];
			root = max_child;
		}
		else
		{
			done = 1;
		}
	}
}

void HeapSort(int* a, int size)
{
	int i;

	for (i = (size / 2); i >= 0; i--)
	{
		SiftDown(a, i, size - 1);
	}

	for (i = size - 1; i >= 1; i--)
	{
		a[0] ^= a[i];
		a[i] ^= a[0];
		a[0] ^= a[i];
		SiftDown(a, 0, i - 1);
	}
}