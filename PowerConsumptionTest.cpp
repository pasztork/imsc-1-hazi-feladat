#include <iostream>
#include <cstdlib>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int capacity, int weights[], int values[], int n)
{
	if (n == 0 || capacity == 0)
		return 0;

	if (weights[n - 1] > capacity)
		return knapSack(capacity, weights, values, n - 1);

	return max(
		values[n - 1] + knapSack(capacity - weights[n - 1], weights, values, n - 1),
		knapSack(capacity, weights, values, n - 1)
	);
}

void fillArrays(int values[], int weights[])
{
	for (int i = 0; i < sizeof(values) / sizeof(int); i++)
		values[i] = rand() % 100 + 1;

	for (int i = 0; i < sizeof(weights) / sizeof(int); i++)
		values[i] = rand() % 50 + 1;
}

int main()
{
	const int numValues = 500;
	srand((unsigned)time(NULL));
	int values[numValues];
	int weights[numValues];
	fillArrays(values, weights);
	int capacity = 3 * rand() % 150 + 1;
	int n = sizeof(values) / sizeof(values[0]);
	std::cout << knapSack(capacity, weights, values, n) << '\n';
}