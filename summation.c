// summetion of all array intergers
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		ans=ans+a[i];
	}
	prinf(" ans = %d",ans);
	return 0;
}
