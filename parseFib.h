/*
 Type definition about FIB structure
 According to http://interoperability.blob.core.windows.net/files/MS-DOC/[MS-DOC].pdf
 */

/*
modification history
--------------------
01a 04may17 lzw Create
*/

#ifndef _PARSE_DOC_H_
#define _PARSE_DOC_H_

#define word1997    0x00C1
#define word2000    0x00D9
#define word2002    0x0101
#define word2003    0x010C
#define word2007    0x0112

typedef unsigned int uint32;
typedef int int32;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned char uint8;

typedef struct fibbase {
    uint32 wIdent:16;         // specifies the file type, 'Word' should be 0xA5EC.
    uint32 nFib:16;           // specifies the version number. Should be 0xC1
    uint32 unused:16;
    uint32 lid:16;            // specifies the install language of the application
    uint32 pnNext:16;         // specifies the offset in the WordDocument stream of the FIB for the document which contains all the AutoText items.
    uint32 fDot:1;            // Specifies whether this is a document template.
    uint32 fGlsy:1;           // Specifies whether this is a document that contains only AutoText items
    uint32 fComplex:1;        //
    uint32 DfHasPic:1;        // When set to 0, there SHOULD be no pictures in the document.
    uint32 cQuickSaves:4;
    uint32 fEncrypted:1;      // 
    uint32 fWhichTblStm:1;    //
    uint32 fReadOnlyRecommended:1;
    uint32 fWriteReservation:1;
    uint32 fExtChar:1;
    uint32 fLoadOverride:1;
    uint32 fFarEast:1;        // Specifies whether the installation language of the application that created the document was an East Asian language.
    uint32 fObfuscated:1;
    uint32 nFibBack:16;
    uint32 lKey0:16;
    uint32 lKey1:16;
    uint32 envr:8;
    uint32 fMac:1;
    uint32 fEmptySpecial:1;
    uint32 fLoadOverridePage:1;
    uint32 reserved1:1;
    uint32 reserved2:1;
    uint32 fSpare0:3;
    uint32 reserved[3];
} Fibbase;

typedef struct fibRgW {
    uint16 reserved[13];
    uint16 lidFE;
} FibRgW97;

typedef struct FibRgLw {
    uint32 cbMac;
    uint32 reserved1;
    uint32 reserved2;
    int32 ccpText;          // A signed integer that specifies the count of CPs in the main document.
                            // Character Position (CP)
    int32 ccpFtn;
    int32 ccpHdd;
    uint32 reserved3;
    int32 ccpAtn;
    int32 ccpEdn;
    int32 ccpTxbx;
    int32 ccpHdrTxbx;
    uint32 reserved[11];
} FibRgLw97;

