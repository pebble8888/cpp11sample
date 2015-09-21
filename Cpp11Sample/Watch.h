//
//  Watch.h
//  Cpp11Sample
//
//  Created by pebble8888 on 2015/09/21.
//  Copyright (c) 2015年 pebble8888. All rights reserved.
//

#ifndef __Cpp11Sample__Watch__
#define __Cpp11Sample__Watch__

#include <string>

class Watch {
public:
    Watch();
    Watch(const Watch& ) = delete;
    Watch& operator=(const Watch&) = delete;
private:
    std::string model_;
};

#endif /* defined(__Cpp11Sample__Watch__) */
