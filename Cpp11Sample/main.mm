//
//  main.m
//  Cpp11Sample
//
//  Created by pebble8888 on 2015/06/21.
//  Copyright (c) 2015年 pebble8888. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "sample03_enum.h"
#import "Watch.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        auto apple = Food::Fruit::Apple;
        Food food;
        NSLog(@"%s", food.fruitName(apple));
        
        Watch watch1;
        //Watch watch("aaa"); // compile error for delete
    }
    return 0;
}
