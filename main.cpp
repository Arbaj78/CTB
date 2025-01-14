#include "Notification.h"


int main() {
    NotificationManager manager;

    manager.setDefaultChannel(sendEmail);

    map<string, string> employeePreferences = {
        {"HR", "email"},
        {"Events", "sms"},
        {"IT", "push"}
    };


    cout << "HR Notification: " << endl;
    manager.notify("this message from HR side.", employeePreferences["HR"]);

    cout << "\nEvent Reminder:" << endl;
    manager.notify("this message from Events side.", employeePreferences["Events"]);

    cout << "\nSystem Alert:" << endl;
    manager.notify("Scheduled server downtime from 11 PM to 3 AM tonight. Please plan accordingly.", employeePreferences["IT"]);

    cout << "\nUnknown :" << endl;
    manager.notify("This is a default notification for an unknown.");

    return 0;
}