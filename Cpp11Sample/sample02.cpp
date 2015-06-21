//
//  sample02.cpp
//  Cpp11Sample
//
//  Created by pebble8888 on 2015/06/21.
//  Copyright (c) 2015年 pebble8888. All rights reserved.
//

#include "sample02.h"

#include <folly/futures/Future.h>
using folly::Future;

// Do foo asynchronously; immediately return a Future for the output
Future<Output> fooFuture(Input);

Future<Output> f = fooFuture(input);
// f may not have a value (or exception) yet. But eventually it will.
f.isReady();  // Maybe, maybe not.
f.wait();     // You can synchronously wait for futures to become ready.
f.isReady();  // Now this is guaranteed to be true.
Output o = f.value();  // If f holds an exception, this will throw that exception.