#include "messagehubimpl.hpp"

#include <iostream>

grpc::Status MessageHubImpl::Publish(::grpc::ServerContext* context, const ::Message* request, ::MessageResult* response) 
{
    std::cout << request->nickname() << " -> " << request->text() << std::endl;
    response->set_result(false);            
    response->set_error("Cannot send any messages for this server");
    return grpc::Status::OK;
}