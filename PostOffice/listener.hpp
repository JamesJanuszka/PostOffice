#pragma once

#include <memory>
#include <vector>
#include "message.hpp"

namespace po
{
  class Listener
  {
  public:
    virtual ~Listener() = default;
    Listener() = default;

    void receive(std::shared_ptr<std::vector<Message>> new_messages);
    void read();
  private:
    virtual void process(const Message& message) = 0;
    
    std::shared_ptr<std::vector<Message>> messages;
  };

  void Listener::receive(std::shared_ptr<std::vector<Message>> new_messages)
  {
    messages = new_messages;
  }

  void Listener::read()
  {
    for(const auto& x : *messages)
      {
	process(x);
      }
  }
  
}//end namespace po
