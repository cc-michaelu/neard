/*
 *
 *  Near Field Communication nfctool
 *
 *  Copyright (C) 2012  Intel Corporation. All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */
#ifndef __NETLINK_H
#define __NETLINK_H

typedef int (*nfc_event_cb_t)(guint8 cmd, guint32 adapter_idx);

struct nfc_adapter;

int nl_init(nfc_event_cb_t cb);

void nl_cleanup(void);

int nl_get_devices(void);

int nl_get_targets(struct nfc_adapter *adapter);

int nl_send_dep_link_up(guint32 idx, guint32 target_idx);

int nl_start_poll(struct nfc_adapter *adapter, guint8 mode);

int nl_set_params(struct nfc_adapter *adapter, gint32 lto, gint32 rw,
		  gint32 miux);

int nl_get_params(struct nfc_adapter *adapter);

#endif /* __NETLINK_H */