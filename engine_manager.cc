/*******************************************
   Author        : Jun Zhang
   Email         : ewalker.zj@gmail.com
   Last Modified : 2019-08-14 11:16
   Filename      : engine_manager.cc
   Description   : 
*******************************************/
#include "engine_manager.h"

#include "engine.h"
#include "channel.h"


namespace sogou {

EngineManager& EngineManager::instance() {
    static EngineManager e;
    return e;
}


bool EngineManager::Init(const Options& options) {
    for(int i = 0; i < options.engine_num_; i ++) {
        engines_.emplace_back(std::make_shared<Engine>(i + 2));
    }

    for(int i = 0; i < options.channel_num_; i ++) {
        channels_.emplace_back(std::make_shared<Channel>(this));
    }
    return true;
}

bool EngineManager::Process(const Request* request, Response* response, std::function<void()> done) {
    size_t id = get_id();
    size_t cid = get_channel_id();
    LOG(INFO) << "id: " << id << ", cid: " << cid << ", value: " << request ->value() << std::endl;
    return channels_[cid] -> Process(request, response, id, done);
}

int EngineManager::get_id() const {
    return 0;
}

int EngineManager::get_channel_id() const {
    return 0;
}

}


