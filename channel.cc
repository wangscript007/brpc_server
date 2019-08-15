/*******************************************
   Author        : Jun Zhang
   Email         : ewalker.zj@gmail.com
   Last Modified : 2019-08-14 23:09
   Filename      : channel.cc
   Description   : 
*******************************************/
#include "channel.h"
#include "engine.h"

namespace sogou {

Channel::Channel(EngineManager* mgr) : mgr_(mgr) {}

bool Channel::Process(const Request* request, Response* response, size_t id, Closure closure) {
    std::cout << "channel::process : " << request -> req_id() << ", value: " << request -> value() << std::endl;
    auto task_ptr = std::make_shared<Closure>(
            std::bind(&Channel::InternalProcess, this, request, response, id, closure)
            );
    return execution_queue_execute(exec_queue_, task_ptr);
}


bool Channel::InternalProcess(const Request* request, Response* response, size_t id, Closure closure) {
    std::cout << "channel::internalprocess : " << request -> req_id() << ", value: " << request -> value() << std::endl;
    int value;
    int in_value = request -> value();
    int ret = 0;
    bool status = mgr_ -> engines_[id] -> Process(in_value, value);
    ret = status ? 0 : -1;
    std::cout << "status: " << status << ", value: " << value << std::endl;
    response -> set_status(ret);
    response -> set_value(value);
    closure();
}

}
