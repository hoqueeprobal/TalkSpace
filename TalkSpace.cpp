#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string FILE_NAME = "chat_history.txt";

// Load chat history from file
void loadChatHistory(vector<string>& chatHistory) {
    ifstream file(FILE_NAME);
    string line;

    while (getline(file, line)) {
        chatHistory.push_back(line);
    }
    file.close();
}

// Save chat history to file
void saveChatHistory(const vector<string>& chatHistory) {
    ofstream file(FILE_NAME);
    for (const string& msg : chatHistory) {
        file << msg << endl;
    }
    file.close();
}

// Display chat history
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

// Clear chat history
void clearChatHistory(vector<string>& chatHistory) {
    chatHistory.clear();
    saveChatHistory(chatHistory);
    cout << "Chat history cleared." << endl;
}

// Search messages
void searchMessages(const vector<string>& chatHistory) {
    string keyword;
    cout << "Enter keyword to search: ";
    getline(cin, keyword);

    bool found = false;
    cout << "\n--- Search Results ---" << endl;

    for (const string& msg : chatHistory) {
        if (msg.find(keyword) != string::npos) {
            cout << msg << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matching messages found." << endl;
    }
    cout << "----------------------" << endl;
}

// Edit last message
void editLastMessage(vector<string>& chatHistory, const string& currentUser) {
    for (int i = chatHistory.size() - 1; i >= 0; i--) {
        if (chatHistory[i].find(currentUser + ": ") == 0) {
            string newMsg;
            cout << "Enter new message: ";
            getline(cin, newMsg);
            chatHistory[i] = currentUser + ": " + newMsg;
            saveChatHistory(chatHistory);
            cout << "Message edited." << endl;
            return;
        }
    }
    cout << "No message found to edit." << endl;
}

// Delete last message
void deleteLastMessage(vector<string>& chatHistory, const string& currentUser) {
    for (int i = chatHistory.size() - 1; i >= 0; i--) {
        if (chatHistory[i].find(currentUser + ": ") == 0) {
            chatHistory.erase(chatHistory.begin() + i);
            saveChatHistory(chatHistory);
            cout << "Message deleted." << endl;
            return;
        }
    }
    cout << "No message found to delete." << endl;
}

int main() {
    vector<string> chatHistory;
    string message;
    string user1, user2;

    // Load old messages
    loadChatHistory(chatHistory);

    cout << "Enter name for User 1: ";
    getline(cin, user1);

    while (true) {
        cout << "Enter name for User 2: ";
        getline(cin, user2);
        if (user2 != user1) break;
        cout << "Username already used.\n";
    }

    string currentUser = user1;

    cout << "\n\t\t\t TalkSpace (Persistent Chat)" << endl;
    cout << "Commands: exit | clear | edit | delete | search" << endl;

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
        else if (message == "search") {
            searchMessages(chatHistory);
        }
        else if (message == "edit") {
            editLastMessage(chatHistory, currentUser);
        }
        else if (message == "delete") {
            deleteLastMessage(chatHistory, currentUser);
        }
        else {
            chatHistory.push_back(currentUser + ": " + message);
            saveChatHistory(chatHistory);
            currentUser = (currentUser == user1) ? user2 : user1;
        }
    }

    cout << "Chat ended." << endl;
    return 0;
}
