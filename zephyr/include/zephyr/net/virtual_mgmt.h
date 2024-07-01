/*
 * Copyright (c) 2021 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Virtual Interface Management interface public header
 */

#ifndef ZEPHYR_INCLUDE_NET_VIRTUAL_MGMT_H_
#define ZEPHYR_INCLUDE_NET_VIRTUAL_MGMT_H_

#include <zephyr/net/virtual.h>
#include <zephyr/net/net_mgmt.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Virtual interface library
 * @defgroup virtual_mgmt Virtual Interface Library
 * @ingroup networking
 * @{
 */

/** @cond INTERNAL_HIDDEN */

#define _NET_VIRTUAL_INTERFACE_LAYER	NET_MGMT_LAYER_L2
#define _NET_VIRTUAL_INTERFACE_CODE	0x209
#define _NET_VIRTUAL_INTERFACE_BASE					\
	(NET_MGMT_IFACE_BIT |						\
	 NET_MGMT_LAYER(_NET_VIRTUAL_INTERFACE_LAYER) |			\
	 NET_MGMT_LAYER_CODE(_NET_VIRTUAL_INTERFACE_CODE))
#define _NET_VIRTUAL_INTERFACE_EVENT					\
	(_NET_VIRTUAL_INTERFACE_BASE | NET_MGMT_EVENT_BIT)

struct virtual_interface_req_params {
	sa_family_t family;
	union {
		struct in_addr peer4addr;
		struct in6_addr peer6addr;
		int mtu;
	};
};

enum net_request_virtual_interface_cmd {
	NET_REQUEST_VIRTUAL_INTERFACE_CMD_SET_PEER_ADDR = 1,
	NET_REQUEST_VIRTUAL_INTERFACE_CMD_GET_PEER_ADDR,
	NET_REQUEST_VIRTUAL_INTERFACE_CMD_SET_MTU,
	NET_REQUEST_VIRTUAL_INTERFACE_CMD_GET_MTU,
};

#define NET_REQUEST_VIRTUAL_INTERFACE_SET_PEER_ADDRESS		\
	(_NET_VIRTUAL_INTERFACE_BASE |				\
	 NET_REQUEST_VIRTUAL_INTERFACE_CMD_SET_PEER_ADDR)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_VIRTUAL_INTERFACE_SET_PEER_ADDRESS);

#define NET_REQUEST_VIRTUAL_INTERFACE_SET_MTU		\
	(_NET_VIRTUAL_INTERFACE_BASE |			\
	 NET_REQUEST_VIRTUAL_INTERFACE_CMD_SET_MTU)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_VIRTUAL_INTERFACE_SET_MTU);

#define NET_REQUEST_VIRTUAL_INTERFACE_GET_PEER_ADDRESS		\
	(_NET_VIRTUAL_INTERFACE_BASE |				\
	 NET_REQUEST_VIRTUAL_INTERFACE_CMD_GET_PEER_ADDR)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_VIRTUAL_INTERFACE_GET_PEER_ADDRESS);

#define NET_REQUEST_VIRTUAL_INTERFACE_GET_MTU		\
	(_NET_VIRTUAL_INTERFACE_BASE |			\
	 NET_REQUEST_VIRTUAL_INTERFACE_CMD_GET_MTU)

NET_MGMT_DEFINE_REQUEST_HANDLER(NET_REQUEST_VIRTUAL_INTERFACE_GET_MTU);

struct net_if;

/** @endcond */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_NET_VIRTUAL_MGMT_H_ */
