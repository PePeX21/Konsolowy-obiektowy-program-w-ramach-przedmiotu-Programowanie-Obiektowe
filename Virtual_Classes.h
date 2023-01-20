#ifndef PO_VIRTUAL_CLASSES_H
#define PO_VIRTUAL_CLASSES_H

#include <iostream>
#include "generic_list.h"
using namespace std;
class File_Operation;
/// Virtual Classes
class Elektrownie {
private:
    bool leaf;
    list<Elektrownie> *list_of_object = new list<Elektrownie>;
protected:
    string name;
    //string company = "unknown";
    //string country = "unknown";
    string type_of_source = "mixed";

    virtual void virtual_show();
    virtual void virtual_modify();
    virtual bool virtual_return_leaf();


public:
    Elektrownie();
    Elektrownie(string);
    void give_name();
    string return_name();
    void rename(string);
    void show();
    void modify();

    virtual void virtual_list_add(string);
    virtual void virtual_list_remove(string);
    virtual void virtual_list_show_all();
    virtual int virtual_list_show_object(string);
    virtual void virtual_list_modify_object(string);

    friend File_Operation;
};

class Surowce_Naturalne : public Elektrownie {
private:
    bool leaf;
    list<Surowce_Naturalne> *list_of_object = new list<Surowce_Naturalne>;
protected:
    string natural_source = "mixed";

    void virtual_show() override;
    void virtual_modify() override;
    bool virtual_return_leaf() override;
public:
    Surowce_Naturalne();
    Surowce_Naturalne(string);
    virtual void virtual_list_add(string);
    virtual void virtual_list_remove(string);
    virtual void virtual_list_show_all();
    virtual int virtual_list_show_object(string);
    virtual void virtual_list_modify_object(string);

    friend File_Operation;
};

class Weglowe : public Surowce_Naturalne {
private:
    bool leaf;
    list<Weglowe> *list_of_object = new list<Weglowe>;
protected:
    string type_of_coal = "mixed";

    void virtual_show() override;
    void virtual_modify()override;
    bool virtual_return_leaf() override;
public:
    Weglowe();
    Weglowe(string);
    virtual void virtual_list_add(string);
    virtual void virtual_list_remove(string);
    virtual void virtual_list_show_all();
    virtual int virtual_list_show_object(string);
    virtual void virtual_list_modify_object(string);

    friend File_Operation;
};

class Brunatny : public virtual Weglowe {
private:
    bool leaf;
    list<Brunatny> *list_of_object = new list<Brunatny>;
protected:
    string type_of_mine = "mixed";

    void virtual_show() override;
    void virtual_modify() override;
    bool virtual_return_leaf() override;
public:
    Brunatny();
    Brunatny(string);
    virtual void virtual_list_add(string);
    virtual void virtual_list_remove(string);
    virtual void virtual_list_show_all();
    virtual int virtual_list_show_object(string);
    virtual void virtual_list_modify_object(string);

    friend File_Operation;
};

class Kamienny : public virtual Weglowe {
private:
    bool leaf;
    list<Kamienny> *list_of_object = new list<Kamienny>;
protected:
    string type_of_mine = "mixed";

    void virtual_show() override;
    void virtual_modify() override;
    bool virtual_return_leaf() override;
public:
    Kamienny();
    Kamienny(string);
    virtual void virtual_list_add(string);
    virtual void virtual_list_remove(string);
    virtual void virtual_list_show_all();
    virtual int virtual_list_show_object(string);
    virtual void virtual_list_modify_object(string);

    friend File_Operation;
};


/// LEAF CLASSES
class Wodne : public Elektrownie {
private:
    bool leaf;
    list<Wodne> *list_of_object = new list<Wodne>;
protected:
    string river = "unknown";

    void virtual_show() override;
    void virtual_modify() override;
    bool virtual_return_leaf() override;
public:
    Wodne();
    Wodne(string);
    virtual void virtual_list_add(string);
    virtual void virtual_list_remove(string);
    virtual void virtual_list_show_all();
    virtual int virtual_list_show_object(string);
    virtual void virtual_list_modify_object(string);

    friend File_Operation;
};

class Jadrowe : public Elektrownie {
private:
    bool leaf;
    list<Jadrowe> *list_of_object = new list<Jadrowe>;
protected:
    string fuel = "unknown";

    void virtual_show() override;
    void virtual_modify() override;
    bool virtual_return_leaf() override;
public:
    Jadrowe();
    Jadrowe(string);
    virtual void virtual_list_add(string);
    virtual void virtual_list_remove(string);
    virtual void virtual_list_show_all();
    virtual int virtual_list_show_object(string);
    virtual void virtual_list_modify_object(string);

    friend File_Operation;
};

class Gazowe : public Surowce_Naturalne {
private:
    bool leaf;
    list<Gazowe> *list_of_object = new list<Gazowe>;
protected:
    string type_of_gas = "unknown";

    void virtual_show() override;
    void virtual_modify() override;
    bool virtual_return_leaf() override;
public:
    Gazowe();
    Gazowe(string);
    virtual void virtual_list_add(string);
    virtual void virtual_list_remove(string);
    virtual void virtual_list_show_all();
    virtual int virtual_list_show_object(string);
    virtual void virtual_list_modify_object(string);

    friend File_Operation;
};

class Ropa : public Surowce_Naturalne {
private:
    bool leaf;
    list<Ropa> *list_of_object = new list<Ropa>;
protected:
    string weight = "unknown_(leight/middle/heavy)";

    void virtual_show() override;
    void virtual_modify() override;
    bool virtual_return_leaf() override;
public:
    Ropa();
    Ropa(string);
    virtual void virtual_list_add(string);
    virtual void virtual_list_remove(string);
    virtual void virtual_list_show_all();
    virtual int virtual_list_show_object(string);
    virtual void virtual_list_modify_object(string);

    friend File_Operation;
};

class Kopalnia_Odkrywkowa : public Brunatny{
private:
    bool leaf;
    list<Kopalnia_Odkrywkowa> *list_of_object = new list<Kopalnia_Odkrywkowa>;
protected:
    string surface = "unknown";

    void virtual_show() override;
    void virtual_modify() override;
    bool virtual_return_leaf() override;
public:
    Kopalnia_Odkrywkowa();
    Kopalnia_Odkrywkowa(string);
    virtual void virtual_list_add(string);
    virtual void virtual_list_remove(string);
    virtual void virtual_list_show_all();
    virtual int virtual_list_show_object(string);
    virtual void virtual_list_modify_object(string);

    friend File_Operation;
};

class Kopalnia_Glebinowa : public Kamienny, public Brunatny{
private:
    bool leaf;
    list<Kopalnia_Glebinowa> *list_of_object = new list<Kopalnia_Glebinowa>;
protected:
    string depth = "unknown";

    void virtual_show() override;
    void virtual_modify() override;
    bool virtual_return_leaf() override;
public:
    Kopalnia_Glebinowa();
    Kopalnia_Glebinowa(string);
    virtual void virtual_list_add(string);
    virtual void virtual_list_remove(string);
    virtual void virtual_list_show_all();
    virtual int virtual_list_show_object(string);
    virtual void virtual_list_modify_object(string);

    friend File_Operation;
};

#endif //PO_VIRTUAL_CLASSES_H