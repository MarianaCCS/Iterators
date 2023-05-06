#include "simplearray.h"
#include "circulararray.h"
#include "forward.h"
#include "circularlist.h"
using namespace std;

void test_simplearray(){
    cout<<"\n\nSimple array: ";
    Vector<int> elementos;
    elementos.push_back(15);
    elementos.push_back(10);
    elementos.push_back(12);
    Vector<int>::iterator ptr;
    for(ptr = elementos.begin(); ptr != elementos.end(); ++ptr){
        cout<<*ptr<<endl;
    }
}


void test_forwardlist(){
    cout<<"\n\nCircular Array: ";
    ForwardList<int> elementos;
    elementos.push_front(15);
    elementos.push_front(10);
    elementos.push_front(12);
    elementos.push_front(20);
    elementos.push_back(15);
    elementos.push_back(10);
    elementos.push_back(12);
    elementos.push_back(20);
 
    cout<<"Elementos - display: "; elementos.display();

    // iterators
    cout<<"Elementos - iterators: ";
    ForwardList<int>::iterator ptr = elementos.begin();
    cout<<*ptr<<endl;
    ForwardList<int>::iterator ptr2 = ++ptr;

    for(;ptr2!=elementos.end(); ++ptr2){
        cout<<*ptr2<<endl;//12,10,15
    } 

}


void test_circulararray(){

    CircularArray<int> elementos(5);
    elementos.push_front(15);
    elementos.push_front(10);
    elementos.push_front(12);
    elementos.push_back(20);
    elementos.push_back(5);

    elementos.display();
    //cout<<"Array[3]: "<<elementos[3]; - sobrecarga de []
    
    CircularArray<int>::iterator ptr = elementos.begin();
    ++ptr; ++ptr;
    
    CircularArray<int>::iterator ptr2 = --ptr;
    for(;ptr2 != elementos.end(); ++ptr2){
        cout<<*ptr2<<endl;//10,15,20,5
    }
    
}


void test_circularlist(){

    CircularList<int> elementos;
    elementos.push_front(15);
    elementos.push_front(10);
    elementos.push_front(12);
    elementos.push_back(20);
    elementos.push_back(5);

    elementos.display();
    //cout<<"Array[3]: "<<elementos[3]; - sobrecarga de []
    
    CircularList<int>::iterator ptr = elementos.begin();
    ++ptr; ++ptr;
    
    CircularList<int>::iterator ptr2 = --ptr;
    for(;ptr2 != elementos.end(); ++ptr2){
        cout<<*ptr2<<endl;//10,15,20,5
    }
    
}


int main() 
{
    test_simplearray();
    test_forwardlist();
    test_circulararray();
    test_circularlist();
    return 0;
}
