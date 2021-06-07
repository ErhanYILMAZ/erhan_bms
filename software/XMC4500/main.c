/*
 * main.c
 *
 *  Created on: 2016 Aug 11 12:27:10
 *  Author: erhan
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)


//uint8_t canMO1_data[8]={0,0,0,0,0,0,0,0};


typedef struct CanReceiveMsg
{
	uint8_t bFlag;
	uint16_t wData[4];
	XMC_RTC_TIME_t tLogTime;
	uint32_t wID;
}CanReceiveMsg_t;

CanReceiveMsg_t ID30,ID31,ID32,ID40,ID41,ID60,ID61,ID62;


extern XMC_CAN_MO_t  CAN0_LMO_01;

// For id 0x30,0x31,0x32
void CAN0RX(void)
{
	uint8_t counter;
	CAN_NODE_MO_Receive(&CAN0_LMO_01_Config);
	switch(CAN0_LMO_01.can_identifier)
	{
	case 0x30:
		ID30.wID=0x30;
		RTC_GetTime(&ID30.tLogTime);
		for(counter=0;counter<4;counter++)
		{
			ID30.wData[counter]=CAN0_LMO_01.can_data_word[counter];
		}
		ID30.bFlag=1;
	break;
	case 0x31:
		ID31.wID=0x31;
		RTC_GetTime(&ID31.tLogTime);
		for(counter=0;counter<4;counter++)
		{
			ID31.wData[counter]=CAN0_LMO_01.can_data_word[counter];
		}
		ID31.bFlag=1;
	break;
	case 0x32:
		ID32.wID=0x32;
		RTC_GetTime(&ID32.tLogTime);
		for(counter=0;counter<4;counter++)
		{
			ID32.wData[counter]=CAN0_LMO_01.can_data_word[counter];
		}
		ID32.bFlag=1;
	break;
	default:
	break;
	}

}

void DebugUartRXHandler(void)
{
	int x=0;
	x++;
	DIGITAL_IO_ToggleOutput(&LED_P3_0);
}

void BridgeUartRXHandler(void)
{
	int x=0;
	x++;
	DIGITAL_IO_ToggleOutput(&LED_P3_0);
}

BYTE writeToEndOfFile(FATFS* fs, FIL* fp, const TCHAR* path, const void *buff, UINT btw)
{
	UINT bw;
	if(f_mount(fs,"",0) == FR_OK)
	{
		if (f_open(fp, path, FA_OPEN_ALWAYS | FA_WRITE) == FR_OK)
		{
			if(f_lseek(fp, f_size(fp)) == FR_OK)
			{
				if(f_write(fp, buff, btw, &bw) == FR_OK)
				{
					if(f_close(fp) == FR_OK)
					{
						return 0;
					}
				}
			}
		}
	}
	f_close(fp);
	return 1;
}

FATFS FatFs;		/* FatFs work area needed for each volume */
FIL Fil;			/* File object needed for each open file */

int main(void)
{
  DAVE_STATUS_t status;
  //UINT bw;
  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status == DAVE_STATUS_FAILURE)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

//uint32_t counter;
unsigned char c1=0,c2=2,c3=4;
char x[128];

  while(1U)
  {

	  //UART_Transmit(&BRIDGE_UART, "Erhan", 5);
/*
	  uint8_t read_data;
		UART_Receive(&BRIDGE_UART, &read_data,1);
		if(read_data != 0x0)
		{
		  read_data = 0x0;
		}
*/
	  if(ID30.bFlag)
	  {
		  sprintf(x,"ID=0x30 %04d:%02d:%02d-%02d:%02d:%02d V1=%05d V2=%05d V3=%05d V4=%05d\r\n",
		  ID30.tLogTime.year,ID30.tLogTime.month,ID30.tLogTime.days,ID30.tLogTime.hours,ID30.tLogTime.minutes,ID30.tLogTime.seconds,ID30.wData[0],ID30.wData[1],ID30.wData[2],ID30.wData[3]);
		  if((c1++ % 10) == 0)
		  {
			  UART_Transmit(&BRIDGE_UART, x, 65);
		  }
		  writeToEndOfFile(&FatFs,&Fil,"log.txt",x,65);
		  DIGITAL_IO_ToggleOutput(&LED_P3_0);
		  ID30.bFlag=0;
	  }

	  if(ID31.bFlag)
	  {
		  sprintf(x,"ID=0x31 %04d:%02d:%02d-%02d:%02d:%02d V5=%05d V6=%05d V7=%05d V8=%05d\r\n",
		  ID31.tLogTime.year,ID31.tLogTime.month,ID31.tLogTime.days,ID31.tLogTime.hours,ID31.tLogTime.minutes,ID31.tLogTime.seconds,ID31.wData[0],ID31.wData[1],ID31.wData[2],ID31.wData[3]);
		  if((c2++ % 10) == 0)
		  {
			  UART_Transmit(&BRIDGE_UART, x, 65);
		  }
		  writeToEndOfFile(&FatFs,&Fil,"log.txt",x,65);
		  DIGITAL_IO_ToggleOutput(&LED_P3_0);
		  ID31.bFlag=0;
	  }

	  if(ID32.bFlag)
	  {
		  sprintf(x,"ID=0x32 %04d:%02d:%02d-%02d:%02d:%02d V9=%05d VA=%05d VB=%05d VC=%05d\r\n",
		  ID32.tLogTime.year,ID32.tLogTime.month,ID32.tLogTime.days,ID32.tLogTime.hours,ID32.tLogTime.minutes,ID32.tLogTime.seconds,ID32.wData[0],ID32.wData[1],ID32.wData[2],ID32.wData[3]);
		  if((c3++ % 10) == 0)
		  {
			  UART_Transmit(&BRIDGE_UART, x, 65);
		  }
		  writeToEndOfFile(&FatFs,&Fil,"log.txt",x,65);
		  DIGITAL_IO_ToggleOutput(&LED_P3_0);
		  ID32.bFlag=0;
	  }
	  //for(i=0;i<4;i++)
	  //canMO1_data[i*2]++;
	  //CAN_NODE_MO_UpdateData(&CAN1_LMO_01_Config,canMO1_data);
	  //CAN_NODE_MO_Transmit(&CAN1_LMO_01_Config);

  }
}
