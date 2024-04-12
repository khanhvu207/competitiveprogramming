struct dynamic_heap
{
	int summax, summin;
	priority_queue<int> heapmax;
	priority_queue<int, vector < int>, greater < int>> heapmin;

	void clear_heaps()
	{
		summax = summin = 0;
		while (!heapmax.empty()) heapmax.pop();
		while (!heapmin.empty()) heapmin.pop();
	}

	int get_median(int x)
	{
		if (heapmax.empty() && heapmin.empty())
		{
			heapmax.push(x);
			summax += x;
			return x;
		}

		int median = heapmax.size() >= heapmin.size() ? heapmax.top() : heapmin.top();
		if (x < median) heapmax.push(x), summax += x;
		else heapmin.push(x), summin += x;
		if (heapmax.size() > heapmin.size() + 1)
		{
			heapmin.push(heapmax.top());
			summin += heapmax.top();
			summax -= heapmax.top();
			heapmax.pop();
		}
		else if (heapmin.size() > heapmax.size() + 1)
		{
			heapmax.push(heapmin.top());
			summax += heapmin.top();
			summin -= heapmin.top();
			heapmin.pop();
		}

		return heapmax.size() >= heapmin.size() ? heapmax.top() : heapmin.top();
	}
};

