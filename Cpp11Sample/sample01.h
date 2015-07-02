//
//  sample01.h
//  Cpp11Sample
//
//  Created by pebble8888 on 2015/06/21.
//  Copyright (c) 2015年 pebble8888. All rights reserved.
//

#ifndef __Cpp11Sample__sample01__
#define __Cpp11Sample__sample01__

#include <stdio.h>

// 型のエイリアス
// C++11以前
//typedef int Output;
//typedef int Input;

// C++11
using Output = int;
using Input  = int;


Output fooSync(Input input);

#endif /* defined(__Cpp11Sample__sample01__) */
