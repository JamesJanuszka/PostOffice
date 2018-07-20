#pragma once

#include <memory>
#include <vector>
#include "message.hpp"

namespace po
{
  class MessageBus
  {
  public:
    virtual ~MessageBus() = default;
    MessageBus() = delete;

    void pollMessages();
    void sendMessage(const Message& message);
    void subscribe(const int& subscriber);
    bool unsubscribe(const int& subscriber);
    std::vector<int>& list();
  private:
    std::vector<Message> messages;
    std::vector<int> subscribers;
  };

  void MessageBus::pollMessages()
  {
    auto newmessages = std::make_shared<std::vector<Message>>(std::move(messages));
    for (auto& x : subscribers)
      {
	//x = newmessages;
	x = 1;
      }
    
  }

  void MessageBus::subscribe(const int& subscriber)
  {
    subscribers.push_back(subscriber);
  }

  bool MessageBus::unsubscribe(const int& subscriber)
  {
    return subscriber == !subscriber;
  }

  std::vector<int>& MessageBus::list()
  {
    return subscribers;
  }

}//end namespace po
