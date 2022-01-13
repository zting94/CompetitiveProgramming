#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int N;
ll sum1 = 0, sum2 = 0;
vector<int> arr;
int main()
{
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int i = 0;
	while(i <= N - 1)
	{
		if (i >= N - 1)
		{
			sum1 += arr[N -1];
			break;
		}
		if (arr[i] == 1 && arr[i + 1] > 1)
		{
			sum1 += arr[i];
			i++;
		}
		else
		{
			sum1 += max(arr[i] * arr[i + 1], arr[i] + arr[i + 1]);
			i += 2;
		}
	}
	i = N - 1;
	while (i >= 0)
	{
		if (i <= 0)
		{
			sum2 += arr[0];
			break;
		}
		if (arr[i] == 1 && arr[i - 1] <= 0)
		{
			sum2 += arr[i];
			i--;
		}
		else
		{
			sum2 += max(arr[i] * arr[i - 1], arr[i] + arr[i - 1]);
			i -= 2;
		}
	}
	cout << max(sum1, sum2);
	return 0;
}