#ifndef PO_GENERIC_LIST_H
#define PO_GENERIC_LIST_H

#include <iostream>
using namespace std;

template <typename T> struct element{
    T Object;
    element *next;
    element(){
        next = 0;
    }
};
template <typename T> struct list {
    element<T> *first;
    list(){
        first = 0;
    }
    void add(string new_name){
        element<T> *new_elem = new element<T>;

        new_elem->Object.rename(new_name);
        new_elem->Object.modify();
        if (first == 0){ // first elem
            first = new_elem;
        }
        else{ // add at the end
            element<T> *temp = first;

            while (temp->next){
                temp = temp->next;
            }

            temp->next = new_elem;
            new_elem->next = 0;
        }
    }
    void remove(string name){
        if(first == 0){ //empty
            cout << "the list is empty" << endl;
            return;
        }

        element<T> *temp = first;
        if (temp->next == 0){ // only 1 element on list
            if (name ==  temp->Object.return_name()) {
                first = temp->next;
                delete temp;
            }
            else{
                cout << "there is no object with the given name" << endl;
            }
        }
        else if (name ==  temp->Object.return_name()){ // first elem on multiple list
            first = temp->next;
            delete temp;
        }
        else{
            while (temp->next->next) {
                if (name ==  temp->next->Object.return_name()) break;
                temp = temp->next;
            }

            if (temp->next->next == 0) { // last elem
                if ( name ==  temp->next->Object.return_name() ){
                    delete temp->next;
                    temp->next = 0;
                }
                else{
                    /// cout << "there is no object with the given name" << endl;
                }
            }
            else { // middle elem
                element<T> *to_delete = temp->next;
                temp->next = temp->next->next;
                delete to_delete;
            }
        }
    }
    void show_all(){
        element<T> *temp = first;

        while (temp){
            temp->Object.give_name();
            cout << endl;
            temp = temp->next;
        }
    }
    int show_object(string name){
        element<T> *temp = first;

        while (temp){
            if(temp->Object.return_name() == name ){
                temp->Object.show();
                cout << endl;
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
    void modify_object(string name){
        string tmp;
        char choice;
        element<T> *temp = first;

        while (temp){
            if(temp->Object.return_name() == name ){
                cout << "do you want to rename object ? n/y" << endl;
                cin >> choice;
                getchar();
                if (choice == 'y'){
                    cout << "enter name" << endl;
                    cin >> tmp;
                    getchar();
                    if(tmp == ""){
                        tmp = "puste";
                    }
                    temp->Object.rename(tmp);
                }
                temp->Object.modify();
                return;
            }
            temp = temp->next;
        }
        cout << "there is no an object" << endl;
    }
};

#endif //PO_GENERIC_LIST_H
