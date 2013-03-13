#ifndef DNDS_PROTOCOL_H
#define DNDS_PROTOCOL_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <netinet/if_ether.h>

#include "DNDSMessage.h"

#ifndef ETHER_ADDR_LEN
#define ETHER_ADDR_LEN	6
#endif

#ifndef INET_ADDRSTRLEN
#define INET_ADDRSTRLEN 16
#endif

typedef enum DNDS_retcode {

	DNDS_success = 0,
	DNDS_alloc_failed,
	DNDS_invalid_param,
	DNDS_invalid_pdu,
	DNDS_invalid_op,
	DNDS_invalid_object_type,
	DNDS_value_not_present,
	DNDS_conversion_failed

} DNDS_retcode_t;

// DNDS API functions
char *DNDSResult_str(e_DNDSResult result);
char *DNDS_strerror(DNDS_retcode_t retcode);

// DNDSMessage
int DNDSMessage_new(DNDSMessage_t **msg);
int DNDSMessage_del(DNDSMessage_t *msg);
int DNDSMessage_set_channel(DNDSMessage_t *msg, uint8_t channel);
int DNDSMessage_get_channel(DNDSMessage_t *msg, uint8_t *channel);
int DNDSMessage_set_pdu(DNDSMessage_t *msg, pdu_PR pdu);
int DNDSMessage_get_pdu(DNDSMessage_t *msg, pdu_PR *pdu);

// ethernet
int DNDSMessage_set_ethernet(DNDSMessage_t *msg, uint8_t *frame, size_t length);
int DNDSMessage_get_ethernet(DNDSMessage_t *msg, uint8_t **frame, size_t *length);

// DNMessage
int DNMessage_set_seqNumber(DNDSMessage_t *msg, uint32_t seqNumber);
int DNMessage_get_seqNumber(DNDSMessage_t *msg, uint32_t *seqNumber);
int DNMessage_set_ackNumber(DNDSMessage_t *msg, uint32_t ackNumber);
int DNMessage_get_ackNumber(DNDSMessage_t *msg, uint32_t *ackNumber);
int DNMessage_set_operation(DNDSMessage_t *msg, dnop_PR operation);
int DNMessage_get_operation(DNDSMessage_t *msg, dnop_PR *operation);

// DSMessage
int DSMessage_set_seqNumber(DNDSMessage_t *msg, uint32_t sequenceNumber);
int DSMessage_get_seqNumber(DNDSMessage_t *msg, uint32_t *sequenceNumber);
int DSMessage_set_ackNumber(DNDSMessage_t *msg, uint32_t ackNumber);
int DSMessage_get_ackNumber(DNDSMessage_t *msg, uint32_t *ackNumber);
int DSMessage_set_operation(DNDSMessage_t *msg, dsop_PR operation);
int DSMessage_get_operation(DNDSMessage_t *msg, dsop_PR *operation);

// DNDSObject
int DNDSObject_set_objectType(DNDSObject_t *object, DNDSObject_PR type);
int DNDSObject_get_objectType(DNDSObject_t *object, DNDSObject_PR *type);

// ContextInfo

int ContextInfo_set_id(DNDSMessage_t *msg, uint32_t id);
int ContextInfo_get_id(DNDSMessage_t *msg, uint32_t *id);
int ContextInfo_set_topology(DNDSMessage_t *msg, e_Topology topology);
int ContextInfo_get_topology(DNDSMessage_t *msg, e_Topology *topology);
int ContextInfo_set_description(DNDSMessage_t *msg, const char *description, size_t length);
int ContextInfo_get_description(DNDSMessage_t *msg, char **description, size_t *length);
int ContextInfo_set_network(DNDSMessage_t *msg, char *network);
int ContextInfo_get_network(DNDSMessage_t *msg, char *network);
int ContextInfo_set_netmask(DNDSMessage_t *msg, char *netmask);
int ContextInfo_get_netmask(DNDSMessage_t *msg, char *netmask);
int ContextInfo_set_serverCert(DNDSMessage_t *msg, const char *serverCert, size_t length);
int ContextInfo_get_serverCert(DNDSMessage_t *msg, char **serverCert, size_t *length);
int ContextInfo_set_serverPrivkey(DNDSMessage_t *msg, const char *serverPrivkey, size_t length);
int ContextInfo_get_serverPrivkey(DNDSMessage_t *msg, char **serverPrivkey, size_t *length);
int ContextInfo_set_trustedCert(DNDSMessage_t *msg, const char *trustedCert, size_t length);
int ContextInfo_get_trustedCert(DNDSMessage_t *msg, char **trustedCert, size_t *length);

