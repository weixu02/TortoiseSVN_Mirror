/* soapCustomBinding_DumpUploadService3_UploaderProxy.cpp
   Generated by gSOAP 2.8.17r from DumpUploader.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapCustomBinding_DumpUploadService3_UploaderProxy.h"

CustomBinding_DumpUploadService3_UploaderProxy::CustomBinding_DumpUploadService3_UploaderProxy()
{   CustomBinding_DumpUploadService3_UploaderProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

CustomBinding_DumpUploadService3_UploaderProxy::CustomBinding_DumpUploadService3_UploaderProxy(const struct soap &_soap) : soap(_soap)
{ }

CustomBinding_DumpUploadService3_UploaderProxy::CustomBinding_DumpUploadService3_UploaderProxy(const char *url)
{   CustomBinding_DumpUploadService3_UploaderProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
    soap_endpoint = url;
}

CustomBinding_DumpUploadService3_UploaderProxy::CustomBinding_DumpUploadService3_UploaderProxy(soap_mode iomode)
{   CustomBinding_DumpUploadService3_UploaderProxy_init(iomode, iomode);
}

CustomBinding_DumpUploadService3_UploaderProxy::CustomBinding_DumpUploadService3_UploaderProxy(const char *url, soap_mode iomode)
{   CustomBinding_DumpUploadService3_UploaderProxy_init(iomode, iomode);
    soap_endpoint = url;
}

CustomBinding_DumpUploadService3_UploaderProxy::CustomBinding_DumpUploadService3_UploaderProxy(soap_mode imode, soap_mode omode)
{   CustomBinding_DumpUploadService3_UploaderProxy_init(imode, omode);
}

CustomBinding_DumpUploadService3_UploaderProxy::~CustomBinding_DumpUploadService3_UploaderProxy()
{ }

void CustomBinding_DumpUploadService3_UploaderProxy::CustomBinding_DumpUploadService3_UploaderProxy_init(soap_mode imode, soap_mode omode)
{   soap_imode(this, imode);
    soap_omode(this, omode);
    soap_endpoint = NULL;
    static const struct Namespace namespaces[] =
{
    {"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://schemas.xmlsoap.org/soap/envelope/", NULL},
    {"SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://schemas.xmlsoap.org/soap/encoding/", NULL},
    {"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
    {"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
    {"xop", "http://www.w3.org/2004/08/xop/include", NULL, NULL},
    {"ns5", "http://schemas.microsoft.com/2003/10/Serialization/Arrays", NULL, NULL},
    {"ns3", "http://schemas.microsoft.com/2003/10/Serialization/", NULL, NULL},
    {"ns4", "http://schemas.datacontract.org/2004/07/DumpUploadService3", NULL, NULL},
    {"ns1", "https://www.drdump.com/services", NULL, NULL},
    {NULL, NULL, NULL, NULL}
};
    soap_set_namespaces(this, namespaces);
}

void CustomBinding_DumpUploadService3_UploaderProxy::destroy()
{   soap_destroy(this);
    soap_end(this);
}

void CustomBinding_DumpUploadService3_UploaderProxy::reset()
{   destroy();
    soap_done(this);
    soap_initialize(this);
    CustomBinding_DumpUploadService3_UploaderProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void CustomBinding_DumpUploadService3_UploaderProxy::soap_noheader()
{   this->header = NULL;
}

const SOAP_ENV__Header *CustomBinding_DumpUploadService3_UploaderProxy::soap_header()
{   return this->header;
}

const SOAP_ENV__Fault *CustomBinding_DumpUploadService3_UploaderProxy::soap_fault()
{   return this->fault;
}

const char *CustomBinding_DumpUploadService3_UploaderProxy::soap_fault_string()
{   return *soap_faultstring(this);
}

const char *CustomBinding_DumpUploadService3_UploaderProxy::soap_fault_detail()
{   return *soap_faultdetail(this);
}

int CustomBinding_DumpUploadService3_UploaderProxy::soap_close_socket()
{   return soap_closesock(this);
}

int CustomBinding_DumpUploadService3_UploaderProxy::soap_force_close_socket()
{   return soap_force_closesock(this);
}

void CustomBinding_DumpUploadService3_UploaderProxy::soap_print_fault(FILE *fd)
{   ::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void CustomBinding_DumpUploadService3_UploaderProxy::soap_stream_fault(std::ostream& os)
{   ::soap_stream_fault(this, os);
}
#endif

char *CustomBinding_DumpUploadService3_UploaderProxy::soap_sprint_fault(char *buf, size_t len)
{   return ::soap_sprint_fault(this, buf, len);
}
#endif

int CustomBinding_DumpUploadService3_UploaderProxy::Hello(const char *endpoint, const char *soap_action, _ns1__Hello *ns1__Hello, _ns1__HelloResponse *ns1__HelloResponse)
{   struct soap *soap = this;
    struct __ns1__Hello soap_tmp___ns1__Hello;
    if (endpoint)
        soap_endpoint = endpoint;
    if (soap_endpoint == NULL)
        soap_endpoint = "http://localhost:59175/Service/DumpUploader3.svc";
    if (soap_action == NULL)
        soap_action = "https://www.drdump.com/services/DumpUploadService3.Uploader/Hello";
    soap_begin(soap);
    soap->encodingStyle = NULL;
    soap_tmp___ns1__Hello.ns1__Hello = ns1__Hello;
    soap_set_version(soap, 2); /* SOAP1.2 */
    soap_serializeheader(soap);
    soap_serialize___ns1__Hello(soap, &soap_tmp___ns1__Hello);
    if (soap_begin_count(soap))
        return soap->error;
    if (soap->mode & SOAP_IO_LENGTH)
    {   if (soap_envelope_begin_out(soap)
         || soap_putheader(soap)
         || soap_body_begin_out(soap)
         || soap_put___ns1__Hello(soap, &soap_tmp___ns1__Hello, "-ns1:Hello", NULL)
         || soap_body_end_out(soap)
         || soap_envelope_end_out(soap))
             return soap->error;
    }
    if (soap_end_count(soap))
        return soap->error;
    if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
     || soap_envelope_begin_out(soap)
     || soap_putheader(soap)
     || soap_body_begin_out(soap)
     || soap_put___ns1__Hello(soap, &soap_tmp___ns1__Hello, "-ns1:Hello", NULL)
     || soap_body_end_out(soap)
     || soap_envelope_end_out(soap)
     || soap_end_send(soap))
        return soap_closesock(soap);
    if (!ns1__HelloResponse)
        return soap_closesock(soap);
    ns1__HelloResponse->soap_default(soap);
    if (soap_begin_recv(soap)
     || soap_envelope_begin_in(soap)
     || soap_recv_header(soap)
     || soap_body_begin_in(soap))
        return soap_closesock(soap);
    ns1__HelloResponse->soap_get(soap, "ns1:HelloResponse", "");
    if (soap->error)
        return soap_recv_fault(soap, 0);
    if (soap_body_end_in(soap)
     || soap_envelope_end_in(soap)
     || soap_end_recv(soap))
        return soap_closesock(soap);
    return soap_closesock(soap);
}

