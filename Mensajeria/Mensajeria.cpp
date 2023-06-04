// Mensajeria.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>



class Message {
private:

    std::string msg;
    int turno;

public:

    static int turno_msg;

    Message() {}

    Message(std::string text) : msg(text){}
    const std::string get_text() {
        return msg;
    }

    const int getTurno() {
        return turno;
    }

    void setTurno(int i) {
        turno = i;
    }

    bool operator < (Message& m) {
        bool rta = this->turno_msg < m.getTurno();
    }

};

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const std::string& text) {
        Message m(text);
        m.setTurno(Message::turno_msg++);
        return m;
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            std::cout << msg.get_text() << std::endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        std::sort(messages_.begin(), messages_.end());
    }
    std::vector<Message> messages_;
};

class Network {
public:
    static void send_messages(std::vector<Message> messages, Recipient& recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    std::vector<Message> messages;
    std::string text;
    while (getline(std::cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
