#ifndef MESSAGEHUBIMPL_HPP
#define MESSAGEHUBIMPL_HPP

#include <grpc/grpc.h>
#include <grpcpp/server_builder.h>
#include <protocol/message.pb.h>
#include <protocol/message.grpc.pb.h>

class MessageHubImpl final : public MessageHub::Service
{
    public:
        MessageHubImpl() = default;
        ~MessageHubImpl() = default;

    public:
        grpc::Status Publish(::grpc::ServerContext* context, const ::Message* request, ::MessageResult* response) override;
};

#endif