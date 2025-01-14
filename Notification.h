#ifndef NOTIFICATION_SYSTEM_H
#define NOTIFICATION_SYSTEM_H

#include <iostream>
#include <string>
#include <functional>
#include <map>

using namespace std;

class NotificationManager {

private:
    map<string, function<void(const string&)>> channels; 
    function<void(const string&)> defaultChannel;      

public:
    NotificationManager();

    void setDefaultChannel(function<void(const string&)> channel);
    void notify(const string& message, const string& channel = "") const;
};

void sendEmail(const string& message);
void sendSMS(const string& message);
void sendPushNotification(const string& message);

#endif