#include <iostream>
#include "list.h"

using namespace std;

int main(void) {
    List* l = create_list(10);
    int comando = 0;

    do { // MENU
        cout << "=============MENU=============";
        cout << "1) Insert\n2) Remove\n3) Move to Start\n4) Move to End\n5) Previous\n6) Next\n7) Leave\n.: ";
        cin >> comando;

        switch(comando) {
            case 1:
                int it;
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
                cout << "Leaving..." << endl;
                break;
            default:
                cout << "Opcao Invalida" << endl;
                break;        
        }
    } while(comando != 7);

    
    
    return 0;
}
