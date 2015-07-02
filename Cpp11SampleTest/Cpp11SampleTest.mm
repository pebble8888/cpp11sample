//
//  Cpp11SampleTest.m
//  Cpp11SampleTest
//
//  Created by pebble8888 on 2015/06/23.
//  Copyright © 2015年 pebble8888. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "sample01.h"
#include "Sample02.h"

@interface Cpp11SampleTest : XCTestCase

@end

@implementation Cpp11SampleTest

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    
    fooSync( 1 );
    [Something somthing];
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
