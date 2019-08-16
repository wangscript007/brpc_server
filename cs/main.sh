
export LD_LIBRARY_PATH=/search/odin/zhangjun/tools/brpc/lib:$LD_LIBRARY_PATH

g++ -c main.cc -I /search/odin/zhangjun/tools/brpc/include/ -I /search/odin/zhangjun/tools/protobuf-3.7.1/include/ -std=c++11

g++ -o main main.o -L /search/odin/zhangjun/tools/brpc/lib/ -lbrpc -L /search/odin/zhangjun/tools/protobuf-3.7.1/lib/ -lprotobuf
