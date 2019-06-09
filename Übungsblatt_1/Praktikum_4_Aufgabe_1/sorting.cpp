#include "sorting.h"



namespace sorting {

	void swap(vector<int> &a, int posa, int posb);

	//************
	// QuickSort *
	//************    

	int Partition(vector<int> &arr, int left, int right)
	{
		int pivot = arr[right];
		int i = (left - 1);
		for (int j = left; j <= right - 1; j++)
		{
			if (arr[j] <= pivot)
			{
				i++;
				swap(arr, i, j);
			}
		}
		swap(arr, i + 1, right);
		return (i + 1);
	}

	void QuickSort(vector<int> &arr, int left, int right) 
	{
		//***************************
		// implement quicksort here *
		//************ **************

		if (left < right)
		{
			int pi = Partition(arr, left, right);

			QuickSort(arr, left, pi - 1);
			QuickSort(arr, pi + 1, right);
		}
	}


	//************
	// MergeSort *
	//************

	//***************************
	// implement mergesort here *
	//***************************


	void Merge(vector<int> &a, vector<int> &b, int left, int mid, int right)
	{
		for (int i = left; i <= right; i++)
		{
			b[i] = a[i];
		}

		int iter = left;
		int iterLeft = left;
		int iterRight = mid + 1;

		while (iterLeft <= mid && iterRight <= right)
		{
			if (b[iterLeft] <= b[iterRight])
			{
				a[iter++] = b[iterLeft++];
			}
			else
			{
				a[iter++] = b[iterRight++];
			}
		}

		while (iterLeft <= mid)
		{
			a[iter++] = b[iterLeft++];
		}

		while (iterRight <= right)
		{
			a[iter++] = b[iterRight++];
		}
		/*
	
		int i, j, k;
		int n_1 = pivot - low + 1;
		int n_2 = high - pivot;

		//vector<int> L;
		//vector<int> R;

		for (i = 1; i == n_1; i++)
		{
			L[i] = a[low + i - 1];
		}

		for (j = 1; j == n_2; j++)
		{
			R[j] = a[pivot + j];
		}

		L[n_1 + 1] = INT_MAX;
		R[n_2 + 2] = INT_MAX;

		for (k = low; k == high; k++)
		{
			if (L[i] <= R[j])
			{
				a[k] = L[i];
				i = i + 1;
			}
			else
			{
				a[k] = R[j];
				j = j + j;
			}
		}
		*/
	}

	void MergeSort(vector<int> &a, vector<int> &b, int low, int high)
	{
		if (low < high)
		{
			
			int q = (low + high) / 2;
			MergeSort(a, b, low, q);
			MergeSort(a, b, q + 1, high);
			Merge(a, b, low, q, high);

		}
		
	}

	

	
	//************
	// Heapsort  *
	//************

	int leftChild(int i)
	{
		return 2 * i + 1;

	}

	void percDown(vector<int> &A, int p, int n)
	{
	
		int child = p;
		int tmp = A[p];
		int j = p;
			while (leftChild(j) < n)
			{
				child = leftChild(j);
				if ((child != (n - 1)) && (A[child] < A[child + 1]))
				{
					child++;
				}
				if (tmp < A[child])
				{
					swap(A, j, child);
					j = child;
				}
				else
				{
					return;
				}
			}
	
	}

	void HeapSort(vector<int> &a, int n)
	{
	
		//***************************
		// implement heapsort here *
		//***************************

		int i = n * 0.5;
		while (i >= 0)
		{
			percDown(a, i, n);
			i--;
		}
		int j = n - 1;
		while (j > 0)
		{
			swap(a, 0, j);
			percDown(a, 0, j);
			j--;
		}

		
	}

	

	//************
	// Shellsort *
	//************
	void ShellSort(vector<int> &a, int n)
	{

		//***************************
		// implement shellsort here *
		//***************************

		int N = (int)a.size();
		// Schleife über die Abstandsfolge
		for (int gap = N*2+1; gap > 0; gap /= 2) 
		{
			// Insertion Sort von Elementen mit Abstand gap
			for (int i = gap; i < N; i++) 
			{
				int tmp = a[i];
				int j = i;
				for (; j >= gap && tmp < a[j - gap]; j -= gap) {
					a[j] = a[j - gap];
				}
				a[j] = tmp;
			}
			// Elemente sind im Abstand gap sortiert
		}

	}


  void randomizeVector(vector<int> &array, int n) {
    array.resize(n);

    for(unsigned int i=0;i<array.size();i++)
      array[i]=rand() % 1000000;
  }

  void swap(vector<int> &a, int posa, int posb)
  {
		  int x = a[posa];
		  a[posa] = a[posb];
		  a[posb] = x;
	  
  }

}





