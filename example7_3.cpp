int factorialIter(int n)
{
	int result = 1;
	for (int k = n; k > 0; k--)
	{
		result = result * k;
	}
	return result;
}