typedef struct FibRgFcLcb97 {
    uint32 fcStshfOrig;
    uint32 lcbStshfOrig;
    uint32 fcStshf;         // An unsigned integer that specifies an offset in the Table Stream. An STSH that specifies the style sheet for this document begins at this offset.
    uint32 lcbStshf;        // An unsigned integer that specifies the size, in bytes, of the STSH that begins at offset fcStshf in the Table Stream. This MUST be a nonzero value.
    uint32 fcPlcffndRef;    // An unsigned integer that specifies an offset in the Table Stream. A PlcffndRef begins at this offset and specifies the locations of footnote references in the Main Document, and whether those references use auto-numbering or custom symbols. If lcbPlcffndRef is zero, fcPlcffndRef is undefined and MUST be ignored.
    uint32 lcbPlcffndRef;   // An unsigned integer that specifies the size, in bytes, of the PlcffndRef that begins at offset fcPlcffndRef in the Table Stream.
    uint32 fcPlcffndTxt;    // An unsigned integer that specifies an offset in the Table Stream. A PlcffndTxt begins at this offset and specifies the locations of each block of footnote text in the Footnote Document. If lcbPlcffndTxt is zero, fcPlcffndTxt is undefined and MUST be ignored.
    uint32 lcbPlcffndTxt;   // An unsigned integer that specifies the size, in bytes, of the PlcffndTxt that begins at offset fcPlcffndTxt in the Table Stream.
    uint32 fcPlcfandRef;    // An unsigned integer that specifies an offset in the Table Stream. A PlcfandRef begins at this offset and specifies the dates, user initials, and locations of comments in the Main Document. If lcbPlcfandRef is zero, fcPlcfandRef is undefined and MUST be ignored.
    uint32 lcbPlcfandRef;   // An unsigned integer that specifies the size, in bytes, of the PlcfandRef at offset fcPlcfandRef in the Table Stream.
    uint32 fcPlcfandTxt;    // An unsigned integer that specifies an offset in the Table Stream. A PlcfandTxt begins at this offset and specifies the locations of comment text ranges in the Comment Document. If lcbPlcfandTxt is zero, fcPlcfandTxt is undefined, and MUST be ignored.
    uint32 lcbPlcfandTxt;   // An unsigned integer that specifies the size, in bytes, of the PlcfandTxt at offset fcPlcfandTxt in the Table Stream.
    uint32 fcPlcfSed;       // An unsigned integer that specifies an offset in the Table Stream. A PlcfSed begins at this offset and specifies the locations of property lists for each section in the Main Document. If lcbPlcfSed is zero, fcPlcfSed is undefined and MUST be ignored.
    uint32 lcbPlcfSed;      // An unsigned integer that specifies the size, in bytes, of the PlcfSed that begins at offset fcPlcfSed in the Table Stream.
    uint32 fcPlcPad;        // This value is undefined and MUST be ignored.
    uint32 lcbPlcPad;       // This value MUST be zero, and MUST be ignored.
    uint32 fcPlcfPhe;       // An unsigned integer that specifies an offset in the Table Stream. A Plc begins at this offset and specifies version-specific information about paragraph height. This Plc SHOULD NOT<27> be emitted and SHOULD<28> be ignored.
    uint32 lcbPlcfPhe;      // An unsigned integer that specifies the size, in bytes, of the Plc at offset fcPlcfPhe in the Table Stream.
    uint32 fcSttbfGlsy;     // An unsigned integer that specifies an offset in the Table Stream. A SttbfGlsy that contains information about the AutoText items that are defined in this document begins at this offset.
    uint32 lcbSttbfGlsy;    // An unsigned integer that specifies the size, in bytes, of the SttbfGlsy at offset fcSttbfGlsy in the Table Stream. If base.fGlsy of the Fib that contains this FibRgFcLcb97 is zero, this value MUST be zero.
    uint32 fcPlcfGlsy;      // An unsigned integer that specifies an offset in the Table Stream. A PlcfGlsy that contains information about the AutoText items that are defined in this document begins at this offset.
    uint32 lcbPlcfGlsy;     // An unsigned integer that specifies the size, in bytes, of the PlcfGlsy at offset fcPlcfGlsy in the Table Stream. If base.fGlsy of the Fib that contains this FibRgFcLcb97 is zero, this value MUST be zero.
    uint32 fcPlcfHdd;       //An unsigned integer that specifies the offset in the Table Stream where a Plcfhdd begins. The Plcfhdd specifies the locations of each block of header/footer text in the WordDocument Stream. If lcbPlcfHdd is 0, fcPlcfHdd is undefined and MUST be ignored.
    uint32 lcbPlcfHdd;      //An unsigned integer that specifies the size, in bytes, of the Plcfhdd at offset fcPlcfHdd in the Table Stream. If there is no Plcfhdd, this value MUST be zero. A Plcfhdd MUST exist if FibRgLw97.ccpHdd indicates that there are characters in the Header Document (that is, if FibRgLw97.ccpHdd is greater than 0). Otherwise, the Plcfhdd MUST NOT exist.
    uint32 fcPlcfBteChpx;        //An unsigned integer that specifies an offset in the Table Stream. A PlcBteChpx begins at the offset. fcPlcfBteChpx MUST be greater than zero, and MUST be a valid offset in the Table Stream.
    uint32 lcbPlcfBteChpx;        //An unsigned integer that specifies the size, in bytes, of the PlcBteChpx at offset fcPlcfBteChpx in the Table Stream. lcbPlcfBteChpx MUST be greater than zero.
    uint32 fcPlcfBtePapx;        //An unsigned integer that specifies an offset in the Table Stream. A PlcBtePapx begins at the offset. fcPlcfBtePapx MUST be greater than zero, and MUST be a valid offset in the Table Stream.
    uint32 lcbPlcfBtePapx;        //An unsigned integer that specifies the size, in bytes, of the PlcBtePapx at offset fcPlcfBtePapx in the Table Stream. lcbPlcfBteChpx MUST be greater than zero.
    uint32 fcPlcfSea;        //This value is undefined and MUST be ignored.
    uint32 lcbPlcfSea;        //This value MUST be zero, and MUST be ignored.
    uint32 fcSttbfFfn;        //An unsigned integer that specifies an offset in the Table Stream. An SttbfFfn begins at this offset. This table specifies the fonts that are used in the document. If lcbSttbfFfn is 0, fcSttbfFfn is undefined and MUST be ignored.
    uint32 lcbSttbfFfn;        //An unsigned integer that specifies the size, in bytes, of the SttbfFfn at offset fcSttbfFfn in the Table Stream.
    uint32 fcPlcfFldMom;        //An unsigned integer that specifies an offset in the Table Stream. A PlcFld begins at this offset and specifies the locations of field characters in the Main Document. All CPs in this PlcFld MUST be greater than or equal to 0 and less than or equal to FibRgLw97.ccpText. If lcbPlcfFldMom is zero, fcPlcfFldMom is undefined and MUST be ignored.
    uint32 lcbPlcfFldMom;        //An unsigned integer that specifies the size, in bytes, of the PlcFld at offset fcPlcfFldMom in the Table Stream.
    uint32 fcPlcfFldHdr;        //An unsigned integer that specifies an offset in the Table Stream. A PlcFld begins at this offset and specifies the locations of field characters in the Header Document. All CPs in this PlcFld are relative to the starting position of the Header Document. All CPs in this PlcFld MUST be greater than or equal to zero and less than or equal to FibRgLw97.ccpHdd. If lcbPlcfFldHdr is zero, fcPlcfFldHdr is undefined and MUST be ignored.
    uint32 lcbPlcfFldHdr;        //An unsigned integer that specifies the size, in bytes, of the PlcFld at offset fcPlcfFldHdr in the Table Stream.
    uint32 fcPlcfFldFtn;        //An unsigned integer that specifies an offset in the Table Stream. A PlcFld begins at this offset and specifies the locations of field characters in the Footnote Document. All CPs in this PlcFld are relative to the starting position of the Footnote Document. All CPs in this PlcFld MUST be greater than or equal to zero and less than or equal to FibRgLw97.ccpFtn. If lcbPlcfFldFtn is zero, fcPlcfFldFtn is undefined, and MUST be ignored.
    uint32 lcbPlcfFldFtn;        //An unsigned integer that specifies the size, in bytes, of the PlcFld at offset fcPlcfFldFtn in the Table Stream.
    uint32 fcPlcfFldAtn;        //An unsigned integer that specifies an offset in the Table Stream. A PlcFld begins at this offset and specifies the locations of field characters in the Comment Document. All CPs in this PlcFld are relative to the starting position of the Comment Document. All CPs in this PlcFld MUST be greater than or equal to zero and less than or equal to FibRgLw97.ccpAtn. If lcbPlcfFldAtn is zero, fcPlcfFldAtn is undefined and MUST be ignored.
    uint32 lcbPlcfFldAtn;        //An unsigned integer that specifies the size, in bytes, of the PlcFld at offset fcPlcfFldAtn in the Table Stream.
    uint32 fcPlcfFldMcr;        //This value is undefined and MUST be ignored.
    uint32 lcbPlcfFldMcr;        //This value MUST be zero, and MUST be ignored.
    uint32 fcSttbfBkmk;        //An unsigned integer that specifies an offset in the Table Stream. An SttbfBkmk that contains the names of the bookmarks in the document begins at this offset. If lcbSttbfBkmk is zero, fcSttbfBkmk is undefined and MUST be ignored.
    uint32 lcbSttbfBkmk;        //An unsigned integer that specifies the size, in bytes, of the SttbfBkmk at offset fcSttbfBkmk.
    uint32 fcPlcfBkf;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfBkf that contains information about the standard bookmarks in the document begins at this offset. If lcbPlcfBkf is zero, fcPlcfBkf is undefined and MUST be ignored.
    uint32 lcbPlcfBkf;        //An unsigned integer that specifies the size, in bytes, of the PlcfBkf at offset fcPlcfBkf.
    uint32 fcPlcfBkl;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfBkl that contains information about the standard bookmarks in the document begins at this offset. If lcbPlcfBkl is zero, fcPlcfBkl is undefined and MUST be ignored.
    uint32 lcbPlcfBkl;        //An unsigned integer that specifies the size, in bytes, of the PlcfBkl at offset fcPlcfBkl.
    uint32 fcCmds;        //An unsigned integer that specifies the offset in the Table Stream of a Tcg that specifies command-related customizations. If lcbCmds is zero, fcCmds is undefined and MUST be ignored.
    uint32 lcbCmds;        //An unsigned integer that specifies the size, in bytes, of the Tcg at offset fcCmds.
    uint32 fcUnused1;        //This value is undefined and MUST be ignored.
    uint32 lcbUnused1;        //This value MUST be zero, and MUST be ignored.
    uint32 fcSttbfMcr;        //This value is undefined and MUST be ignored.
    uint32 lcbSttbfMcr;        //This value MUST be zero, and MUST be ignored.
    uint32 fcPrDrvr;        //An unsigned integer that specifies an offset in the Table Stream. The PrDrvr, which contains printer driver information (the names of drivers, port, and so on), begins at this offset. If lcbPrDrvr is zero, fcPrDrvr is undefined and MUST be ignored.
    uint32 lcbPrDrvr;        //An unsigned integer that specifies the size, in bytes, of the PrDrvr at offset fcPrDrvr.
    uint32 fcPrEnvPort;        //An unsigned integer that specifies an offset in the Table Stream. The PrEnvPort that is the print environment in portrait mode begins at this offset. If lcbPrEnvPort is zero, fcPrEnvPort is undefined and MUST be ignored.
    uint32 lcbPrEnvPort;        //An unsigned integer that specifies the size, in bytes, of the PrEnvPort at offset fcPrEnvPort.
    uint32 fcPrEnvLand;        //An unsigned integer that specifies an offset in the Table Stream. The PrEnvLand that is the print environment in landscape mode begins at this offset. If lcbPrEnvLand is zero, fcPrEnvLand is undefined and MUST be ignored.
    uint32 lcbPrEnvLand;        //An unsigned integer that specifies the size, in bytes, of the PrEnvLand at offset fcPrEnvLand.
    uint32 fcWss;           //An unsigned integer that specifies an offset in the Table Stream. A Selsf begins at this offset and specifies the last selection that was made in the Main Document. If lcbWss is zero, fcWss is undefined and MUST be ignored.
    uint32 lcbWss;          //An unsigned integer that specifies the size, in bytes, of the Selsf at offset fcWss.
    uint32 fcDop;           //An unsigned integer that specifies an offset in the Table Stream. A Dop begins at this offset.
    uint32 lcbDop;          //An unsigned integer that specifies the size, in bytes, of the Dopat fcDop. This value MUST NOT be zero.
    uint32 fcSttbfAssoc;    //An unsigned integer that specifies an offset in the Table Stream. An SttbfAssoc that contains strings that are associated with the document begins at this offset.
    uint32 lcbSttbfAssoc;   //An unsigned integer that specifies the size, in bytes, of the SttbfAssoc at offset fcSttbfAssoc. This value MUST NOT be zero.
    uint32 fcClx;           // An unsigned integer that specifies an offset in the Table Stream. A Clx begins at this offset.
    uint32 lcbClx;          // An unsigned integer that specifies the size, in bytes, of the Clx at offset fcClx in the Table Stream. This value MUST be greater than zero.
    uint32 fcPlcfPgdFtn;
    uint32 lcbPlcfPgdFtn;
    uint32 fcAutosaveSource;
    uint32 lcbAutosaveSource;
    uint32 fcGrpXstAtnOwners;   // An unsigned integer that specifies an offset in the Table Stream. An array of XSTs begins at this offset. The value of cch for all XSTs in this array MUST be less than 56. The number of entries in this array is limited to 0x7FFF. This array contains the names of authors of comments in the document. The names in this array MUST be unique. If no comments are defined, lcbGrpXstAtnOwners and fcGrpXstAtnOwners MUST be zero and MUST be ignored. If any comments are in the document, fcGrpXstAtnOwners MUST point to a valid array of XSTs.
    uint32 lcbGrpXstAtnOwners;  // An unsigned integer that specifies the size, in bytes, of the XST array at offset fcGrpXstAtnOwners in the Table Stream.
    uint32 fcSttbfAtnBkmk;      // An unsigned integer that specifies an offset in the Table Stream. An SttbfAtnBkmk that contains information about the annotation bookmarks in the document begins at this offset. If lcbSttbfAtnBkmk is zero, fcSttbfAtnBkmk is undefined and MUST be ignored.
    uint32 lcbSttbfAtnBkmk;        //An unsigned integer that specifies the size, in bytes, of the SttbfAtnBkmk at offset fcSttbfAtnBkmk.
    uint32 fcUnused2;        //This value is undefined and MUST be ignored.
    uint32 lcbUnused2;        //This value MUST be zero, and MUST be ignored.
    uint32 fcUnused3;        //This value is undefined and MUST be ignored.
    uint32 lcbUnused3;        //This value MUST be zero, and MUST be ignored.
    uint32 fcPlcSpaMom;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfSpa begins at this offset. The PlcfSpa contains shape information for the Main Document. All CPs in this PlcfSpa are relative to the starting position of the Main Document and MUST be greater than or equal to zero and less than or equal to cppText in FibRgLw97. The final CP is undefined and MUST be ignored, though it MUST be greater than the previous entry. If there are no shapes in the Main Document, lcbPlcSpaMom and fcPlcSpaMom MUST be zero and MUST be ignored. If there are shapes in the Main Document, fcPlcSpaMom MUST point to a valid PlcfSpa structure.
    uint32 lcbPlcSpaMom;        //An unsigned integer that specifies the size, in bytes, of the PlcfSpa at offset fcPlcSpaMom.
    uint32 fcPlcSpaHdr;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfSpa begins at this offset. The PlcfSpa contains shape information for the Header Document. All CPs in this PlcfSpa are relative to the starting position of the Header Document and MUST be greater than or equal to zero and less than or equal to ccpHdd in FibRgLw97. The final CP is undefined and MUST be ignored, though this value MUST be greater than the previous entry. If there are no shapes in the Header Document, lcbPlcSpaHdr and fcPlcSpaHdr MUST both be zero and MUST be ignored. If there are shapes in the Header Document, fcPlcSpaHdr MUST point to a valid PlcfSpa structure.
    uint32 lcbPlcSpaHdr;        //An unsigned integer that specifies the size, in bytes, of the PlcfSpa at the offset fcPlcSpaHdr.
    uint32 fcPlcfAtnBkf;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfBkf that contains information about annotation bookmarks in the document begins at this offset. If lcbPlcfAtnBkf is zero, fcPlcfAtnBkf is undefined and MUST be ignored.
    uint32 lcbPlcfAtnBkf;        //An unsigned integer that specifies the size, in bytes, of the PlcfBkf at offset fcPlcfAtnBkf.
    uint32 fcPlcfAtnBkl;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfBkl that contains information about annotation bookmarks in the document begins at this offset. If lcbPlcfAtnBkl is zero, then fcPlcfAtnBkl is undefined and MUST be ignored.
    uint32 lcbPlcfAtnBkl;        //An unsigned integer that specifies the size, in bytes, of the PlcfBkl at offset fcPlcfAtnBkl.
    uint32 fcPms;        //An unsigned integer that specifies an offset in the Table Stream. A Pms, which contains the current state of a print merge operation, begins at this offset. If lcbPms is zero, fcPms is undefined and MUST be ignored.
    uint32 lcbPms;        //An unsigned integer which specifies the size, in bytes, of the Pms at offset fcPms.
    uint32 fcFormFldSttbs;        //This value is undefined and MUST be ignored.
    uint32 lcbFormFldSttbs;        //This value MUST be zero, and MUST be ignored.
    uint32 fcPlcfendRef;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfendRef that begins at this offset specifies the locations of endnote references in the Main Document and whether those references use auto-numbering or custom symbols. If lcbPlcfendRef is zero, fcPlcfendRef is undefined and MUST be ignored.
    uint32 lcbPlcfendRef;        //An unsigned integer that specifies the size, in bytes, of the PlcfendRef that begins at offset fcPlcfendRef in the Table Stream.
    uint32 fcPlcfendTxt;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfendTxt begins at this offset and specifies the locations of each block of endnote text in the Endnote Document. If lcbPlcfendTxt is zero, fcPlcfendTxt is undefined and MUST be ignored.
    uint32 lcbPlcfendTxt;        //An unsigned integer that specifies the size, in bytes, of the PlcfendTxt that begins at offset fcPlcfendTxt in the Table Stream.
    uint32 fcPlcfFldEdn;        //An unsigned integer that specifies an offset in the Table Stream. A PlcFld begins at this offset and specifies the locations of field characters in the Endnote Document. All CPs in this PlcFld are relative to the starting position of the Endnote Document. All CPs in this PlcFld MUST be greater than or equal to zero and less than or equal to FibRgLw97.ccpEdn. If lcbPlcfFldEdn is zero, fcPlcfFldEdn is undefined and MUST be ignored.
    uint32 lcbPlcfFldEdn;        //An unsigned integer that specifies the size, in bytes, of the PlcFld at offset fcPlcfFldEdn in the Table Stream.
    uint32 fcUnused4;        //This value is undefined and MUST be ignored.
    uint32 lcbUnused4;        //This value MUST be zero, and MUST be ignored.
    uint32 fcDggInfo;        //An unsigned integer that specifies an offset in the Table Stream. An OfficeArtContent that contains information about the drawings in the document begins at this offset.
    uint32 lcbDggInfo;        //An unsigned integer that specifies the size, in bytes, of the OfficeArtContent at the offset fcDggInfo. If lcbDggInfo is zero, there MUST NOT be any drawings in the document.
    uint32 fcSttbfRMark;        //An unsigned integer that specifies an offset in the Table Stream. An SttbfRMark that contains the names of authors who have added revision marks or comments to the document begins at this offset. If lcbSttbfRMark is zero, fcSttbfRMark is undefined and MUST be ignored.
    uint32 lcbSttbfRMark;        //An unsigned integer that specifies the size, in bytes, of the SttbfRMark at the offset fcSttbfRMark.
    uint32 fcSttbfCaption;        //An unsigned integer that specifies an offset in the Table Stream. An SttbfCaption that contains information about the captions that are defined in this document begins at this offset. If lcbSttbfCaption is zero, fcSttbfCaption is undefined and MUST be ignored. If this document is not the Normal template, this value MUST be ignored.
    uint32 lcbSttbfCaption;        //An unsigned integer that specifies the size, in bytes, of the SttbfCaption at offset fcSttbfCaption in the Table Stream. If base.fDot of the Fib that contains this FibRgFcLcb97 is zero, this value MUST be zero.
    uint32 fcSttbfAutoCaption;        //An unsigned integer that specifies an offset in the Table Stream. A SttbfAutoCaption that contains information about the AutoCaption strings defined in this document begins at this offset. If lcbSttbfAutoCaption is zero, fcSttbfAutoCaption is undefined and MUST be ignored. If this document is not the Normal template, this value MUST be ignored.
    uint32 lcbSttbfAutoCaption;        //An unsigned integer that specifies the size, in bytes, of the SttbfAutoCaption at offset fcSttbfAutoCaption in the Table Stream. If base.fDot of the Fib that contains this FibRgFcLcb97 is zero, this MUST be zero.
    uint32 fcPlcfWkb;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfWKB that contains information about all master documents and subdocuments begins at this offset.
    uint32 lcbPlcfWkb;        //An unsigned integer that specifies the size, in bytes, of the PlcfWKB at offset fcPlcfWkb in the Table Stream. If lcbPlcfWkb is zero, fcPlcfWkb is undefined and MUST be ignored.
    uint32 fcPlcfSpl;        //An unsigned integer that specifies an offset in the Table Stream. A Plcfspl, which specifies the state of the spell checker for each text range, begins at this offset. If lcbPlcfSpl is zero, then fcPlcfSpl is undefined and MUST be ignored.
    uint32 lcbPlcfSpl;        //An unsigned integer that specifies the size, in bytes, of the Plcfspl that begins at offset fcPlcfSpl in the Table Stream.
    uint32 fcPlcftxbxTxt;        //An unsigned integer that specifies an offset in the Table Stream. A PlcftxbxTxt begins at this offset and specifies which ranges of text are contained in which textboxes. If lcbPlcftxbxTxt is zero, fcPlcftxbxTxt is undefined and MUST be ignored.
    uint32 lcbPlcftxbxTxt;        //An unsigned integer that specifies the size, in bytes, of the PlcftxbxTxt that begins at offset fcPlcftxbxTxt in the Table Stream.
    uint32 fcPlcfFldTxbx;        //An unsigned integer that specifies an offset in the Table Stream. A PlcFld begins at this offset and specifies the locations of field characters in the Textbox Document. All CPs in this PlcFld are relative to the starting position of the Textbox Document. All CPs in this PlcFld MUST be greater than or equal to zero and less than or equal to FibRgLw97.ccpTxbx. If lcbPlcfFldTxbx is zero, fcPlcfFldTxbx is undefined and MUST be ignored.
    uint32 lcbPlcfFldTxbx;        //An unsigned integer that specifies the size, in bytes, of the PlcFld at offset fcPlcfFldTxbx in the Table Stream.
    uint32 fcPlcfHdrtxbxTxt;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfHdrtxbxTxt begins at this offset and specifies which ranges of text are contained in which header textboxes.
    uint32 lcbPlcfHdrtxbxTxt;        //An unsigned integer that specifies the size, in bytes, of the PlcfHdrtxbxTxt that begins at offset fcPlcfHdrtxbxTxt in the Table Stream.
    uint32 fcPlcffldHdrTxbx;        //An unsigned integer that specifies an offset in the Table Stream. A PlcFld begins at this offset and specifies the locations of field characters in the Header Textbox Document. All CPs in this PlcFld are relative to the starting position of the Header Textbox Document. All CPs in this PlcFld MUST be greater than or equal to zero and less than or equal to FibRgLw97.ccpHdrTxbx. If lcbPlcffldHdrTxbx is zero, fcPlcffldHdrTxbx is undefined, and MUST be ignored.
    uint32 lcbPlcffldHdrTxbx;        //An unsigned integer that specifies the size, in bytes, of the PlcFld at offset fcPlcffldHdrTxbx in the Table Stream.
    uint32 fcStwUser;        //An unsigned integer that specifies an offset into the Table Stream. An StwUser that specifies the user-defined variables and VBA digital signature, as specified by [MS-OSHARED] section 2.3.2, begins at this offset. If lcbStwUser is zero, fcStwUser is undefined and MUST be ignored.
    uint32 lcbStwUser;        //An unsigned integer that specifies the size, in bytes, of the StwUser at offset fcStwUser.
    uint32 fcSttbTtmbd;        //An unsigned integer that specifies an offset into the Table Stream. A SttbTtmbd begins at this offset and specifies information about the TrueType fonts that are embedded in the document. If lcbSttbTtmbd is zero, fcSttbTtmbd is undefined and MUST be ignored.
    uint32 lcbSttbTtmbd;        //An unsigned integer that specifies the size, in bytes, of the SttbTtmbd at offset fcSttbTtmbd.
    uint32 fcCookieData;        //An unsigned integer that specifies an offset in the Table Stream. An RgCdb begins at this offset. If lcbCookieData is zero, fcCookieData is undefined and MUST be ignored. Otherwise, fcCookieData MAY<29> be ignored.
    uint32 lcbCookieData;        //An unsigned integer that specifies the size, in bytes, of the RgCdb at offset fcCookieData in the Table Stream.
    uint32 fcPgdMotherOldOld;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated document page layout cache begins at this offset. Information SHOULD NOT<30> be emitted at this offset and SHOULD<31> be ignored. If lcbPgdMotherOldOld is zero, fcPgdMotherOldOld is undefined and MUST be ignored.
    uint32 lcbPgdMotherOldOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated document page layout cache at offset fcPgdMotherOldOld in the Table Stream.
    uint32 fcBkdMotherOldOld;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated document text flow break cache begins at this offset. Information SHOULD NOT<32> be emitted at this offset and SHOULD<33> be ignored. If lcbBkdMotherOldOld is zero, fcBkdMotherOldOld is undefined and MUST be ignored.
    uint32 lcbBkdMotherOldOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated document text flow break cache at offset fcBkdMotherOldOld in the Table Stream.
    uint32 fcPgdFtnOldOld;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated footnote layout cache begins at this offset. Information SHOULD NOT<34> be emitted at this offset and SHOULD<35> be ignored. If lcbPgdFtnOldOld is zero, fcPgdFtnOldOld is undefined and MUST be ignored.
    uint32 lcbPgdFtnOldOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated footnote layout cache at offset fcPgdFtnOldOld in the Table Stream.
    uint32 fcBkdFtnOldOld;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated footnote text flow break cache begins at this offset. Information SHOULD NOT<36> be emitted at this offset and SHOULD<37> be ignored. If lcbBkdFtnOldOld is zero, fcBkdFtnOldOld is undefined and MUST be ignored.
    uint32 lcbBkdFtnOldOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated footnote text flow break cache at offset fcBkdFtnOldOld in the Table Stream.
    uint32 fcPgdEdnOldOld;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated endnote layout cache begins at this offset. Information SHOULD NOT<38> be emitted at this offset and SHOULD<39> be ignored. If lcbPgdEdnOldOld is zero, fcPgdEdnOldOld is undefined and MUST be ignored.
    uint32 lcbPgdEdnOldOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated endnote layout cache at offset fcPgdEdnOldOld in the Table Stream.
    uint32 fcBkdEdnOldOld;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated endnote text flow break cache begins at this offset. Information SHOULD NOT<40> be emitted at this offset and SHOULD<41> be ignored. If lcbBkdEdnOldOld is zero, fcBkdEdnOldOld is undefined and MUST be ignored.
    uint32 lcbBkdEdnOldOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated endnote text flow break cache at offset fcBkdEdnOldOld in the Table Stream.
    uint32 fcSttbfIntlFld;        //This value is undefined and MUST be ignored.
    uint32 lcbSttbfIntlFld;        //This value MUST be zero, and MUST be ignored.
    uint32 fcRouteSlip;        //An unsigned integer that specifies an offset in the Table Stream. A RouteSlip that specifies the route slip for this document begins at this offset. This value SHOULD<42> be ignored.
    uint32 lcbRouteSlip;        //An unsigned integer that specifies the size, in bytes, of the RouteSlip at offset fcRouteSlip in the Table Stream.
    uint32 fcSttbSavedBy;        //An unsigned integer that specifies an offset in the Table Stream. A SttbSavedBy that specifies the save history of this document begins at this offset. This value SHOULD<43> be ignored.
    uint32 lcbSttbSavedBy;        //An unsigned integer that specifies the size, in bytes, of the SttbSavedBy at the offset fcSttbSavedBy. This value SHOULD<44> be zero.
    uint32 fcSttbFnm;        //An unsigned integer that specifies an offset in the Table Stream. An SttbFnm that contains information about the external files that are referenced by this document begins at this offset. If lcbSttbFnm is zero, fcSttbFnm is undefined and MUST be ignored.
    uint32 lcbSttbFnm;        //An unsigned integer that specifies the size, in bytes, of the SttbFnm at the offset fcSttbFnm.
    uint32 fcPlfLst;        //An unsigned integer that specifies an offset in the Table Stream. A PlfLst that contains list formatting information begins at this offset. An array of LVLs is appended to the PlfLst. lcbPlfLst does not account for the array of LVLs. The size of the array of LVLs is specified by the LSTFs in PlfLst. For each LSTF whose fSimpleList is set to 0x1, there is one LVL in the array of LVLs that specifies the level formatting of the single level in the list which corresponds to the LSTF. And, for each LSTF whose fSimpleList is set to 0x0, there are 9 LVLs in the array of LVLs that specify the level formatting of the respective levels in the list which corresponds to the LSTF. This array of LVLs is in the same respective order as the LSTFs in PlfLst. If lcbPlfLst is 0, fcPlfLst is undefined and MUST be ignored.
    uint32 lcbPlfLst;        //An unsigned integer that specifies the size, in bytes, of the PlfLst at the offset fcPlfLst. This does not include the size of the array of LVLs that are appended to the PlfLst.
    uint32 fcPlfLfo;        //An unsigned integer that specifies an offset in the Table Stream. A PlfLfo that contains list formatting override information begins at this offset. If lcbPlfLfo is zero, fcPlfLfo is undefined and MUST be ignored.
    uint32 lcbPlfLfo;        //An unsigned integer that specifies the size, in bytes, of the PlfLfo at the offset fcPlfLfo.
    uint32 fcPlcfTxbxBkd;        //An unsigned integer that specifies an offset in the Table Stream. A PlcftxbxBkd begins at this offset and specifies which ranges of text go inside which textboxes.
    uint32 lcbPlcfTxbxBkd;        //An unsigned integer that specifies the size, in bytes, of the PlcftxbxBkd that begins at offset fcPlcfTxbxBkd in the Table Stream.
    uint32 fcPlcfTxbxHdrBkd;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfTxbxHdrBkd begins at this offset and specifies which ranges of text are contained inside which header textboxes.
    uint32 lcbPlcfTxbxHdrBkd;        //An unsigned integer that specifies the size, in bytes, of the PlcfTxbxHdrBkd that begins at offset fcPlcfTxbxHdrBkd in the Table Stream.
    uint32 fcDocUndoWord9;        //An unsigned integer that specifies an offset in the WordDocument Stream. Version-specific undo information begins at this offset. This information SHOULD NOT<45> be emitted and SHOULD<46> be ignored.
    uint32 lcbDocUndoWord9;        //An unsigned integer. If this is nonzero, version-specific undo information exists at offset fcDocUndoWord9 in the WordDocument Stream.
    uint32 fcRgbUse;        //An unsigned integer that specifies an offset in the WordDocument Stream. Version-specific undo information begins at this offset. This information SHOULD NOT<47> be emitted and SHOULD<48> be ignored.
    uint32 lcbRgbUse;        //An unsigned integer that specifies the size, in bytes, of the version-specific undo information at offset fcRgbUse in the WordDocument Stream.
    uint32 fcUsp;        //An unsigned integer that specifies an offset in the WordDocument Stream. Version-specific undo information begins at this offset. This information SHOULD NOT<49> be emitted and SHOULD<50> be ignored.
    uint32 lcbUsp;        //An unsigned integer that specifies the size, in bytes, of the version-specific undo information at offset fcUsp in the WordDocument Stream.
    uint32 fcUskf;        //An unsigned integer that specifies an offset in the Table Stream. Version-specific undo information begins at this offset. This information SHOULD NOT<51> be emitted and SHOULD<52> be ignored.
    uint32 lcbUskf;        //An unsigned integer that specifies the size, in bytes, of the version-specific undo information at offset fcUskf in the Table Stream.
    uint32 fcPlcupcRgbUse;        //An unsigned integer that specifies an offset in the Table Stream. A Plc begins at this offset and contains version-specific undo information. This information SHOULD NOT<53> be emitted and SHOULD<54> be ignored.
    uint32 lcbPlcupcRgbUse;        //An unsigned integer that specifies the size, in bytes, of the Plc at offset fcPlcupcRgbUse in the Table Stream.
    uint32 fcPlcupcUsp;        //An unsigned integer that specifies an offset in the Table Stream. A Plc begins at this offset and contains version-specific undo information. This information SHOULD NOT<55> be emitted and SHOULD<56> be ignored.
    uint32 lcbPlcupcUsp;        //An unsigned integer that specifies the size, in bytes, of the Plc at offset fcPlcupcUsp in the Table Stream.
    uint32 fcSttbGlsyStyle;        //An unsigned integer that specifies an offset in the Table Stream. A SttbGlsyStyle, which contains information about the styles that are used by the AutoText items which are defined in this document, begins at this offset.
    uint32 lcbSttbGlsyStyle;        //An unsigned integer that specifies the size, in bytes, of the SttbGlsyStyle at offset fcSttbGlsyStyle in the Table Stream. If base.fGlsy of the Fib that contains this FibRgFcLcb97 is zero, this value MUST be zero.
    uint32 fcPlgosl;        //An unsigned integer that specifies an offset in the Table Stream. A PlfGosl begins at the offset. If lcbPlgosl is zero, fcPlgosl is undefined and MUST be ignored.
    uint32 lcbPlgosl;        //An unsigned integer that specifies the size, in bytes, of the PlfGosl at offset fcPlgosl in the Table Stream.
    uint32 fcPlcocx;        //An unsigned integer that specifies an offset in the Table Stream. A RgxOcxInfo that specifies information about the OLE controls in the document begins at this offset. When there are no OLE controls in the document, fcPlcocx and lcbPlcocx MUST be zero and MUST be ignored. If there are any OLE controls in the document, fcPlcocx MUST point to a valid RgxOcxInfo.
    uint32 lcbPlcocx;        //An unsigned integer that specifies the size, in bytes, of the RgxOcxInfo at the offset fcPlcocx.
    uint32 fcPlcfBteLvc;        //An unsigned integer that specifies an offset in the Table Stream. A deprecated numbering field cache begins at this offset. This information SHOULD NOT<57> be emitted and SHOULD<58> ignored. If lcbPlcBteLvc is zero, fcPlcfBteLvc is undefined and MUST be ignored.
    uint32 lcbPlcfBteLvc;        //An unsigned integer that specifies the size, in bytes, of the deprecated numbering field cache at offset fcPlcfBteLvc in the Table Stream. This value SHOULD<59> be zero.
    uint32 dwLowDateTime;        //The low-order part of a FILETIME structure, as specified by [MS-DTYP], that specifies when the document was last saved.
    uint32 dwHighDateTime;        //The high-order part of a FILETIME structure, as specified by [MS-DTYP], that specifies when the document was last saved.
    uint32 fcPlcfLvcPre10;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated list level cache begins at this offset. Information SHOULD NOT<60> be emitted at this offset and SHOULD<61> be ignored. If lcbPlcfLvcPre10 is zero, fcPlcfLvcPre10 is undefined and MUST be ignored.
    uint32 lcbPlcfLvcPre10;        //An unsigned integer that specifies the size, in bytes, of the deprecated list level cache at offset fcPlcfLvcPre10 in the Table Stream. This value SHOULD<62> be zero.
    uint32 fcPlcfAsumy;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfAsumy begins at the offset. If lcbPlcfAsumy is zero, fcPlcfAsumy is undefined and MUST be ignored.
    uint32 lcbPlcfAsumy;        //An unsigned integer that specifies the size, in bytes, of the PlcfAsumy at offset fcPlcfAsumy in the Table Stream.
    uint32 fcPlcfGram;        //An unsigned integer that specifies an offset in the Table Stream. A Plcfgram, which specifies the state of the grammar checker for each text range, begins at this offset. If lcbPlcfGram is zero, then fcPlcfGram is undefined and MUST be ignored.
    uint32 lcbPlcfGram;        //An unsigned integer that specifies the size, in bytes, of the Plcfgram that begins at offset fcPlcfGram in the Table Stream.
    uint32 fcSttbListNames;        //An unsigned integer that specifies an offset in the Table Stream. A SttbListNames, which specifies the LISTNUM field names of the lists in the document, begins at this offset. If lcbSttbListNames is zero, fcSttbListNames is undefined and MUST be ignored.
    uint32 lcbSttbListNames;        //An unsigned integer that specifies the size, in bytes, of the SttbListNames at the offset fcSttbListNames.
    uint32 fcSttbfUssr;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated, version-specific undo information begins at this offset. This information SHOULD NOT<63> be emitted and SHOULD<64> be ignored.
    uint32 lcbSttbfUssr;        //An unsigned integer that specifies the size, in bytes, of the deprecated, version-specific undo information at offset fcSttbfUssr in the Table Stream.
} FibRgFcLcb97;

