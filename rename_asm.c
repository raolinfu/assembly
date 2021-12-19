#include<stdio.h>
int main(){
	int ret;
	char *oldname = "a.txt";
	char *newname = "b.txt";
	asm volatile(
		"movl %2, %%ecx\n\t"
		"movl %1, %%ebx\n\t"
		"movl %0x26, %%eax\n\t"
		"int $0x80\n\t"
		"movl %%eax, %0"
		:"=m"(ret)
		:"b"(oldname), "c"(newname)
			);
	return 0;
}
