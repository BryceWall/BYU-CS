#include "Hashmap.h"

Hashmap::Hashmap(){
    mapSize = 0;
    for(int i = 0; i < BUCKETS; i++){
        buckets[i] = NULL;
    }
}

Hashmap::~Hashmap(){

}

void Hashmap::insert(string key, int value){
    int &valPtr = at(key);
    valPtr = value;
    mapSize++;
}

bool Hashmap::contains(string key) const{
    if(get(key) != -1){
        return true;
    }
    else {
        return false;
    }
}

int Hashmap::get(string key) const{
    int hashKey = hash(key);
    Node* ptr = buckets[hashKey];
    if(ptr == NULL){
        throw invalid_argument("INVALID_ARGUMENT");
        return -1;
    }
    else {
        while(ptr != NULL){
            if(ptr->key == key){
                return ptr->value;
            }
            ptr = ptr->next;
        }
        throw invalid_argument("INVALID_ARGUMENT");
        return -1;
    }
}

int& Hashmap::operator [](string key){
    return at(key);
}

int& Hashmap::at(string name){
    int hashval = hash(name); // Compute the hash value for this name
    Node *ptr = buckets[hashval];
    while(ptr != NULL) {
        if(name == ptr->key) { // We found it
            break;
        }
        else {
            ptr = ptr->next;
        }
    }
    if(ptr == NULL) { // We need to create a new node, put it on the front of the list
        ptr = new Node();
        ptr->next = buckets[hashval];
        buckets[hashval] = ptr;
        ptr->key = name;
    }
    return(ptr->value);
  delete ptr;
}

bool Hashmap::remove(string key){
  if(!contains(key)){
    return false;
  }
  else {
    int hashval = hash(key);
    Node *ptr = buckets[hashval];
      while(ptr != NULL) {
        //Node* keyVal = buckets[hashval];
        if(key == ptr->key) { // We found it
          if(ptr->prev == NULL){
            Node *current = ptr;
            ptr = ptr->next;
            ptr->prev = NULL;
            delete current;
            return true;
            mapSize--;      //fixme
          }
          else {
            Node *current = ptr;
            ptr->next->prev = ptr->prev;
            ptr = ptr->next;
            delete current;
            return true;
            mapSize--;
          }
        }
        else if(key != ptr->key){
          ptr = ptr->next;
        }
        else {
          return false;    
        }
    }
    }
  return true;
}

string Hashmap::toString() const{
    stringstream ss;
    for(int i = 0; i < BUCKETS; i++){
        Node *head = buckets[i];
        if(head == NULL){
            ss << "[" << i << "]" << endl;
        }
        else {
            Node* current = head;
            ss << "[" << i << "]";
            while(current != NULL){
                ss << current->key << current->value;
                if(current->next != NULL)
                    ss << ", ";
                current = current->next;
            }
            ss << endl;
        }
    }
    return ss.str();
}

int Hashmap::size() const{
    return mapSize;
}

string Hashmap::toSortedString() const{
    stringstream ss;
    priority_queue<Node*, vector<Node*>, NodeCompare> nodeHeap;
    for(int i = 0; i < BUCKETS; i++){
        Node* current = buckets[i];
        while(current != NULL){
            nodeHeap.push(current);
            current = current->next;
        }
    }
    while(!nodeHeap.empty()){
        Node* top = nodeHeap.top();
        ss << top->key << " => " << top->value << endl;
        nodeHeap.pop();
    }
    return ss.str();
}

unsigned int Hashmap::hash(string key) const{  //unsigned
    // int seed = 131;
    // unsigned long hash = 0;
    // for(int i = 0; i < key.length(); i++){
    //   hash = (hash * seed) + key[i];
    // }
    // return hash % BUCKETS;

//    int seed = 131;
//    int hashCode = 0;
//    for (int i = 0; i < key.length(); i++) {
//        hashCode += key[i] * pow(seed, i);
//    }
//    return hashCode;

    unsigned int hashVal = 7;
    for (int i = 0; i < key.length(); i++) {
        hashVal = hashVal * 53 + key.at(i);
    }
    // Modify hashVal to fit in buckets
    hashVal %= BUCKETS;
    return hashVal;
}

void Hashmap::clear(){
    for(int i = 0; i < BUCKETS; i++){
            Node *head = buckets[i];
            if(head == NULL){
                continue;
            }
            else {
                while(head != NULL){
                    Node* current = head;
                    head = head->next;
                    delete current;
                }
                continue;
            }
    }
  mapSize = 0;
}