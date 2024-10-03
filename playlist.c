#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_CAPACITY 100

char songs[MAX_CAPACITY][MAX_LENGTH]; 
int front = 0;
int rear = -1;
int size = 0;
int capacity;
void createPlaylist(int cap) {
    capacity = cap;
    front = 0;
    rear = -1;
    size = 0;
}

int isFull() {
    return (size == capacity);
}

int isEmpty() {
    return (size == 0);
}

void addSong(const char* song) {
    if (isFull()) {
        printf("Error: Playlist is full.\n");
        return;
    }
    rear = (rear + 1) % capacity;
    strncpy(songs[rear], song, MAX_LENGTH);
    size++;
    printf("Added song: %s\n", song);
}

void removeSong(int position) {
    if (isEmpty()) {
        printf("Error: Playlist is empty.\n");
        return;
    }
    if (position < 0 || position >= size) {
        printf("Error: Invalid position.\n");
        return;
    }
    int index = (front + position) % capacity;
    printf("Removed song: %s\n", songs[index]);
    for (int i = index; i != rear; i = (i + 1) % capacity) {
        strncpy(songs[i], songs[(i + 1) % capacity], MAX_LENGTH);
    }
    rear = (rear - 1 + capacity) % capacity;
    size--;
}
void playSongs(int position) {
    if (isEmpty()) {
        printf("Error: Playlist is empty.\n");
        return;
    }
    if (position < 0 || position >= size) {
        printf("Error: Invalid position.\n");
        return;
    }
    printf("Playing songs from position %d:\n", position);
    for (int i = 0; i < size; i++) {
        int index = (front + position + i) % capacity;
        printf("%s\n", songs[index]);
    }
}
void displayPlaylist() {
    if (isEmpty()) {
        printf("Playlist is empty.\n");
        return;
    }
    printf("Current Playlist:\n");
    for (int i = 0; i < size; i++) {
        int index = (front + i) % capacity;
        printf("%s\n", songs[index]);
    }
}

int main() {
    int cap;
    printf("Enter the maximum length of the playlist: ");
    scanf("%d", &cap);

    createPlaylist(cap);

    addSong("Song 1");
    addSong("Song 2");
    addSong("Song 3");
    addSong("Song 4");
    addSong("Song 5");
    addSong("Song 6");

    displayPlaylist();

    removeSong(1);
    displayPlaylist();

    playSongs(0);

    return 0;
}