// PeerConnectInfo
int PeerConnectInfo_set_certName(DNDSMessage_t *msg, char *name, size_t length);
int PeerConnectInfo_get_certName(DNDSMessage_t *msg, char **name, size_t *length);
int PeerConnectInfo_set_ipAddr(DNDSMessage_t *msg, char *ipAddress);
int PeerConnectInfo_get_ipAddr(DNDSMessage_t *msg, char *ipAddress);
int PeerConnectInfo_set_state(DNDSMessage_t *msg, e_ConnectState state);
int PeerConnectInfo_get_state(DNDSMessage_t *msg, e_ConnectState *state);

// AddRequest
int AddRequest_set_objectType(DNDSMessage_t *msg, DNDSObject_PR objType, DNDSObject_t **object);
int AddRequest_get_objectType(DNDSMessage_t *msg, DNDSObject_PR *objType);
int AddRequest_get_object(DNDSMessage_t *msg, DNDSObject_t **object);

// AddResponse
int AddResponse_set_result(DNDSMessage_t *msg, e_DNDSResult result);
int AddResponse_get_result(DNDSMessage_t *msg, e_DNDSResult *result);

// AuthRequest
int AuthRequest_set_certName(DNDSMessage_t *msg, char *certName, size_t length);
int AuthRequest_get_certName(DNDSMessage_t *msg, char **certName, size_t *length);

// AuthResponse
int AuthResponse_set_result(DNDSMessage_t *msg, e_DNDSResult result);
int AuthResponse_get_result(DNDSMessage_t *msg, e_DNDSResult *result);

// DelRequest
int DelRequest_set_objectType(DNDSMessage_t *msg, DNDSObject_PR objType, DNDSObject_t **object);
int DelRequest_get_objectType(DNDSMessage_t *msg, DNDSObject_PR *objType);
int DelRequest_get_object(DNDSMessage_t *msg, DNDSObject_t **object);

// DelResponse
int DelResponse_set_result(DNDSMessage_t *msg, e_DNDSResult result);
int DelResponse_get_result(DNDSMessage_t *msg, e_DNDSResult *result);

// ModifyRequest
int ModifyRequest_set_objectType(DNDSMessage_t *msg, DNDSObject_PR objType, DNDSObject_t **object);
int ModifyRequest_get_objectType(DNDSMessage_t *msg, DNDSObject_PR *objType);
int ModifyRequest_get_object(DNDSMessage_t *msg, DNDSObject_t **object);

// ModifyResponse
int ModifyResponse_set_result(DNDSMessage_t *msg, e_DNDSResult result);
int ModifyResponse_get_result(DNDSMessage_t *msg, e_DNDSResult *result);

// NetinfoRequest
int NetinfoRequest_set_ipLocal(DNDSMessage_t *msg, char *ipLocal);
int NetinfoRequest_get_ipLocal(DNDSMessage_t *msg, char *ipLocal);
int NetinfoRequest_set_macAddr(DNDSMessage_t *msg, uint8_t *macAddr);
int NetinfoRequest_get_macAddr(DNDSMessage_t *msg, uint8_t *macAddr);

// NetinfoResponse
int NetinfoResponse_set_ipAddress(DNDSMessage_t *msg, char *ipAddress);
int NetinfoResponse_get_ipAddress(DNDSMessage_t *msg, char *ipAddress);
int NetinfoResponse_set_netmask(DNDSMessage_t *msg, char *netmask);
int NetinfoResponse_get_netmask(DNDSMessage_t *msg, char *netmask);
int NetinfoResponse_set_result(DNDSMessage_t *msg, e_DNDSResult result);
int NetinfoResponse_get_result(DNDSMessage_t *msg, e_DNDSResult *result);

// P2pRequest
int P2pRequest_set_macAddrDst(DNDSMessage_t *msg, uint8_t *macAddrDst);
int P2pRequest_get_macAddrDst(DNDSMessage_t *msg, uint8_t *macAddrDst);
int P2pRequest_set_ipAddrDst(DNDSMessage_t *msg, char *ipAddrDst);
int P2pRequest_get_ipAddrDst(DNDSMessage_t *msg, char *ipAddrDst);
int P2pRequest_set_port(DNDSMessage_t *msg, uint32_t port);
int P2pRequest_get_port(DNDSMessage_t *msg, uint32_t *port);
int P2pRequest_set_side(DNDSMessage_t *msg, e_P2pSide side);
int P2pRequest_get_side(DNDSMessage_t *msg, e_P2pSide *side);

