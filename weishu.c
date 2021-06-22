
#include <stdio.h>
#include <string.h>

int weishu(int aa, int jz=10)
{
	int ws = 0;
	
	// 0 must be 1.
	if (aa == 0)
		return 1;
	
	// minus number has - , so add 1.
	if (aa < 0)
	{
		aa = -aa;
		++ws;
	}
	
	do
	{
		if (!aa)
			break;
		aa /= jz;
		++ws;
	} while(1);
	return ws;
}

int main(int argc, char* argv[])
{
	int clen;
	int count;
	int ret = 0;

	if (argc != 3)
		return -1;

	var1 = atoi(argv[1]);
	var2 = atoi(argv[2]);
	ret = (weishu(var1) == weishu(var2));
	
	printf("the two number has the %s weishu \n", (ret) ? "same" : "different");
	return 0;
}
