/*
 * NetVirt - Network Virtualization Platform
 * Copyright (C) 2009-2016
 * Nicolas J. Bouliane <admin@netvirt.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation; version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details
 */

#ifndef DAO_H
#define DAO_H

#include "ctrler.h"

int dao_connect(struct ctrler_cfg *ctrler_cfg);
void dao_disconnect();

int dao_update_node_status(char *context, char *uuid, char *status, char *public_ip);
int dao_add_vnetwork(char **network_uuid, char *client_id,
			char *description,
			char *network,
			char *embassy_certificate,
			char *embassy_privatekey,
			char *embassy_serial,
			char *passport_certificate,
			char *passport_privatekey,
			const unsigned char *ippool,
			size_t pool_size);

int dao_del_context(char *client_id, char *context_id);

int dao_update_client_apikey(char *apikey, char *new_apikey);
int dao_activate_client(char *apikey);
int dao_set_password(char *email, char *resetkey, char *password);
int dao_set_resetkey(char *email, char *resetkey);
int dao_add_client(char *email, char *password, char *apikey);
int dao_fetch_account_apikey(char **apikey, char *email, char *password);
int dao_fetch_client_id_by_apikey(char **client_id, char *apikey);

int dao_fetch_network_by_client_id_desc(char *client_id, char *description,
					void *data, int (*cb_data_handler)(void *data,
					char *id,
					char *description,
					char *client_id,
					char *network,
					char *netmask,
					char *serverCert,
					char *serverPrivkey,
					char *trustedCert));

int dao_fetch_context_ippool(char *, unsigned char **);
int dao_fetch_network_id(char **context_id, char *client_id, char *description);
int dao_fetch_context_embassy(char *uuid,
			char **certificate,
			char **privatekey,
			char **serial,
			unsigned char **ippool);


int dao_update_embassy_serial(char *, char *);

int dao_del_node(char *context_id, char *uuid);
int dao_del_node_by_context_id(char *context_id);

int dao_add_node(char *context_id, char *uuid, char *certificate, char *privatekey, char *provcode, char *description, char *ipaddress);

int dao_update_context_ippool(char *context_id, unsigned char *ippool, int pool_size);

int dao_fetch_client_id(char **client_id, char *email, char *password);

int dao_fetch_networks_by_client_id(
	char *client_id,
	void *data,
	int (*cb_data_handler)(void *data,
		char *description, char *uuid));

int dao_fetch_context(void *data, int (*cb_data_handler)(void *data, int remaining,
							char *id,
							char *uuid,
							char *description,
							char *client_id,
							char *network,
							char *netmask,
							char *serverCert,
							char *serverPrivkey,
							char *trustedCert));


void dao_reset_node_state();
int dao_fetch_node_sequence(uint32_t *context_id_list, uint32_t list_size, void *data, void (*cb_data_handler)(void *data, int remaining,
								char *uuid, char *contextId));
int dao_fetch_node_uuid_networkuuid(void *arg, int (*cb_data_handler)(void *, int, char *, char *));

int dao_fetch_node_ip(char *, char *, char **);

int dao_fetch_node_from_context_id(char *context_id, void *data, int (*cb_data_handler)(void *data,
								char *uuid,
								char *description,
								char *provcode,
								char *ipaddress,
								char *status));
int dao_fetch_node_from_provcode(char *provcode,
					char **certificate,
					char **private_key,
					char **trustedcert,
					char **ipAddress);
char *uuid_v4(void);
#endif