typedef struct FibRgFcLcb2000 {
    FibRgFcLcb97 rgFcLcb97;
    uint32 fcPlcfTch;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfTch begins at this offset and specifies a cache of table characters. Information at this offset SHOULD<65> be ignored. If lcbPlcfTch is zero, fcPlcfTch is undefined and MUST be ignored.
    uint32 lcbPlcfTch;        //An unsigned integer that specifies the size, in bytes, of the PlcfTch at offset fcPlcfTch.
    uint32 fcRmdThreading;        // An unsigned integer that specifies an offset in the Table Stream. An RmdThreading that specifies the data concerning the e-mail messages and their authors in this document begins at this offset.
    uint32 lcbRmdThreading;        // An unsigned integer that specifies the size, in bytes, of the RmdThreading at the offset fcRmdThreading. This value MUST NOT be zero.
    uint32 fcMid;        // An unsigned integer that specifies an offset in the Table Stream. A double-byte character Unicode string that specifies the message identifier of the document begins at this offset. This value MUST be ignored.
    uint32 lcbMid;        // An unsigned integer that specifies the size, in bytes, of the double-byte character Unicode string at offset fcMid. This value MUST be ignored.
    uint32 fcSttbRgtplc;        //An unsigned integer that specifies an offset in the Table Stream. A SttbRgtplc that specifies the styles of lists in the document begins at this offset. If lcbSttbRgtplc is zero, fcSttbRgtplc is undefined and MUST be ignored.
    uint32 lcbSttbRgtplc;        //An unsigned integer that specifies the size, in bytes, of the SttbRgtplc at the offset fcSttbRgtplc.
    uint32 fcMsoEnvelope;        //An unsigned integer that specifies an offset in the Table Stream. An MsoEnvelopeCLSID, which specifies the envelope data as specified by [MS-OSHARED] section 2.3.8.1, begins at this offset. If lcbMsoEnvelope is zero, fcMsoEnvelope is undefined and MUST be ignored.
    uint32 lcbMsoEnvelope;        //An unsigned integer that specifies the size, in bytes, of the MsoEnvelopeCLSID at the offset fcMsoEnvelope.
    uint32 fcPlcfLad;        //An unsigned integer that specifies an offset in the Table Stream. A Plcflad begins at this offset and specifies the language auto-detect state of each text range. If lcbPlcfLad is zero, fcPlcfLad is undefined and MUST be ignored.
    uint32 lcbPlcfLad;        // An unsigned integer that specifies the size, in bytes, of the Plcflad that begins at offset fcPlcfLad in the Table Stream.
    uint32 fcRgDofr;        //An unsigned integer that specifies an offset in the Table Stream. A variable-length array with elements of type Dofrh begins at that offset. The elements of this array are records that support the frame set and list style features. If lcbRgDofr is zero, fcRgDofr is undefined and MUST be ignored.
    uint32 lcbRgDofr;        // An unsigned integer that specifies the size, in bytes, of the array that begins at offset fcRgDofr in the Table Stream.
    uint32 fcPlcosl;        //An unsigned integer that specifies an offset in the Table Stream. A PlfCosl begins at the offset. If lcbPlcosl is zero, fcPlcosl is undefined and MUST be ignored.
    uint32 lcbPlcosl;        //An unsigned integer that specifies the size, in bytes, of the PlfCosl at offset fcPlcosl in the Table Stream.
    uint32 fcPlcfCookieOld;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfcookieOld begins at this offset. If lcbPlcfcookieOld is zero, fcPlcfcookieOld is undefined and MUST be ignored. fcPlcfcookieOld MAY<66> be ignored.
    uint32 lcbPlcfCookieOld;        // An unsigned integer that specifies the size, in bytes, of the PlcfcookieOld at offset fcPlcfcookieOld in the Table Stream.
    uint32 fcPgdMotherOld;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated document page layout cache begins at this offset. Information SHOULD NOT<67> be emitted at this offset and SHOULD<68> be ignored. If lcbPgdMotherOld is zero, fcPgdMotherOld is undefined and MUST be ignored.
    uint32 lcbPgdMotherOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated document page layout cache at offset fcPgdMotherOld in the Table Stream.
    uint32 fcBkdMotherOld;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated document text flow break cache begins at this offset. Information SHOULD NOT<69> be emitted at this offset and SHOULD<70> be ignored. If lcbBkdMotherOld is zero, fcBkdMotherOld is undefined and MUST be ignored.
    uint32 lcbBkdMotherOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated document text flow break cache at offset fcBkdMotherOld in the Table Stream.
    uint32 fcPgdFtnOld;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated footnote layout cache begins at this offset. Information SHOULD NOT<71> be emitted at this offset and SHOULD<72> be ignored. If lcbPgdFtnOld is zero, fcPgdFtnOld is undefined and MUST be ignored.
    uint32 lcbPgdFtnOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated footnote layout cache at offset fcPgdFtnOld in the Table Stream.
    uint32 fcBkdFtnOld;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated footnote text flow break cache begins at this offset. Information SHOULD NOT<73> be emitted at this offset and SHOULD<74> be ignored. If lcbBkdFtnOld is zero, fcBkdFtnOld is undefined and MUST be ignored.
    uint32 lcbBkdFtnOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated footnote text flow break cache at offset fcBkdFtnOld in the Table Stream.
    uint32 fcPgdEdnOld;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated endnote layout cache begins at this offset. Information SHOULD NOT<75> be emitted at this offset and SHOULD<76> be ignored. If lcbPgdEdnOld is zero, fcPgdEdnOld is undefined and MUST be ignored.
    uint32 lcbPgdEdnOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated endnote layout cache at offset fcPgdEdnOld in the Table Stream.
    uint32 fcBkdEdnOld;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated endnote text flow break cache begins at this offset. Information SHOULD NOT<77> be emitted at this offset and SHOULD<78> be ignored. If lcbBkdEdnOld is zero, fcBkdEdnOld is undefined and MUST be ignored.
    uint32 lcbBkdEdnOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated endnote text flow break cache at offset fcBkdEdnOld in the Table Stream.   
} FibRgFcLcb2000;

