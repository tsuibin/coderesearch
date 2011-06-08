#define LED (*(volatile unsigned char *)0x20800000)

int mymain(void)
{
	while(1)
	{
		LED = 0xff;
	}

	return 0;
}
