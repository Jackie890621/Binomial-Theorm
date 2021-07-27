#include <iostream>
#include <stdio.h>
using namespace std;

int main() 
{
   	int n, k = 0; 
	int a[100], b[100], ans[50];
	unsigned __int128 result, temp, temp2;
   	scanf("%d", &n);
   	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		if (b[i] > (a[i] / 2)) {
			b[i] = a[i] - b[i];
		}
	}
	for (int i = 0; i < n; i++) {	
		result = 1;
		temp = a[i];
		temp2 = 1;
		for (int j = 1; j <= b[i]; j++) {
			if (temp > (a[i] - b[i])) {
				result *= temp;
				temp--;
			}
			temp2 *= j;
			if (result % j == 0) {
				result /= j;
				temp2 /= j;
			}
		}
		result /= temp2;
		k = 0;
		while (1) {
			if (result == 0) {
				break;
			}
			ans[k] = result % 10;
			result /= 10;
			k++;
		}
		for (int j = k - 1; j >= 0; j--) {
			printf("%d", ans[j]);
		}
		printf("\n");
	}
   	return 0;
}
