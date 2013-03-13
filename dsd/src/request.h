/*
 * Dynamic Network Directory Service
 * Copyright (C) 2010-2012 Nicolas Bouliane
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 */

#ifndef DSD_REQUEST_H
#define DSD_REQUEST_H

#include <dnds.h>
#include "dsd.h"

void authRequest(struct session *session, DNDSMessage_t *msg);
void addRequest(struct session *session, DNDSMessage_t *msg);
void delRequest(struct session *session, DNDSMessage_t *msg);
void modifyRequest(struct session *session, DNDSMessage_t *msg);
void searchRequest(struct session *session, DNDSMessage_t *msg);
void peerConnectInfo(struct session *session, DNDSMessage_t *req_msg);

#endif

