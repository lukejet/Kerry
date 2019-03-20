
#include <stdio.h>
#include <string.h>

int weishu(int aa)
{
	int ws = 0;
	
	// minus number has - , so add 1.
	if (aa < 0)
		return weishu(-aa) + 1;
	
	do
	{
		if (!aa)
			break;
		aa /= 10;
		ws++;
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

	clen = atoi(argv[1]);
	count = atoi(argv[2]);
	ret = (weishu(clen) == weishu(count));
	
	printf("the two number has the %s weishu \n", (ret) ? "same" : "different");
	return 0;
}
