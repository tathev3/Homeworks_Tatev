bool has_cycle(Node* head) {
    if( head == NULL)
            return false;
    
    Node* ptr1 = head;
    Node* ptr2 = head;
    
    while( ptr2 !=nullptr and ptr2->next!=nullptr){
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
        
        if(ptr1==ptr2){
            return true;
        }
    }
    return false;

}