//
//  Breakpoint.h
//  Liberation
//
//  Created by satori
//  Copyright © 2016 satori. All rights reserved.
//

#pragma once

#include <mach/mach.h>
#include <functional>
#include <vector>

#include "process.h"
#include "thread_state.h"

using BreakpointCallback = std::function<void(ThreadState &)>;

class Breakpoint {
 public:
  Breakpoint(Process *proc, vm_address_t address)
  : address_(address), proc_(proc) {}
  virtual ~Breakpoint() {}

  virtual bool Apply() = 0;
  virtual bool Reset() = 0;

  void SetCallback(BreakpointCallback cb) { callback_ = cb; }

  bool active() const { return active_; }
  vm_address_t address() const { return address_; }
  BreakpointCallback callback() const { return callback_; }

 protected:
  bool active_;
  vm_address_t address_;
  Process *proc_;
  BreakpointCallback callback_;
};