typedef struct FibRgFcLcb2002 {
    FibRgFcLcb2000 rgFcLcb2000;
    uint32 fcUnused1;        //This value is undefined and MUST be ignored.
    uint32 lcbUnused1;        // This value MUST be zero, and MUST be ignored
    uint32 fcPlcfPgp;        //An unsigned integer that specifies an offset in the Table Stream. A PGPArray begins at this offset. If lcbPlcfPgp is 0, fcPlcfPgp is undefined and MUST be ignored.
    uint32 lcbPlcfPgp;        //An unsigned integer that specifies the size, in bytes, of the PGPArray that is stored at offset fcPlcfPgp.
    uint32 fcPlcfuim;        //An unsigned integer that specifies an offset in the Table Stream. A Plcfuim begins at this offset. If lcbPlcfuim is zero, fcPlcfuim is undefined and MUST be ignored.
    uint32 lcbPlcfuim;        //An unsigned integer that specifies the size, in bytes, of the Plcfuim at offset fcPlcfuim.
    uint32 fcPlfguidUim;        //An unsigned integer that specifies an offset in the Table Stream. A PlfguidUim begins at this offset. If lcbPlfguidUim is zero, fcPlfguidUim is undefined and MUST be ignored.
    uint32 lcbPlfguidUim;        //An unsigned integer that specifies the size, in bytes, of the PlfguidUim at offset fcPlfguidUim.
    uint32 fcAtrdExtra;        //An unsigned integer that specifies an offset in the Table Stream. An AtrdExtra begins at this offset. If lcbAtrdExtra is zero, fcAtrdExtra is undefined and MUST be ignored.
    uint32 lcbAtrdExtra;        //An unsigned integer that specifies the size, in bytes, of the AtrdExtra at offset fcAtrdExtra in the Table Stream.
    uint32 fcPlrsid;        // An unsigned integer that specifies an offset in the Table Stream. A PLRSID begins at this offset. If lcbPlrsid is zero, fcPlrsid is undefined and MUST be ignored.
    uint32 lcbPlrsid;        //An unsigned integer that specifies the size, in bytes, of the PLRSID at offset fcPlrsid in the Table Stream.
    uint32 fcSttbfBkmkFactoid;        //An unsigned integer that specifies an offset in the Table Stream. An SttbfBkmkFactoid containing information about smart tag bookmarks in the document begins at this offset. If lcbSttbfBkmkFactoid is zero, fcSttbfBkmkFactoid is undefined and MUST be ignored.
    uint32 lcbSttbfBkmkFactoid;        //An unsigned integer that specifies the size, in bytes, of the SttbfBkmkFactoid at offset fcSttbfBkmkFactoid.
    uint32 fcPlcfBkfFactoid;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfBkfd that contains information about the smart tag bookmarks in the document begins at this offset. If lcbPlcfBkfFactoid is zero, fcPlcfBkfFactoid is undefined and MUST be ignored.
    uint32 lcbPlcfBkfFactoid;        //An unsigned integer that specifies the size, in bytes, of the PlcfBkfd at offset fcPlcfBkfFactoid.
    uint32 fcPlcfcookie;        //An unsigned integer that specifies an offset in the Table Stream. A Plcfcookie begins at this offset. If lcbPlcfcookie is zero, fcPlcfcookie is undefined and MUST be ignored. fcPlcfcookie MAY<79> be ignored.
    uint32 lcbPlcfcookie;        //An unsigned integer that specifies the size, in bytes, of the Plcfcookie at offset fcPlcfcookie in the Table Stream.
    uint32 fcPlcfBklFactoid;        //An unsigned integer that specifies an offset in the Table Stream. A Plcfbkld that contains information about the smart tag bookmarks in the document begins at this offset. If lcbPlcfBklFactoid is zero, fcPlcfBklFactoid is undefined and MUST be ignored.
    uint32 lcbPlcfBklFactoid;        //An unsigned integer that specifies the size, in bytes, of the Plcfbkld at offset fcPlcfBklFactoid.
    uint32 fcFactoidData;        //An unsigned integer that specifies an offset in the Table Stream. A SmartTagData begins at this offset and specifies information about the smart tag recognizers that are used in this document. If lcbFactoidData is zero, fcFactoidData is undefined and MUST be ignored.
    uint32 lcbFactoidData;        //An unsigned integer that specifies the size, in bytes, of the SmartTagData at offset fcFactoidData in the Table Stream.
    uint32 fcDocUndo;        //An unsigned integer that specifies an offset in the WordDocument Stream. Version-specific undo information begins at this offset. This information SHOULD NOT<80> be emitted and SHOULD<81> be ignored.
    uint32 lcbDocUndo;        //An unsigned integer. If this value is nonzero, version-specific undo information exists at offset fcDocUndo in the WordDocument Stream.
    uint32 fcSttbfBkmkFcc;        //An unsigned integer that specifies an offset in the Table Stream. An SttbfBkmkFcc that contains information about the format consistency-checker bookmarks in the document begins at this offset. If lcbSttbfBkmkFcc is zero, fcSttbfBkmkFcc is undefined and MUST be ignored.
    uint32 lcbSttbfBkmkFcc;        //An unsigned integer that specifies the size, in bytes, of the SttbfBkmkFcc at offset fcSttbfBkmkFcc.
    uint32 fcPlcfBkfFcc;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfBkfd that contains information about format consistency-checker bookmarks in the document begins at this offset. If lcbPlcfBkfFcc is zero, fcPlcfBkfFcc is undefined and MUST be ignored.
    uint32 lcbPlcfBkfFcc;        //An unsigned integer that specifies the size, in bytes, of the PlcfBkfd at offset fcPlcfBkfFcc.
    uint32 fcPlcfBklFcc;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfBkld that contains information about the format consistency-checker bookmarks in the document begins at this offset. If lcbPlcfBklFcc is zero, fcPlcfBklFcc is undefined and MUST be ignored.
    uint32 lcbPlcfBklFcc;        //An unsigned integer that specifies the size, in bytes, of the PlcfBkld at offset fcPlcfBklFcc.
    uint32 fcSttbfbkmkBPRepairs;        // An unsigned integer that specifies an offset in the Table Stream. An SttbfBkmkBPRepairs that contains information about the repair bookmarks in the document begins at this offset. If lcbSttbfBkmkBPRepairs is zero, fcSttbfBkmkBPRepairs is undefined and MUST be ignored.
    uint32 lcbSttbfbkmkBPRepairs;        //An unsigned integer that specifies the size, in bytes, of the SttbfBkmkBPRepairs at offset fcSttbfBkmkBPRepairs.
    uint32 fcPlcfbkfBPRepairs;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfBkf that contains information about the repair bookmarks in the document begins at this offset. If lcbPlcfBkfBPRepairs is zero, fcPlcfBkfBPRepairs is undefined and MUST be ignored.
    uint32 lcbPlcfbkfBPRepairs;        //An unsigned integer that specifies the size, in bytes, of the PlcfBkf at offset fcPlcfbkfBPRepairs.
    uint32 fcPlcfbklBPRepairs;        //An unsigned integer that specifies an offset in the Table Stream. A PlcfBkl that contains information about the repair bookmarks in the document begins at this offset. If lcbPlcfBklBPRepairs is zero, fcPlcfBklBPRepairs is undefined and MUST be ignored.
    uint32 lcbPlcfbklBPRepairs;        //An unsigned integer that specifies the size, in bytes, of the PlcfBkl at offset fcPlcfBklBPRepairs.
    uint32 fcPmsNew;        //An unsigned integer that specifies an offset in the Table Stream. A new Pms, which contains the current state of a print merge operation, begins at this offset. If lcbPmsNew is zero, fcPmsNew is undefined and MUST be ignored.
    uint32 lcbPmsNew;        //An unsigned integer which specifies the size, in bytes, of the Pms at offset fcPmsNew.
    uint32 fcODSO;        //An unsigned integer that specifies an offset in the Table Stream. Office Data Source Object (ODSO) data that is used to perform mail merge begins at this offset. The data is stored in an array of ODSOPropertyBase items. The ODSOPropertyBase items are of variable size and are stored contiguously. The complete set of properties that are contained in the array is determined by reading each ODSOPropertyBase, until a total of lcbODSO bytes of data are read. If lcbODSO is zero, fcODSO is undefined and MUST be ignored.
    uint32 lcbODSO;        //An unsigned integer that specifies the size, in bytes, of the Office Data Source Object data at offset fcODSO in the Table Stream.
    uint32 fcPlcfpmiOldXP;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated paragraph mark information cache begins at this offset. Information SHOULD NOT<82> be emitted at this offset and SHOULD<83> be ignored. If lcbPlcfpmiOldXP is zero, fcPlcfpmiOldXP is undefined and MUST be ignored.
    uint32 lcbPlcfpmiOldXP;        //An unsigned integer that specifies the size, in bytes, of the deprecated paragraph mark information cache at offset fcPlcfpmiOldXP in the Table Stream. This value SHOULD<84> be zero.
    uint32 fcPlcfpmiNewXP;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated paragraph mark information cache begins at this offset. Information SHOULD NOT<85> be emitted at this offset and SHOULD<86> be ignored. If lcbPlcfpmiNewXP is zero, fcPlcfpmiNewXP is undefined and MUST be ignored.
    uint32 lcbPlcfpmiNewXP;        //An unsigned integer that specifies the size, in bytes, of the deprecated paragraph mark information cache at offset fcPlcfpmiNewXP in the Table Stream. This value SHOULD<87> be zero.
    uint32 fcPlcfpmiMixedXP;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated paragraph mark information cache begins at this offset. Information SHOULD NOT<88> be emitted at this offset and SHOULD<89> be ignored. If lcbPlcfpmiMixedXP is zero, fcPlcfpmiMixedXP is undefined and MUST be ignored.
    uint32 lcbPlcfpmiMixedXP;        //An unsigned integer that specifies the size, in bytes, of the deprecated paragraph mark information cache at offset fcPlcfpmiMixedXP in the Table Stream. This value SHOULD<90> be zero.
    uint32 fcUnused2;        //This value is undefined and MUST be ignored.
    uint32 lcbUnused2;        //This value MUST be zero, and MUST be ignored.
    uint32 fcPlcffactoid;        //An unsigned integer that specifies an offset in the Table Stream. A Plcffactoid, which specifies the smart tag recognizer state of each text range, begins at this offset. If lcbPlcffactoid is zero, fcPlcffactoid is undefined and MUST be ignored.
    uint32 lcbPlcffactoid;        // An unsigned integer that specifies the size, in bytes of the Plcffactoid that begins at offset fcPlcffactoid in the Table Stream.
    uint32 fcPlcflvcOldXP;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated listnum field cache begins at this offset. Information SHOULD NOT<91> be emitted at this offset and SHOULD<92> be ignored. If lcbPlcflvcOldXP is zero, fcPlcflvcOldXP is undefined and MUST be ignored.
    uint32 lcbPlcflvcOldXP;        //An unsigned integer that specifies the size, in bytes, of the deprecated listnum field cache at offset fcPlcflvcOldXP in the Table Stream. This value SHOULD<93> be zero.
    uint32 fcPlcflvcNewXP;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated listnum field cache begins at this offset. Information SHOULD NOT<94> be emitted at this offset and SHOULD<95> be ignored. If lcbPlcflvcNewXP is zero, fcPlcflvcNewXP is undefined and MUST be ignored.
    uint32 lcbPlcflvcNewXP;        //An unsigned integer that specifies the size, in bytes, of the deprecated listnum field cache at offset fcPlcflvcNewXP in the Table Stream. This value SHOULD<96> be zero.
    uint32 fcPlcflvcMixedXP;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated listnum field cache begins at this offset. Information SHOULD NOT<97> be emitted at this offset and SHOULD<98> be ignored. If lcbPlcflvcMixedXP is zero, fcPlcflvcMixedXP is undefined and MUST be ignored.
    uint32 lcbPlcflvcMixedXP;        //An unsigned integer that specifies the size, in bytes, of the deprecated listnum field cache at offset fcPlcflvcMixedXP in the Table Stream. This value SHOULD<99> be zero.
} FibRgFcLcb2002;

