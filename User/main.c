
#include "stm32f10x.h"

/* Ϊ��ʹ�����д���㣬���Ƕ��弸������LED���صĺ� */
#define LED1_ON()	{GPIO_ResetBits(GPIOF, GPIO_Pin_6);}	/* PF6 = 0 ����LED1 */
#define LED1_OFF()	{GPIO_SetBits(GPIOF, GPIO_Pin_6);}		/* PF6 = 1 Ϩ��LED1 */
#define LED2_ON()	{GPIO_ResetBits(GPIOF, GPIO_Pin_7);}	/* PF7 = 0 ����LED2 */
#define LED2_OFF()	{GPIO_SetBits(GPIOF, GPIO_Pin_7);}		/* PF7 = 1 ����LED2 */
#define LED3_ON()	{GPIO_ResetBits(GPIOF, GPIO_Pin_8);}	/* PF8 = 0 ����LED3 */
#define LED3_OFF()	{GPIO_SetBits(GPIOF, GPIO_Pin_8);}		/* PF8 = 1 ����LED3 */
#define LED4_ON()	{GPIO_ResetBits(GPIOF, GPIO_Pin_9);}	/* PF9 = 0 ����LED4 */
#define LED4_OFF()	{GPIO_SetBits(GPIOF, GPIO_Pin_9);}		/* PF9 = 1 ����LED4 */

void Delay(__IO uint32_t nCount)
{
	for (; nCount != 0; nCount--);
}

int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* ��GPIOF ʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);

	/* �ڽ�LED����Ϊ���ǰ���������1������һ��ʼ�͵���LED */
	GPIO_SetBits(GPIOF, GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);

	/* ���Զ�PF6 - PF9 һ���ʼ�� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7
								| GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; /* �������ģʽ */
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure); /* ���ÿ⺯����ʼ��GPIO */
 
	/* �������whileѭ��ʵ�ּ򵥵�����ƹ��� */
	while (1)
	{
		LED1_ON();		/* ����LED1 */
		Delay(0xAFFFF); /* ������ʱ */

		LED2_ON();		/* ����LED2 */
		LED3_ON();		/* ����LED3 */
		LED1_OFF();		/* Ϩ��LED1 */
		Delay(0xAFFFF); /* ������ʱ */

		LED4_ON();		/* ����LED4 */
		LED2_OFF();		/* �ر�LED2 */
		LED3_OFF();		/* �ر�LED3 */
		Delay(0xAFFFF); /* ������ʱ */

		LED4_OFF();		/* �ر�LED4 */
		Delay(0xAFFFF); /* ������ʱ */
	}
}
