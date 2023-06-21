#include <stdexcept>
#include <iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include"pack109.hpp"

template <class T>
int test(const char* label, T lhs, T rhs) {
  printf("%s: ", label);
  if (lhs==rhs) {
    printf("Passed\n");
    return 1;
  } else {
    printf("Failed\n");
    printf("  lhs=%lx\n", lhs);
    printf("  rhs=%lx\n", rhs);
    exit(1);
  }
}

int testvec(const char* label, vec lhs, vec rhs) {
  printf("%s: ", label);
  if (lhs==rhs) {
    printf("Passed\n");
    return 1;
  } else {
    printf("Failed\n");
    printf("  lhs="); pack109::printVec(lhs); printf("\n");
    printf("  rhs="); pack109::printVec(rhs); printf("\n");
    exit(1);
  }
}

int teststr(const char* label, string lhs, string rhs) {
  printf("%s: ", label);
  if (lhs.compare(rhs) == 0) {
    printf("Passed\n");
    return 1;
  } else {
    printf("Failed\n");
    printf("  lhs=%s\n", lhs.c_str());
    printf("  rhs=%s\n", rhs.c_str());
    exit(1);
  }
}

int testvecu64(const char* label, std::vector<u64> lhs, std::vector<u64> rhs) {
    printf("%s: ", label);
    if (lhs==rhs) {
      printf("Passed\n");
      return 1;
    } else {
      printf("Failed\n");
      exit(1);
    }
  }

  int testvecf64(const char* label, std::vector<f64> lhs, std::vector<f64> rhs) {
    printf("%s: ", label);
    if (lhs==rhs) {
      printf("Passed\n");
      return 1;
    } else {
      printf("Failed\n");
      exit(1);
    }
  }

  int testvecstring(const char* label, std::vector<string> lhs, std::vector<string> rhs) {
    printf("%s: ", label);
    if (lhs==rhs) {
      printf("Passed\n");
      return 1;
    } else {
      printf("Failed\n");
      exit(1);
    }
  }

  int testp1(const char* label, Person lhs, Person rhs) {
    printf("%s: ", label);
    if (lhs.age==rhs.age && lhs.height==rhs.height && lhs.name==rhs.name) {
      printf("Passed\n");
      return 1;
    } else {
      printf("Failed\n");
      exit(1);
    }
  }


