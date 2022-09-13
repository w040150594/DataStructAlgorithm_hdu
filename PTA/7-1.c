#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	int* s1 = (int*)malloc(sizeof(int) * n);  //分配内存
	int* s2 = (int*)malloc(sizeof(int) * n);
	int* s = (int*)malloc(sizeof(int) * 2 * n);
	for(int i = 0; i < n; i++)
		scanf("%d", &s1[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &s2[i]);
	int i = 0, j = 0, k = 0;
	//遍历两个数组，将较小的元素放入新数组
	while(i < n && j < n){
		if(s1[i] <= s2[j])
			s[k++] = s1[i++];
		else
			s[k++] = s2[j++];
	}
	//将剩余元素放入新数组
	while(i < n)
		s[k++] = s1[i++];
	while(j < n)
		s[k++] = s2[j++];
	//输出新数组
	printf("%d", s[(k - 1) / 2]);
	free(s1); free(s2); free(s);  //释放内存

	return 0;
}
