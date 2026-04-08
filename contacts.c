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

void tfn_Loeschen(const char* Name, const char* Vorname, const char* Telefonnummer){
    tfv* temp = head;
    tfv* prev = NULL;

    while(temp!= NULL){
        if(strcmp(temp->Name, Name)==0 && 
           strcmp(temp->Vorname, Vorname)==0 && 
           strcmp(temp->Telefonnummer, Telefonnummer)==0){

            if(prev==NULL){
                head = temp->next;
            }else{
                prev->next=temp->next;
            }

            tfv* to_delete = temp;
            temp = temp->next;

            free(to_delete->Name);
            free(to_delete->Vorname);
            free(to_delete->Telefonnummer);
            free(to_delete);
            printf("Kontakt gelöscht: %s %s\n", Name, Vorname);
        } else {
            prev=temp;
            temp=temp->next;
        }
    }
}

void tfv_Anzeigen() {
    printf("\n--- Telefonsverzeichnis ---\n");
    tfv *temp = head;
    if (!temp) {
        printf("Keine Telefonnummer\n");
        return;
    }

    while (temp) {
        printf("%s %s %s\n", temp->Name, temp->Vorname, temp->Telefonnummer);
        temp = temp->next;
    }
    printf("---------------------------\n");
}

void tfv_Speichern() {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("Kann %s nicht oeffnen\n", FILE_NAME);
        return;
    }

    tfv *temp = head;
    while (temp) {
        fprintf(file, "%s,%s,%s\n", temp->Name, temp->Vorname, temp->Telefonnummer);
        temp = temp->next;
    }

    fclose(file);
}

void tfv_Laden() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        // Tệp có thể chưa tồn tại ở lần chạy đầu, không cần in lỗi quá gắt
        return; 
    }

    // Đọc vào mảng tạm tĩnh, sau đó hàm Hinzufuegen sẽ cấp phát động
    char Name[256], Vorname[256], Telefonnummer[256];
    while (fscanf(file, "%255[^,],%255[^,],%255[^\n]\n", Name, Vorname, Telefonnummer) == 3) {
        tfn_Hinzufuegen(Name, Vorname, Telefonnummer);
    }

    fclose(file);
}


void tfv_Freigeben() {
    tfv *temp = head;
    while (temp) {
        tfv *to_delete = temp;
        temp = temp->next;
        free(to_delete->Name);
        free(to_delete->Vorname);
        free(to_delete->Telefonnummer);
        free(to_delete);
    }
    head = NULL;
}