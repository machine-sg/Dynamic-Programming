vector <int> getOrdering( vector <int> height, vector <int> bloom, vector <int> wilt ) 
{
	int n = height.size();
	vector <int> res (n);
	vector <int> mark (n, 0);
	int mini, ind;
	bool b;
	for (int i = n-1; i >= 0; i--)
	{
		ind = mini = 1001;
		for (int j = 0; j < n; j++)
			if (!mark[j])
			{
				b = true;
				for (int k = 0; k < n; k++)
					if (!mark[k] && height[k] > height[j] &&
						( (bloom[j] >= bloom[k] && bloom[j] <= wilt[k]) || (bloom[k] >= bloom[j] && bloom[k] <= wilt[j]) )
					    )
					{
						b = false;
						break;
					}
				if (b && height[j] < mini)
				{
					mini = height[j];
					ind = j;
				}
			}
		mark[ind] = 1;
		res[i] = mini;
	}
	return res;
}
