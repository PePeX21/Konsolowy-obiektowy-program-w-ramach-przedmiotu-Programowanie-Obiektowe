#include <iostream>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include "Virtual_Classes.h"
#include "generic_list.h"
#include <typeinfo> /// potrzebne do dynamic casta
using namespace std;


/// lista klas
Elektrownie elektrownie("Elektrownie");
Wodne wodne("Wodne");
Jadrowe jadrowe("Jadrowe");
Surowce_Naturalne surowceNaturalne("Surowce_Naturalne");
Weglowe weglowe("Weglowe");
Gazowe gazowe("Gazowe");
Ropa ropa("Ropa");
Brunatny brunatny("Brunatny");
Kamienny kamienny("Kamienny");
Kopalnia_Odkrywkowa kopalniaOdkrywkowa("Kopalnia_Odkrywkowa");
Kopalnia_Glebinowa kopalniaGlebinowa("Kopalnia_Glebinowa");
Elektrownie *base = &elektrownie;

void choose_the_node(string node,Elektrownie **ptr){
    if (node == "Elektrownie" || node == "elektrownie"){
        *ptr = &elektrownie;
    }
    else if (node == "Wodne" || node == "wodne"){
        *ptr = &wodne;
    }
    else if (node == "Jadrowe" || node == "jadrowe"){
        *ptr = &jadrowe;
    }
    else if (node == "Surowce_Naturalne" || node == "surowcenaturalne"){
        *ptr = &surowceNaturalne;
    }
    else if (node == "Weglowe" || node == "weglowe"){
        *ptr = &weglowe;
    }
    else if (node == "Gazowe" || node == "gazowe"){
        *ptr = &gazowe;
    }
    else if (node == "Ropa" || node == "ropa"){
        *ptr = &ropa;
    }
    else if (node == "Brunatny" || node == "brunatny"){
        *ptr = &brunatny;
    }
    else if (node == "kamienny" || node == "kamienny"){
        *ptr = &kamienny;
    }
    else if (node == "Kopalnia_Glebinowa" || node == "kopalniaglebinowa"){
        *ptr = &kopalniaGlebinowa;
    }
    else if (node == "Kopalnia_Odkrywkowa" || node == "kopalniaodkrywkowa"){
        *ptr = &kopalniaOdkrywkowa;
    }
    else{
        cout << "there is not such a node" << endl;
    }
}
void show_hereditary_objects(Elektrownie *ptr ){
    if (typeid(elektrownie).name() == typeid(*ptr).name()) {
        wodne.virtual_list_show_all();
        jadrowe.virtual_list_show_all();
        gazowe.virtual_list_show_all();
        ropa.virtual_list_show_all();
        kopalniaOdkrywkowa.virtual_list_show_all();
        kopalniaGlebinowa.virtual_list_show_all();
    }
    else if (typeid(wodne).name() == typeid(*ptr).name()) {
        wodne.virtual_list_show_all();
    }
    else if (typeid(jadrowe).name() == typeid(*ptr).name()) {
        jadrowe.virtual_list_show_all();
    }
    else if (typeid(surowceNaturalne).name() == typeid(*ptr).name()) {
        gazowe.virtual_list_show_all();
        ropa.virtual_list_show_all();
        kopalniaOdkrywkowa.virtual_list_show_all();
        kopalniaGlebinowa.virtual_list_show_all();
    }
    else if (typeid(weglowe).name() == typeid(*ptr).name()) {
        kopalniaOdkrywkowa.virtual_list_show_all();
        kopalniaGlebinowa.virtual_list_show_all();
    }
    else if (typeid(gazowe).name() == typeid(*ptr).name()) {
        gazowe.virtual_list_show_all();
    }
    else if (typeid(ropa).name() == typeid(*ptr).name()) {
        ropa.virtual_list_show_all();
    }
    else if (typeid(brunatny).name() == typeid(*ptr).name()) {
        kopalniaOdkrywkowa.virtual_list_show_all();
        kopalniaGlebinowa.virtual_list_show_all();
    }
    else if (typeid(kamienny).name() == typeid(*ptr).name()) {
        kopalniaGlebinowa.virtual_list_show_all();
    }
    else if (typeid(kopalniaOdkrywkowa).name() == typeid(*ptr).name()) {
        kopalniaOdkrywkowa.virtual_list_show_all();
    }
    else if (typeid(kopalniaGlebinowa).name() == typeid(*ptr).name()) {
        kopalniaGlebinowa.virtual_list_show_all();
    }
}
void show_object_from_hereditary(string object, Elektrownie *ptr){
    int counter = 0;
    if (typeid(elektrownie).name() == typeid(*ptr).name()) {
        counter += wodne.virtual_list_show_object(object);
        counter += jadrowe.virtual_list_show_object(object);
        counter += gazowe.virtual_list_show_object(object);
        counter += ropa.virtual_list_show_object(object);
        counter += kopalniaOdkrywkowa.virtual_list_show_object(object);
        counter += kopalniaGlebinowa.virtual_list_show_object(object);
    }
    else if (typeid(wodne).name() == typeid(*ptr).name()) {
        counter += wodne.virtual_list_show_object(object);
    }
    else if (typeid(jadrowe).name() == typeid(*ptr).name()) {
        counter += jadrowe.virtual_list_show_object(object);
    }
    else if (typeid(surowceNaturalne).name() == typeid(*ptr).name()) {
        counter += gazowe.virtual_list_show_object(object);
        counter += ropa.virtual_list_show_object(object);
        counter += kopalniaOdkrywkowa.virtual_list_show_object(object);
        counter += kopalniaGlebinowa.virtual_list_show_object(object);
    }
    else if (typeid(weglowe).name() == typeid(*ptr).name()) {
        counter += kopalniaOdkrywkowa.virtual_list_show_object(object);
        counter += kopalniaGlebinowa.virtual_list_show_object(object);
    }
    else if (typeid(gazowe).name() == typeid(*ptr).name()) {
        counter += gazowe.virtual_list_show_object(object);
    }
    else if (typeid(ropa).name() == typeid(*ptr).name()) {
        counter += ropa.virtual_list_show_object(object);
    }
    else if (typeid(brunatny).name() == typeid(*ptr).name()) {
        counter += kopalniaOdkrywkowa.virtual_list_show_object(object);
        counter += kopalniaGlebinowa.virtual_list_show_object(object);
    }
    else if (typeid(kamienny).name() == typeid(*ptr).name()) {
        counter += kopalniaGlebinowa.virtual_list_show_object(object);
    }
    else if (typeid(kopalniaOdkrywkowa).name() == typeid(*ptr).name()) {
        counter += kopalniaOdkrywkowa.virtual_list_show_object(object);
    }
    else if (typeid(kopalniaGlebinowa).name() == typeid(*ptr).name()) {
        counter += kopalniaGlebinowa.virtual_list_show_object(object);
    }
    if (counter == 0){
        cout << "there is not object with such a name" << endl;
    }
}
void show_tree(){
    cout << "\n";
   cout << "                    Elektrownie" << endl;
   cout << "    ________________/   /    |__________ " << endl;
   cout << "   /            /'''''''                |" << endl;
   cout << "Wodne       Jadrowe              Surowce_Naturalne" << endl;
   cout << "                           ______/      |       |____" << endl;
   cout << "                          /             |            |" << endl;
   cout << "                        Weglowe       Gazowe        Ropa" << endl;
   cout << "                   _____/    |___" << endl;
   cout << "                  /              |" << endl;
   cout << "              Brunatny         Kamienny" << endl;
   cout << "         _____/     |_____       |" << endl;
   cout << "        /                 \\      |" << endl;
   cout << "Kopalnia_Odkrywkowa       Kopalnia_Glebinowa" << endl;
}