typedef struct FibRgFcLcb2003 {
    FibRgFcLcb2002 rgFcLcb2002;
    uint32 fcHplxsdr;        //An unsigned integer that specifies an offset in the Table Stream. An Hplxsdr structure begins at this offset. This structure specifies information about XML schema definition references.
    uint32 lcbHplxsdr;        //An unsigned integer that specifies the size, in bytes, of the Hplxsdr structure at the offset fcHplxsdr in the Table Stream. If lcbHplxsdr is zero, then fcHplxsdr is undefined and MUST be ignored.
    uint32 fcSttbfBkmkSdt;        //An unsigned integer that specifies an offset in the Table Stream. An SttbfBkmkSdt that contains information about the structured document tag bookmarks in the document begins at this offset. If lcbSttbfBkmkSdt is zero, then fcSttbfBkmkSdt is undefined and MUST be ignored.
    uint32 lcbSttbfBkmkSdt;        //An unsigned integer that specifies the size, in bytes, of the SttbfBkmkSdt at offset fcSttbfBkmkSdt.
    uint32 fcPlcfBkfSdt;        //An unsigned integer that specifies an offset in the Table Stream. A PlcBkfd that contains information about the structured document tag bookmarks in the document begins at this offset. If lcbPlcfBkfSdt is zero, fcPlcfBkfSdt is undefined and MUST be ignored.
    uint32 lcbPlcfBkfSdt;        //An unsigned integer that specifies the size, in bytes, of the PlcBkfd at offset fcPlcfBkfSdt.
    uint32 fcPlcfBklSdt;        //An unsigned integer that specifies an offset in the Table Stream. A PlcBkld that contains information about the structured document tag bookmarks in the document begins at this offset. If lcbPlcfBklSdt is zero, fcPlcfBklSdt is undefined and MUST be ignored.
    uint32 lcbPlcfBklSdt;        //An unsigned integer that specifies the size, in bytes, of the PlcBkld at offset fcPlcfBklSdt.
    uint32 fcCustomXForm;        //An unsigned integer that specifies an offset in the Table Stream. An array of 16-bit Unicode characters, which specifies the full path and file name of the XML Stylesheet to apply when saving this document in XML format, begins at this offset. If lcbCustomXForm is zero, fcCustomXForm is undefined and MUST be ignored.
    uint32 lcbCustomXForm;        //An unsigned integer that specifies the size, in bytes, of the array at offset fcCustomXForm in the Table Stream. This value MUST be less than or equal to 4168 and MUST be evenly divisible by two.
    uint32 fcSttbfBkmkProt;        //An unsigned integer that specifies an offset in the Table Stream. An SttbfBkmkProt that contains information about range-level protection bookmarks in the document begins at this offset. If lcbSttbfBkmkProt is zero, fcSttbfBkmkProt is undefined and MUST be ignored.
    uint32 lcbSttbfBkmkProt;        //An unsigned integer that specifies the size, in bytes, of the SttbfBkmkProt at offset fcSttbfBkmkProt.
    uint32 fcPlcfBkfProt;        //An unsigned integer that specifies an offset in the Table Stream. A PlcBkf that contains information about range-level protection bookmarks in the document begins at this offset. If lcbPlcfBkfProt is zero, then fcPlcfBkfProt is undefined and MUST be ignored.
    uint32 lcbPlcfBkfProt;        //An unsigned integer that specifies the size, in bytes, of the PlcBkf at offset fcPlcfBkfProt.
    uint32 fcPlcfBklProt;        //An unsigned integer that specifies an offset in the Table Stream. A PlcBkl containing information about range-level protection bookmarks in the document begins at this offset. If lcbPlcfBklProt is zero, then fcPlcfBklProt is undefined and MUST be ignored.
    uint32 lcbPlcfBklProt;        //An unsigned integer that specifies the size, in bytes, of the PlcBkl at offset fcPlcfBklProt.
    uint32 fcSttbProtUser;        // An unsigned integer that specifies an offset in the Table Stream. A SttbProtUser that specifies the usernames that are used for range-level protection begins at this offset.
    uint32 lcbSttbProtUser;        // An unsigned integer that specifies the size, in bytes, of the SttbProtUser at the offset fcSttbProtUser.
    uint32 fcUnused;        //This value MUST be zero, and MUST be ignored.
    uint32 lcbUnused;        //This value MUST be zero, and MUST be ignored.
    uint32 fcPlcfpmiOld;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated paragraph mark information cache begins at this offset. Information SHOULD NOT<100> be emitted at this offset and SHOULD<101> be ignored. If lcbPlcfpmiOld is zero, then fcPlcfpmiOld is undefined and MUST be ignored.
    uint32 lcbPlcfpmiOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated paragraph mark information cache at offset fcPlcfpmiOld in the Table Stream. SHOULD<102> be zero.
    uint32 fcPlcfpmiOldInline;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated paragraph mark information cache begins at this offset. Information SHOULD NOT<103> be emitted at this offset and SHOULD<104> be ignored. If lcbPlcfpmiOldInline is zero, then fcPlcfpmiOldInline is undefined and MUST be ignored.
    uint32 lcbPlcfpmiOldInline;        //An unsigned integer that specifies the size, in bytes, of the deprecated paragraph mark information cache at offset fcPlcfpmiOldInline in the Table Stream. SHOULD<105> be zero.
    uint32 fcPlcfpmiNew;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated paragraph mark information cache begins at this offset. Information SHOULD NOT<106> be emitted at this offset and SHOULD<107> be ignored. If lcbPlcfpmiNew is zero, then fcPlcfpmiNew is undefined and MUST be ignored.
    uint32 lcbPlcfpmiNew;        //An unsigned integer that specifies the size, in bytes, of the deprecated paragraph mark information cache at offset fcPlcfpmiNew in the Table Stream. SHOULD<108> be zero.
    uint32 fcPlcfpmiNewInline;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated paragraph mark information cache begins at this offset. Information SHOULD NOT<109> be emitted at this offset and SHOULD<110> be ignored. If lcbPlcfpmiNewInline is zero, then fcPlcfpmiNewInline is undefined and MUST be ignored.
    uint32 lcbPlcfpmiNewInline;        //An unsigned integer that specifies the size, in bytes, of the deprecated paragraph mark information cache at offset fcPlcfpmiNewInline in the Table Stream. SHOULD<111> be zero.
    uint32 fcPlcflvcOld;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated listnum field cache begins at this offset. Information SHOULD NOT<112> be emitted at this offset and SHOULD<113> be ignored. If lcbPlcflvcOld is zero, then fcPlcflvcOld is undefined and MUST be ignored.
    uint32 lcbPlcflvcOld;        //An unsigned integer that specifies the size, in bytes, of the deprecated listnum field cache at offset fcPlcflvcOld in the Table Stream. SHOULD<114> be zero.
    uint32 fcPlcflvcOldInline;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated listnum field cache begins at this offset. Information SHOULD NOT<115> be emitted at this offset and SHOULD<116> be ignored. If lcbPlcflvcOldInline is zero, fcPlcflvcOldInline is undefined and MUST be ignored.
    uint32 lcbPlcflvcOldInline;        //An unsigned integer that specifies the size, in bytes, of the deprecated listnum field cache at offset fcPlcflvcOldInline in the Table Stream. SHOULD<117> be zero.
    uint32 fcPlcflvcNew;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated listnum field cache begins at this offset. Information SHOULD NOT<118> be emitted at this offset and SHOULD<119> be ignored. If lcbPlcflvcNew is zero, fcPlcflvcNew is undefined and MUST be ignored.
    uint32 lcbPlcflvcNew;        //An unsigned integer that specifies the size, in bytes, of the deprecated listnum field cache at offset fcPlcflvcNew in the Table Stream. SHOULD<120> be zero.
    uint32 fcPlcflvcNewInline;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated listnum field cache begins at this offset. Information SHOULD NOT<121> be emitted at this offset and SHOULD<122> be ignored. If lcbPlcflvcNewInline is zero, fcPlcflvcNewInline is undefined and MUST be ignored.
    uint32 lcbPlcflvcNewInline;        //An unsigned integer that specifies the size, in bytes, of the deprecated listnum field cache at offset fcPlcflvcNewInline in the Table Stream. SHOULD<123> be zero.
    uint32 fcPgdMother;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated document page layout cache begins at this offset. Information SHOULD NOT<124> be emitted at this offset and SHOULD<125> be ignored. If lcbPgdMother is zero, fcPgdMother is undefined and MUST be ignored.
    uint32 lcbPgdMother;        //An unsigned integer that specifies the size, in bytes, of the deprecated document page layout cache at offset fcPgdMother in the Table Stream.
    uint32 fcBkdMother;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated document text flow break cache begins at this offset. Information SHOULD NOT<126> be emitted at this offset and SHOULD<127> be ignored. If lcbBkdMother is zero, then fcBkdMother is undefined and MUST be ignored.
    uint32 lcbBkdMother;        //An unsigned integer that specifies the size, in bytes, of the deprecated document text flow break cache at offset fcBkdMother in the Table Stream.
    uint32 fcAfdMother;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated document author filter cache begins at this offset. Information SHOULD NOT<128> be emitted at this offset and SHOULD<129> be ignored. If lcbAfdMother is zero, then fcAfdMother is undefined and MUST be ignored.
    uint32 lcbAfdMother;        //An unsigned integer that specifies the size, in bytes, of the deprecated document author filter cache at offset fcAfdMother in the Table Stream.
    uint32 fcPgdFtn;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated footnote layout cache begins at this offset. Information SHOULD NOT<130> be emitted at this offset and SHOULD<131> be ignored. If lcbPgdFtn is zero, then fcPgdFtn is undefined and MUST be ignored.
    uint32 lcbPgdFtn;        //An unsigned integer that specifies the size, in bytes, of the deprecated footnote layout cache at offset fcPgdFtn in the Table Stream.
    uint32 fcBkdFtn;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated footnote text flow break cache begins at this offset. Information SHOULD NOT<132> be emitted at this offset and SHOULD<133> be ignored. If lcbBkdFtn is zero, fcBkdFtn is undefined and MUST be ignored.
    uint32 lcbBkdFtn;        //An unsigned integer that specifies the size, in bytes, of the deprecated footnote text flow break cache at offset fcBkdFtn in the Table Stream.
    uint32 fcAfdFtn;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated footnote author filter cache begins at this offset. Information SHOULD NOT<134> be emitted at this offset and SHOULD<135> be ignored. If lcbAfdFtn is zero, fcAfdFtn is undefined and MUST be ignored.
    uint32 lcbAfdFtn;        //An unsigned integer that specifies the size, in bytes, of the deprecated footnote author filter cache at offset fcAfdFtn in the Table Stream.
    uint32 fcPgdEdn;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated endnote layout cache begins at this offset. Information SHOULD NOT<136> be emitted at this offset and SHOULD<137> be ignored. If lcbPgdEdn is zero, then fcPgdEdn is undefined and MUST be ignored.
    uint32 lcbPgdEdn;        //An unsigned integer that specifies the size, in bytes, of the deprecated endnote layout cache at offset fcPgdEdn in the Table Stream.
    uint32 fcBkdEdn;        //An unsigned integer that specifies an offset in the Table Stream. The deprecated endnote text flow break cache begins at this offset. Information SHOULD NOT<138> be emitted at this offset and SHOULD<139> be ignored. If lcbBkdEdn is zero, fcBkdEdn is undefined and MUST be ignored.
    uint32 lcbBkdEdn;        //An unsigned integer that specifies the size, in bytes, of the deprecated endnote text flow break cache at offset fcBkdEdn in the Table Stream.
    uint32 fcAfdEdn;        //An unsigned integer that specifies an offset in the Table Stream. Deprecated endnote author filter cache begins at this offset. Information SHOULD NOT<140> be emitted at this offset and SHOULD<141> be ignored. If lcbAfdEdn is zero, then fcAfdEdn is undefined and MUST be ignored.
    uint32 lcbAfdEdn;        //An unsigned integer that specifies the size, in bytes, of the deprecated endnote author filter cache at offset fcAfdEdn in the Table Stream.
    uint32 fcAfd;        // An unsigned integer that specifies an offset in the Table Stream. A deprecated AFD structure begins at this offset. Information SHOULD NOT<142> be emitted at this offset and SHOULD<143> be ignored. If lcbAfd is zero, fcAfd is undefined and MUST be ignored.
    uint32 lcbAfd;        //An unsigned integer that specifies the size, in bytes, of the deprecated AFD structure at offset fcAfd in the Table Stream.
} FibRgFcLcb2003;

