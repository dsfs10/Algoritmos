#include <iostream>
#include <sstream>

using namespace std;

typedef struct {
    int n;
} Case;

typedef struct link {
    int element; // E type, value stored in this link/node
    struct link* next; // Reference to the next link/node
} Link;

typedef struct list {
    Link* head;
    Link* tail;
    Link* curr;
    int cnt; // list size
} List;


List* create_list(); // Creates a new list // Lembrar do 'int size' como parametro para array list
void clear(List* l);
void insert(List* l, int item);
void remove(List* l);
void prev(List* l);
void next(List* l);
void printList(List* l);
int count(List* l);
Link* create_link(int it, Link* nextval);
Link* create_link(Link* nextval);
int extractIntegerWords(string str);


int main(void) {
    int c;
    cin >> c;
    Case caso[c];
    List* l = create_list();

    for(int i = 0; i < c; i++) {
        cin >> caso[i].n;
        for(int j = 0; j < caso[i].n; j++) {
            string input;
            getline(cin, input);
            
            if(input.substr(0, 1) == "i") {
                int it = extractIntegerWords(input);
                insert(l, it);
            }
            else if(input.substr(0, 1) == "r") {
                remove(l);
            }
            else if(input.substr(0, 1) == "n") {
                next(l);
            }
            else if(input.substr(0, 1) == "p") {
                prev(l);
            }
            else if(input.substr(0, 1) == "c") {
                
            }

        }
        //clear();
    }


    return 0;
}


Link* create_link(int it, Link* nextval) {
    Link* n = (Link *) new int;
    n->element = it;
    n->next = nextval;
    return n;
}

Link* create_link(Link* nextval) {
    Link* n = (Link *) new int;
    n->next = nextval;
    return n;
}

List* create_list() {
    List* l = (List *) new int;
    l->curr = l->tail = l->head = create_link(NULL); // header node
    l->cnt = 0;
    return l;
}

void clear(List* l) {
       Link *temp = l->head;
       Link *next = temp->next;

       while(temp->next != NULL) {
        next = temp->next;
        delete temp;
        temp = next;
       }
       delete temp;
       delete l;
}

void insert(List* l, int it) {
    l->curr->next = create_link(it, l->curr->next);
    
    if(l->tail == l->curr) {
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void remove(List* l) {
    if(l->curr->next == NULL) {
        return;
    }
    //int it = l->curr->next->element;

    if(l->tail == l->curr->next) {
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    l->cnt--;
    //return it;
}

void prev(List* l) {
    if(l->curr == l->head) {
        return;
    }

    Link* temp = l->head;

    while(temp->next != l->curr) {
        temp = temp->next;
    }
    l->curr = temp;
}

void next(List* l) {
    if(l->curr != l->tail) {
        l->curr = l->curr->next;
    }
}

int count(List* l) {
    
}

int extractIntegerWords(string str) {
    stringstream ss;
 
    /* Storing the whole string into string stream */
    ss << str;
 
    /* Running loop till the end of the stream */
    string temp;
    int found;
    while (!ss.eof()) {
 
        /* extracting word by word from stream */
        ss >> temp;
 
        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found) {
            temp = "";
            return found;
        }
            //cout << found << " ";
 
        /* To save from space at the end of string */
        //temp = "";
    }
}