class File_Operation{
public:
    void operator + (){
        fstream file;
        string name_of_file;

        cout << "give the name of file" << endl;
        cin >> name_of_file;
        getchar();
        file.open(name_of_file, ios::out | ios::app);
        file << typeid(wodne).name() << endl;
        while (wodne.list_of_object->first){
            file << wodne.list_of_object->first->Object.name << endl;
            file << wodne.list_of_object->first->Object.type_of_source << endl;
            file << wodne.list_of_object->first->Object.river << endl;
            wodne.list_of_object->first = wodne.list_of_object->first->next;
        }
        file << typeid(jadrowe).name() << endl;
        while (jadrowe.list_of_object->first) {
            file << jadrowe.list_of_object->first->Object.name << endl;
            file << jadrowe.list_of_object->first->Object.type_of_source << endl;
            file << jadrowe.list_of_object->first->Object.fuel << endl;
            jadrowe.list_of_object->first = jadrowe.list_of_object->first->next;
        }
        file << typeid(Gazowe).name() << endl;
        while (gazowe.list_of_object->first) {
            file << gazowe.list_of_object->first->Object.name << endl;
            file << gazowe.list_of_object->first->Object.type_of_source << endl;
            file << gazowe.list_of_object->first->Object.natural_source << endl;
            file << gazowe.list_of_object->first->Object.type_of_gas << endl;
            gazowe.list_of_object->first = gazowe.list_of_object->first->next;
        }
        file << typeid(Ropa).name() << endl;
        while (ropa.list_of_object->first) {
            file << ropa.list_of_object->first->Object.name << endl;
            file << ropa.list_of_object->first->Object.type_of_source << endl;
            file << ropa.list_of_object->first->Object.natural_source << endl;
            file << ropa.list_of_object->first->Object.weight << endl;
            ropa.list_of_object->first = ropa.list_of_object->first->next;
        }
        file << typeid(Kopalnia_Odkrywkowa).name() << endl;
        while (kopalniaOdkrywkowa.list_of_object->first) {
            file << kopalniaOdkrywkowa.list_of_object->first->Object.name << endl;
            file << kopalniaOdkrywkowa.list_of_object->first->Object.type_of_source << endl;
            file << kopalniaOdkrywkowa.list_of_object->first->Object.natural_source << endl;
            file << kopalniaOdkrywkowa.list_of_object->first->Object.type_of_coal << endl;
            file << kopalniaOdkrywkowa.list_of_object->first->Object.type_of_mine << endl;
            file << kopalniaOdkrywkowa.list_of_object->first->Object.surface << endl;
            kopalniaOdkrywkowa.list_of_object->first = kopalniaOdkrywkowa.list_of_object->first->next;
        }
        file << typeid(Kopalnia_Glebinowa).name() << endl;
        while (kopalniaGlebinowa.list_of_object->first) {
            file << kopalniaGlebinowa.list_of_object->first->Object.name << endl;
            file << kopalniaGlebinowa.list_of_object->first->Object.type_of_source << endl;
            file << kopalniaGlebinowa.list_of_object->first->Object.natural_source << endl;
            file << kopalniaGlebinowa.list_of_object->first->Object.type_of_coal << endl;
            file << kopalniaGlebinowa.list_of_object->first->Object.Kamienny::type_of_mine << endl;
            file << kopalniaGlebinowa.list_of_object->first->Object.depth << endl;
            kopalniaGlebinowa.list_of_object->first = kopalniaGlebinowa.list_of_object->first->next;
        }
        file.close();
    }
    void operator - (){
        fstream file;
        string name_of_file;
        string tmp;

        cout << "give the name of file" << endl;
        cin >> name_of_file;
        getchar();
        file.open(name_of_file, ios::in);
        if(file.good() == false){
            cout << "file doesnt exist" << endl;
            return;
        }
        file >> tmp;
        if(tmp == typeid(wodne).name()){
            while(true){
                file >> tmp;
                if(tmp == typeid(jadrowe).name()){
                    break;
                }
                element<Wodne> *new_elem = new element<Wodne>;
                new_elem->Object.name = tmp;
                file >> new_elem->Object.type_of_source;
                file >> new_elem->Object.river;

                if (wodne.list_of_object->first == 0){ // first elem
                    wodne.list_of_object->first = new_elem;
                }
                else{ // add at the end
                    element<Wodne> *temp = wodne.list_of_object->first;
                    while (temp->next){
                        temp = temp->next;
                    }
                    temp->next = new_elem;
                    new_elem->next = 0;
                }
            }

            while(true){
                file >> tmp;
                if(tmp == typeid(gazowe).name()){
                    break;
                }

                element<Jadrowe> *new_elem = new element<Jadrowe>;
                new_elem->Object.name = tmp;
                file >> new_elem->Object.type_of_source;
                file >> new_elem->Object.fuel;

                if (jadrowe.list_of_object->first == 0){ // first elem
                    jadrowe.list_of_object->first = new_elem;
                }
                else{ // add at the end
                    element<Jadrowe> *temp = jadrowe.list_of_object->first;
                    while (temp->next){
                        temp = temp->next;
                    }
                    temp->next = new_elem;
                    new_elem->next = 0;
                }
            }

            while(true){
                file >> tmp;
                if(tmp == typeid(ropa).name()){
                    break;
                }

                element<Gazowe> *new_elem = new element<Gazowe>;
                new_elem->Object.name = tmp;
                file >> new_elem->Object.type_of_source;
                file >> new_elem->Object.natural_source;
                file >> new_elem->Object.type_of_gas;

                if (gazowe.list_of_object->first == 0){ // first elem
                    gazowe.list_of_object->first = new_elem;
                }
                else{ // add at the end
                    element<Gazowe> *temp = gazowe.list_of_object->first;
                    while (temp->next){
                        temp = temp->next;
                    }
                    temp->next = new_elem;
                    new_elem->next = 0;
                }
            }

            while(true){
                file >> tmp;
                if(tmp == typeid(kopalniaOdkrywkowa).name()){
                    break;
                }
                element<Ropa> *new_elem = new element<Ropa>;
                new_elem->Object.name = tmp;
                file >> new_elem->Object.type_of_source;
                file >> new_elem->Object.natural_source;
                file >> new_elem->Object.weight;

                if (ropa.list_of_object->first == 0){ // first elem
                    ropa.list_of_object->first = new_elem;
                }
                else{ // add at the end
                    element<Ropa> *temp = ropa.list_of_object->first;
                    while (temp->next){
                        temp = temp->next;
                    }
                    temp->next = new_elem;
                    new_elem->next = 0;
                }
            }

            while(true){
                file >> tmp;
                if(tmp == typeid(kopalniaGlebinowa).name()){
                    break;
                }

                element<Kopalnia_Odkrywkowa> *new_elem = new element<Kopalnia_Odkrywkowa>;
                new_elem->Object.name = tmp;
                file >> new_elem->Object.type_of_source;
                file >> new_elem->Object.natural_source;
                file >> new_elem->Object.type_of_coal;
                file >> new_elem->Object.type_of_mine;
                file >> new_elem->Object.surface;

                if (kopalniaOdkrywkowa.list_of_object->first == 0){ // first elem
                    kopalniaOdkrywkowa.list_of_object->first = new_elem;
                }
                else{ // add at the end
                    element<Kopalnia_Odkrywkowa> *temp = kopalniaOdkrywkowa.list_of_object->first;
                    while (temp->next){
                        temp = temp->next;
                    }
                    temp->next = new_elem;
                    new_elem->next = 0;
                }
            }

            while(true){
                if(!(file >> tmp)){
                    if(tmp == typeid(wodne).name()){
                        break;
                    }
                    break;
                }
                element<Kopalnia_Glebinowa> *new_elem = new element<Kopalnia_Glebinowa>;
                new_elem->Object.name = tmp;
                file >> new_elem->Object.type_of_source;
                file >> new_elem->Object.natural_source;
                file >> new_elem->Object.type_of_coal;
                file >> new_elem->Object.Kamienny::type_of_mine;
                file >> new_elem->Object.depth;

                if (kopalniaGlebinowa.list_of_object->first == 0){ // first elem
                    kopalniaGlebinowa.list_of_object->first = new_elem;
                }
                else{ // add at the end
                    element<Kopalnia_Glebinowa> *temp = kopalniaGlebinowa.list_of_object->first;
                    while (temp->next){
                        temp = temp->next;
                    }
                    temp->next = new_elem;
                    new_elem->next = 0;
                }
            }
        }
        file.close();
    }

};

