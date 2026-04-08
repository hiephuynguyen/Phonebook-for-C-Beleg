#include "contacts.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "phonebook.txt"

tfv* head = NULL;

char* duplicate_string(const char* str){
    if(!str){
        return NULL;
    }

    char* copy = (char*) malloc(strlen(str)+1);

    if(copy){
        strcpy(copy,str);
    }

    return copy;
};

void tfn_Hinzufuegen(const char* Name, const char* Vorname, const char* Telefonnummer){
    tfv *new_contact = (tfv*) malloc(sizeof(tfv));
    if(!new_contact){
        printf("Fehler: Keine Speicherzuweisung möglich.\n");
        return;
    }


    new_contact->Name=duplicate_string(Name);
    new_contact->Vorname=duplicate_string(Vorname);
    new_contact->Telefonnummer=duplicate_string(Telefonnummer);

    new_contact->next = head;
    head = new_contact;
}

tfv* tfn_Suchen(const char *Name, const char *Vorname){
    tfv* temp = head;
    while(temp){
        if(strcmp(temp->Name, Name)==0 && strcmp(temp->Vorname, Vorname)==0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

