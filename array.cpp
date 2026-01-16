#include <iostream>
using namespace std;

class Tab {
    public:
        int size;
        int number_of_elements;
        int* array;

        Tab(int s) { 
            size = s;
            number_of_elements = 0;
            array = new int[size]; 
        }
        ~Tab() {delete[] array;}

        int len() {
            cout << "rozmiar: " << size << endl;
            return size;
        }
        void print() {
            for(int i = 0; i < size; i++){
                cout << array[i] << endl;
            }
        }
        void append(int element) {
            if(size == number_of_elements) {resize();}

            array[number_of_elements] = element;
            number_of_elements++;
        }
        void pop() {
            number_of_elements--;
        }
        

    private:
        void resize() {
                int* new_array = new int[size+=1];
                
                for(int i = 0; i < size; i++) {
                    new_array[i] = array[i];
                }
                delete[] array;
                array = new_array;
            }
        
};

int main() {
    Tab tablica(2);
    tablica.len();
    tablica.append(1);
    tablica.append(5);
    tablica.print();
    tablica.len();
    tablica.append(5);
    tablica.len();

    return 0;
}