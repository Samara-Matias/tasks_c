#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Implementing the data format for the tasks
enum TypePriority { // enum TypePriority {...}; -> alternative way
    low,
    medium,
    high
};

enum TypeStatus {
    pending,
    onGoing,
    completed
} Status;

typedef struct TypeTask {
    int id;
    char title[80], description[255];
    enum TypePriority priority;
    enum TypeStatus status; 
} Task;


// Implementing the funcionalities
int returnLastId () {
    int id = 0;

    FILE *file = fopen( "lastId.dat", "rb" );

    if( file != NULL  ){
        fread( &id, sizeof( int ), 1, file );
    }   
    fclose( file );
    
    return id;
}

void saveNewLastId ( int id ) {
    FILE *file = fopen( "lastId.dat", "wb");

    if( file != NULL ) {
        fwrite( &id, sizeof( int ), 1, file );
    }

    fclose( file );
}

const char *returnStatus ( enum TypeStatus status ) {
    switch (status) {
        case pending:
            return "Pending";
        case onGoing:
            return "On going";
        case completed:
            return "Completed";
        default:
            return "Unknown";
    }
}

const char *returnPriority ( enum TypePriority priority) {
    switch (priority) {
        case low:
            return "Low";
        case medium:
            return "Medium";
        case high:
            return "High";
        default:
            return "Unknown";
    }
}


void saveTask ( Task task, FILE *file) {
    fwrite(&task, sizeof( Task ), 1, file);
}

void listTasks ( FILE *file ) {
    Task task;
    printf("\n||THIS IS YOU TASKS LIST||\n");
    
    while( fread( &task, sizeof( Task ), 1, file ) ){
        printf("\n|------------------------------------------|\n");
        printf("- TASK ID....: [%d]\n", task.id);
        printf("- TITLE......: %s\n", task.title);
        printf("- PRIORITY...: [%s]\n", returnPriority( task.priority ));
        printf("- STATUS.....: [%s]\n", returnStatus( task.status ));
        printf("- DESCRIPTION: %s\n", task.description);
        printf("\n|------------------------------------------|\n");
    }

    fclose( file );
}


int main(){
    FILE *output_file = fopen( "tasks.dat", "ab" );




    return 0;
}