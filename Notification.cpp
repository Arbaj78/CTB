#include "Notification.h"

NotificationManager::NotificationManager() {
    channels["email"] = sendEmail;
    channels["sms"] = sendSMS;
    channels["push"] = sendPushNotification;
}

void NotificationManager::setDefaultChannel(function<void(const string&)> channel) {
    defaultChannel = move(channel);
}

void NotificationManager::notify(const string& message, const string& channel) const {
    if (!channel.empty() && channels.find(channel) != channels.end()) {
        channels.at(channel)(message); 
    } else if (defaultChannel) {
        defaultChannel(message); 
    } else {
        cerr << "Error No valid notification channel available!" << endl;
    }
}

void sendEmail(const string& message) {
    cout << "Sending Email..: " << message << endl;
}

void sendSMS(const string& message) {
    cout << "Sending SMS: " << message << endl;
}

void sendPushNotification(const string& message) {
    cout << "Sending Push Notification: " << message << endl;
}