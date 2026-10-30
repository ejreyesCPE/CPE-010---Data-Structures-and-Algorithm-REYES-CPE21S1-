#include <iostream>
#include <string>
#include "singly_ll.h"

void clearBuffer() {
    char c;
    while (std::cin.get(c) && c != '\n');
}

void playPlaylist(SingleList<std::string>* head) {
    if (head == nullptr) {
        std::cout << "\nPlaylist is empty! Add some songs first.\n";
        return;
    }

    SingleList<std::string>* currentSong = head;
    char playerChoice = ' ';

    while (true) {
        std::cout << "\n----------------------------------------\n";
        std::cout << "NOW PLAYING: >>> " << currentSong->data << " <<<\n";
        std::cout << "----------------------------------------\n";
        std::cout << "[N]ext Song | [P]revious Song | [S]top Playing\n";
        std::cout << "Choice: ";
        std::cin >> playerChoice;

        if (playerChoice == 'N' || playerChoice == 'n') {
            currentSong = currentSong->next;
        } 
        else if (playerChoice == 'P' || playerChoice == 'p') {
            currentSong = getPreviousNode(head, currentSong);
        } 
        else if (playerChoice == 'S' || playerChoice == 's') {
            std::cout << "Stopping player mode...\n";
            break;
        } 
        else {
            std::cout << "Invalid player choice. Please use the valid options.\n";
        }
    }
}

int main() {
    char choice = ' ';
    std::string newSong;

    SingleList<std::string>* head = nullptr;

    sllinsertEnd(std::string("MEOWMEOW"), head);
    sllinsertEnd(std::string("ANIMAL"), head);
    sllinsertEnd(std::string("HALA"), head);

    std::cout << "Welcome to Spotify!\n";
    std::cout << "==============================\n";
    std::cout << "Just created a playlist!\n";
    std::cout << "==============================\n\n";

    while (choice != 'D' && choice != 'd') {
        std::cout << "\n----- Current Playlist ----- \n";
        listTraversal(head);

        std::cout << "\nChoose action below:\n";
        std::cout << "A. Play playlist (Interactive)\n";
        std::cout << "B. Add a song to the playlist\n";
        std::cout << "C. Remove a song from the playlist\n";
        std::cout << "D. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 'A' || choice == 'a') {
            playPlaylist(head);
        } 
        else if (choice == 'B' || choice == 'b') {
            clearBuffer(); 
            std::cout << "Enter the song name to add: ";
            std::getline(std::cin, newSong);
            sllinsertEnd(newSong, head);
            std::cout << "\"" << newSong << "\" added successfully.\n";
        } 
        else if (choice == 'C' || choice == 'c') {
            clearBuffer(); 
            std::cout << "Enter the song name to remove: ";
            std::getline(std::cin, newSong);
            sllDelete(newSong, head);
            std::cout << "Removal requested for: \"" << newSong << "\".\n";
        } 
        else if (choice != 'D' && choice != 'd') {
            std::cout << "Invalid choice. Please select A, B, C, or D.\n";
        }
    }

    sllDeleteList(head);
    std::cout << "\nExiting the program. Goodbye!\n";

    return 0;
}