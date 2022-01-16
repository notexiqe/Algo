void bubble_sort(int** p, int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < (size - i - 1); j++) {
			if (*p[j] > *p[j + 1]) {
				int* tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}

void bubble_sort_reverse(int** p, int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = (size - 1); j > i; j--) {
			if (*p[j - 1] > *p[j]) {
				int* tmp = p[j - 1];
				p[j - 1] = p[j];
				p[j] = tmp;
			}
		}
	}
}

void shaker_sort(int** p, int size) {
	int i, start = 0, end = size - 1;
	char swap = 1;

	while ((start < end) && (swap)) {
		swap = 0;
		// ---->
		for (i = start; i < end; i++) {
			if (*p[i] > *p[i + 1]) {
				int* tmp = p[i];
				p[i] = p[i + 1];
				p[i + 1] = tmp;
				swap = 1;
			}
		}
		end--;

		// <----
		for (i = end; i > start; i--) {
			if (*p[i - 1] > *p[i]) {
				int* tmp = p[i - 1];
				p[i - 1] = p[i];
				p[i] = tmp;
				swap = 1;
			}
		}
		start++;
	}

}

int next_step_comb_sort(int step) {
	step = (step * 10) / 13;
	if (step < 1) {
		return step;
	}
	return step;
}

void comb_sort(int** p, int size) {
	int i, step = size;
	char swap = 1;

	while (step != 1 || swap) {
		step = next_step_comb_sort(step);
		swap = 0;

		for (i = 0; i < size - step; i++) {
			if (*p[i] > *p[i + step]) {
				int* tmp = p[i];
				p[i] = p[i + step];
				p[i + step] = tmp;
				//p[i] ^= p[i + step];
				//p[i + step] ^= p[i];
				//p[i] ^= p[i + step];
				swap = 0;
			}
		}
	}
}

void insert_sort(int** p, int size) {
	int i, j;

	for (i = 1; i < size; i++) {
		for (j = i; j > 0 && *p[j - 1] > *p[j]; j--) {
			int* tmp = p[j - 1];
			p[j - 1] = p[j];
			p[j] = tmp;
		}
	}
}

void shell_sort(int** p, int size) {
	int i, j, step;

	for (step = size / 2; step > 0; step /= 2) {
		for (i = step; i < size; i++) {
			int* tmp = p[i];

			for (j = i; j >= step; j -= step) {
				if (*tmp < *p[j - step]) {
					p[j] = p[j - step];
				}
				else {
					break;
				}
			}
			p[j] = tmp;
		}
	}
}

void select_sort(int** p, int size) {
	int i, j;

	for (i = 0; i < size - 1; i++)
	{
		int key = i;
		for (j = i + 1; j < size; j++)
			if (*p[j] < *p[key])
			{
				key = j;
			}
		int* tmp = p[i];
		p[i] = p[key];
		p[key] = tmp;
	}
}

void gnome_sort(int** p, int size) {
	int i = 1, j = 2;

	while (i < size) {
		if (*p[i - 1] < *p[i]) {
			i = j;
			j++;
		}
		else {
			int* tmp = p[i];
			p[i] = p[i - 1];
			p[i - 1] = tmp;
			i--;
			if (i == 0) {
				i = j;
				j++;
			}
		}

	}
}

void quicksort(int** p, int size, int first, int last) {
	int left = first,
		right = last,
		mid = *p[(first + last) / 2];

	do
	{
		while ((*p[left] < mid) && (left < last)) left++;
		while ((*p[right] > mid) && (right > first)) right--;

		if (left <= right)
		{
			int* tmp = p[left];
			p[left] = p[right];
			p[right] = tmp;
			//p[left] ^= p[right];
			//p[right] ^= p[left];
			//p[left] ^= p[right];
			left++; right--;
		}
	} while (left <= right);

	if (first < right) quicksort(p, size, first, right);
	if (last > left) quicksort(p, size, left, last);
}

//! heap sort

void sift_down(int** p, int root, int bottom) {
	int max_child;
	int done = 0;

	while ((root * 2 <= bottom) && (!done)) {
		if (root * 2 == bottom) {
			max_child = root * 2;
		}
		else if (*p[root * 2] > *p[root * 2 + 1]) {
			max_child = root * 2;
		}
		else {
			max_child = root * 2 + 1;
		}
		if (*p[root] < *p[max_child]) {

			int* tmp = p[root];
			p[root] = p[max_child];
			p[max_child] = tmp;
			root = max_child;
		}
		else {
			done = 1;
		}
	}
}

void heap_sort(int** p, int size) {
	int i;

	for (i = (size / 2); i >= 0; i--) {
		sift_down(p, i, size - 1);
	}
	for (i = size - 1; i >= 1; i--) {
		int* tmp = p[0];
		p[0] = p[i];
		p[i] = tmp;
		sift_down(p, 0, i - 1);
	}
}
