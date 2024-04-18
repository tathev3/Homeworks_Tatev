SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    if (position == 0){
        newNode->next=llist;
        return newNode;
    }

    SinglyLinkedListNode* positionNode = llist;
    for (int i=1;i<position;i++){
        positionNode = positionNode->next;
    }

    newNode->next = positionNode->next;
    positionNode->next = newNode;

    return llist;

}