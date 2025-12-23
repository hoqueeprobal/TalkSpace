#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to display the chat history
void displayChatHistory(const vector<string>& chatHistory) {
    cout << "\n--- Chat History ---" << endl;

    if (chatHistory.empty()) {
        cout << "No messages yet." << endl;
    } else {
        for (const string& msg : chatHistory) {
            cout << msg << endl;
        }
    }

    cout << "--------------------" << endl;
}

// Function to clear the chat history
void clearChatHistory(vector<string>& chatHistory) {
    chatHistory.clear();
    cout << "Chat history has been cleared." << endl;
}

int main() {
     // Dynamic history
    vector<string> chatHistory;  
    string message;

    // Custom usernames with duplicate prevention
    string user1, user2;

    cout << "Enter name for User 1: ";
    getline(cin, user1);

    while (true) {
        cout << "Enter name for User 2: ";
        getline(cin, user2);

        if (user2 == user1) {
            cout << "Username already used! Please enter a different name.\n";
        } else {
            break;
        }
    }

    string currentUser = user1;

    cout << "\nSimple Chat Application" << endl;
    cout << "Commands: 'exit' to quit, 'clear' to clear chat history." << endl;

    while (true) {
        displayChatHistory(chatHistory);

        cout << currentUser << ": ";
        getline(cin, message);

        if (message == "exit") {
            break;
        }
        else if (message == "clear") {
            clearChatHistory(chatHistory);
        }
        else {
            chatHistory.push_back(currentUser + ": " + message);
            currentUser = (currentUser == user1) ? user2 : user1;
        }
    }

    cout << "Chat ended." << endl;
    return 0;
}
