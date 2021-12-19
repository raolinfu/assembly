#include<stdio.h>
#include<sys/syscall.h>
int main(){
	int ret;
	char oldname[] = "a.txt";
	char newname[] = "b.txt";
	ret = syscall(SYS_rename, oldname, newname);
	if(ret == 0)
		printf("rename successfully\n");
	else
		printf("rename failed\n");
	return 0;
}
