#include <iostream>
#include <string>

using namespace std;

const int MAX_MESSAGES = 100; // Maximum number of chat messages

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
    messageCount = 0; // Reset the message count to zero, effectively clearing the history
    cout << "Chat history has been cleared." << endl;
}

int main() {
    string chatHistory[MAX_MESSAGES]; // Array to store chat messages
    int messageCount = 0; // Count of current messages
    string message;
    string user1 = "User1";
    string user2 = "User2";
    string currentUser = user1; // Start with User1

    cout << " \n\t\t\t         TalkSpace" << endl;
    cout << "Commands: 'exit' to quit, 'clear' to clear chat history." << endl;
    while (true) {
        // Display chat history
        displayChatHistory(chatHistory, messageCount);

        // Prompt the current user to enter a message
        cout << currentUser << ": ";
        getline(cin, message);

        // Check if the user wants to exit the chat
        if (message == "exit") {
            break;
        }
        // Command to clear the chat history
        else if (message == "clear") {
            clearChatHistory(messageCount);
        }
        //
        else {
            // Add the message to the chat history if there's space
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
