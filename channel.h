/*******************************************
   Author        : Jun Zhang
   Email         : ewalker.zj@gmail.com
   Last Modified : 2019-08-14 23:09
   Filename      : channel.h
   Description   : 
*******************************************/
#pragma once

#include <memory>
#include <bthread/execution_queue.h>

#include "engine_manager.h"


namespace sogou {

class Channel {
    public:
        Channel(EngineManager* mgr);
        ~Channel() {}

        bool Process(const Request* request, Response* response, size_t id, Closure closure);
        bool InternalProcess(const Request* request, Response* response, size_t id, Closure closure);

    private:
        EngineManager* mgr_{nullptr};
        ::bthread::ExecutionQueueId<std::shared_ptr<Closure>> exec_queue_;
};

}
