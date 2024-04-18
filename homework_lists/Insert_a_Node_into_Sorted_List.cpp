DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    
    DoublyLinkedListNode* newNode = new  DoublyLinkedListNode(data);
    
     if (llist == nullptr) 
        return newNode;
    
    if (newNode->data<llist->data){
        newNode->prev = nullptr;
        newNode->next =llist;
        return newNode;

    }

    DoublyLinkedListNode* current = llist;
    
    while(current->next != nullptr && current->next->data <data){
        current = current->next;
    }
    
    newNode->next = current->next;
    if (current->next != nullptr)
        current->next->prev = newNode;
      
    newNode->prev = current;
    current->next = newNode;
    
    return llist;
}