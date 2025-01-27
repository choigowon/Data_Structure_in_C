#include <stdio.h>
#include <stdlib.h>

void recursive(int n) {
	if (n == 0)
		return;
	recursive(n - 1);
	printf("%d ", n); // 재귀 호출 이후에 실행되므로 결과는 역순
}

int power(int x, int y) { // x의 y 거듭제곱
	if (y == 0)
		return 1;
	return x * power(x, y - 1);
}

int gcd(int x, int y) { // x와 y의 최대공약수
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int binarysearch(int* arr, int left, int right, int target) {
	if (left > right)
		return -1;
	int mid = (left + right) / 2;
	if (arr[mid] == target)
		return mid;
	if (arr[mid] < target)
		return binarysearch(arr, mid + 1, right, target);
	else
		return binarysearch(arr, left, mid - 1, target);
}

long long fibo(int n) { // O(2^n). 중복된 계산이 많아짐
	if (n <= 2)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

double mz[100] = { 0,1,1 };
double fibo1(int n) { // DP(top-down 방식): memoization
	if (mz[n] != 0)
		return mz[n];
	else {
		mz[n] = fibo(n - 1) + fibo(n - 2);
		return mz[n];
	}
}

double fibo2(int n) { // DP(bottom-up 방식): 반복문
	for (int i = 3; i <= n; i++) {
		mz[i] = mz[i - 1] + mz[i - 2];
	}
	return mz[n];
}

void hanoi(int n, char from, char temp, char to) {
	if (n == 1) { // 가장 큰 원 옮기기 (2)
		printf("%c->%c\n", from, to);
		return;
	}
	hanoi(n - 1, from, to, temp); // 나머지 원 임시 공간에 옮기기 (1)
	printf("%c->%c\n", from, to);
	hanoi(n - 1, temp, from, to); // 나머지 원 목표 공간에 옮기기 (3)
}

int main() {
	recursive(3);
	printf("\n2와 3의 거듭제곱: %d\n", power(2, 3));
	printf("72와 30의 최대공약수: %d\n", gcd(72, 30));

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int index;
	index = binarysearch(arr, 0, 9, 14);
	if (index == -1)
		printf("error\n");
	else
		printf("arr[%d]\n", index);

	printf("%lld\n", fibo(5));

	hanoi(3, 'A', 'B', 'C');
	return 0;
}
