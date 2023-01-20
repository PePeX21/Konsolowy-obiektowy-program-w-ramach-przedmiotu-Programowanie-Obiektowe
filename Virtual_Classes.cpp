#include <iostream>
#include "Virtual_Classes.h"
#include "generic_list.h"

using namespace std;

/// VIRTUAL CLASSES
Elektrownie::Elektrownie() { /// jakby cos zaczelo sie piepszyc to tu zmienilem leaf= false /////////////////////////////////////
    leaf = false;
}
Elektrownie::Elektrownie(string class_name) {
    leaf = false;
    name = class_name;
}
void Elektrownie::virtual_show(){
    cout << "name of object:\t" << name <<endl;
    //cout << "company:\t" << company << endl;
    //cout << "country:\t" << country << endl;
    cout << "type of source:\t" << type_of_source << endl;
}
void Elektrownie::virtual_modify(){
    char choice;
    string new_name;
    /*
    cout << "do you want change company ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter name" << endl;
        cin >> new_name;
        company = new_name;
    }
    cout << "do you want chane country ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter name" << endl;
        cin >> new_name;
        country = new_name;
    }
     */
    cout << "do you want change type of source ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter name" << endl;
        cin >> new_name;
        type_of_source = new_name;
    }
};
bool Elektrownie::virtual_return_leaf() {
    return leaf;
}

void Elektrownie::rename(string new_name) {
    if (virtual_return_leaf()) {
        name = new_name;
    }
    else{
        cout << "class is not a leaf" << endl;
    }
}
void Elektrownie::give_name() {
    if (virtual_return_leaf()) {
        cout << "object: " << name << endl;
    }
    else{
        cout << "class is not a leaf, it has not name" << endl;
    }
}
string Elektrownie::return_name() {
    return name;
}
void Elektrownie::show(){
    if (virtual_return_leaf()){
        virtual_show();
    }
    else{
        cout << "you can not show properties\nclass is not a leaf" << endl;
    }
}
void Elektrownie::modify() {
    if (virtual_return_leaf()){
        virtual_modify();
    }
    else{
        cout << "you can not change properties and creat object" << endl;
    }
}

