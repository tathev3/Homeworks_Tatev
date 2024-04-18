DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* current = llist;
    DoublyLinkedListNode* new_head = nullptr;
    
    while(current!=nullptr){
        DoublyLinkedListNode* ptr = current->prev;
        current->prev = current->next;
        current->next=ptr;
        
        new_head=current;
        current=current->prev;
        
    }
    return new_head;

}