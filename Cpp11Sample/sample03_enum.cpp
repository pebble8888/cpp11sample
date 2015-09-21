//
//  sample03_enum.cpp
//  Cpp11Sample
//
//  Created by pebble8888 on 2015/09/21.
//  Copyright (c) 2015年 pebble8888. All rights reserved.
//

#include "sample03_enum.h"

const char* Food::zm_fruit_name_[Fruit::kNumOfFruit] = {
    "Apple",
    "Orange",
};

const char* Food::fruitName(const enum Fruit fruit)
{
    return zm_fruit_name_[fruit];
}

Food::Food()
{
}

