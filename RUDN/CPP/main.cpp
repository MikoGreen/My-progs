#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

struct product{
    string name;
    float price;
    int amount;
    //указатель на следующий по порядку элемент
    product *next;
    product(): next(nullptr){}
};

// Добавляет элемент в начало списка
// Создает первую запись о товаре, если список пустой
/*product *addfirst(product *product_list, string name, float price, int amount) {
    product* first_product = new product;
    first_product -> name = name;
    first_product -> price = price;
    first_product -> amount = amount;
    first_product -> next = product_list;
    product_list = first_product;
    return product_list;
};*/
/*void addfirst(product* product_list, string name, float price, int amount) {
    product* first_product = new product;
    first_product -> name = name;
    first_product -> price = price;
    first_product -> amount = amount;
    first_product -> next = product_list;
    *&product_list = first_product;
}*/


// Добавляет элемент в начало списка
// Создает первую запись о товаре, если список пустой
product* addfirst(product* product_list, string name, float price, int amount){
    product* first_product = new product;
    first_product -> name = name;
    first_product -> price = price;
    first_product -> amount = amount;
    first_product -> next = product_list;
    return first_product;
};

// Выводит на экран всю информацию о каждом элементе
void printlist(product *product_list) {
    if (product_list == NULL) cout << "The list is empty." << endl;
    else {
        product *temp = product_list;
        int i = 1;
        cout << "The list of products:\n" << endl;
        while (temp != NULL) {
            cout << i << ". " << temp -> name << "\t" << temp -> price << "\t" << temp -> amount << endl;
            i++;
            temp = temp -> next;
        }
    }
}

// Выводит на экран всю информацию об одном выбранном элементе
void printitem(product* product_list, int pos) {
    product *temp = product_list;
    if (product_list == NULL) cout << "\nThe product description is empty." << endl;
    else {
        int i = 1;
        while (temp != NULL && i <= pos) {
            if (i == pos) {
                cout << "\nThe product description:" << "\n" << i << ". " << temp->name << "\t" << temp->price << "\t"
                     << temp->amount << endl;
                if (temp->next == nullptr){
                    cout << " Warning! The next product doesn't exist\n" << endl;}
            } else {
                temp = temp->next;}
            i += 1;
        }
        if (temp == NULL) cout << "\nThe product description is empty." << endl;
    }
}

//void printitem(product* product_list, int pos) {
//    pos = pos - 1;
//    if (product_list == NULL) cout << "The product description is empty." << endl;
//    else {
//        product *temp = product_list;
//        int i = 0;
//        cout << "The product description:\n" << endl;
//        while (temp != NULL && i <= pos) {
//            if (i == pos) {
//                cout << i + 1 << ". " << temp->name << "\t" << temp->price << "\t" << temp->amount << endl;
//                if (temp->next == nullptr){
//                    cout << "The product doesn't exist" << endl;
//                    temp = NULL;}
//                }
//            temp = temp -> next;
//            i +=1;
//            }
//        }
//}


//if (temp -> next == NULL) {
//                cout << "The product doesn't exist." << endl;}
//            else{
//                temp = temp->next;
//                i += 1;}


//if (i == pos - 1) {
//                    cout << i + 2 << ". " << temp->name << "\t" << temp->price << "\t" << temp->amount << endl;}
//                    if (temp->next == nullptr) {
//                        cout << "The product doesn't exist." << endl;
//                        temp = NULL;}
//                    else {
//                        temp = temp->next;
//                        i += 1;}

// Добавляет новый элемент в конец списка
product* addlast(product* product_list, string name, float price, int amount) {
    product *temp = product_list;
    if (product_list == NULL) {
        cout << "\nThe product list is empty, but we can do it :)" << endl;
        return addfirst(product_list, name, price, amount);}
    else {
        while (temp -> next != NULL) temp = temp -> next;
        if (temp -> next  == NULL) {
            product* last_product = new product;
            last_product -> name = name;
            last_product -> price = price;
            last_product -> amount = amount;
            last_product -> next = nullptr;
            temp -> next = last_product;
            return product_list;
        }
    }
}

// Вставляет новый элемент сразу после выбранного элемента
product* addafter(product* product_list, string name, float price, int amount, int pos) {
    product *temp = product_list;
    if (product_list == NULL) {
        cout << "\nThe product list is empty." << endl;
        return addfirst(product_list, name, price, amount);}
    else {
        int i = 1;
        while (i<=pos){
            if (temp -> next  == NULL) {
                return addlast(product_list,name,price,amount);}
            else if  (i == pos){
                product* mark = temp -> next;
                product* after_product = new product;
                after_product -> name = name;
                after_product -> price = price;
                after_product -> amount = amount;
                temp -> next = after_product;
                after_product -> next = mark;
                return product_list;}
            temp = temp -> next;
            i += 1;
        }
}}

// Вставляет новый элемент перед выбранным элементом
product* addbefore(product* product_list, string name, float price, int amount, int pos) {
    product *temp = product_list;
    pos = pos - 1;
    if (pos == 0) {
        return addfirst(product_list, name, price, amount);
    } else {
        return addafter(product_list, name, price, amount, pos);
    }
}


