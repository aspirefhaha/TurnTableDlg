#include "commontools.h"
#include <windows.h>

#define wCRCPoly      0x1021  //对应生成多项式x16+x12+x5+x0
#define CRC16_INIT    0       //CRC校验码初始值
WORD CRCTable[256] = {0};

static int isInitialized = 0;

/***********************************************************************
* 模块名称：16位CRC校验表构造函数
* 原作者：
* 模块功能：根据CRC生成多项式计算生成16位CRC校验码表
* 输入参数：
*   无
* 输出参数：
*   pwCRCTable:CRC校验码表的指针
* 返回值：
*   无
*
* 注意事项:
*   用户在调用该函数时，需保证指针参数pwCRCTable不是空指针,并指向空间不小于256字(512字节)的缓冲区
*/
static void BuildCRCTable16(WORD *pwCRCTable)
{
    WORD wIndex = 0, wSize = 0;
    WORD wData = 0;
    WORD wCRC = 0;

    //将8位二进制序列数的CRC码全部计算出来，放在pwCRCTable表中
    for(wIndex=0; wIndex<256; wIndex++)
    {
        wData = (WORD)(wIndex << 8);
        wCRC = 0;
        for(wSize=0; wSize<8; wSize++)
        {
            if( ((wData^wCRC) & 0x8000) == 0x8000 )
            {
                wCRC = (wCRC << 1) ^ wCRCPoly;
            }
            else
            {
                wCRC <<= 1;
            }
            wData <<= 1;
        }
        pwCRCTable[wIndex] = wCRC;
    }
}

/***********************************************************************
* 模块名称：16位CRC校验码计算函数
* 原作者：
* 模块功能：根据数据缓冲区的起始地址和数据区长度计算16位的CRC校验码
* 输入参数：
*   pbDataBuf：待计算的数据缓冲区
*   dwNumOfBytes: 待计算的字节个数
* 输出参数：
*   无
* 返回值：
*   数据区的16位CRC校验码
*
* 注意事项：
*   1) 需根据事先指定的CRC多项式生成CRC表；
*   2) 待计算的字节个数dwNumOfBytes应小于等于待计算的数据缓冲区pbDataBuf的长度;
*   3) 用户在调用该函数时，需保证指针参数pbDataBuf、pwCRCTable不是空指针.
*/
WORD CalcCRC16(BYTE *pbDataBuf, DWORD dwNumOfBytes)
{
    //WORD	wIndex = 0;                          // CRC表索引值
    BYTE	bData = 0;
    DWORD	dwNum=dwNumOfBytes;
    WORD	wCRC = CRC16_INIT;                 // CRC校验码

    if(isInitialized==0){
        BuildCRCTable16(CRCTable);
        isInitialized = 1;
    }

    while ((dwNum--) != 0)
    {
        bData = (BYTE)(wCRC >> 8);
        wCRC <<= 8;
        wCRC ^= CRCTable[bData ^ *pbDataBuf];
        pbDataBuf++;
    }
    return	wCRC;
}
