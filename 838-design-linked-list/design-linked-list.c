
struct node {
    int val;
    struct node *next;
};


typedef struct {
    struct node *head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    struct node *temp = obj->head;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->val = val;
    newnode->next = obj->head;
    obj->head = newnode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->val = val;
    newnode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newnode;
    } else {
        struct node *temp = obj->head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    struct node *temp = obj->head;

    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->val = val;
    newnode->next = temp->next;
    temp->next = newnode;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    struct node *temp;

    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
    } else {
        struct node *prev = obj->head;

        for (int i = 0; i < index - 1; i++)
            prev = prev->next;

        temp = prev->next;
        prev->next = temp->next;
    }

    free(temp);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    struct node *temp;

    while (obj->head != NULL) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }

    free(obj);
}
/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/