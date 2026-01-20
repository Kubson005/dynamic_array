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
            cout << "rozmiar: " << number_of_elements << endl;
            return number_of_elements;
        }

        void print() {
            for(int i = 0; i < number_of_elements; i++){
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

        void remove(int element) {
            int position;
            for(int i = 0; i < number_of_elements; i++) {
                if(array[i] == element) {
                    position = i;
                    break;
                }
            }
            for(int i = position; i < number_of_elements; i++) {
                array[i] = array[i+1];
            }
            number_of_elements--;
        }

        void clear() {
            number_of_elements = 0;
        }

        int count(int element) {
            int counter = 0;
            for(int i = 0; i < number_of_elements; i++) {
                if(array[i] == element) {
                    counter++;
                }
            }
            return counter;
        }

        void insert(int element, int position) {
            position--;
            if(size == number_of_elements) {resize();}

            for(int i = number_of_elements; i > 0; i--){
                if(i < position) {
                   break;
                }
                array[i+1] = array[i];
            }
            array[position] = element;
            number_of_elements++;
        }
        
        void reverse() {
            if(number_of_elements % 2 == 0) {
                for(int i = 0; i < number_of_elements / 2; i++) {
                    int temp = array[i];
                    array[i] = array[number_of_elements - i - 1];
                    array[number_of_elements - i - 1] = temp;
                }
            } else {
                for(int i = 0; i < (number_of_elements - 1) / 2; i++) {
                    int temp = array[i];
                    array[i] = array[number_of_elements - i - 1];
                    array[number_of_elements - i - 1] = temp;
                }
            }
        }

        int index(int element) {
            for(int i = 0; i < number_of_elements; i++) {
                if(array[i] == element) {
                    return i;
                }
            }
            return -1;
        }
        void sort() {
            bool flag = true;
            while(flag) {
                flag = false;
                for(int i = 0; i < number_of_elements - 1; i++) {
                    if(array[i] > array[i+1]) {
                        int temp = array[i];
                        array[i] = array[i+1];
                        array[i+1] = temp;
                        flag = true;
                    }
                }
            }
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
    tablica.append(5);
    tablica.append(4);
    tablica.append(9);
    tablica.append(2);
    tablica.append(1);
    tablica.print();
    cout << "---------" << endl;
    tablica.sort();
    tablica.print();

    return 0;
}