int CustomBinding_DumpUploadService3_UploaderProxy::UploadMiniDump(const char *endpoint, const char *soap_action, _ns1__UploadMiniDump *ns1__UploadMiniDump, _ns1__UploadMiniDumpResponse *ns1__UploadMiniDumpResponse)
{   struct soap *soap = this;
    struct __ns1__UploadMiniDump soap_tmp___ns1__UploadMiniDump;
    if (endpoint)
        soap_endpoint = endpoint;
    if (soap_endpoint == NULL)
        soap_endpoint = "http://localhost:59175/Service/DumpUploader3.svc";
    if (soap_action == NULL)
        soap_action = "https://www.drdump.com/services/DumpUploadService3.Uploader/UploadMiniDump";
    soap_begin(soap);
    soap->encodingStyle = NULL;
    soap_tmp___ns1__UploadMiniDump.ns1__UploadMiniDump = ns1__UploadMiniDump;
    soap_set_version(soap, 2); /* SOAP1.2 */
    soap_serializeheader(soap);
    soap_serialize___ns1__UploadMiniDump(soap, &soap_tmp___ns1__UploadMiniDump);
    if (soap_begin_count(soap))
        return soap->error;
    if (soap->mode & SOAP_IO_LENGTH)
    {   if (soap_envelope_begin_out(soap)
         || soap_putheader(soap)
         || soap_body_begin_out(soap)
         || soap_put___ns1__UploadMiniDump(soap, &soap_tmp___ns1__UploadMiniDump, "-ns1:UploadMiniDump", NULL)
         || soap_body_end_out(soap)
         || soap_envelope_end_out(soap))
             return soap->error;
    }
    if (soap_end_count(soap))
        return soap->error;
    if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
     || soap_envelope_begin_out(soap)
     || soap_putheader(soap)
     || soap_body_begin_out(soap)
     || soap_put___ns1__UploadMiniDump(soap, &soap_tmp___ns1__UploadMiniDump, "-ns1:UploadMiniDump", NULL)
     || soap_body_end_out(soap)
     || soap_envelope_end_out(soap)
     || soap_end_send(soap))
        return soap_closesock(soap);
    if (!ns1__UploadMiniDumpResponse)
        return soap_closesock(soap);
    ns1__UploadMiniDumpResponse->soap_default(soap);
    if (soap_begin_recv(soap)
     || soap_envelope_begin_in(soap)
     || soap_recv_header(soap)
     || soap_body_begin_in(soap))
        return soap_closesock(soap);
    ns1__UploadMiniDumpResponse->soap_get(soap, "ns1:UploadMiniDumpResponse", "");
    if (soap->error)
        return soap_recv_fault(soap, 0);
    if (soap_body_end_in(soap)
     || soap_envelope_end_in(soap)
     || soap_end_recv(soap))
        return soap_closesock(soap);
    return soap_closesock(soap);
}