// P2pResponse
int P2pResponse_set_macAddrDst(DNDSMessage_t *msg, uint8_t *macAddrDst);
int P2pResponse_get_macAddrDst(DNDSMessage_t *msg, uint8_t *macAddrDst);
int P2pResponse_set_ipAddrDst(DNDSMessage_t *msg, char *ipAddrDst);
int P2pResponse_get_ipAddrDst(DNDSMessage_t *msg, char *ipAddrDst);
int P2pResponse_set_port(DNDSMessage_t *msg, uint32_t port);
int P2pResponse_get_port(DNDSMessage_t *msg, uint32_t *port);
int P2pRequest_set_side(DNDSMessage_t *msg, e_P2pSide side);
int P2pRequest_get_side(DNDSMessage_t *msg, e_P2pSide *side);
int P2pResponse_set_result(DNDSMessage_t *msg, e_DNDSResult result);
int P2pResponse_get_result(DNDSMessage_t *msg, e_DNDSResult *result);

// SearchRequest
int SearchRequest_set_searchType(DNDSMessage_t *msg, e_SearchType SearchType);
int SearchRequest_get_searchType(DNDSMessage_t *msg, e_SearchType *SearchType);
int SearchRequest_set_objectName(DNDSMessage_t *msg, e_ObjectName ObjectName);
int SearchRequest_get_objectName(DNDSMessage_t *msg, e_ObjectName *ObjectName);
int SearchRequest_set_object(DNDSMessage_t *msg, DNDSObject_t *object);
int SearchRequest_get_object(DNDSMessage_t *msg, DNDSObject_t **object);

// SearchResponse
int SearchResponse_set_result(DNDSMessage_t *msg, e_DNDSResult result);
int SearchResponse_get_result(DNDSMessage_t *msg, e_DNDSResult *result);
int SearchResponse_add_object(DNDSMessage_t *msg, DNDSObject_t *object);
int SearchResponse_get_object(DNDSMessage_t *msg, DNDSObject_t **object);
int SearchResponse_get_object_count(DNDSMessage_t *msg, uint32_t *count);

// terminateRequest -- need nothing

// DNDS Objects
int DNDSObject_new(DNDSObject_t **object);

// Acl
int Acl_set_id(DNDSObject_t *AclObject, uint32_t id);
int Acl_get_id(DNDSObject_t *AclObject, uint32_t *id);
int Acl_set_contextId(DNDSObject_t *AclObject, uint32_t contextId);
int Acl_get_contextId(DNDSObject_t *AclObject, uint32_t *contextId);
int Acl_set_description(DNDSObject_t *AclObject, char *description, size_t length);
int Acl_get_description(DNDSObject_t *AclObject, char **description, size_t *length);

// AclGroup
int AclGroup_set_id(DNDSObject_t *AclGroupObject, uint32_t id);
int AclGroup_get_id(DNDSObject_t *AclGroupObject, uint32_t *id);
int AclGroup_set_contextId(DNDSObject_t *AclGroupObject, uint32_t contextId);
int AclGroup_get_contextId(DNDSObject_t *AclGroupObject, uint32_t *contextId);
int AclGroup_set_name(DNDSObject_t *AclGroupObject, char *name, size_t length);
int AclGroup_get_name(DNDSObject_t *AclGroupObject, char **name, size_t *length);
int AclGroup_set_description(DNDSObject_t *AclGroupObject, char *description, size_t length);
int AclGroup_get_description(DNDSObject_t *AclGroupObject, char **description, size_t *length);

// IpPool
int IpPool_set_id(DNDSObject_t *IpPoolObject, uint32_t id);
int IpPool_get_id(DNDSObject_t *IpPoolObject, uint32_t *id);
int IpPool_set_ipLocal(DNDSObject_t *IpPoolObject, char *ipLocal);
int IpPool_get_ipLocal(DNDSObject_t *IpPoolObject, char *ipLocal);
int IpPool_set_ipBegin(DNDSObject_t *IpPoolObject, char *ipBegin);
int IpPool_get_ipBegin(DNDSObject_t *IpPoolObject, char *ipBegin);
int IpPool_set_ipEnd(DNDSObject_t *IpPoolObject, char *ipEnd);
int IpPool_get_ipEnd(DNDSObject_t *IpPoolObject, char *ipEnd);
int IpPool_set_netmask(DNDSObject_t *IpPoolObject, char *netmask);
int IpPool_get_netmask(DNDSObject_t *IpPoolObject, char *netmask);

