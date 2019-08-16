/*******************************************
   Author        : Jun Zhang
   Email         : ewalker.zj@gmail.com
   Last Modified : 2019-08-14 11:16
   Filename      : engine_manager.h
   Description   : 
*******************************************/
#pragma once 

#include <vector>
#include <memory>
#include <functional>

#include "options.h"
#include "data.pb.h"

#include <butil/logging.h>

namespace sogou {

class Channel;
class Engine;
typedef std::function<void()> Closure;

class EngineManager {
    public:
        friend class Channel;  // 
    public:
        EngineManager() {}

        ~EngineManager() {}

        static EngineManager& instance();

        bool Init(const Options& options);

        bool Destory();

        bool Process(const Request* request, Response* response, std::function<void()> done);
        int get_id() const;
        int get_channel_id() const;

    private:
        std::vector<std::shared_ptr<Engine>> engines_;
        std::vector<std::shared_ptr<Channel>> channels_;
};

}
