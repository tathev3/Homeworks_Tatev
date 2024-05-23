template<typename T>
List<T>::List() : head(nullptr), tail(nullptr), count(0) {}

template<typename T>
List<T>::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

template<typename T>
void List<T>::push_back(const T& value) {
    Node* node = static_cast<Node*>(malloc(sizeof(Node)));
    new (node) Node(value);

    if (tail == nullptr) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    count++;
}

template<typename T>
void List<T>::push_front(const T& value) {
    Node* node = static_cast<Node*>(malloc(sizeof(Node)));
    new (node) Node(value);

    if (head == nullptr) {
        head = tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    count++;
}

template<typename T>
void List<T>::pop_back() {
    if (tail == nullptr) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail == nullptr) {
        head = nullptr;
    } else {
        tail->next = nullptr;
    }
    free(temp);
    count--;
}

template<typename T>
void List<T>::pop_front() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    } else {
        head->prev = nullptr;
    }
    free(temp);
    count--;
}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator++() {
    node = node->next;
    return *this;
}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator--() {
    node = node->prev;
    return *this;
}

