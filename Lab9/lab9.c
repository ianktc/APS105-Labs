/*
 APS105 Lab 9

 This is a program written to maintain a personal music library,
 using a linked list to hold the songs in the library.

 Author: Ian Chan
 Student Number: 1005211263
 
 TO-DO: 

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

//Delcaring a node struct called songInfo. Each node consists of an artist, song name and genre. 
typedef struct node {
    char *songName;
    char *artist;
    char *genre;
    struct node *next;
} Node, *NodePointer;

//Declaring a linked list. Here I define the head of the linked list using a struct.
typedef struct linkedList {
    Node *head;
} LinkedList;

//initializing linked list
void initList(LinkedList *list) {
    // The head initially points to nothing.
    list->head = NULL;
}

// PSEUDOCODE COMMENT: Each string in the node is declared as a character pointer variable,
// so they need to be dynamically allocated using the malloc() function,
// and deallocated using the free() function after use. 

//Function to create a new node
Node *createNode(char *songName, char *artist, char *genre) {
    //Ian clarify what this does exactly (I think it dynamically allocates memory)
    Node *newNode = (Node *) malloc(sizeof(Node));
    
    if(newNode != NULL) {
        newNode->songName = songName;
        newNode->artist = artist;
        newNode->genre = genre;
        newNode->next = NULL;
    }
    
    return newNode;
}

void inputStringFromUser(char *prompt, char *s, int arraySize);
void songNameDuplicate(char *songName);
void songNameFound(char *songName);
void songNameNotFound(char *songName);
void songNameDeleted(char *songName);
void printMusicLibraryEmpty(void);
void printMusicLibraryTitle(void);

bool insertAtFront(LinkedList *list, char *nameArray, char *artistArray, char *genreArray);
bool insertOrdered(LinkedList *list, char *songName, char *artist, char *genre);
bool isEmpty(LinkedList *list);
void printMusicLibrary(LinkedList *list);
bool checkSong(LinkedList *list, char *songQuery);
bool deleteSong(LinkedList *list, char *songQuery);
void deleteFront(LinkedList *list);
void deleteAllNodes(LinkedList *list);

const int MAX_LENGTH = 1024;

int main(void) {

    // Announce the start of the program
    printf("Personal Music Library.\n\n");
    printf("%s", "Commands are I (insert), D (delete), S (search by song name),\n"
           "P (print), Q (quit).\n");
      
    //initialize linked list
    LinkedList library;
    initList(&library);
     
    char songQuery[MAX_LENGTH];
    char response;
    char input[MAX_LENGTH + 1];
    
    do {
        inputStringFromUser("\nCommand", input, MAX_LENGTH);

        // Response is the first character entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if (response == 'I') {
            
            // declare the three variables that will store each attribute
            char *promptName = "\nSong name";
            char *promptArtist =  "Artist";
            char *promptGenre = "Genre";
            
            // allocate space for each string array
            char *songName = malloc(sizeof(char) * (MAX_LENGTH + 1));
            char *artist = malloc(sizeof(char) * (MAX_LENGTH + 1));
            char *genre = malloc(sizeof(char) * (MAX_LENGTH + 1));
                
            // Insert a song into the linked list. DONE
            // Maintain the list in alphabetical order by song name.        
            
            //this accepts user input 
            inputStringFromUser(promptName, songName, MAX_LENGTH); 
            inputStringFromUser(promptArtist, artist, MAX_LENGTH);
            inputStringFromUser(promptGenre, genre, MAX_LENGTH);
            
            //but wait there's more, I need to alphabetize it!
            if(!insertOrdered(&library, songName, artist, genre)){
                songNameDuplicate(songName);
            }
            
        }
        
        else if (response == 'D') {
            
            // Delete a song from the list.

            char *prompt = "\nEnter the name of the song to be deleted" ;
            inputStringFromUser(prompt, songQuery, MAX_LENGTH);
            
            deleteSong(&library, songQuery);


        }
        
        else if (response == 'S') {
            // Search for a song by its name.
            
            bool empty = false;
            
            //if list is empty, song is not there
            if(isEmpty(&library)){
                printMusicLibraryEmpty();
                empty = true;
            }
            
            //take user input
            if(!empty){
                char *prompt = "\nEnter the name of the song to search for" ;
                inputStringFromUser(prompt, songQuery, MAX_LENGTH);
                     
                //checks for song
                if(checkSong(&library, songQuery)){
                    songNameFound(songQuery);
                } else {
                    songNameNotFound(songQuery);
                }
            }
        }
        
        else if (response == 'P') {
            // Print the music library.
        printMusicLibrary(&library);
        }
        
        else if (response == 'Q') {
            // do nothing, we'll catch this below
        }
        
        else {
            // do this if no command matched ...
            printf ("\nInvalid command.\n");
        }
        
    } while (response != 'Q');

    deleteAllNodes(&library);

    return 0;
}

// SUPPORT FUNCTIONS

// Function to print each node
void printMusicLibrary(LinkedList *list){
    if(isEmpty(list)){
        printMusicLibraryEmpty();
        return;
    }
    printMusicLibraryTitle();
    Node *currentNode = list->head;
    while(currentNode != NULL){
        printf("\n%s", currentNode->songName);
        printf("\n%s", currentNode->artist);
        printf("\n%s\n", currentNode->genre);
        //move node to next
        currentNode = currentNode->next;
    }
}

// Function to check if empty
bool isEmpty(LinkedList *list) {
    if(list->head == NULL) {
        return true;
    }
    return false;
}

// Function to insert at front
bool insertAtFront(LinkedList *list, char *songName, char *artist, char *genre) {
   
    // Create a new node.
    Node *temp = createNode(songName, artist, genre);
    
    if (temp == NULL) {
        // We couldn't allocate enough memory for a new node.
        return false;
    }

    // The node will be inserted before head, so next should point to head.
    temp->next = list->head;
    
    // Now update head to the new front of the list.
    list->head = temp;
    
    return true;
}

// Function to insert in ordered list
bool insertOrdered(LinkedList *list, char *songQuery, char *artist, char *genre){
    
    //if empty, insert at the front (only usage)
    if (isEmpty(list)) {
        insertAtFront(list, songQuery, artist, genre);
        return true;
    }
    
    //checking if song already exists
    if(checkSong(list,songQuery)){
        return false;
    }
    
    //now alphabetize that shit
    
    //checking for alphetization for first two letters
    if (songQuery[0] < list->head->songName[0]){
        // The value to insert comes before the current head, so insert before it.
        return insertAtFront(list, songQuery, artist, genre);
    }else if(songQuery[0] == list->head->songName[0] && songQuery[1] < list->head->songName[1]){
        return insertAtFront(list, songQuery, artist, genre);
    }
    
    //creating temp node to compare 
    Node *current = list->head;
    while (current->next != NULL && songQuery[0] > list->head->songName[0]) {
            // The value to insert is larger than the next element in the list.
            // Move to the next element in the list.
            current = current->next;
    }
    
    Node *newNode = createNode(songQuery, artist, genre);
    if (newNode == NULL) {
            // Could not allocate memory for a new node.
            return false;
    }
    
    // current may be the last element in the list.
    // current may also be the last element in an ordered list that is less than value.
    
    newNode->next = current->next; 
    // Link the rest of the list with this new node.
    current->next = newNode; 
    // Overwrite next with the new node.
    
    return true;    
}

// Function to check if song exists
bool checkSong(LinkedList *list, char *songQuery){
    
    bool found = false;
    
    //check if list has no space
    if(isEmpty(list)){
        return false;
    }
    
    //check first node
    if (strcmp(list->head->songName, songQuery) == 0) {
        return true;
    }
    
    // Search for a node that matches the value, but maintain a pointer to the node just before it.
    Node *current = list->head;
    while (current->next != NULL && found == false){
        if(strcmp(current->next->songName,songQuery) != 0){
            found = true;
        }
        current = current->next; 
    }
    
    // current now points to a node just before the node that matched, OR current points to the last node.
    if (current->next != NULL) {
        return true;
    }
    
    return false;
}

// Function to delete song
bool deleteSong(LinkedList *list, char *songQuery){
    
    if (isEmpty(list) == true) {
        printMusicLibraryEmpty();
        return false;
    }

    if (strcmp(list->head->songName, songQuery) == 0) {
        // The first node matches the value.

        // Save a pointer to the second element in the list. Could be NULL, that's ok.
        Node *temp = list->head->next;
        
        free(list->head->songName); // Delete the first element of the list.
        free(list->head->artist); 
        free(list->head->genre); 
        list->head = temp; // Update the list to point to a new head.
        songNameDeleted(songQuery);
        return true;
    }

    // Search for a node that matches the value, but maintain a pointer to the node just before it.
    Node *current = list->head;
    while (current->next != NULL && strcmp(current->next->songName, songQuery) != 0) {
        current = current->next;
    }

    // current now points to a node just before the node that matched, OR current points to the last node.
    if (current->next != NULL) {
        // current does not point to the last node.
        Node *temp = current->next; // temp is the node we must delete.
        current->next = temp->next; // Update n so that temp is no longer linked.
        free(temp->songName);
        free(temp->artist);
        free(temp->genre);
        free(temp);
        songNameDeleted(songQuery);
        return true;
    } else {
        songNameNotFound(songQuery);
        return false;
    }
    
}

// Function to delete all shits
void deleteAllNodes(LinkedList *list) {
    
    //using deleteFront function provided
    do {
        deleteFront(list);
    } while (!isEmpty(list)); 

    // The list is now empty.
    list->head = NULL;
}

// Function to delete front node
void deleteFront(LinkedList *list) {
    if (isEmpty(list) == true) {
        // The list is empty, there is nothing to delete.
        return;
    }

    // Save the location of the node after head. Could be NULL, that's okay
    Node *newHead = list->head->next;
    // Free up the memory used by the current head.
    songNameDeleted(list->head->songName);
    free(list->head->songName);
    free(list->head->artist);
    free(list->head->genre);

    // Update the current head to the saved location.
    list->head = newHead;
}

//GIVEN FUNCTIONS

// Prompt the user for a string safely, without buffer overflow
void inputStringFromUser(char *prompt, char *s, int maxStrLength) {
    int i = 0;
    char c;

    printf("%s --> ", prompt);
    while (i < maxStrLength && (c = getchar()) != '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
}

// Function to call when the user is trying to insert a song name
// that is already in the personal music library.
void songNameDuplicate(char *songName) {
    printf("\nA song with the name '%s' is already in the music library.\n"
           "No new song entered.\n", songName);
}

// Function to call when a song name was found in the personal music library.
void songNameFound(char *songName) {
    printf("\nThe song name '%s' was found in the music library.\n",
           songName);
}

// Function to call when a song name was not found in the personal music library.
void songNameNotFound(char *songName) {
    printf("\nThe song name '%s' was not found in the music library.\n",
           songName);
}

// Function to call when a song name that is to be deleted
// was found in the personal music library.
void songNameDeleted(char *songName) {
    printf("\nDeleting a song with name '%s' from the music library.\n",
           songName);
}

// Function to call when printing an empty music library.
void printMusicLibraryEmpty(void) {
    printf("\nThe music library is empty.\n");
}

// Function to call to print a title when the entire music library is printed.
void printMusicLibraryTitle(void) {
    printf("\nMy Personal Music Library: \n");
}