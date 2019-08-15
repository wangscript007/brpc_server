/*******************************************
   Author        : Jun Zhang
   Email         : ewalker.zj@gmail.com
   Last Modified : 2019-08-14 23:03
   Filename      : engine.h
   Description   : 
*******************************************/
#pragma once 

namespace sogou {

class Engine {
    public:
        Engine(int n) : n_(n) {}

        bool Process(const int req, int &resp);

    public:
        int n_;
};

}