void Elektrownie::virtual_list_add(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->add(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Elektrownie::virtual_list_remove(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->remove(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Elektrownie::virtual_list_show_all(){
    list_of_object->show_all();
}
int Elektrownie::virtual_list_show_object(string tmp){
    return list_of_object->show_object(tmp);
}
void Elektrownie::virtual_list_modify_object(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->modify_object(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}


Surowce_Naturalne::Surowce_Naturalne():Elektrownie() {
    leaf = false;
    type_of_source = "Surowce_Naturalne";
}
Surowce_Naturalne::Surowce_Naturalne(string class_name) {
    leaf = false;
    name = class_name;
}
void Surowce_Naturalne::virtual_show(){
    Elektrownie::virtual_show();
    cout << "natural source:\t" <<natural_source << endl;
}
void Surowce_Naturalne::virtual_modify() {
    Elektrownie::virtual_modify();
    char choice;
    string new_name;
    cout << "do you want change natural source ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter name" << endl;
        cin >> new_name;
        natural_source = new_name;
    }
}
bool Surowce_Naturalne::virtual_return_leaf() {
    return leaf;
}

void Surowce_Naturalne::virtual_list_add(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->add(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Surowce_Naturalne::virtual_list_remove(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->remove(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Surowce_Naturalne::virtual_list_show_all(){
    list_of_object->show_all();
}
int Surowce_Naturalne::virtual_list_show_object(string tmp){
    return list_of_object->show_object(tmp);
}
void Surowce_Naturalne::virtual_list_modify_object(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->modify_object(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}


Weglowe::Weglowe():Surowce_Naturalne() {
    leaf = false;
    natural_source = "Wegiel";
}
Weglowe::Weglowe(string class_name) {
    leaf = false;
    name = class_name;
}
void Weglowe::virtual_show() {
    Surowce_Naturalne::virtual_show();
    cout << "type of coal:\t" << type_of_coal << endl;
}
void Weglowe::virtual_modify(){
    Surowce_Naturalne::virtual_modify();
    char choice;
    string new_name;
    cout << "do you want change type of coal ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter name" << endl;
        cin >> new_name;
        type_of_coal = new_name;
    }
};
bool Weglowe::virtual_return_leaf() {
    return leaf;
}

void Weglowe::virtual_list_add(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->add(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Weglowe::virtual_list_remove(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->remove(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Weglowe::virtual_list_show_all(){
    list_of_object->show_all();
}
int Weglowe::virtual_list_show_object(string tmp){
    return list_of_object->show_object(tmp);
}
void Weglowe::virtual_list_modify_object(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->modify_object(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}

Brunatny::Brunatny():Weglowe() {
    leaf = false;
    type_of_coal = "Brunatny";
}
Brunatny::Brunatny(string class_name) {
    leaf = false;
    name = class_name;
}
void Brunatny::virtual_show() {
    Weglowe::virtual_show();
    cout << "type of mine:\t" << type_of_mine << endl;
}
void Brunatny::virtual_modify() {
    Weglowe::virtual_modify();
    char choice;
    string new_name;
    cout << "do you want change type of mine ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter name" << endl;
        cin >> new_name;
        type_of_mine = new_name;
    }
}
bool Brunatny::virtual_return_leaf() {
    return leaf;
}

void Brunatny::virtual_list_add(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->add(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Brunatny::virtual_list_remove(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->remove(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Brunatny::virtual_list_show_all(){
    list_of_object->show_all();
}
int Brunatny::virtual_list_show_object(string tmp){
    return list_of_object->show_object(tmp);
}
void Brunatny::virtual_list_modify_object(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->modify_object(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}

Kamienny::Kamienny():Weglowe() {
    leaf = false;
    type_of_coal = "Kamienny";
}
Kamienny::Kamienny(string class_name) {
    leaf = false;
    name = class_name;
}
void Kamienny::virtual_show() {
    Weglowe::virtual_show();
    cout << "type of mine:\t" << type_of_mine << endl;
}
void Kamienny::virtual_modify() {
    Weglowe::virtual_modify();
    char choice;
    string new_name;
    cout << "do you want change type of mine ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter name" << endl;
        cin >> new_name;
        type_of_mine = new_name;
    }
}
bool Kamienny::virtual_return_leaf() {
    return leaf;
}

void Kamienny::virtual_list_add(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->add(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Kamienny::virtual_list_remove(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->remove(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Kamienny::virtual_list_show_all(){
    list_of_object->show_all();
}
int Kamienny::virtual_list_show_object(string tmp){
    return list_of_object->show_object(tmp);
}
void Kamienny::virtual_list_modify_object(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->modify_object(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
/// LEAF CLASSES
Wodne::Wodne():Elektrownie() {
    leaf = true;
    type_of_source = "Wodne";
}
Wodne::Wodne(string class_name) {
    leaf = true;
    name = class_name;
}
void Wodne::virtual_show() {
    Elektrownie::virtual_show();
    cout << "river:\t" << river << endl;
}
void Wodne::virtual_modify() {
    Elektrownie::virtual_modify();
    char choice;
    string new_name;
    cout << "do you want change river ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter name" << endl;
        cin >> new_name;
        river = new_name;
    }
}
bool Wodne::virtual_return_leaf() {
    return leaf;
}

void Wodne::virtual_list_add(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->add(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Wodne::virtual_list_remove(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->remove(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Wodne::virtual_list_show_all(){
    list_of_object->show_all();
}
int Wodne::virtual_list_show_object(string tmp){
    return list_of_object->show_object(tmp);
}
void Wodne::virtual_list_modify_object(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->modify_object(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}

Jadrowe::Jadrowe():Elektrownie() {
    leaf = true;
    type_of_source = "Jadrowe";
}
Jadrowe::Jadrowe(string class_name) {
    leaf = true;
    name = class_name;
}
void Jadrowe::virtual_show() {
    Elektrownie::virtual_show();
    cout << "fuel:\t" << fuel << endl;
}
void Jadrowe::virtual_modify() {
    Elektrownie::virtual_modify();
    char choice;
    string new_name;
    cout << "do you want change fuel ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter name" << endl;
        cin >> new_name;
        fuel = new_name;
    }
}
bool Jadrowe::virtual_return_leaf() {
    return leaf;
}

void Jadrowe::virtual_list_add(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->add(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Jadrowe::virtual_list_remove(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->remove(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Jadrowe::virtual_list_show_all(){
    list_of_object->show_all();
}
int  Jadrowe::virtual_list_show_object(string tmp){
    return list_of_object->show_object(tmp);
}
void Jadrowe::virtual_list_modify_object(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->modify_object(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}

Gazowe::Gazowe():Surowce_Naturalne() {
    leaf = true;
    natural_source = "Gazowe";
}
Gazowe::Gazowe(string class_name) {
    leaf = true;
    name = class_name;
}
void Gazowe::virtual_show() {
    Surowce_Naturalne::virtual_show();
    cout << "type of gas:\t" << type_of_gas << endl;
}
void Gazowe::virtual_modify() {
    Surowce_Naturalne::virtual_modify();
    char choice;
    string new_name;
    cout << "do you want change type of gas ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter name" << endl;
        cin >> new_name;
        type_of_gas = new_name;
    }
}
bool Gazowe::virtual_return_leaf() {
    return leaf;
}

void Gazowe::virtual_list_add(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->add(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Gazowe::virtual_list_remove(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->remove(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Gazowe::virtual_list_show_all(){
    list_of_object->show_all();
}
int  Gazowe::virtual_list_show_object(string tmp){
    return list_of_object->show_object(tmp);
}
void Gazowe::virtual_list_modify_object(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->modify_object(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}

Ropa::Ropa():Surowce_Naturalne() {
    leaf = true;
    natural_source = "Ropa";
}
Ropa::Ropa(string class_name) {
    leaf = true;
    name = class_name;
}
void Ropa::virtual_show() {
    Surowce_Naturalne::virtual_show();
    cout << "weight:\t" << weight << endl;
}
void Ropa::virtual_modify() {
    Surowce_Naturalne::virtual_modify();
    char choice;
    string new_name;
    cout << "do you want change weight ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter number" << endl;
        cin >> new_name;
        weight = new_name;
    }
}
bool Ropa::virtual_return_leaf() {
    return leaf;
}

void Ropa::virtual_list_add(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->add(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Ropa::virtual_list_remove(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->remove(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Ropa::virtual_list_show_all(){
    list_of_object->show_all();
}
int Ropa::virtual_list_show_object(string tmp){
    return list_of_object->show_object(tmp);
}
void Ropa::virtual_list_modify_object(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->modify_object(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}

Kopalnia_Odkrywkowa::Kopalnia_Odkrywkowa():Brunatny() {
    leaf = true;
    type_of_mine = "Kopalnia_odkrywkowa";
}
Kopalnia_Odkrywkowa::Kopalnia_Odkrywkowa(string class_name) {
    leaf = true;
    name = class_name;
}
void Kopalnia_Odkrywkowa::virtual_show() {
    Brunatny::virtual_show();
    cout << "surface:\t" << surface << endl;
}
void Kopalnia_Odkrywkowa::virtual_modify() {
    Brunatny::virtual_modify();
    char choice;
    string new_name;
    cout << "do you want change type surface ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter name" << endl;
        cin >> new_name;
        surface = new_name;
    }
}
bool Kopalnia_Odkrywkowa::virtual_return_leaf() {
    return leaf;
}

void Kopalnia_Odkrywkowa::virtual_list_add(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->add(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Kopalnia_Odkrywkowa::virtual_list_remove(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->remove(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Kopalnia_Odkrywkowa::virtual_list_show_all(){
    list_of_object->show_all();
}
int Kopalnia_Odkrywkowa::virtual_list_show_object(string tmp){
    return list_of_object->show_object(tmp);
}
void Kopalnia_Odkrywkowa::virtual_list_modify_object(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->modify_object(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}

Kopalnia_Glebinowa::Kopalnia_Glebinowa(): Kamienny(), Brunatny() { /// diamend
    leaf = true;
    Kamienny::type_of_mine = "kopalnia_glebinowy";
    Brunatny::type_of_mine = Kamienny::type_of_mine;
}
Kopalnia_Glebinowa::Kopalnia_Glebinowa(string class_name) {
    leaf = true;
    name = class_name;
}
void Kopalnia_Glebinowa::virtual_show() {
    Brunatny::virtual_show();
    cout << "depth:\t\t" << depth << endl;
}
void Kopalnia_Glebinowa::virtual_modify() {
    Brunatny::virtual_modify();
    char choice;
    string new_name;
    cout << "do you want change depth ? n/y" << endl;
    cin >> choice;
    if (choice == 'y'){
        cout << "enter number" << endl;
        cin >> new_name;
        depth = new_name;
    }
}
bool Kopalnia_Glebinowa::virtual_return_leaf() {
    return leaf;
}

void Kopalnia_Glebinowa::virtual_list_add(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->add(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Kopalnia_Glebinowa::virtual_list_remove(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->remove(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}
void Kopalnia_Glebinowa::virtual_list_show_all(){
    list_of_object->show_all();
}
int  Kopalnia_Glebinowa::virtual_list_show_object(string tmp){
    return list_of_object->show_object(tmp);
}
void Kopalnia_Glebinowa::virtual_list_modify_object(string tmp){
    if (virtual_return_leaf()) {
        list_of_object->modify_object(tmp);
    }
    else{
        cout << "class is not a leaf, operation prohibited" << endl;
    }
}