typedef struct PrcData {
    uint8 cbGrpprl;
} __attribute__((packed)) PrcData;

typedef struct Prc {
    uint8 clxt;     // This value MUST be 0x01.
    PrcData RgPrc;
} __attribute__((packed)) Prc;

typedef struct Pcdt {
    uint8 clxt;     // This value MUST be 0x02.
    uint32 lcb;     // An unsigned integer that specifies the size, in bytes, of the PlcPcd structure.
} __attribute__((packed)) Pcdt;

typedef struct cp {
    uint32 cp;
} cp;

typedef struct FcCompressed {
    uint32 fc:30;
    uint32 fCompressed:1;
    uint32 r1:1;
} FcCompressed;

typedef struct pcd {
    uint16 fNoParaLast:1;
    uint16 fR1:1;
    uint16 fDirty:1;
    uint16 fR2:13;
    FcCompressed fc;
    uint16 prm;
} __attribute__((packed)) pcd;

typedef struct sttb {
    uint16 fExtend;
    uint16 cData;
    uint16 cbExtra;
    uint16 cchData0;
} sttb;

typedef struct FibRgFcLcb2007 {
    FibRgFcLcb2003 rgFcLcb2003;
    uint32 fcPlcfmthd;        //This value is undefined and MUST be ignored.
    uint32 lcbPlcfmthd;        //This value MUST be zero, and MUST be ignored.
    uint32 fcSttbfBkmkMoveFrom;        // This value is undefined and MUST be ignored.
    uint32 lcbSttbfBkmkMoveFrom;        // This value MUST be zero, and MUST be ignored.
    uint32 fcPlcfBkfMoveFrom;        // This value is undefined and MUST be ignored
    uint32 lcbPlcfBkfMoveFrom;        // This value MUST be zero, and MUST be ignored.
    uint32 fcPlcfBklMoveFrom;        // This value is undefined and MUST be ignored.
    uint32 lcbPlcfBklMoveFrom;        // This value MUST be zero, and MUST be ignored.
    uint32 fcSttbfBkmkMoveTo;        // This value is undefined and MUST be ignored.
    uint32 lcbSttbfBkmkMoveTo;        // This value MUST be zero, and MUST be ignored.
    uint32 fcPlcfBkfMoveTo;        // This value is undefined and MUST be ignored.
    uint32 lcbPlcfBkfMoveTo;        // This value MUST be zero, and MUST be ignored.
    uint32 fcPlcfBklMoveTo;        // This value is undefined and MUST be ignored.
    uint32 lcbPlcfBklMoveTo;        // This value MUST be zero, and MUST be ignored.
    uint32 fcUnused1;        // This value is undefined and MUST be ignored.
    uint32 lcbUnused1;        // This value MUST be zero, and MUST be ignored.
    uint32 fcUnused2;        // This value is undefined and MUST be ignored.
    uint32 lcbUnused2;        // This value MUST be zero, and MUST be ignored.
    uint32 fcUnused3;        // This value is undefined and MUST be ignored.
    uint32 lcbUnused3;        // This value MUST be zero, and MUST be ignored.
    uint32 fcSttbfBkmkArto;        // This value is undefined and MUST be ignored.
    uint32 lcbSttbfBkmkArto;        // This value MUST be zero, and MUST be ignored.
    uint32 fcPlcfBkfArto;        // This value is undefined and MUST be ignored.
    uint32 lcbPlcfBkfArto;        // This value MUST be zero, and MUST be ignored
    uint32 fcPlcfBklArto;        // Undefined and MUST be ignored.
    uint32 lcbPlcfBklArto;        // MUST be zero, and MUST be ignored.
    uint32 fcArtoData;        // This value is undefined and MUST be ignored.
    uint32 lcbArtoData;        // This value MUST be zero, and MUST be ignored.
    uint32 fcUnused4;        // This value is undefined and MUST be ignored.
    uint32 lcbUnused4;        // This value MUST be zero, and MUST be ignored.
    uint32 fcUnused5;        // This value is undefined and MUST be ignored.
    uint32 lcbUnused5;        // This value MUST be zero, and MUST be ignored.
    uint32 fcUnused6;        // This value is undefined and MUST be ignored.
    uint32 lcbUnused6;        // This value MUST be zero, and MUST be ignored.
    uint32 fcOssTheme;        // This value is undefined and MUST be ignored.
    uint32 lcbOssTheme;        // This value SHOULD<144> be zero, and MUST be ignored.
    uint32 fcColorSchemeMapping;        // This value is undefined and MUST be ignored.
    uint32 lcbColorSchemeMapping;        // This value SHOULD<145> be zero, and MUST be ignored.
} FibRgFcLcb2007;

typedef struct fib {
    Fibbase fbase;
    uint32 csw:16;          // 0x0E
    FibRgW97 fibRgW;
    uint16 cslw;            // 0x16
    FibRgLw97 fibRgLw;
    uint16 cbRgFcLcb;       // 
    FibRgFcLcb97 fibRgFcLcbBlob;
} __attribute__((packed)) FIB;

#endif
