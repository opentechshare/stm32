
#include "stm32f10x.h"

/* 为了使编程书写方便，我们定义几个控制LED开关的宏 */
#define LED1_ON()	{GPIO_ResetBits(GPIOF, GPIO_Pin_6);}	/* PF6 = 0 点亮LED1 */
#define LED1_OFF()	{GPIO_SetBits(GPIOF, GPIO_Pin_6);}		/* PF6 = 1 熄灭LED1 */
#define LED2_ON()	{GPIO_ResetBits(GPIOF, GPIO_Pin_7);}	/* PF7 = 0 点亮LED2 */
#define LED2_OFF()	{GPIO_SetBits(GPIOF, GPIO_Pin_7);}		/* PF7 = 1 点亮LED2 */
#define LED3_ON()	{GPIO_ResetBits(GPIOF, GPIO_Pin_8);}	/* PF8 = 0 点亮LED3 */
#define LED3_OFF()	{GPIO_SetBits(GPIOF, GPIO_Pin_8);}		/* PF8 = 1 点亮LED3 */
#define LED4_ON()	{GPIO_ResetBits(GPIOF, GPIO_Pin_9);}	/* PF9 = 0 点亮LED4 */
#define LED4_OFF()	{GPIO_SetBits(GPIOF, GPIO_Pin_9);}		/* PF9 = 1 点亮LED4 */

void Delay(__IO uint32_t nCount)
{
	for (; nCount != 0; nCount--);
}

int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* 打开GPIOF 时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);

	/* 在将LED设置为输出前先设置输出1，避免一开始就点亮LED */
	GPIO_SetBits(GPIOF, GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);

	/* 可以对PF6 - PF9 一起初始化 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7
								| GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; /* 推挽输出模式 */
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure); /* 调用库函数初始化GPIO */
 
	/* 下面这个while循环实现简单的跑马灯功能 */
	while (1)
	{
		LED1_ON();		/* 点亮LED1 */
		Delay(0xAFFFF); /* 插入延时 */

		LED2_ON();		/* 点亮LED2 */
		LED3_ON();		/* 点亮LED3 */
		LED1_OFF();		/* 熄灭LED1 */
		Delay(0xAFFFF); /* 插入延时 */

		LED4_ON();		/* 点亮LED4 */
		LED2_OFF();		/* 关闭LED2 */
		LED3_OFF();		/* 关闭LED3 */
		Delay(0xAFFFF); /* 插入延时 */

		LED4_OFF();		/* 关闭LED4 */
		Delay(0xAFFFF); /* 插入延时 */
	}
}
