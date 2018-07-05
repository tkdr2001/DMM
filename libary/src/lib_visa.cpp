//#include <QCoreApplication>
#include <QDebug>
#include <visa.h>
#include <string.h>
//#include <iostream>

using namespace std;

#define MAX_SCPI_LEN    255
#define DEFAULT_TMO     5000

int test()
{
    // open resource manager
    ViSession rscmng;
    ViStatus stat = viOpenDefaultRM(&rscmng);

    // search for the oscilloscope
    ViChar viFound[VI_FIND_BUFLEN];
    ViUInt32 nFound;
    ViFindList listOfFound;
    stat = viFindRsrc(rscmng, (ViString)"USB?*", &listOfFound, &nFound, viFound);

    // connect to the oscilloscope
    ViSession osc;
    stat = viOpen(rscmng, viFound, VI_NULL, VI_NULL, &osc);

    // communicate
    viPrintf(osc, (ViString)"*IDN?\n");
    char buf[256] = {0};
    viScanf(osc,(ViString)"%t",&buf);
    qDebug()<<buf;

    // close VI sessions
    viClose(osc);
    viClose(rscmng);
    return 0;
}


//for (i = 0;i < (*retCount);i++)
//{
    // 读仪表名称
    //strSrc.Format("%s",instrDesc);
    //InstrWrite(strSrc,"*IDN?");
    //::Sleep(200);
    //InstrRead(strSrc,&strInstr);
    // If the instrument(resource) belongs to the DP series then jump out from the loop
    //strInstr.MakeUpper();
    //if (strInstr.Find("DG") >= 0)
    //{
    //bFindDP = true;
    //m_strInstrAddr = strSrc;
    //break;
    //}
    //Find next instrument
//    nRetStatus  =    viFindNext(*findList,instrDesc);
//}

//nRetStatus = viOpen( rmSession, "GPIB0::22::INSTR", VI_NULL, VI_NULL, &pInstrHandle);
/* set visa Format */
//nRetStatus = viSetAttribute( pInstrHandle, VI_ATTR_TMO_VALUE, DEFAULT_TMO);
//nRetStatus = viSetAttribute( pInstrHandle, VI_ATTR_SUPPRESS_END_EN, VI_FALSE);
//nRetStatus = viSetAttribute( pInstrHandle, VI_ATTR_SEND_END_EN, VI_FALSE);
/* Query device IDN */
//nRetStatus = viQueryf( pInstrHandle, "*IDN?\n", "%s", rdBuff);


/* Close */
//viClose( pInstrHandle);
