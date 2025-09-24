#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT

            int i, j;
            for(i = 0; i < index; i++){
              Entry existing = array[i]; // *(array + i);
                if(entry->compare(&existing)){
                    for(j = index; j > i; j--){
                      if(j == SIZE){
                        continue;
                      }
                        array[j] = array[j - 1];
                    }
                  array[i] = *entry;
                  if(index < SIZE){
                    index++;
                  }
                  return;
                }
            }

            if(index < SIZE){
              arr[index] = *entry;
              index++;
            }
            else {
              cout << entry->name << "'s score is too low to be added!" << endl;
            }


            // int i, j;
            // for(i = 0; i < SIZE; i++){
            //     if(entry->compare(&array[i])){
            //         for(j = SIZE - 1; j > i; j--){
            //             array[j] = array[j - 1];
            //         }
            //       array[i] = *entry;
            //       index++;
            //       return;
            //     }
            // }
            //
            // cout << entry->name << "'s score is too low to be added!" << endl;
            return;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};