// Context

int Context_set_id(DNDSObject_t *object, uint32_t id);
int Context_get_id(DNDSObject_t *object, uint32_t *id);
int Context_set_clientId(DNDSObject_t *object, uint32_t clientId);
int Context_get_clientId(DNDSObject_t *object, uint32_t *clientId);
int Context_set_topology(DNDSObject_t *object, e_Topology topology);
int Context_get_topology(DNDSObject_t *object, e_Topology *topology);
int Context_set_description(DNDSObject_t *object, char *description, size_t length);
int Context_get_description(DNDSObject_t *object, char **description, size_t *length);
int Context_set_network(DNDSObject_t *object, char *network);
int Context_get_network(DNDSObject_t *object, char *network);
int Context_set_netmask(DNDSObject_t *object, char *netmask);
int Context_get_netmask(DNDSObject_t *object, char *netmask);
int Context_set_serverCert(DNDSObject_t *object, char *serverCert, size_t length);
int Context_get_serverCert(DNDSObject_t *object, char **serverCert, size_t *length);
int Context_set_serverPrivkey(DNDSObject_t *object, char *serverPrivkey, size_t length);
int Context_get_serverPrivkey(DNDSObject_t *object, char **serverPrivkey, size_t *length);
int Context_set_trustedCert(DNDSObject_t *object, char *trustedCert, size_t length);
int Context_get_trustedCert(DNDSObject_t *object, char **trustedCert, size_t *length);

// WebCredential
int WebCredential_set_clientId(DNDSObject_t *object, uint32_t id);
int WebCredential_get_clientId(DNDSObject_t *object, uint32_t *id);
int WebCredential_set_username(DNDSObject_t *object, char *username, size_t length);
int WebCredential_get_username(DNDSObject_t *object, char **username, size_t *length);
int WebCredential_set_password(DNDSObject_t *object, char *password, size_t length);
int WebCredential_get_password(DNDSObject_t *object, char **password, size_t *length);

// Host
int Host_set_id(DNDSObject_t *HostObject, uint32_t id);
int Host_get_id(DNDSObject_t *HostObject, uint32_t *id);
int Host_set_contextId(DNDSObject_t *HostObject, uint32_t contextId);
int Host_get_contextId(DNDSObject_t *HostObject, uint32_t *contextId);
int Host_set_peerId(DNDSObject_t *HostObject, uint32_t peerId);
int Host_get_peerId(DNDSObject_t *HostObject, uint32_t *peerId);
int Host_set_name(DNDSObject_t *HostObject, char *name, size_t length);
int Host_get_name(DNDSObject_t *HostObject, char **name, size_t *length);
int Host_set_macAddress(DNDSObject_t *HostObject, uint8_t *macAddress);
int Host_get_macAddress(DNDSObject_t *HostObject, uint8_t *macAddress);
int Host_set_ipAddress(DNDSObject_t *HostObject, char *ipAddress);
int Host_get_ipAddress(DNDSObject_t *HostObject, char *ipAddress);
int Host_set_status(DNDSObject_t *HostObject, uint8_t status);
int Host_get_status(DNDSObject_t *HostObject, uint8_t *status);

// Node
int Node_set_id(DNDSObject_t *NodeObject, uint32_t id);
int Node_get_id(DNDSObject_t *NodeObject, uint32_t *id);
int Node_set_name(DNDSObject_t *NodeObject, char *name, size_t length);
int Node_get_name(DNDSObject_t *NodeObject, char **name, size_t *length);
int Node_set_certificate(DNDSObject_t *NodeObject, char *certificate, size_t length);
int Node_get_certificate(DNDSObject_t *NodeObject, char **certificate, size_t *length);
int Node_set_certificateKey(DNDSObject_t *NodeObject, uint8_t *certificateKey, size_t length);
int Node_get_certificateKey(DNDSObject_t *NodeObject, uint8_t **certificateKey, size_t *length);
int Node_set_ipAddress(DNDSObject_t *NodeObject, char *ipAddress);
int Node_get_ipAddress(DNDSObject_t *NodeObject, char *ipAddress);
int Node_set_status(DNDSObject_t *NodeObject, uint8_t status);
int Node_get_status(DNDSObject_t *NodeObject, uint8_t *status);

