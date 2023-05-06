#include <iostream>
using namespace std;

template <class T>
class CircularList;

template <class T>
class IteratorCircularList{
    CircularList<T> lista;
    int index;

    public:
    IteratorCircularList(){}
    IteratorCircularList(int _index){
        index = _index;
    }
    IteratorCircularList(int _index, CircularList<T>& _lista){
        lista = _lista;
        index = _index;
    }

    friend IteratorCircularList<T>& operator++(IteratorCircularList<T>& it){
        it.index++;
        return it;
    }

    friend IteratorCircularList<T>& operator--(IteratorCircularList<T>& it){
        it.index--;
        return it;
    }

    T operator*(){
        return lista[index];
    }

    bool operator!=(IteratorCircularList<T> it){
        return it.index != this->index;
    }

    ~IteratorCircularList(){}
};

template <class T>
struct NodeC{
    NodeC* next;
    NodeC* prev;
    T data;

    NodeC(){
        next = prev = nullptr;
    }

    NodeC(T _data){
        next = prev = nullptr;
        data = _data;
    }

    void killSelf(){
        if (next) next->prev = prev; 
        if (prev) prev->next = next;
        delete this;
    }

    ~NodeC(){
    }
};

template <class T>
class CircularList{ // con sentinela
    NodeC<T>* head; 
    int size;

    public:
    friend class IteratorCircularList<T>; // clase amiga
    typedef IteratorCircularList<T> iterator; // renombramiento

    CircularList(){
        head = new NodeC<T>(); // sentinel
        size = 0;
    }


    void push_front(T _data){
        size++;
        NodeC<T>* nuevo = new NodeC<T>(_data); // nodo a añadir
        
        if (!head->next){
            head->next = head->prev = nuevo;
            return;
        }
        // nodo se cuelga
        nuevo->next = head->next;
        nuevo->prev = head;

        // sus vecinos lo ayudan a colgarse
        head->next->prev = nuevo;
        head->next = nuevo;
    }

    void push_back(T _data){
        size++;
        NodeC<T>* nuevo = new NodeC<T>(_data);

        if (!head->prev){
            head->next = head->prev = nuevo;
            return;
        }
        // nodo se cuelga
        nuevo->next = head;
        nuevo->prev = head->prev;

        // sus vecinos lo ayudan a colgarse
        head->prev->next = nuevo;
        head->prev = nuevo;
    }


    void display(){
        NodeC<T>* temp = head->next;
        while (temp!=head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    T operator[](int pos){
        if (pos>=size || pos<0){cerr<<"Posicion no valida\n"; } 
        
        NodeC<T>* temp = head->next;

        for  (int i=0; i<pos;i++) temp = temp->next; // recorrido
    
        return temp->data;
    }

    iterator begin(){
        return iterator(0,*this);
    }

    iterator end(){
        return iterator(size);
    }

    ~CircularList(){
    }

};    