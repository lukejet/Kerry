
#include <stdio.h>
#include <string.h>

int weishu(int aa)
{
	int tmp = aa;
	int ws = 0;
	if (aa < 0)
		ws = 1;
	while(1)
	{
		if (tmp == 0)
			break;
		tmp /= 10;
		ws++;
	}
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