int main() {

  // Test bool

  // True
  vec v1{0xa0};
  vec bytes1 = pack109::serialize(true);
  testvec("Test 1 - true ser", bytes1, v1);

  bool bool_true = pack109::deserialize_bool(bytes1);
  test("Test 2 - true de", bool_true, true);
 

  // False
  vec v2{0xa1};
  vec bytes2 = pack109::serialize(false);
  testvec("Test 3 - false ser", bytes2, v2);

  bool bool_false = pack109::deserialize_bool(bytes2); 
  test("Test 4 - false de", bool_false, false);

  // Test Integers

  // u8
  
  u8 item1 = 0x42;
  vec v3{0xa2, 0x42};
  vec bytes3 = pack109::serialize(item1);
  testvec("Test 5 - u8 ser", bytes3, v3);
  
  u8 int_u8 = pack109::deserialize_u8(bytes3);  
  test("Test 6 - u8 de", int_u8, item1);

  // u32

  u32 item2 = 0x12345678;
  vec v4{0xa3, 0x12, 0x34, 0x56, 0x78};
  vec bytes4 = pack109::serialize(item2);
  testvec("Test 7 - u32 ser", bytes4, v4);
  

  u32 int_u32 = pack109::deserialize_u32(bytes4);
  test("Test 8 - u32 de", int_u32, item2);


  u64 item3 = 0x1234567890abcdef;
  vec v5{0xa4, 0x12, 0x34, 0x56, 0x78, 0x90, 0xab, 0xcd, 0xef};
  vec bytes5 = pack109::serialize(item3);
  testvec("Test 9 - u64 ser", bytes5, v5);

  u64 int_u64 = pack109::deserialize_u64(bytes5);
  test("Test 10 - u64 de", int_u64, item3);


  i8 item4 = 0x42;
  vec v6{0xa5, 0x42};
  vec bytes6 = pack109::serialize(item4);
  testvec("Test 11 - i8 ser", bytes6, v6);

  i8 int_i8 = pack109::deserialize_i8(bytes6);
  test("Test 12 - i8 de", int_i8, item4);


  i32 item5 = 0x12345678;
  vec v7{0xa6, 0x12, 0x34, 0x56, 0x78};
  vec bytes7 = pack109::serialize(item5);
  testvec("Test 13 - i32 ser", bytes7, v7);

  i32 int_i32 = pack109::deserialize_i32(bytes7);
  test("Test 14 - i32 de", int_i32, item5);


  i64 item6 = 0x1234567890abcdef;
  vec v8{0xa7, 0x12, 0x34, 0x56, 0x78, 0x90, 0xab, 0xcd, 0xef};
  vec bytes8 = pack109::serialize(item6);
  testvec("Test 15 - i64 ser", bytes8, v8);

  i64 int_i64 = pack109::deserialize_i64(bytes8);
  test("Test 16 - i64 de", int_i64, item6);

  // Test Float
  

  f32 item7 = 23.321;
  vec v9{0xa8, 0x41, 0xba, 0x91, 0x68};
  vec bytes9 = pack109::serialize(item7);
  testvec("Test 17 - f32 ser", bytes9, v9);

  f32 int_f32 = pack109::deserialize_f32(v9);
  test("Test 18 - f32 de", int_f32, item7);

  f64 item8 = 12.2;
  vec v10{0xa9, 0x40, 0x28, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66};
  vec bytes10 = pack109::serialize(item8);
  testvec("Test 19 - f64 ser", bytes10, v10);

  f64 int_f64 = pack109::deserialize_f64(bytes10);
  test("Test 20 - f64 de", int_f64, item8);


  // Test Strings

  // s8
  string item9 = "Hello";
  vec v11{0xaa, 0x05, 0x48, 0x65, 0x6c, 0x6c, 0x6f};
  vec bytes11 = pack109::serialize(item9);
  testvec("Test 21 - s8 ser", bytes11, v11);

  string str_s8 = pack109::deserialize_string(bytes11);
  teststr("Test 22 - s8 de", str_s8, item9);

  // Test Arrays

  // a8 - array of u8
  std::vector<u8> item11 = {0x01, 0x02, 0x03, 0x04, 0x05};
  vec v13{0xac, 0x05, 0xa2, 0x01, 0xa2, 0x02, 0xa2, 0x03, 0xa2, 0x04, 0xa2, 0x05};
  vec bytes13 = pack109::serialize(item11);
  testvec("Test 23 - a8-u8 ser", bytes13, v13);

  vec arr_u8 = pack109::deserialize_vec_u8(bytes13);
  testvec("Test 24 - a8-u8 de", arr_u8, item11);



  // a8 - array vector of type u64
  std::vector<u64> item12 = {0x1122334455667788,0x8877665544332211,0x2211443366558877,0x7788556633441122};
  vec v14{0xac,0x04,0xa4,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0xa4,0x88,0x77,0x66,0x55,0x44,0x33,0x22,0x11,0xa4,0x22,0x11,0x44,0x33,0x66,0x55,0x88,0x77,0xa4,0x77,0x88,0x55,0x66,0x33,0x44,0x11,0x22};
  vec bytes14 = pack109::serialize(item12);
  testvec("Test 25 - a8-u64 ser", bytes14, v14);

  std::vector<u64> arr_u64 = pack109::deserialize_vec_u64(bytes14);
  testvecu64("Test 26 - a8-u64 de", arr_u64, item12);


  // a8 - array of f64
  std::vector<f64> item13 = {(double)0x1122334455667788};
  vec v15{0xac,0x01,0xa9,0x11,0x22,0x33,0x44,0x55,0x66,0x78,0x00};
  vec bytes15 = pack109::serialize(item13);
  testvec("Test 27 - a8-f64 ser", bytes15, v15);

  std::vector<f64> arr_f64 = pack109::deserialize_vec_f64(bytes15);
  testvecf64("Test 28 - a8-f64 de", arr_f64, item13);

  // a8 - array vector of a string
  std::vector<string> item14 = {"Hello", "World"};
  vec v16{0xac,0x02,0xaa,0x05,0x48,0x65,0x6c,0x6c,0x6f,0xaa,0x05,0x57,0x6f,0x72,0x6c,0x64};
  vec bytes16 = pack109::serialize(item14);
  testvec("Test 29 - a8-s8 ser", bytes16, v16);

  std::vector<string> arr_s8 = pack109::deserialize_vec_string(bytes16);
  testvecstring("Test 30 - a8-s8 de", arr_s8, item14);

  // Test Person struct
  struct Person p1 = {.age = 10, .height = 3.4, .name = "Ann"};
  vec v17{0xae, 0x01, 0xaa, 0x06, 0x50, 0x65, 0x72, 0x73, 0x6f, 0x6e, 0xae, 0x03, 0xaa, 0x03, 0x61, 0x67, 0x65, 0xa2, 0x0a, 0xaa, 0x06, 0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0xa8, 0x40, 0x59, 0x99, 0x9a, 0xaa, 0x04, 0x6e, 0x61, 0x6d, 0x65, 0xaa, 0x03, 0x41, 0x6e, 0x6e};
  vec bytes17 = pack109::serialize(p1);
  testvec("test 31 - m8Person ser", bytes17, v17);

  f32 valtest = p1.height;
  struct Person map = pack109::deserialize_person(bytes17);
  testp1("test 32 - m8Person de", map, p1);
  
}
