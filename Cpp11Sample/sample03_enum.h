//
//  sample03_enum.h
//  Cpp11Sample
//
//  Created by pebble8888 on 2015/09/21.
//  Copyright (c) 2015年 pebble8888. All rights reserved.
//

#ifndef __Cpp11Sample__sample03__
#define __Cpp11Sample__sample03__

#include <stdint.h>

class Food {
public:
    Food();
    enum Fruit: uint16_t {
        Apple,
        Orange,
        kNumOfFruit
    };
    static const char* fruitName(const enum Fruit fruit);
private:
    static const char* zm_fruit_name_[kNumOfFruit];
    
};

#endif /* defined(__Cpp11Sample__sample03__) */
