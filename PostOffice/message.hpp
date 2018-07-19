#pragma once

#include <variant>
#include <string>
#include <functional>

namespace po
{
  struct Bar
  {
    Bar(const std::string& key, bool flag)
    {
      m_key = std::hash<std::string>{}(key);
      m_flag = flag;
    }
    size_t m_key;
    bool m_flag;
  };

  struct Test
  {
    Test(const std::string& key, int amount)
    {
      m_key = std::hash<std::string>{}(key);
      m_amount = amount;
    }
    size_t m_key;
    int m_amount;
  };

  using MessageType_t = std::variant<std::monostate, Bar, Test>;

  struct Message
  {
    Message(MessageType_t thing)
    {
      message_type = thing;
    }
  
    virtual ~Message() = default;
    MessageType_t  message_type;
  protected:
    Message() = default;
  };

  const Message isTrue(bool flag = 1);
  
  const Message isTrue(bool flag)
  {
    return Message(Bar("Is true", flag));
  }

}//end namespace po
