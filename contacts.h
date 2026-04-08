#ifndef CONTACTS_H
#define CONTACTS_H

typedef struct contact {
    char* Name;
    char* Vorname;
    char* Telefonmnummer;
    struct contact*next;
} tfv; //tfv = Telefonverzeichnis

extern tfv* head;

void tfn_Hinzufuegen(const char* Name, const char* vorname, const char* telefonnummer);
tfv *tfn_Suchen(const char* Name, const char* Vorname);
void tfn_Loeschen(const char* Name, const char* Vorname,const char* Telefonnummer);

void tff_Anzeigen();
void tfv_Speichern();
void tfv_Laden();
void tfv_Freigeben();

#endif // CONTACTS_H

