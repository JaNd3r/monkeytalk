//
//  MTRESTServiceMapping.h
//  iWebDriver
//
//  Copyright 2009 Google Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#import <Foundation/Foundation.h>
#import <CFNetwork/CFNetwork.h>
#import "MTHTTPResponse.h"

@class MTVirtualDirectory;

// |MTRESTServiceMapping| stores the tree of virtual directories. When the HTTP
// server recieves an http request, the request is forwarded through
// |MTHTTPServerController| to |MTRESTServiceMapping| which in turn delegates it to
// the appropriate |MTHTTPResource|.
@interface MTRESTServiceMapping : NSObject {
  // Stores the root directory of the HTTP server
  MTVirtualDirectory *serverRoot_;
}

@property (nonatomic, copy) MTVirtualDirectory *serverRoot;

- (NSObject<MTHTTPResponse> *)httpResponseForRequest:(CFHTTPMessageRef)request;
+ (void)propertiesOfHTTPMessage:(CFHTTPMessageRef)request
                        toQuery:(NSString **)query
                         method:(NSString **)method
                           data:(NSData **)data;

@end
