/*******************************************
   Author        : Jun Zhang
   Email         : ewalker.zj@gmail.com
   Last Modified : 2019-08-14 20:29
   Filename      : options.h
   Description   : 
*******************************************/

#pragma once 

namespace sogou {

class Options {
    public:
        Options(int channel_num = 4, int engine_num = 4) : 
            channel_num_(channel_num), engine_num_(engine_num) {}

    public:
        int channel_num_;
        int engine_num_; 
};

}