// Permission
int Permission_set_id();
int Permission_set_name();
int Permission_set_matrix();

// Peer
int Peer_set_contextId(DNDSObject_t *PeerObject, uint32_t contextId);
int Peer_get_contextId(DNDSObject_t *PeerObject, uint32_t *contextId);
int Peer_set_description(DNDSObject_t *object, char *description, size_t length);
int Peer_get_description(DNDSObject_t *object, char **description, size_t *length);
int Peer_set_certificate(DNDSObject_t *PeerObject, char *certificate, size_t length);
int Peer_get_certificate(DNDSObject_t *PeerObject, char **certificate, size_t *length);
int Peer_set_certificateKey(DNDSObject_t *PeerObject, uint8_t *certificateKey, size_t length);
int Peer_get_certificateKey(DNDSObject_t *PeerObject, uint8_t **certificateKey, size_t *length);
int Peer_set_status(DNDSObject_t *PeerObject, uint8_t status);
int Peer_get_status(DNDSObject_t *PeerObject, uint8_t *status);

// User
int User_set_id(DNDSObject_t *UserObject, uint32_t id);
int User_get_id(DNDSObject_t *UserObject, uint32_t *id);
int User_set_contextId(DNDSObject_t *UserObject, uint32_t contextId);
int User_get_contextId(DNDSObject_t *UserObject, uint32_t *contextId);
int User_set_name(DNDSObject_t *UserObject, char *name, size_t length);
int User_get_name(DNDSObject_t *UserObject, char **name, size_t *length);
int User_set_password(DNDSObject_t *UserObject, char *password, size_t length);
int User_get_password(DNDSObject_t *UserObject, char **password, size_t *length);
int User_set_firstname(DNDSObject_t *UserObject, char *firstname, size_t length);
int User_get_firstname(DNDSObject_t *UserObject, char **firstname, size_t *length);
int User_set_lastname(DNDSObject_t *UserObject, char *lastname, size_t length);
int User_get_lastname(DNDSObject_t *UserObject, char **lastname, size_t *length);
int User_set_email(DNDSObject_t *UserObject, char *email, size_t length);
int User_get_email(DNDSObject_t *UserObject, char **email, size_t *length);
int User_set_role(DNDSObject_t *UserObject, uint8_t role);
int User_get_role(DNDSObject_t *UserObject, uint8_t *role);
int User_set_status(DNDSObject_t *UserObject, uint8_t status);
int User_get_status(DNDSObject_t *UserObject, uint8_t *status);

// _printf functions usefull for debugging
void DNDSMessage_printf(DNDSMessage_t *msg);
void DNDSMessage_ethernet_printf(DNDSMessage_t *msg);
void DSMessage_printf(DNDSMessage_t *msg);
void DNMessage_printf(DNDSMessage_t *msg);
void PeerConnectInfo_printf(DNDSMessage_t *msg);
void AddRequest_printf(DNDSMessage_t *msg);
void AddResponse_printf(DNDSMessage_t *msg);
void P2pRequest_printf(DNDSMessage_t *msg);
void P2pResponse_printf(DNDSMessage_t *msg);
void AuthRequest_printf(DNDSMessage_t *msg);
void AuthResponse_printf(DNDSMessage_t *msg);
void DelRequest_printf(DNDSMessage_t *msg);
void DelResponse_printf(DNDSMessage_t *msg);
void ModifyRequest_printf(DNDSMessage_t *msg);
void ModifyResponse_printf(DNDSMessage_t *msg);
void ModifyReponse_printf(DNDSMessage_t *msg);
void NetinfoRequest_printf(DNDSMessage_t *msg);
void NetinfoResponse_printf(DNDSMessage_t *msg);
void SearchRequest_printf(DNDSMessage_t *msg);
void SearchResponse_printf(DNDSMessage_t *msg);
void Acl_printf(DNDSObject_t *object);
void AclGroup_printf(DNDSObject_t *object);
void IpPool_printf(DNDSObject_t *object);
void Context_printf(DNDSObject_t *object);
void Host_printf(DNDSObject_t *object);
void Node_printf(DNDSObject_t *object);
void Peer_printf(DNDSObject_t *object);
void Permission_printf(DNDSObject_t *object);
void User_printf(DNDSObject_t *object);
void DNDSObject_printf(DNDSObject_t *obj);

#endif /* DNDS_PROTOCOL_H */
