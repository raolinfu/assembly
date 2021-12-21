#include<stdio.h>
#include<unistd.h>
#include<time.h>

int main(){
	time_t tt;
	struct tm *t;
	asm volatile(
		"mov $0, %%ebx\n\t"
		"mov $0xd, %%eax\n\t"
		"int $0x80\n\t"
		"mov %%eax, %0\n\t"
		:"=m"(tt)
	);
	t = localtime(&tt);
	printf("time:%d:%d:%d:%d:%d:%d\n", t->tm_year, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
	write(1, "raolinhu\n", 15);

	int fd = 1;
	char str[]="hahahaha\n";
	// char *str="hahahaha";
	int n = 12;
	int ret;
	// printf("----------------");
	asm volatile(
		"int $0x80"
		:"=a"(ret)
		:"a"(1), "b"(1), "c"("linhu"), "d"(12)
		// :"a"(1), "b"(1), "c"(str), "d"(12)
	);
	return 0;
}
