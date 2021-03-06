/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "DNDS"
 * 	found in "dnds.asn1"
 * 	`asn1c -fnative-types`
 */

#ifndef	_DSMessage_H_
#define	_DSMessage_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <PrintableString.h>
#include <NativeEnumerated.h>
#include "AddRequest.h"
#include "AddResponse.h"
#include "DelRequest.h"
#include "DelResponse.h"
#include "ModifyRequest.h"
#include "ModifyResponse.h"
#include "NodeConnInfo.h"
#include "SearchRequest.h"
#include "SearchResponse.h"
#include "TerminateRequest.h"
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum action {
	action_addAccount	= 1,
	action_delAccount	= 2,
	action_getAccountApiKey	= 3,
	action_activateAccount	= 4,
	action_addNetwork	= 5,
	action_delNetwork	= 6,
	action_listNetwork	= 7,
	action_updateNetworkName	= 8,
	action_addNode	= 9,
	action_delNode	= 10,
	action_listNode	= 11,
	action_updateNodeName	= 12,
	action_updateNodeConnInfo	= 13,
	action_provisionningNode	= 14
	/*
	 * Enumeration is extensible
	 */
} e_action;
typedef enum dsop_PR {
	dsop_PR_NOTHING,	/* No components present */
	dsop_PR_addRequest,
	dsop_PR_addResponse,
	dsop_PR_delRequest,
	dsop_PR_delResponse,
	dsop_PR_modifyRequest,
	dsop_PR_modifyResponse,
	dsop_PR_nodeConnInfo,
	dsop_PR_searchRequest,
	dsop_PR_searchResponse,
	dsop_PR_terminateRequest,
	/* Extensions may appear below */
	
} dsop_PR;

/* DSMessage */
typedef struct DSMessage {
	unsigned long	 seqNumber;
	unsigned long	 ackNumber;
	PrintableString_t	*apikey	/* OPTIONAL */;
	long	 action;
	struct dsop {
		dsop_PR present;
		union DSMessage__dsop_u {
			AddRequest_t	 addRequest;
			AddResponse_t	 addResponse;
			DelRequest_t	 delRequest;
			DelResponse_t	 delResponse;
			ModifyRequest_t	 modifyRequest;
			ModifyResponse_t	 modifyResponse;
			NodeConnInfo_t	 nodeConnInfo;
			SearchRequest_t	 searchRequest;
			SearchResponse_t	 searchResponse;
			TerminateRequest_t	 terminateRequest;
			/*
			 * This type is extensible,
			 * possible extensions are below.
			 */
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} dsop;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DSMessage_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_seqNumber_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_ackNumber_3;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_action_5;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_DSMessage;

#ifdef __cplusplus
}
#endif

#endif	/* _DSMessage_H_ */
#include <asn_internal.h>
