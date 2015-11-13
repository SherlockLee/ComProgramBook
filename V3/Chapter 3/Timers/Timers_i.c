/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Nov 13 16:26:31 2015
 */
/* Compiler settings for C:\Documents and Settings\Administrator\×ÀÃæ\ComProgramBook\V3\Chapter 3\Timers\Timers.idl:
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

const IID IID_IStopwatch = {0x52D89D35,0x2685,0x4286,{0x80,0xC8,0xBD,0x33,0x50,0x62,0x60,0x0F}};


const IID LIBID_TIMERSLib = {0x739844B7,0x9345,0x4F9E,{0xBD,0x3D,0x19,0xEA,0xD3,0x53,0x25,0x5B}};


const CLSID CLSID_Stopwatch = {0xB2411CD4,0xD6D1,0x4AE5,{0x87,0x14,0xA4,0x29,0x4B,0x8C,0xE9,0x60}};


#ifdef __cplusplus
}
#endif

