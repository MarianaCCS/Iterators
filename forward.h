#include <iostream>
using namespace std;

template <class T>
class ForwardIterator;

template <class T>
struct Node{
    Node* next;
    T data;
    Node(){
        next = nullptr;
    }
};


template <class T>
class ForwardList{

    Node<T>* head; 
    int size = 0;

    public:
    friend class ForwardIterator<T>; // clase amiga
    typedef ForwardIterator<T> iterator; // clase renombrada

    ForwardList(){
        head = nullptr;     
    }

    void push_front(T data){
        size++;
        Node<T>* nuevo = new Node<T>(); // creando el nuevo nodo
        nuevo->data = data;
        
        if(!head) head = nuevo;
        else{
            nuevo->next = head;
            head = nuevo; 
        }
    }

    void push_back(T data){
        size++;
        Node<T>* nuevo = new Node<T>();  // nodo a añadir
        nuevo->data = data;
       
        if(!head) head = nuevo;
        else{
            Node<T>* temp = head;
            while(temp->next) { temp = temp->next;}  // mientras que el nodo tenga un sig
            temp->next = nuevo;
        }
    }

    T operator[](int pos){
        if (pos>=size || pos<0) cerr<<"Posicion no valida\n";

        Node<T>* temp = head;
        for (int i=0;i<pos;i++){
            temp = temp->next;
        }
        return temp->data;
    }


    void display(){
        Node<T>* temp = head;
        while (temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }

    iterator begin(){
        return iterator(0,*this);
    }


    iterator end(){
        return iterator(size);
    }

    ~ForwardList(){
        delete head;
    }
};

template <class T>
class ForwardIterator{
    public:
    int pos; // posicion del nodo
    ForwardList<T> lista; // otra opcion es solo pasarle el nodo (al sobrecargar*, habrá que iterar)

    public:
    ForwardIterator(){
    }

    ForwardIterator(int _pos){       
        pos = _pos;
    }

    ForwardIterator(int _pos, ForwardList<T> &_lista){       
        pos = _pos;
        lista = _lista;
    }


    T operator*(){
        return lista[pos];
    }

    

    friend ForwardIterator<T>& operator++(ForwardIterator<T>& it){
        it.pos++;
        return it;
    }

    bool operator!=(ForwardIterator<T> other){
       return other.pos!=pos;
    }

    
    ~ForwardIterator(){
    }
    
};