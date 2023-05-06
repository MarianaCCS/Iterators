#include <iostream>
using namespace std;

template <class T>
class CircularArray;

template <class T>
class IteratorCircularArray{
    CircularArray<T> lista;
    int index;

    public:
    IteratorCircularArray(){}

    IteratorCircularArray(int _index){
        index = _index;
    }

    IteratorCircularArray(int _index, CircularArray<T> &_lista){
        lista = _lista;
        index = _index;
    }

    T operator*(){
        return lista[index];
    }

    friend IteratorCircularArray<T>& operator++(IteratorCircularArray<T>& it){
        it.index++;
        return it;
    }

    friend IteratorCircularArray<T>& operator--(IteratorCircularArray<T>& it){
        it.index--;
        return it;
    }

    bool operator!=(IteratorCircularArray<T> it){
        return it.index!=index;
    }

    ~IteratorCircularArray(){
    }

};

template <class T>
class CircularArray{
    int capacity;
    T* array;
    int front, back; // indices

    friend class IteratorCircularArray<T>;

    public:
    typedef IteratorCircularArray<T> iterator; // renombramiento

    CircularArray():capacity(10),front(-1),back(-1){
        array = new T[capacity];
    }

    CircularArray(int _capacity):capacity(_capacity),front(-1),back(-1){
        array = new T[capacity]; 
    }

    bool is_full(){ // para que esté lleno, el back debe estar en uno antes que el front (si front == 0 -> back = capacity-1)
        if (front==-1 && back==-1) return false; // solo se inicializó
        else if (prev(front)==back) {cout<<"Lleno: "; resize();}
        return false;
    }

    int size(){
        if (back>front) return back-front+1;
        return capacity - (front-back+1) + 2;  // +2 se añade por posiciones front/back
    }

    int next(int ind){ // siguiente posicion = (ind+1)%capacity
        return (ind+1)%capacity;
    }

    int prev(int ind){ // posicion previa -> si: ind<=0, prev=capacity-1 // else: prev=ind-1;
        return (ind==0)?capacity-1:ind-1;
    }

    void resize(){
        cout<<"Se hace resize..."<<endl;

        // tener cuidado con cambiar el valor de la capacidad, el siguiente bucle no funcionaría correctamente
        T* temp = new T[capacity*2];  

        int ind = 0; // indice para temp
        int i=front;
        for (;i!=back;i=next(i)){ // hay que tener cuidado: next(back)=front
            temp[ind] = array[i];
            ind++;
        }
        temp[ind] = array[i];

        front = 0;
        back = ind;

        delete [] array;
        capacity*=2;
        array = new T[capacity];

        for (int i=front; i!=next(back); i=next(i)){ // no hay chance que front sea igual a next(back)
            array[i] = temp[i];
        }

        delete [] temp;
    }

    void push_front(T _data){
        if (is_full()) resize(); // se hace resize, si está lleno

        front = (front==-1)? 0:prev(front); 
        
        if (back==-1) back = front;
        array[front] = _data; // se añade el elemento
    }

    void push_back(T _data){
        if (is_full()) resize(); // se hace resize, si está lleno

        back = (back==-1)?0:next(back);
    
        if (front==-1) front = back;
        array[back] = _data;
    }

    void display(){
        cout<<"Array: ";
        cout<<array[front]<<" ";
        for (int i=next(front); i!=next(back); i=next(i)) cout<<array[i]<<" ";
        cout<<endl;
    }

    T operator[](int pos){
        if (pos>=size()) cerr<<"Posicion no valida"<<endl;
        int index = (front+pos)%capacity;

        return array[index];
    }

    iterator begin(){
        return iterator(0,*this);
    }

    iterator end(){
        return iterator(size());
    }

    ~CircularArray(){}
};






