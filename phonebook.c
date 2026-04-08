#include "contacts.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strip_newLine(char *str){
    size_t len = strlen(str);
    if(len > 0 && str[len-1] == '\n'){
        str[len-1] = '\0';
    }
}

int main(){
    int choice;
    char name[256], vorname[256], telefonnummer[256];

    tfv_Laden();

    while(1){
        printf("\n======= Telefonbuch =======\n");
        printf("1. Hinzufuegen\n");
        printf("2. Suchen\n");
        printf("3. Loeschen\n");
        printf("4. Alle Anzeigen\n");
        printf("5. Beenden\n");
        printf("Waehlen Sie eine Option (1-5): ");


        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                printf("Name: ");
                fgets(name, sizeof(name), stdin);
                strip_newline(name);

                printf("Vorname: ");
                fgets(vorname, sizeof(vorname), stdin);
                strip_newline(vorname);

                printf("Telefonnummer: ");
                fgets(telefonnummer, sizeof(telefonnummer), stdin);
                strip_newline(telefonnummer);

                tfn_Hinzufuegen(name, vorname, telefonnummer);
                printf("Erfolgreich hinzugefuegt.\n");
                break;

            case 2:
                printf("Name: ");
                fgets(name, sizeof(name), stdin);
                strip_newline(name);

                printf("Vorname: ");
                fgets(vorname, sizeof(vorname), stdin);
                strip_newline(vorname);

                tfv *result = tfn_Suchen(name, vorname);
                if (result) {
                    printf("\nGefunden: %s %s: %s\n", result->Name, result->Vorname, result->Telefonnummer);
                } else {
                    printf("\nKontakt nicht gefunden.\n");
                }
                break;

            case 3:
                printf("Name: ");
                fgets(name, sizeof(name), stdin);
                strip_newline(name);

                printf("Vorname: ");
                fgets(vorname, sizeof(vorname), stdin);
                strip_newline(vorname);

                printf("Telefonnummer: ");
                fgets(telefonnummer, sizeof(telefonnummer), stdin);
                strip_newline(telefonnummer);

                tfn_Loeschen(name, vorname, telefonnummer);
                break;

            case 4:
                tfv_Anzeigen();
                break;

            case 5:
                tfv_Speichern();
                tfv_Freigeben(); 
                printf("Programm beendet.\n");
                return 0;

            default:
                printf("Ungueltige Auswahl. Bitte versuchen Sie es erneut.\n");
        }
    }

    return 0;
}