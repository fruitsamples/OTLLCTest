/*	File:		NegotiateRawModeSample.h	Contains:		Written by: rich kubota		Copyright:	Copyright � 1997-1999 by Apple Computer, Inc., All Rights Reserved.				You may incorporate this Apple sample source code into your program(s) without				restriction. This Apple sample source code has been provided "AS IS" and the				responsibility for its operation is yours. You are not permitted to redistribute				this Apple sample source code as "Apple sample source code" after having made				changes. If you're going to re-distribute the source, we require that you make				it clear in the source that the code was descended from Apple sample source				code, but that you've made changes.	Change History (most recent first):				7/22/1999	Karl Groethe	Updated for Metrowerks Codewarror Pro 2.1				*/#ifndef __NEGOTIATERAWMODESAMPLE__#define __NEGOTIATERAWMODESAMPLE__#include <Types.h>#include "OpenTransport.h"#ifdef __cplusplusextern "C" {#endif#if PRAGMA_ALIGN_SUPPORTED#pragma options align=mac68k#endif#if PRAGMA_IMPORT_SUPPORTED#pragma import on#endifenum{	kOTVers12	= 0x01208000};enum{	kUnknownTemplate 	= 0x00,	kOrigTemplate,	kMentatTemplate};/* Flags for various structures. */enum{	DL_NORMAL_STATUS	= 0x01,	DL_ERROR_STATUS		= 0x02,	DL_TRUNCATED_PACKET	= 0x04,	DL_VERSION			= 0x00,	DL_VERSION_BITS		= 0xF0000000};/* * Receive and send error flags, these should not overlap with other * flags above. */enum{	DL_CRC_ERROR		= 0x10,	DL_RUNT_ERROR		= 0x20,	DL_FRAMING_ERROR	= 0x40,	DL_BAD_802_3_LENGTH	= 0x80,	DL_ERROR_MASK		= DL_CRC_ERROR | DL_RUNT_ERROR | DL_FRAMING_ERROR | DL_BAD_802_3_LENGTH};/* Input and output structure for I_OTSetRawMode kOTSetRecvMode ioctl. */struct dl_recv_control_t {	unsigned long	dl_primitive;	unsigned long	dl_flags;	unsigned long	dl_truncation_length;};typedef struct dl_recv_control_t dl_recv_control_t;struct dl_recv_status_t {unsigned long	dl_overall_length;unsigned long	dl_flags;unsigned long	dl_packet_length_before_truncation;unsigned long	dl_pad;OTTimeStamp		dl_timestamp;};typedef struct dl_recv_status_t dl_recv_status_t;extern pascal OSStatus DoNegotiateRawModeOption(EndpointRef ep, 												UInt32 rawModeOption,												UInt32 *templateType);#if PRAGMA_ALIGN_SUPPORTED#pragma options align=reset#endif#if PRAGMA_IMPORT_SUPPORTED#pragma import off#endif#ifdef __cplusplus}#endif#endif	// __NEGOTIATERAWMODESAMPLE__