int CustomBinding_DumpUploadService3_UploaderProxy::UploadFullDump(const char *endpoint, const char *soap_action, _ns1__UploadFullDump *ns1__UploadFullDump, _ns1__UploadFullDumpResponse *ns1__UploadFullDumpResponse)
{   struct soap *soap = this;
    struct __ns1__UploadFullDump soap_tmp___ns1__UploadFullDump;
    if (endpoint)
        soap_endpoint = endpoint;
    if (soap_endpoint == NULL)
        soap_endpoint = "http://localhost:59175/Service/DumpUploader3.svc";
    if (soap_action == NULL)
        soap_action = "https://www.drdump.com/services/DumpUploadService3.Uploader/UploadFullDump";
    soap_begin(soap);
    soap->encodingStyle = NULL;
    soap_tmp___ns1__UploadFullDump.ns1__UploadFullDump = ns1__UploadFullDump;
    soap_set_version(soap, 2); /* SOAP1.2 */
    soap_serializeheader(soap);
    soap_serialize___ns1__UploadFullDump(soap, &soap_tmp___ns1__UploadFullDump);
    if (soap_begin_count(soap))
        return soap->error;
    if (soap->mode & SOAP_IO_LENGTH)
    {   if (soap_envelope_begin_out(soap)
         || soap_putheader(soap)
         || soap_body_begin_out(soap)
         || soap_put___ns1__UploadFullDump(soap, &soap_tmp___ns1__UploadFullDump, "-ns1:UploadFullDump", NULL)
         || soap_body_end_out(soap)
         || soap_envelope_end_out(soap))
             return soap->error;
    }
    if (soap_end_count(soap))
        return soap->error;
    if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
     || soap_envelope_begin_out(soap)
     || soap_putheader(soap)
     || soap_body_begin_out(soap)
     || soap_put___ns1__UploadFullDump(soap, &soap_tmp___ns1__UploadFullDump, "-ns1:UploadFullDump", NULL)
     || soap_body_end_out(soap)
     || soap_envelope_end_out(soap)
     || soap_end_send(soap))
        return soap_closesock(soap);
    if (!ns1__UploadFullDumpResponse)
        return soap_closesock(soap);
    ns1__UploadFullDumpResponse->soap_default(soap);
    if (soap_begin_recv(soap)
     || soap_envelope_begin_in(soap)
     || soap_recv_header(soap)
     || soap_body_begin_in(soap))
        return soap_closesock(soap);
    ns1__UploadFullDumpResponse->soap_get(soap, "ns1:UploadFullDumpResponse", "");
    if (soap->error)
        return soap_recv_fault(soap, 0);
    if (soap_body_end_in(soap)
     || soap_envelope_end_in(soap)
     || soap_end_recv(soap))
        return soap_closesock(soap);
    return soap_closesock(soap);
}

