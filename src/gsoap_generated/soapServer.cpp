/* soapServer.cpp
   Generated by gSOAP 2.8.12 from EBMS_serverClass.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapServer.cpp ver 2.8.12 2013-01-21 18:12:04 GMT")


extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:doOperation"))
		return soap_serve___ns1__doOperation(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:login"))
		return soap_serve___ns1__login(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:hasPrivilege"))
		return soap_serve___ns1__hasPrivilege(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:doOperation"))
		return soap_serve___ns1__doOperation_(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:login"))
		return soap_serve___ns1__login_(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:hasPrivilege"))
		return soap_serve___ns1__hasPrivilege_(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__doOperation(struct soap *soap)
{	struct __ns1__doOperation soap_tmp___ns1__doOperation;
	_ns1__doOperationResponse ns1__doOperationResponse;
	ns1__doOperationResponse.soap_default(soap);
	soap_default___ns1__doOperation(soap, &soap_tmp___ns1__doOperation);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__doOperation(soap, &soap_tmp___ns1__doOperation, "-ns1:doOperation", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__doOperation(soap, soap_tmp___ns1__doOperation.ns1__doOperation, &ns1__doOperationResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__doOperationResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__doOperationResponse.soap_put(soap, "ns1:doOperationResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__doOperationResponse.soap_put(soap, "ns1:doOperationResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__login(struct soap *soap)
{	struct __ns1__login soap_tmp___ns1__login;
	_ns1__loginResponse ns1__loginResponse;
	ns1__loginResponse.soap_default(soap);
	soap_default___ns1__login(soap, &soap_tmp___ns1__login);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__login(soap, &soap_tmp___ns1__login, "-ns1:login", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__login(soap, soap_tmp___ns1__login.ns1__login, &ns1__loginResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__loginResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__loginResponse.soap_put(soap, "ns1:loginResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__loginResponse.soap_put(soap, "ns1:loginResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__hasPrivilege(struct soap *soap)
{	struct __ns1__hasPrivilege soap_tmp___ns1__hasPrivilege;
	_ns1__hasPrivilegeResponse ns1__hasPrivilegeResponse;
	ns1__hasPrivilegeResponse.soap_default(soap);
	soap_default___ns1__hasPrivilege(soap, &soap_tmp___ns1__hasPrivilege);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__hasPrivilege(soap, &soap_tmp___ns1__hasPrivilege, "-ns1:hasPrivilege", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__hasPrivilege(soap, soap_tmp___ns1__hasPrivilege.ns1__hasPrivilege, &ns1__hasPrivilegeResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__hasPrivilegeResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__hasPrivilegeResponse.soap_put(soap, "ns1:hasPrivilegeResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__hasPrivilegeResponse.soap_put(soap, "ns1:hasPrivilegeResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__doOperation_(struct soap *soap)
{	struct __ns1__doOperation_ soap_tmp___ns1__doOperation_;
	_ns1__doOperationResponse ns1__doOperationResponse;
	ns1__doOperationResponse.soap_default(soap);
	soap_default___ns1__doOperation_(soap, &soap_tmp___ns1__doOperation_);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__doOperation_(soap, &soap_tmp___ns1__doOperation_, "-ns1:doOperation", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__doOperation_(soap, soap_tmp___ns1__doOperation_.ns1__doOperation, &ns1__doOperationResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__doOperationResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__doOperationResponse.soap_put(soap, "ns1:doOperationResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__doOperationResponse.soap_put(soap, "ns1:doOperationResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__login_(struct soap *soap)
{	struct __ns1__login_ soap_tmp___ns1__login_;
	_ns1__loginResponse ns1__loginResponse;
	ns1__loginResponse.soap_default(soap);
	soap_default___ns1__login_(soap, &soap_tmp___ns1__login_);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__login_(soap, &soap_tmp___ns1__login_, "-ns1:login", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__login_(soap, soap_tmp___ns1__login_.ns1__login, &ns1__loginResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__loginResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__loginResponse.soap_put(soap, "ns1:loginResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__loginResponse.soap_put(soap, "ns1:loginResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__hasPrivilege_(struct soap *soap)
{	struct __ns1__hasPrivilege_ soap_tmp___ns1__hasPrivilege_;
	_ns1__hasPrivilegeResponse ns1__hasPrivilegeResponse;
	ns1__hasPrivilegeResponse.soap_default(soap);
	soap_default___ns1__hasPrivilege_(soap, &soap_tmp___ns1__hasPrivilege_);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__hasPrivilege_(soap, &soap_tmp___ns1__hasPrivilege_, "-ns1:hasPrivilege", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__hasPrivilege_(soap, soap_tmp___ns1__hasPrivilege_.ns1__hasPrivilege, &ns1__hasPrivilegeResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__hasPrivilegeResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__hasPrivilegeResponse.soap_put(soap, "ns1:hasPrivilegeResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__hasPrivilegeResponse.soap_put(soap, "ns1:hasPrivilegeResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapServer.cpp */
