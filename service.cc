/*******************************************
   Author        : Jun Zhang
   Email         : ewalker.zj@gmail.com
   Last Modified : 2019-08-15 14:51
   Filename      : service.cc
   Description   : 
*******************************************/
#include "service.h"
#include "engine_manager.h"


namespace sogou {

void Service::Process(::google::protobuf::RpcController* controller, const ::sogou::Request* request, ::sogou::Response* response, ::google::protobuf::Closure* done) {
    EngineManager& mgr = EngineManager::instance();

    bool status = mgr.Process(request, response, [done](void) { done -> Run();});
    if(!status) {
    }
    LOG(INFO) << "status: " << status << ", res value: " << response -> value();
    //return status;
}

}