int CustomBinding_DumpUploadService3_UploaderProxy::UploadAdditionalInfo(const char *endpoint, const char *soap_action, _ns1__UploadAdditionalInfo *ns1__UploadAdditionalInfo, _ns1__UploadAdditionalInfoResponse *ns1__UploadAdditionalInfoResponse)
{   struct soap *soap = this;
    struct __ns1__UploadAdditionalInfo soap_tmp___ns1__UploadAdditionalInfo;
    if (endpoint)
        soap_endpoint = endpoint;
    if (soap_endpoint == NULL)
        soap_endpoint = "http://localhost:59175/Service/DumpUploader3.svc";
    if (soap_action == NULL)
        soap_action = "https://www.drdump.com/services/DumpUploadService3.Uploader/UploadAdditionalInfo";
    soap_begin(soap);
    soap->encodingStyle = NULL;
    soap_tmp___ns1__UploadAdditionalInfo.ns1__UploadAdditionalInfo = ns1__UploadAdditionalInfo;
    soap_set_version(soap, 2); /* SOAP1.2 */
    soap_serializeheader(soap);
    soap_serialize___ns1__UploadAdditionalInfo(soap, &soap_tmp___ns1__UploadAdditionalInfo);
    if (soap_begin_count(soap))
        return soap->error;
    if (soap->mode & SOAP_IO_LENGTH)
    {   if (soap_envelope_begin_out(soap)
         || soap_putheader(soap)
         || soap_body_begin_out(soap)
         || soap_put___ns1__UploadAdditionalInfo(soap, &soap_tmp___ns1__UploadAdditionalInfo, "-ns1:UploadAdditionalInfo", NULL)
         || soap_body_end_out(soap)
         || soap_envelope_end_out(soap))
             return soap->error;
    }
    if (soap_end_count(soap))
        return soap->error;
    if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
     || soap_envelope_begin_out(soap)
     || soap_putheader(soap)
     || soap_body_begin_out(soap)
     || soap_put___ns1__UploadAdditionalInfo(soap, &soap_tmp___ns1__UploadAdditionalInfo, "-ns1:UploadAdditionalInfo", NULL)
     || soap_body_end_out(soap)
     || soap_envelope_end_out(soap)
     || soap_end_send(soap))
        return soap_closesock(soap);
    if (!ns1__UploadAdditionalInfoResponse)
        return soap_closesock(soap);
    ns1__UploadAdditionalInfoResponse->soap_default(soap);
    if (soap_begin_recv(soap)
     || soap_envelope_begin_in(soap)
     || soap_recv_header(soap)
     || soap_body_begin_in(soap))
        return soap_closesock(soap);
    ns1__UploadAdditionalInfoResponse->soap_get(soap, "ns1:UploadAdditionalInfoResponse", "");
    if (soap->error)
        return soap_recv_fault(soap, 0);
    if (soap_body_end_in(soap)
     || soap_envelope_end_in(soap)
     || soap_end_recv(soap))
        return soap_closesock(soap);
    return soap_closesock(soap);
}

int CustomBinding_DumpUploadService3_UploaderProxy::RejectedToSendAdditionalInfo(const char *endpoint, const char *soap_action, _ns1__RejectedToSendAdditionalInfo *ns1__RejectedToSendAdditionalInfo, _ns1__RejectedToSendAdditionalInfoResponse *ns1__RejectedToSendAdditionalInfoResponse)
{   struct soap *soap = this;
    struct __ns1__RejectedToSendAdditionalInfo soap_tmp___ns1__RejectedToSendAdditionalInfo;
    if (endpoint)
        soap_endpoint = endpoint;
    if (soap_endpoint == NULL)
        soap_endpoint = "http://localhost:59175/Service/DumpUploader3.svc";
    if (soap_action == NULL)
        soap_action = "https://www.drdump.com/services/DumpUploadService3.Uploader/RejectedToSendAdditionalInfo";
    soap_begin(soap);
    soap->encodingStyle = NULL;
    soap_tmp___ns1__RejectedToSendAdditionalInfo.ns1__RejectedToSendAdditionalInfo = ns1__RejectedToSendAdditionalInfo;
    soap_set_version(soap, 2); /* SOAP1.2 */
    soap_serializeheader(soap);
    soap_serialize___ns1__RejectedToSendAdditionalInfo(soap, &soap_tmp___ns1__RejectedToSendAdditionalInfo);
    if (soap_begin_count(soap))
        return soap->error;
    if (soap->mode & SOAP_IO_LENGTH)
    {   if (soap_envelope_begin_out(soap)
         || soap_putheader(soap)
         || soap_body_begin_out(soap)
         || soap_put___ns1__RejectedToSendAdditionalInfo(soap, &soap_tmp___ns1__RejectedToSendAdditionalInfo, "-ns1:RejectedToSendAdditionalInfo", NULL)
         || soap_body_end_out(soap)
         || soap_envelope_end_out(soap))
             return soap->error;
    }
    if (soap_end_count(soap))
        return soap->error;
    if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
     || soap_envelope_begin_out(soap)
     || soap_putheader(soap)
     || soap_body_begin_out(soap)
     || soap_put___ns1__RejectedToSendAdditionalInfo(soap, &soap_tmp___ns1__RejectedToSendAdditionalInfo, "-ns1:RejectedToSendAdditionalInfo", NULL)
     || soap_body_end_out(soap)
     || soap_envelope_end_out(soap)
     || soap_end_send(soap))
        return soap_closesock(soap);
    if (!ns1__RejectedToSendAdditionalInfoResponse)
        return soap_closesock(soap);
    ns1__RejectedToSendAdditionalInfoResponse->soap_default(soap);
    if (soap_begin_recv(soap)
     || soap_envelope_begin_in(soap)
     || soap_recv_header(soap)
     || soap_body_begin_in(soap))
        return soap_closesock(soap);
    ns1__RejectedToSendAdditionalInfoResponse->soap_get(soap, "ns1:RejectedToSendAdditionalInfoResponse", "");
    if (soap->error)
        return soap_recv_fault(soap, 0);
    if (soap_body_end_in(soap)
     || soap_envelope_end_in(soap)
     || soap_end_recv(soap))
        return soap_closesock(soap);
    return soap_closesock(soap);
}

