/*
 *
 * (C) 2013-21 - ntop.org
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#ifndef _FLOW_CALLBACKS_EXECUTOR_H_
#define _FLOW_CALLBACKS_EXECUTOR_H_

#include "ntop_includes.h"

class FlowCallbacksExecutor { /* One instance per ntopng Interface */
 private:
  NetworkInterface *iface;
  list<FlowCallback*> list_protocol_detected, list_periodic_update, list_idle;
  static FlowLuaCallExecStatus listExecute(Flow *f, list<FlowCallback*> *l);

 public:
  FlowCallbacksExecutor(NetworkInterface *iface);
  virtual ~FlowCallbacksExecutor();

  void reloadFlowCallbacks();
  list<FlowCallback*> getFlowCallbacks(NetworkInterface *iface, FlowLuaCall flow_lua_call);
  FlowLuaCallExecStatus execute(Flow *f, FlowLuaCall flow_lua_call);
};

#endif /* _FLOW_CALLBACKS_EXECUTOR_H_ */