/*
 Parse FIB structure in worddocument stream of doc file.
 According to http://interoperability.blob.core.windows.net/files/MS-DOC/[MS-DOC].pdf
 How to read the FIB: https://msdn.microsoft.com/en-us/library/dd950942(v=office.12).aspx
 */

/*
modification history
--------------------
01a 04may17 lzw Create
*/

#include <stdio.h>
#include <stdlib.h>

#include "parseFib.h"

typedef struct Result {
    uint32 textOffset;
    uint32 textSize;
    uint32 utf16;
} Result;

Result * parse_fib(int * stream, int * table)
{
    // Parse FIB
    FIB * fib = (FIB *)stream;

    if(fib->fbase.wIdent == 0xA5EC){
        short ver = fib->fbase.nFib;
        short lang = fib->fbase.lid;
        short offset = fib->fbase.pnNext;
        int east = fib->fbase.fFarEast;
        //printf("This is a word document, ver:0x%x, language: 0x%x, offset:0x%x, far east: 0x%x\n", ver, lang, offset, east);
    }

    uint32 clxOffset = fib->fibRgFcLcbBlob.fcClx;
    uint32 clxSize = fib->fibRgFcLcbBlob.lcbClx;

    Prc * p = (Prc *)((char*)table + clxOffset);
    Pcdt * ppcdt = (Pcdt *)p;

    // Skip the RgPrc structure.
    if(p->clxt == 0x01){
        //printf("Do something\n");
        ppcdt = (Pcdt *)((char *)p + sizeof(Prc) + sizeof(PrcData) + p->RgPrc.cbGrpprl);
    }

    // parse PlcPcd
    char * PlcPcd = (char *)ppcdt + sizeof(Pcdt);

    uint32 numcp = ppcdt->lcb / (sizeof(cp) + sizeof(pcd));

    cp * pcp = (cp *)PlcPcd;
    pcd * ppcd = (pcd *)(PlcPcd + (numcp + 1) * sizeof(cp));

    Result * r = (Result *)malloc(sizeof(Result));

    for(int i = 0; i < numcp; i++)
    {
        if (i == 0) {
            r->textOffset = ppcd->fc.fc;
            r->utf16 = 1 - ppcd->fc.fCompressed;
        }
        if (i == 1)
            r->textSize = pcp->cp;
        // printf("cp%d: %d, text offset:%d, utf-16: %d\n",i, pcp->cp, ppcd->fc.fc, 1 - ppcd->fc.fCompressed);
        pcp += 1;
        ppcd += 1;
    }
    // there is one more cp define the end cp.
    // printf("cp%d: %d\n", numcp, pcp->cp);
    if (numcp == 1)
        r->textSize = pcp->cp;

    // printf("text offset:%d, size:%d, utf-16: %x, n:%d\n", r->textOffset, r->textSize, r->utf16, numcp);

    return r;
}