#include <iostream>
using namespace std;

const int N = 100010, M = 1000010;
char p[N], s[M];
int ne[N];

int main()
{
	int n, m;
	cin >> n >> p + 1 >> m >> s + 1;
	ne[1] = 0;
	ne[0] = 0;
	//next数组
	for (int i = 2, j = 1; i <= n; i++)
	{
	    if (j == 0) j = 1; 
		while (j > 1 && p[i] != p[j]) 
		{
            j = ne[j-1];
            if (j == 0) j = 1;  
     }
		if (p[i] == p[j]) j++;
		ne[i] = j;
	}

	//kmp匹配
	for (int i = 1, j = 1; i <= m; i++)
	{
	    if (j == 0) j = 1; 
		while (j > 1 && s[i] != p[j]) 
		{
            j = ne[j-1];
            if (j == 0) j = 1;  
        }
		if (s[i] == p[j]) j++;
		if (j == n+1)
		{
			printf("%d ", i - n+1);
			j = ne[j-1];
		}
	}
	return 0;
}