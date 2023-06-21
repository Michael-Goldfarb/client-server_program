#include <vector>
#include <stdio.h>
#include "pack109.hpp"

using namespace std;

int main() {




  Person person;
  person.age = 25;
  person.height = 6.1;
  person.name = "John";

  vec bytes;

  bytes.push_back(PACK109_M8);
  bytes.push_back(3); // number of fields

  bytes.push_back(PACK109_U8);
  bytes.push_back(person.age);

  bytes.push_back(PACK109_F32);
  bytes.push_back((u8)person.height);

  bytes.push_back(PACK109_M8);
  bytes.push_back(person.name.size());
  for (int i = 0; i < person.name.size(); i++) {
    bytes.push_back(person.name[i]);
  }

  FILE *file = fopen("person.pack109", "wb");
  fwrite(bytes.data(), 1, bytes.size(), file);
  fclose(file);

  FILE *file2 = fopen("person.pack109", "rb");
  fseek(file2, 0, SEEK_END);
  long fsize = ftell(file2);
  fseek(file2, 0, SEEK_SET);  // same as rewind(f); 

  char *string = (char *)malloc(fsize + 1);
  fread(string, fsize, 1, file2);
  fclose(file2);

  string[fsize] = 0;

  Person person2;

  int i = 0;
  if (string[i] == PACK109_M8) {
    i++;
    int numFields = string[i];
    i++;
    for (int j = 0; j < numFields; j++) {
      if (string[i] == PACK109_U8) {
        i++;
        person2.age = string[i];
        i++;
      } else if (string[i] == PACK109_F32) {
        i++;
        person2.height = string[i];
        i++;
      } else if (string[i] == PACK109_M8) {
        i++;
        int stringSize = string[i];
        i++;
        for (int k = 0; k < stringSize; k++) {
          person2.name += string[i];
          i++;
        }
      }
    }
  }

  printf("person.age: %d\n", person.age);
  printf("person2.age: %d\n", person2.age);

  printf("person.height: %f\n", person.height);
  printf("person2.height: %f\n", person2.height);

  printf("person.name: %s\n", person.name.c_str());
  printf("person2.name: %s\n", person2.name.c_str());

  return 0;

  /*

 struct Person myPerson = {.age = 10, .height = 3.4, .name = "Ann"};
    std::vector<u8> v8person = pack109::serialize(myPerson);
    ofstream myfile;
    myfile.open("person.pack109", ios::out | ios::app | ios::binary);
    char* temp1;
    for(int i = 0; i < v8person.size(); i++){
      myfile.write((char*)&v8person[i],v8person.size()*sizeof(u8));
    }
    vec readVector;
    char* temp;
    myfile.close();
    std::ifstream myfile1("person.pack109", std::ios::binary);
    //myfile1.read(temp, v8person.size()*sizeof(u8));
    //struct Person finalPerson = pack109::deserialize_person(temp);

    printf("Original person: age:%d height:%f name:%s\n",myPerson.age,myPerson.height,myPerson.name.c_str());
  return 0;
  */
}