int CustomBinding_DumpUploadService3_UploaderProxy::UploadSymbol(const char *endpoint, const char *soap_action, _ns1__UploadSymbol *ns1__UploadSymbol, _ns1__UploadSymbolResponse *ns1__UploadSymbolResponse)
{   struct soap *soap = this;
    struct __ns1__UploadSymbol soap_tmp___ns1__UploadSymbol;
    if (endpoint)
        soap_endpoint = endpoint;
    if (soap_endpoint == NULL)
        soap_endpoint = "http://localhost:59175/Service/DumpUploader3.svc";
    if (soap_action == NULL)
        soap_action = "https://www.drdump.com/services/DumpUploadService3.Uploader/UploadSymbol";
    soap_begin(soap);
    soap->encodingStyle = NULL;
    soap_tmp___ns1__UploadSymbol.ns1__UploadSymbol = ns1__UploadSymbol;
    soap_set_version(soap, 2); /* SOAP1.2 */
    soap_serializeheader(soap);
    soap_serialize___ns1__UploadSymbol(soap, &soap_tmp___ns1__UploadSymbol);
    if (soap_begin_count(soap))
        return soap->error;
    if (soap->mode & SOAP_IO_LENGTH)
    {   if (soap_envelope_begin_out(soap)
         || soap_putheader(soap)
         || soap_body_begin_out(soap)
         || soap_put___ns1__UploadSymbol(soap, &soap_tmp___ns1__UploadSymbol, "-ns1:UploadSymbol", NULL)
         || soap_body_end_out(soap)
         || soap_envelope_end_out(soap))
             return soap->error;
    }
    if (soap_end_count(soap))
        return soap->error;
    if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
     || soap_envelope_begin_out(soap)
     || soap_putheader(soap)
     || soap_body_begin_out(soap)
     || soap_put___ns1__UploadSymbol(soap, &soap_tmp___ns1__UploadSymbol, "-ns1:UploadSymbol", NULL)
     || soap_body_end_out(soap)
     || soap_envelope_end_out(soap)
     || soap_end_send(soap))
        return soap_closesock(soap);
    if (!ns1__UploadSymbolResponse)
        return soap_closesock(soap);
    ns1__UploadSymbolResponse->soap_default(soap);
    if (soap_begin_recv(soap)
     || soap_envelope_begin_in(soap)
     || soap_recv_header(soap)
     || soap_body_begin_in(soap))
        return soap_closesock(soap);
    ns1__UploadSymbolResponse->soap_get(soap, "ns1:UploadSymbolResponse", "");
    if (soap->error)
        return soap_recv_fault(soap, 0);
    if (soap_body_end_in(soap)
     || soap_envelope_end_in(soap)
     || soap_end_recv(soap))
        return soap_closesock(soap);
    return soap_closesock(soap);
}
/* End of client proxy code */
