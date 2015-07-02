//
//  sample01.cpp
//  Cpp11Sample
//
//  Created by pebble8888 on 2015/06/21.
//  Copyright (c) 2015年 pebble8888. All rights reserved.
//

#include "sample01.h"

// std::function
// C++11以前では関数ポインタ
// std::functionの方が関数ポインタの宣言よりソースが読みやすい。
#include <functional>
// Tを引数とし戻り値がvoidの関数
template <typename T> using Callback = std::function<void(T)>;

Output fooSync(Input input)
{
    return input * 10;
}

/**
 * @brief inputを入力データとし、処理結果を引数としてcallback関数を呼び出す
 */
void fooAsync(Input input, Callback<Output> callback)
{
    // something long process
    Output output = input * 10;
    callback( output );
}


#include <vector>
#include <mutex>
using std::vector; // vectorをstd::vectorの意味で使う

vector<Output> multiFooSync(vector<Input> inputs) {
    vector<Output> outputs;
    // autoは型推論を行う変数宣言に使う
    // vectorの変数を:で区切ることで全ての要素のループを表す
    for (auto input : inputs) {
        outputs.push_back(fooSync(input));
    }
    return outputs;
}

/**
 * @param vector<Input> inputs     　　　　　 入力データ
 * @param Callback<vector<Output>> callback  vector<Output>を引数とする処理関数
 */
void multiFooAsync(vector<Input> inputs,
                   Callback<vector<Output>> callback)
{
    struct Context {
        vector<Output> outputs;
        std::mutex lock;
        size_t remaining;
    };
    auto context = std::make_shared<Context>();
    context->remaining = inputs.size();
    
    for (auto input : inputs) {
        // inputを10倍した値を引数として第２引数の関数を呼び出す
        fooAsync(
                 input,
                 [=](Output output) {
                     std::lock_guard<std::mutex> guard(context->lock);
                     // outputsとremainingへのアクセスを排他する想定
                     // forループは複数のスレッドで割り当てるような形式を想定(ここではそうなってはない)
                     context->outputs.push_back(output);
                     if (--context->remaining == 0) {
                         // 全てのinputsの処理が完了してからまとめて呼び出す。
                         callback(context->outputs);
                     }
                 });
    }
}
