﻿// Copyright (c) 2016 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//

#ifndef CEF_INCLUDE_CAPI_CEF_GEOLOCATION_HANDLER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_GEOLOCATION_HANDLER_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"
#include "include/capi/cef_browser_capi.h"

#ifdef __cplusplus
extern "C" {
#endif


///
// Callback structure used for asynchronous continuation of geolocation
// permission requests.
///
typedef struct _cef_geolocation_callback_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Call to allow or deny geolocation access.
  ///
  void (CEF_CALLBACK *cont)(struct _cef_geolocation_callback_t* self,
      int allow);
} cef_geolocation_callback_t;


///
// Implement this structure to handle events related to geolocation permission
// requests. The functions of this structure will be called on the browser
// process UI thread.
///
typedef struct _cef_geolocation_handler_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Called when a page requests permission to access geolocation information.
  // |requesting_url| is the URL requesting permission and |request_id| is the
  // unique ID for the permission request. Return true (1) and call
  // cef_geolocation_callback_t::cont() either in this function or at a later
  // time to continue or cancel the request. Return false (0) to cancel the
  // request immediately.
  ///
  int (CEF_CALLBACK *on_request_geolocation_permission)(
      struct _cef_geolocation_handler_t* self, struct _cef_browser_t* browser,
      const cef_string_t* requesting_url, int request_id,
      struct _cef_geolocation_callback_t* callback);

  ///
  // Called when a geolocation access request is canceled. |request_id| is the
  // unique ID for the permission request.
  ///
  void (CEF_CALLBACK *on_cancel_geolocation_permission)(
      struct _cef_geolocation_handler_t* self, struct _cef_browser_t* browser,
      int request_id);
} cef_geolocation_handler_t;


#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_GEOLOCATION_HANDLER_CAPI_H_
