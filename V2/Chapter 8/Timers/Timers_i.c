/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Nov 05 11:20:33 2014
 */
/* Compiler settings for C:\Documents and Settings\Administrator\×ÀÃæ\ComProgramBook\V2\Chapter 8\Timers\Timers.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IStopwatch = {0x8DC0EEEC,0xFA21,0x4044,{0xA1,0x42,0x6F,0x83,0xBC,0x55,0xF2,0x4A}};


const IID IID_IStopwatch2 = {0x8ECA2E64,0xE725,0x4C95,{0xA3,0x45,0xAE,0xD8,0xCB,0x7B,0xAF,0xD4}};


const IID LIBID_TIMERSLib = {0x00D050EA,0x8533,0x48B3,{0x87,0x8D,0x00,0xBE,0x75,0x19,0xC8,0xFB}};


const CLSID CLSID_Stopwatch = {0x90236F32,0xCB2C,0x40F2,{0x9D,0x8F,0xFC,0x64,0x3D,0xB6,0x36,0xA2}};


#ifdef __cplusplus
}
#endif

