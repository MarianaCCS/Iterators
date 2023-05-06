template <class T>
class IteratorVector{ // clase que simule el comportamiento de un iterator 
    int indice; 
    T* array;

    public:
    IteratorVector(){
    }

    IteratorVector(int _indice, T* _array=nullptr){
        indice = _indice;
        array = _array;
    }

    // sobrecarga de operadores
    IteratorVector<T>& operator++(){
        indice++;
        return *this;
    }

    bool operator!=(IteratorVector i){
        return i.indice!=this->indice;
    }


    T& operator*(){
        return array[indice];
    }



    ~IteratorVector(){
        delete array;
    }
};

template <class T>
class Vector{
    int size;
    int capacity;
    T* array;

    public:
    typedef IteratorVector<T> iterator; // redefinicion de iteratorVector (EN PUBLICO)
    Vector(){
        size = 0;
        capacity = 10;
        array = new T[capacity];
    }

    void resize(){
        capacity = 2*capacity;
        T* temp = new T [capacity];

        for (int i=0;i<size;i++){
            temp[i] = array[i];
        }

        delete array;

        array = new T[capacity];
        array = temp;
    }


    void push_back(T data){
        if (size==capacity){
            resize();
        }
        array[size] = data;
        size++;
    }

    iterator begin(){
        return iterator(0,array);
    }

    iterator end(){
        return iterator(size);
    }

    ~Vector(){
        delete array;
    }
};

