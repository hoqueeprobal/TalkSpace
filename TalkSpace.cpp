#include <iostream>
#include <string>

using namespace std;

const int MAX_MESSAGES = 100;

// Function to display the chat history
void displayChatHistory(const string chatHistory[], int messageCount) {
    cout << "\n--- Chat History ---" << endl;
    if (messageCount == 0) {
        cout << "No messages yet." << endl;
    } else {
        for (int i = 0; i < messageCount; i++) {
            cout << chatHistory[i] << endl;
        }
    }
    cout << "--------------------" << endl;
}

// Function to clear the chat history
void clearChatHistory(int& messageCount) {
    messageCount = 0;
    cout << "Chat history has been cleared." << endl;
}

int main() {
    string chatHistory[MAX_MESSAGES];
    int messageCount = 0;
    string message;

    // Custom usernames with duplicate prevention
    string user1, user2;

    cout << "Enter name for User 1: ";
    getline(cin, user1);

    //  Prevent duplicate names
    while (true) {
        cout << "Enter name for User 2: ";
        getline(cin, user2);

        if (user2 == user1) {
            cout << "Username already used! Please enter a different name.\n";
        } else {
            break; // Valid username
        }
    }

    string currentUser = user1;

    cout << "\nSimple Chat Application" << endl;
    cout << "Commands: 'exit' to quit, 'clear' to clear chat history." << endl;

    while (true) {
        displayChatHistory(chatHistory, messageCount);

        cout << currentUser << ": ";
        getline(cin, message);

        if (message == "exit") {
            break;
        }
        else if (message == "clear") {
            clearChatHistory(messageCount);
        }
        else {
            if (messageCount < MAX_MESSAGES) {
                chatHistory[messageCount] = currentUser + ": " + message;
                messageCount++;
            } else {
                cout << "Chat history is full. No more messages can be added." << endl;
                break;
            }

            currentUser = (currentUser == user1) ? user2 : user1;
        }
    }

    cout << "Chat ended." << endl;
    return 0;
}
