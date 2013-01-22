/* soapClient.cpp
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

SOAP_SOURCE_STAMP("@(#) soapClient.cpp ver 2.8.12 2013-01-21 18:12:04 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__doOperation(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__doOperation *ns1__doOperation, _ns1__doOperationResponse *ns1__doOperationResponse)
{	struct __ns1__doOperation soap_tmp___ns1__doOperation;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap11Endpoint/ http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap12Endpoint/";
	if (soap_action == NULL)
		soap_action = "urn:doOperation";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__doOperation.ns1__doOperation = ns1__doOperation;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__doOperation(soap, &soap_tmp___ns1__doOperation);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__doOperation(soap, &soap_tmp___ns1__doOperation, "-ns1:doOperation", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__doOperation(soap, &soap_tmp___ns1__doOperation, "-ns1:doOperation", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__doOperationResponse)
		return soap_closesock(soap);
	ns1__doOperationResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__doOperationResponse->soap_get(soap, "ns1:doOperationResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__login(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__login *ns1__login, _ns1__loginResponse *ns1__loginResponse)
{	struct __ns1__login soap_tmp___ns1__login;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap11Endpoint/ http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap12Endpoint/";
	if (soap_action == NULL)
		soap_action = "urn:login";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__login.ns1__login = ns1__login;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__login(soap, &soap_tmp___ns1__login);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__login(soap, &soap_tmp___ns1__login, "-ns1:login", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__login(soap, &soap_tmp___ns1__login, "-ns1:login", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__loginResponse)
		return soap_closesock(soap);
	ns1__loginResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__loginResponse->soap_get(soap, "ns1:loginResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__hasPrivilege(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__hasPrivilege *ns1__hasPrivilege, _ns1__hasPrivilegeResponse *ns1__hasPrivilegeResponse)
{	struct __ns1__hasPrivilege soap_tmp___ns1__hasPrivilege;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap11Endpoint/ http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap12Endpoint/";
	if (soap_action == NULL)
		soap_action = "urn:hasPrivilege";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__hasPrivilege.ns1__hasPrivilege = ns1__hasPrivilege;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__hasPrivilege(soap, &soap_tmp___ns1__hasPrivilege);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__hasPrivilege(soap, &soap_tmp___ns1__hasPrivilege, "-ns1:hasPrivilege", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__hasPrivilege(soap, &soap_tmp___ns1__hasPrivilege, "-ns1:hasPrivilege", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__hasPrivilegeResponse)
		return soap_closesock(soap);
	ns1__hasPrivilegeResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__hasPrivilegeResponse->soap_get(soap, "ns1:hasPrivilegeResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__doOperation_(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__doOperation *ns1__doOperation, _ns1__doOperationResponse *ns1__doOperationResponse)
{	struct __ns1__doOperation_ soap_tmp___ns1__doOperation_;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap11Endpoint/ http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap12Endpoint/";
	if (soap_action == NULL)
		soap_action = "urn:doOperation";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__doOperation_.ns1__doOperation = ns1__doOperation;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__doOperation_(soap, &soap_tmp___ns1__doOperation_);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__doOperation_(soap, &soap_tmp___ns1__doOperation_, "-ns1:doOperation", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__doOperation_(soap, &soap_tmp___ns1__doOperation_, "-ns1:doOperation", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__doOperationResponse)
		return soap_closesock(soap);
	ns1__doOperationResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__doOperationResponse->soap_get(soap, "ns1:doOperationResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__login_(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__login *ns1__login, _ns1__loginResponse *ns1__loginResponse)
{	struct __ns1__login_ soap_tmp___ns1__login_;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap11Endpoint/ http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap12Endpoint/";
	if (soap_action == NULL)
		soap_action = "urn:login";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__login_.ns1__login = ns1__login;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__login_(soap, &soap_tmp___ns1__login_);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__login_(soap, &soap_tmp___ns1__login_, "-ns1:login", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__login_(soap, &soap_tmp___ns1__login_, "-ns1:login", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__loginResponse)
		return soap_closesock(soap);
	ns1__loginResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__loginResponse->soap_get(soap, "ns1:loginResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__hasPrivilege_(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__hasPrivilege *ns1__hasPrivilege, _ns1__hasPrivilegeResponse *ns1__hasPrivilegeResponse)
{	struct __ns1__hasPrivilege_ soap_tmp___ns1__hasPrivilege_;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap11Endpoint/ http://localhost:8080/EBMS_server/services/EBMS_serverClass.EBMS_serverClassHttpSoap12Endpoint/";
	if (soap_action == NULL)
		soap_action = "urn:hasPrivilege";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__hasPrivilege_.ns1__hasPrivilege = ns1__hasPrivilege;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__hasPrivilege_(soap, &soap_tmp___ns1__hasPrivilege_);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__hasPrivilege_(soap, &soap_tmp___ns1__hasPrivilege_, "-ns1:hasPrivilege", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__hasPrivilege_(soap, &soap_tmp___ns1__hasPrivilege_, "-ns1:hasPrivilege", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__hasPrivilegeResponse)
		return soap_closesock(soap);
	ns1__hasPrivilegeResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__hasPrivilegeResponse->soap_get(soap, "ns1:hasPrivilegeResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.cpp */