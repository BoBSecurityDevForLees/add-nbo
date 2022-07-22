#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include "add.h"

int main(int argc, char **argv)
{
	FILE* fp1 = fopen(argv[1], "rb");
	FILE* fp2 = fopen(argv[2], "rb");
	
	uint32_t s1 = 0;
	uint32_t s2 = 0;

	fread(&s1, sizeof(s1), 1, fp1);
	fread(&s2, sizeof(s2), 1, fp2);
	
	printf("%d(0x%03x) + %d(0x%03x) = %d(0x%03x)\n", ntohl(s1), 
			ntohl(s1), ntohl(s2), ntohl(s2), 
			add_nbo(ntohl(s1),ntohl(s2)), 
			add_nbo(ntohl(s1),ntohl(s2)));
	return 0;
}
