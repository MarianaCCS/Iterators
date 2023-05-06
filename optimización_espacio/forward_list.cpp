#include <iostream>
using namespace std;


// clases del archivo
template <class T>
class Forward_List;

template <class T>
class Forward_List_Iterator;

template <class T>
struct NodeF;



// definicion de clases 
template <class T>
class Forward_List_Iterator{

    NodeF<T>* nodo; // atributos
    int index;

    public:
    Forward_List_Iterator(){}
    Forward_List_Iterator(int _index):index(_index){}
    Forward_List_Iterator(int _index, NodeF<T>*& _nodo):index(_index),nodo(_nodo){}

    friend Forward_List_Iterator<T>& operator++(Forward_List_Iterator<T>& it){
        it.index ++;
        it.nodo = it.nodo->next;
        return it;
    }

    T operator*(){
        return nodo->data;
    }

    bool operator!=(Forward_List_Iterator<T> it){
        return it.index!=this->index;
    }



    ~Forward_List_Iterator(){}
};


template <class T>
struct NodeF{
    NodeF* next;
    T data;

    NodeF():next(nullptr){}
    NodeF(T _data):next(nullptr),data(_data){}

    void killSelf(){
        this = next;
    }

    ~NodeF(){}
};


template <class T>
class Forward_List{
    NodeF<T>* head;
    int nodes;
    public: 
    typedef Forward_List_Iterator<T> iterator;
    
    Forward_List():head(nullptr),nodes(0){}
    
    void push_front(T _data){
        nodes++;
        NodeF<T>* nuevo = new NodeF<T>(_data);

        nuevo->next = head; // nodo se cuelga
        head = nuevo; // la "cabeza" cambia
    }

    void push_back(T _data){
        nodes++;
       NodeF<T>* nuevo = new NodeF<T>(_data);

       if (!head){ head = nuevo; return;}

       NodeF<T>* temp = head; // recorrido
       while(temp->next) temp = temp->next;
       temp->next = nuevo;
    }

    void display(){
        NodeF<T>* temp = head;
        while (temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    iterator begin(){
        return iterator(0,head);
    }

    iterator end(){
        return iterator(nodes);
    }

};


void test_forward_list(){
    cout<<"\n\nForward List Array: ";
    Forward_List<int> elementos;
    elementos.push_front(15);
    elementos.push_front(10);
    elementos.push_front(12);
    elementos.push_front(20);
    elementos.push_back(15);
    elementos.push_back(10);
    elementos.push_back(12);
    elementos.push_back(20); 
    cout<<"Elementos - display: "; elementos.display();

    
    Forward_List<int>::iterator ptr = elementos.begin();
    cout<<*ptr<<endl;
    Forward_List<int>::iterator ptr2 = ++ptr;

    for(;ptr2!=elementos.end(); ++ptr2){
        cout<<*ptr2<<endl;//12,10,15
    } 

}

int main(){
    test_forward_list();

    return 0;
}
