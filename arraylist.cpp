#include <iostream>
#include "list.h"

using namespace std;

int main(void) {
    int tam;
    cout << "Digite o tamanho da lista a ser criada: ";
    cin >> tam;
    List* l = create_list(tam);
    int comando = 0;

    do { // MENU
        cout << "=============MENU=============\n";
        cout << "1) Insert\n2) Remove\n3) Move to Start\n4) Move to End\n5) Previous\n6) Next\n7) Print List\n8) Current Position\n9) Clear\n10) Leave\n.: ";
        cin >> comando;

        switch(comando) {
            case 1:
                int it;
                cout << "Digite o elemento a ser inserido na lista: ";
                cin >> it;
                insert(l, it);
                break;
            case 2:
                remove(l);
                break;
            case 3:
                moveToStart(l);
                break;
            case 4:
                moveToEnd(l);
                break;
            case 5:
                prev(l);
                break;
            case 6:
                next(l);
                break;
            case 7:
                printList(l);
                break;
            case 8:
                currentpos(l);
                break;
            case 9:
                //delete (l);
                //List* l = create_list(tam);
                break;
            case 10:
                cout << "Leaving..." << endl;
                break;
            default:
                cout << "Opcao Invalida" << endl;
                break;        
        }
    } while(comando != 10);

    //delete (l);
    
    return 0;
}