// Удаляет выбранный элемент из списка
void del(product *product_list, string spec_name) {
    string xlr = spec_name;
    product *temp = product_list;
    while (temp -> next && temp -> name != spec_name) {
        xlr = temp -> name;
        temp = temp -> next;
    }
    if (xlr == spec_name) {
        temp = temp -> next;
        product_list = temp;
    }
    else {
        product *tmp = product_list;
        while (tmp -> next && tmp -> name != xlr) tmp = tmp -> next;
        tmp -> next = temp -> next;
    }
}

//product* del(product* product_list, int pos) {}


// Поиск элемента по названию
void find_name(product *product_list, string spec_name) {
    product *temp = product_list;
    while (temp -> next && temp -> name != spec_name) {
        temp = temp -> next;
    }
    cout << "This product is the element of the list:" << endl << endl;
    cout << temp -> name << "\t" << temp -> price << "\t" << temp -> amount << endl;
}



//Проверки различного рода
//bufet = addfirst(bufet, "konfetka", 1000.0, 100);
//    bufet = addfirst(bufet,"snikers",50.0,1);
//    bufet = addfirst(bufet, "chups",150.0,25);
//
//    printlist(bufet);
//    printitem(bufet, 1);
//    printitem(bufet, 2);
//    printitem(bufet, 3);
//    printitem(bufet, 4);
//
//    bufet = addlast(bufet,"fanta",10.0, 40);
//
//    printlist(bufet);
//    printitem(bufet, 1);
//    printitem(bufet, 2);
//    printitem(bufet, 3);
//    printitem(bufet, 4);
//
//    bufet = addafter(bufet,"sprite",15.0,50,5);
//    printlist(bufet);
//
//    bufet = addbefore(bufet,"apple",5.0,500,1);
//    find_name(bufet,"fanta");
//    printlist(bufet);
//
//    del(bufet,"fanta");
//    printlist(bufet);




int main(){
    product *bufet = nullptr;
    int res, pos, k, amount;
    string name, nameafter;
    float price;

    k = 100;

    while (k != 0){
        while (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k!=5 && k!=6 && k!=7){
            cout<<"To add an item at the end of the list, enter 1;\n\
            to add an item to the top of the list, enter 2;\n\
            to delete an item, enter 3; \n\
            to add after an item, enter 4;\n\
            to add befor an item, enter 5;\n\
            to find an item, enter 6;\n\
            to print a list, enter 7;\n\
            to exit, enter 0: ";
            cin>>k;
            cout<<"\n\n";

            if (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k!=5 && k!=6 && k!=7){
                cout<<"Wrong code!\n\n";
                system("pause");
            } else{
                switch(k){
                    case 0:{
                        //Выходим из цикла
                        cout << "\t\t\tGOODBYE" << endl;
                        break;
                    }
                    case 1:{
                        // Реализуем логику добавления элемента в конец списка
                        cout << "Enter name\n";
                        cin >> name;
                        cout << "Enter price\n";
                        cin >> price;
                        cout << "Enter amount\n";
                        cin >> amount;
                        bufet = addlast(bufet, name, price, amount);
                        k=100;
                        break;
                    }
                    case 2:{
                        // Реализуем логику добавления элемента в начало списка
                        cout << "Enter name\n";
                        cin >> name;
                        cout << "Enter price\n";
                        cin >> price;
                        cout << "Enter amount\n";
                        cin >> amount;
                        bufet = addfirst(bufet, name, price, amount);
                        k = 100;
                        break;
                    }

                    case 3:{
                        // Реализуем логику удаления элемента из списка
                        cout << "Enter name to delete\n";
                        cin >> name;
                        del(bufet, name);
                        k = 100;
                        break;
                    }
                    case 4:{
                        // Просим пользователя выбрать элемент (например, ввести название)
                        cout << "Enter position\n";
                        cin >> pos;
                        // Реализуем логику добавления нового элемента в список сразу ПОСЛЕ выбранного элемента
                        cout << "Enter name\n";
                        cin >> name;
                        cout << "Enter price\n";
                        cin >> price;
                        cout << "Enter amount\n";
                        cin >> amount;
                        bufet = addafter(bufet,name,price,amount,pos);
                        k = 100;
                        break;
                    }
                    case 5:{
                        // Просим пользователя выбрать элемент (например, ввести название)
                        cout << "Enter position\n";
                        cin >> pos;
                        // Реализуем логику добавления нового элемента в список сразу ПЕРЕД выбранным элементом
                        cout << "Enter name\n";
                        cin >> name;
                        cout << "Enter price\n";
                        cin >> price;
                        cout << "Enter amount\n";
                        cin >> amount;
                        bufet = addbefore(bufet,name,price,amount,pos);
                        k = 100;
                        break;
                    }
                    case 6:{
                        // Просим пользователя выбрать элемент (например, ввести название)
                        cout << "Enter position\n";
                        cin >> pos;

                        // Выводим на экран информацию о выбранном элементе
                        printitem(bufet,pos);
                        k = 100;
                        break;
                    }
                    case 7:{
                        // Выводим на экран информацию о всех элементах списка
                        printlist(bufet);
                        k = 100;
                        break;
                    }
                }
            }
            cout<<"\n\n";
        }
    }

    return 0;
}
