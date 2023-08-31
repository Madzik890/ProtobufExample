#include <iostream>
#include <fstream>
#include <future>
#include <grpc/grpc.h>
#include <grpcpp/create_channel.h>

#include "messagehub/messagehubimpl.hpp"

void clientFunc()
{
    grpc::ClientContext context;   
    auto channel = grpc::CreateChannel("0.0.0.0:50051", grpc::InsecureChannelCredentials());
    auto client = MessageHub::NewStub(channel);

    Message message; 
    message.set_nickname("Rogal DLL");
    message.set_text("EBE EBE");
    MessageResult result;

    const auto status = client->Publish(&context, message, &result);
    if(status.error_code() != grpc::StatusCode::OK) {
        std::cerr << "Cannot publish message" << std::endl;
        return;
    }

    std::cout << "Result of sending message: " << std::boolalpha << result.result() << std::endl;
    if(!result.result()) std::cout << "Error message: " << result.error() << std::endl;
}

int main() 
{        
    MessageHubImpl messageHubImpl;
    grpc::ServerBuilder builder;    
    builder.AddListeningPort("0.0.0.0:50051", grpc::InsecureServerCredentials());
    builder.RegisterService(&messageHubImpl);

    const auto server = builder.BuildAndStart();        
    const auto clientTask = std::async(&clientFunc);
    
    if(!clientTask.valid()) return -1;
    clientTask.wait();
    server->Wait();    

    return 0;
}

