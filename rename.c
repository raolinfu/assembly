#include<stdio.h>
#include<unistd.h>
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
	// write(1, "hello", 7);
	ret = syscall(SYS_write, 1, "world\n", 8);
	return 0;
}
