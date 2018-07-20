#pragma once

#include <memory>
#include <vector>
#include <algorithm>
#include "message.hpp"
#include "listener.hpp"

namespace po
{
  class MessageBus
  {
  public:
    virtual ~MessageBus() = default;
    MessageBus() = delete;

    void pollMessages();
    void sendMessage(const Message& message);
    void subscribe(Listener* subscriber);
    void unsubscribe(Listener* subscriber);
    std::vector<Listener*>& list();
  private:
    std::vector<Message> messages;
    std::vector<Listener*> subscribers;
  };

  void MessageBus::pollMessages()
  {
    auto new_messages = std::make_shared<std::vector<Message>>(std::move(messages));
    for(auto& x : subscribers)
      {
	x->receive(new_messages);
      }
    
  }

  void MessageBus::subscribe(Listener* subscriber)
  {
    subscribers.push_back(subscriber);
  }

  void MessageBus::unsubscribe(Listener* subscriber)
  {
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end()); 
  }

  std::vector<Listener*>& MessageBus::list()
  {
    return subscribers;
  }

}//end namespace po
