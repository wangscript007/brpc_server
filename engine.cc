/*******************************************
   Author        : Jun Zhang
   Email         : ewalker.zj@gmail.com
   Last Modified : 2019-08-14 23:04
   Filename      : engine.cc
   Description   : 
*******************************************/
#include "engine.h"

namespace sogou {

bool Engine::Process(const int req, int &resp) {
    resp = n_ + req;
    return true;
}

}