int main() {
    File_Operation F;
    bool exit = true;
    string choose;
    string tmp;
    while (exit) {
        cout << "\n CURRENT NODE: " << base->return_name() << endl;
        cout << "write the operation from the list:" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "CD[node]    -change of node in the structure" << endl;
        cout << "MO[object]  -creates an object to the current leaf" << endl;
        cout << "DO[object]  -removes the object to the current leaf" << endl;
        cout << "MDO[object] -modification of the object for the current leaf" << endl;
        cout << "DIR         -displays information about objects visible from a given level" << endl;
        cout << "SHOW[object]-displays detailed information about the object" << endl;
        cout << "SAVE        -saving a collection to a file" << endl;
        cout << "READ        -read a collection from a file" << endl;
        cout << "TREE        -displays the entire structure" << endl;
        cout << "EXIT        -to finish" << endl << endl;
        fflush(stdin);
        fflush(stdout);
        cin >> choose;
        getchar();
        system("cls");

        if (choose == "CD") {
            cin >> tmp;
            getchar();
            choose_the_node(tmp, &base);
        } else if (choose == "MO") {
            cin >> tmp;
            getchar();
            base->virtual_list_add(tmp); /// parametry tez przy tworzeniu
        } else if (choose == "DO") {
            cin >> tmp;
            getchar();
            base->virtual_list_remove(tmp);
        } else if (choose == "MDO") {
            cin >> tmp;
            getchar();
            base->virtual_list_modify_object(tmp);
        } else if (choose == "DIR") {
            show_hereditary_objects(base);
        } else if (choose == "SHOW") {
            cin >> tmp;
            getchar();
            show_object_from_hereditary(tmp ,base);
        } else if (choose == "SAVE") {
            +F;
        } else if (choose == "READ") {
            -F;
        } else if (choose == "TREE") {
            show_tree();
        } else if (choose == "EXIT"){
            exit = false;
        } else{
            cout << "unknown command" << endl;

        }
    }
    return 0;
}
