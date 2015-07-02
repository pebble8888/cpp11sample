//
//  main.cpp
//  cppsample_move
//
//  Created by pebble8888 on 2015/07/02.
//  Copyright (c) 2015年 pebble8888. All rights reserved.
//

#include <utility> // move()
#include <vector>
using namespace std;

/**
 *
 */

struct JOB {
    int reward;
};

vector<JOB> get_job(void)
{
    vector<JOB> v_job;
    for( int i = 0; i < 10; ++i ){
        JOB job;
        job.reward = i;
        v_job.push_back( job );
    }
    return v_job;
}

int main(int argc, const char * argv[])
{
    {
        // vector全体の所有権を移動
        vector<JOB> v1 = get_job();
        printf( "v1.size()[%ld]\n", v1.size() );    // v1.size()[10]
        vector<JOB> v2 = move(v1);
        printf( "v1.size()[%ld]\n", v1.size() );    // v1.size()[0]
        printf( "v2.size()[%ld]\n", v2.size() );    // v2.size()[10]
    }
    {
        // vectorのfront()一つの所有権を移動
        vector<JOB> v1 = get_job();
        printf( "v1.size()[%ld]\n", v1.size() );    // v1.size()[10]
        JOB job_1 = move(v1.front());
        printf( "v1.size()[%ld]\n", v1.size() );    // v1.size()[10]
    }
    return 0;
}
