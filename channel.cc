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

//Channel::Channel(EngineManager* mgr) : mgr_(mgr) {}
Channel::Channel() {}

int Channel::Start() {
        ::bthread::ExecutionQueueOptions options;
        int ret = ::bthread::execution_queue_start(&exec_queue_, &options, &Channel::run_loop, nullptr);
        if(ret != 0) {
            std::cout << "channel::start failed." << std::endl;
        }
}

int Channel::Stop() {
        int ret = ::bthread::execution_queue_stop(exec_queue_);

        ret = ::bthread::execution_queue_join(exec_queue_);

        return ret;
}

bool Channel::Enqueue(Closure closure) {
    if(::bthread::execution_queue_execute(exec_queue_, closure) != 0) {
        std::cout << "Channel::Enqueue to Channel failed." << std::endl;
        return false;
    }
    return true;
}

int Channel::run_loop(void*, ::bthread::TaskIterator<std::function<void()>>& iter) {
    if(iter.is_queue_stopped()){
        return 0;
    }

    while(iter) {
        (*iter)();
        ++ iter;
    }

    return 0;
}

//bool Channel::Process(const Request* request, Response* response, size_t id, Closure closure) {
//    std::cout << "channel::process : " << request -> req_id() << ", value: " << request -> value() << std::endl;
//    auto task_ptr = std::make_shared<Closure>(
//            std::bind(&Channel::InternalProcess, this, request, response, id, closure)
//            );
//    return execution_queue_execute(exec_queue_, task_ptr);
//}
//
//
//bool Channel::InternalProcess(const Request* request, Response* response, size_t id, Closure closure) {
//    std::cout << "channel::internalprocess : " << request -> req_id() << ", value: " << request -> value() << std::endl;
//    int value;
//    int in_value = request -> value();
//    int ret = 0;
//    bool status = mgr_ -> engines_[id] -> Process(in_value, value);
//    ret = status ? 0 : -1;
//    std::cout << "status: " << status << ", value: " << value << std::endl;
//    response -> set_status(ret);
//    response -> set_value(value);
//    closure();
//}

}
