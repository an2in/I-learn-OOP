#include <iostream>
#include <string>
using namespace std;
class NotificationSender {
public:
  virtual ~NotificationSender() {}
  virtual void send(const string &recipient, const string &message) = 0;
};
class EmailSender : public NotificationSender {
public:
  void send(const string &recipient, const string &message) override {
    cout << "[Email to " << recipient << "]: " << message;
  }
};
class PushSender : public NotificationSender {
public:
  void send(const string &recipient, const string &message) override {
    cout << "[Push notification to " << recipient << "]: " << message;
  }
};
void sendNoti(NotificationSender &sender, const string &user) {
  sender.send(user, "Hallo, wer bist du? Ich freue mich!\n");
}
int main() {
  EmailSender email;
  PushSender recipent;
  sendNoti(email, "mothaiba@edu.vn");
  sendNoti(recipent, "midimo@vn.edu");
}