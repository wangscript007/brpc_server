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
        channels_.emplace_back(std::make_shared<Channel>());
        channels_[i] -> Start();
    }
    return true;
}

bool EngineManager::Destory() {
    for(auto it : channels_) {
        it -> Stop();
    }
}


bool EngineManager::Process(const Request* request, Response* response, std::function<void()> closure) {
    size_t id = get_id();
    size_t cid = get_channel_id();

    std::shared_ptr<Engine> engine = engines_[id];

    channels_[cid] -> Enqueue([engine, request, response, closure](void) {
                int value;
                int in_value = request -> value();
                int ret = 0;
                bool status = engine -> Process(in_value, value);
                ret = status ? 0 : -1;
                std::cout << "status: " << status << ", value: " << value << std::endl;
                response -> set_status(ret);
                response -> set_value(value);
                closure();
            });
    
    return true;

    //LOG(INFO) << "id: " << id << ", cid: " << cid << ", value: " << request ->value() << std::endl;
    //return channels_[cid] -> Process(request, response, id, done);
}

int EngineManager::get_id() const {
    return 0;
}

int EngineManager::get_channel_id() const {
    return 0;
}

}


