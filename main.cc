/*******************************************
   Author        : Jun Zhang
   Email         : ewalker.zj@gmail.com
   Last Modified : 2019-06-29 23:39
   Filename      : main.cc
   Description   : 
*******************************************/

#include <iostream>
#include <chrono>

#include <gflags/gflags.h>
#include <brpc/server.h>

#include "service.h"
#include "options.h"
#include "engine_manager.h"
//#include "brpc/channel.h"

DEFINE_int32(port, 2019, "service port");

namespace sogou {

int run(int argc, char** argv) {
    google::ParseCommandLineFlags(&argc, &argv, true);

    EngineManager& mgr = EngineManager::instance();

    Options running_options;

    mgr.Init(running_options);

    brpc::Server server;
    Service service;

    if(server.AddService(&service, brpc::SERVER_DOESNT_OWN_SERVICE) != 0) {
        std::cout << "failed to add service." << std::endl;
        return -1;
    }

    brpc::ServerOptions server_options;
    if(server.Start(FLAGS_port, &server_options) != 0) {
        std::cout << "failed to start service." << std::endl;
        return -1;
    }

    server.RunUntilAskedToQuit();


    auto begin = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

    return 0;
}

}


int main(int argc, char** argv) {
    return sogou::run(argc, argv);
}

