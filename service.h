/*******************************************
   Author        : Jun Zhang
   Email         : ewalker.zj@gmail.com
   Last Modified : 2019-08-15 12:56
   Filename      : service.h
   Description   : 
*******************************************/
#pragma once 

#include "data.pb.h"

namespace sogou {

class Service : public BaseService {
    public:
        Service() {}
        ~Service() {}
        virtual void Process(::google::protobuf::RpcController* controller, const ::sogou::Request* request, ::sogou::Response* response, ::google::protobuf::Closure* done);

};

}
