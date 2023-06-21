#include <vector>
#include <stdio.h>
#include "pack109.hpp"

vec pack109::serialize(bool item) {
  vec bytes;
  if (item == true) {
    bytes.push_back(PACK109_TRUE);
  } else {
    bytes.push_back(PACK109_FALSE);
  }
  return bytes;
}

bool pack109::deserialize_bool(vec bytes) {
  if (bytes.size() < 1) {
     throw;
  }

  if (bytes[0] == PACK109_TRUE) {
    return true;
  } else if (bytes[0] == PACK109_FALSE) {
    return false;
  } else {
    throw;
  }

}

void pack109::printVec(vec &bytes) {
  printf("[ ");
  for (int i = 0; i < bytes.size(); i++) {
    printf("%x ", bytes[i]);
  }
  printf("]\n");
}

vec pack109::serialize(u8 item) {
  vec bytes;
  bytes.push_back(PACK109_U8);
  bytes.push_back(item);
  return bytes;
}

u8 pack109::deserialize_u8(vec bytes) {
  if (bytes.size() < 2) {
    throw;
  }
  if (bytes[0] == PACK109_U8) {
    return bytes[1];
  } else {
    throw;
  }
}


vec pack109::serialize(u32 item) {
  vec bytes;
  bytes.push_back(PACK109_U32);
  bytes.push_back((item >> 24) & 0xFF);
  bytes.push_back((item >> 16) & 0xFF);
  bytes.push_back((item >> 8) & 0xFF);
  bytes.push_back(item & 0xFF);
  return bytes;
}

u32 pack109::deserialize_u32(vec bytes) {
  if (bytes.size() < 5) {
    throw;
  }
  if (bytes[0] == PACK109_U32) {
    u32 item = 0;
    item |= bytes[1] << 24;
    item |= bytes[2] << 16;
    item |= bytes[3] << 8;
    item |= bytes[4];
    return item;
  } else {
    throw;
  }
}

vec pack109::serialize(u64 item) {
  vec bytes;
  bytes.push_back(PACK109_U64);
  bytes.push_back((item >> 56) & 0xFF);
  bytes.push_back((item >> 48) & 0xFF);
  bytes.push_back((item >> 40) & 0xFF);
  bytes.push_back((item >> 32) & 0xFF);
  bytes.push_back((item >> 24) & 0xFF);
  bytes.push_back((item >> 16) & 0xFF);
  bytes.push_back((item >> 8) & 0xFF);
  bytes.push_back(item & 0xFF);
  return bytes;
}


u64 pack109::deserialize_u64(vec bytes) {
  if (bytes.size() < 9) {
    throw;
  }
  if (bytes[0] == PACK109_U64) {
    u64 item = 0;
    item |= (u64)bytes[1] << 56;
    item |= (u64)bytes[2] << 48;
    item |= (u64)bytes[3] << 40;
    item |= (u64)bytes[4] << 32;
    item |= (u64)bytes[5] << 24;
    item |= (u64)bytes[6] << 16;
    item |= (u64)bytes[7] << 8;
    item |= (u64)bytes[8];
    return item;
  } else {
    throw;
  }
}

vec pack109::serialize(i8 item) {
  vec bytes;
  bytes.push_back(PACK109_I8);
  bytes.push_back(item);
  return bytes;
}

i8 pack109::deserialize_i8(vec bytes) {
  if (bytes.size() < 2) {
    throw;
  }
  if (bytes[0] == PACK109_I8) {
    return bytes[1];
  } else {
    throw;
  }
}

vec pack109::serialize(i32 item) {
  vec bytes;
  bytes.push_back(PACK109_I32);
  bytes.push_back((item >> 24) & 0xFF);
  bytes.push_back((item >> 16) & 0xFF);
  bytes.push_back((item >> 8) & 0xFF);
  bytes.push_back(item & 0xFF);
  return bytes;
}

i32 pack109::deserialize_i32(vec bytes) {
  if (bytes.size() < 5) {
    throw;
  }
  if (bytes[0] == PACK109_I32) {
    i32 item = 0;
    item |= bytes[1] << 24;
    item |= bytes[2] << 16;
    item |= bytes[3] << 8;
    item |= bytes[4];
    return item;
  } else {
    throw;
  }
}

vec pack109::serialize(i64 item) {
  vec bytes;
  bytes.push_back(PACK109_I64);
  bytes.push_back((item >> 56) & 0xFF);
  bytes.push_back((item >> 48) & 0xFF);
  bytes.push_back((item >> 40) & 0xFF);
  bytes.push_back((item >> 32) & 0xFF);
  bytes.push_back((item >> 24) & 0xFF);
  bytes.push_back((item >> 16) & 0xFF);
  bytes.push_back((item >> 8) & 0xFF);
  bytes.push_back(item & 0xFF);
  return bytes;
}

i64 pack109::deserialize_i64(vec bytes) {
  if (bytes.size() < 9) {
    throw;
  }
  if (bytes[0] == PACK109_I64) {
    i64 item = 0;
    item |= (i64)bytes[1] << 56;
    item |= (i64)bytes[2] << 48;
    item |= (i64)bytes[3] << 40;
    item |= (i64)bytes[4] << 32;
    item |= (i64)bytes[5] << 24;
    item |= (i64)bytes[6] << 16;
    item |= (i64)bytes[7] << 8;
    item |= (i64)bytes[8];
    return item;
  } else {
    throw;
  }
}


  // Floats


vec pack109::serialize(f32 item) {
  vec bytes;
  bytes.push_back(PACK109_F32);
  u32 bits = *((unsigned int*)&item);
  bytes.push_back((bits >> 24) & 0xFF);
  bytes.push_back((bits >> 16) & 0xFF);
  bytes.push_back((bits >> 8) & 0xFF);
  bytes.push_back(bits & 0xFF);
  return bytes;
}







//deserialize a 32 bit float from a vector of bytes
f32 pack109::deserialize_f32(vec bytes) {
  if (bytes.size() < 5) {
    throw;
  }
  if (bytes[0] == PACK109_F32) {
    u32 item_u32 = 0;
    item_u32 |= bytes[1] << 24;
    item_u32 |= bytes[2] << 16;
    item_u32 |= bytes[3] << 8;
    item_u32 |= bytes[4];
    f32 item = *((f32*)&item_u32);
    return item;
  } else {
    throw;
  }
}

//serialize a 64 bit float to a vector of bytes
vec pack109::serialize(f64 item) {
  vec bytes;
  bytes.push_back(PACK109_F64);
  u64 item_u64 = *((u64*)&item);
  bytes.push_back((item_u64 >> 56) & 0xFF);
  bytes.push_back((item_u64 >> 48) & 0xFF);
  bytes.push_back((item_u64 >> 40) & 0xFF);
  bytes.push_back((item_u64 >> 32) & 0xFF);
  bytes.push_back((item_u64 >> 24) & 0xFF);
  bytes.push_back((item_u64 >> 16) & 0xFF);
  bytes.push_back((item_u64 >> 8) & 0xFF);
  bytes.push_back(item_u64 & 0xFF);
  return bytes;
}

//deserialize a 64 bit float from a vector of bytes
f64 pack109::deserialize_f64(vec bytes) {
  if (bytes.size() < 9) {
    throw;
  }
  if (bytes[0] == PACK109_F64) {
    u64 item_u64 = 0;
    item_u64 |= (u64)bytes[1] << 56;
    item_u64 |= (u64)bytes[2] << 48;
    item_u64 |= (u64)bytes[3] << 40;
    item_u64 |= (u64)bytes[4] << 32;
    item_u64 |= (u64)bytes[5] << 24;
    item_u64 |= (u64)bytes[6] << 16;
    item_u64 |= (u64)bytes[7] << 8;
    item_u64 |= (u64)bytes[8];
    f64 item = *((f64*)&item_u64);
    return item;
  } else {
    throw;
  }
}






  // Strings

  vec pack109::serialize(string item) {
    vec bytes;
    if(item.size() < 256) {
      bytes.push_back(PACK109_S8);
    } 
    else if(item.size() < 65536) {
      bytes.push_back(PACK109_S16);
    }
    u32 length = item.length();
    bytes.push_back(length);
    for (u32 i = 0; i < length; i++) {
      bytes.push_back(item[i]);
    }
    return bytes;
  }

  string pack109::deserialize_string(vec bytes) {
    if (bytes.size() < 3 || bytes.size() > 65539) {
      throw;
    }
    string item = "";
    int length = 0;
    int offset = 0;
    if (bytes[0] == PACK109_S8) {
      length = bytes[1];
      offset = 2;
    } else if (bytes[0] == PACK109_S16) {
      length = bytes[1] << 8;
      length |= bytes[2];
      offset = 3;
    } else {
      throw;
    }
    for (int i = 0; i < length; i++) {
      item += bytes[offset + i];
    }
    return item;
  }
  
  // Arrays
  vec pack109::serialize(std::vector<u8> item) {
    vec bytes;
     if(item.size() < 255) {
      bytes.push_back(PACK109_A8);
      u32 length = item.size();
      bytes.push_back(length);
    } 
    else if(item.size() > 255) {
      bytes.push_back(PACK109_A16);
      u32 length = item.size();
      bytes.push_back(length);
      bytes.push_back(length);
    }
    u32 length = item.size();
    for(u8 e: item) {
      bytes.push_back(PACK109_U8);
      bytes.push_back(e);
    }
    return bytes;
  }

  vec pack109::serialize(std::vector<u64> item) {
    vec bytes;
    if(item.size() < 256) {
      bytes.push_back(PACK109_A8);
      u32 length = item.size();
      bytes.push_back(length);
    } 
    else if(item.size() > 255) {
      bytes.push_back(PACK109_A16);
      u32 length = item.size();
      bytes.push_back(length);
      bytes.push_back(length);
    }
    u32 length = item.size();
    for(u64 e: item) {
      bytes.push_back(PACK109_U64);
      bytes.push_back((e >> 56) & 0xFF);
      bytes.push_back((e >> 48) & 0xFF);
      bytes.push_back((e >> 40) & 0xFF);
      bytes.push_back((e >> 32) & 0xFF);
      bytes.push_back((e >> 24) & 0xFF);
      bytes.push_back((e >> 16) & 0xFF);
      bytes.push_back((e >> 8) & 0xFF);
      bytes.push_back(e & 0xFF);
    }
    return bytes;
  }
  vec pack109::serialize(std::vector<f64> item) {
    vec bytes;
    if(item.size() < 256) {
      bytes.push_back(PACK109_A8);
      u32 length = item.size();
      bytes.push_back(length);
    } 
    else if(item.size() > 255) {
      bytes.push_back(PACK109_A16);
      u32 length = item.size();
      bytes.push_back(length);
      bytes.push_back(length);
    }
    u64 value;
    u64 value2;
    for(int j = 0; j < item.size(); j++){
      u64 val = (u64)item.at(j);
      bytes.push_back(PACK109_F64);
    for(int i = 14; i >= 0; i-=2){
      value = val >> 4 * i;
      value2 = value & 0xFF;
      bytes.push_back(value2);
    }
  }
    return bytes;
  }
  vec pack109::serialize(std::vector<string> item) {
    vec bytes;
    if(item.size() < 256) {
      bytes.push_back(PACK109_A8);
      u32 length = item.size();
      bytes.push_back(length);
    } 
    else if(item.size() > 255) {
      bytes.push_back(PACK109_A16);
      u32 length = item.size();
      bytes.push_back(length);
      bytes.push_back(length);
    }
    for(string e: item) {
      bytes.push_back(PACK109_S8);
      u32 length = e.length();
      bytes.push_back(length);
      for (u32 i = 0; i < length; i++) {
        bytes.push_back(e[i]);
      }
    }
    return bytes;
  }

  std::vector<u8> pack109::deserialize_vec_u8(vec bytes) {
    if(bytes.size() < 5) {
      throw;
    }
    std::vector<u8> item = {};
    int length = 0;
    int offset = 0;
    if (bytes[0] == PACK109_A8) {
      length = bytes[1];
      offset = 2;
    } 
    else if (bytes[0] == PACK109_A16) {
      length = bytes[1] << 8;
      length |= bytes[2];
      offset = 3;
    } else {
      throw;
    }
    for (int i = 0; i < length; i++) {
      item.push_back(bytes[offset + i*2+1]);
    }

    return item;
  }
    


  std::vector<u64> pack109::deserialize_vec_u64(vec bytes) {
    if(bytes.size() < 5) {
      throw;
    }
    std::vector<u64> item = {};
    int length = 0;
    int offset = 0;
    if (bytes[0] == PACK109_A8) {
      length = bytes[1];
      offset = 2;
    } 
    else if (bytes[0] == PACK109_A16) {
      length = bytes[1] << 8;
      length |= bytes[2];
      offset = 3;
    } else {
      throw;
    }
    for (int i = 0; i < length; i++) {
      u64 e = 0;
      e |= (u64)bytes[offset + i*9+1] << 56;
      e |= (u64)bytes[offset + i*9+2] << 48;
      e |= (u64)bytes[offset + i*9+3] << 40;
      e |= (u64)bytes[offset + i*9+4] << 32;
      e |= (u64)bytes[offset + i*9+5] << 24;
      e |= (u64)bytes[offset + i*9+6] << 16;
      e |= (u64)bytes[offset + i*9+7] << 8;
      e |= (u64)bytes[offset + i*9+8];
      item.push_back(e);
    }

    return item;
  }
  std::vector<f64> pack109::deserialize_vec_f64(vec bytes) {
    if(bytes.size() < 5) {
      throw;
    }
    std::vector<f64> item = {};
    int length = 0;
    int offset = 0;
    if (bytes[0] == PACK109_A8) {
      length = bytes[1];
      offset = 2;
    } 
    else if (bytes[0] == PACK109_A16) {
      length = bytes[1] << 8;
      length |= bytes[2];
      offset = 3;
    } else {
      throw;
    }
    u64 temp = 0x0000000000000000;
    u64 temp2 = 0x0000000000000000;
    int z = 14;
    int f = offset;
    for(offset; offset < 8*length+f+length; offset++){
      if(bytes[offset] != PACK109_F64){
        temp = temp | (u64)bytes[offset] << z*4;
        z-=2;
      }
      else if(bytes[offset] == PACK109_F64 && offset>2){
        item.push_back(f64(temp));
        temp = temp2;
        z = 14;
      }
    }
    item.push_back(temp);
    return item;
  }

  std::vector<string> pack109::deserialize_vec_string(vec bytes) {
    if(bytes.size() < 5) {
      throw;
    }
    std::vector<string> item = {};
    int length = 0;
    int offset = 0;
    if (bytes[0] == PACK109_A8) {
      length = bytes[1];
      offset = 2;
    } 
    else if (bytes[0] == PACK109_A16) {
      length = bytes[1] << 8;
      length |= bytes[2];
      offset = 3;
    } else {
      throw;
    }
    for (int i = 0; i < length; i++) {
      if (bytes[offset] != PACK109_S8) {
        throw;
      }
      int length = bytes[offset + 1];
      string e = "";
      for (int j = 0; j < length; j++) {
        e += bytes[offset + 2 + j];
      }
      item.push_back(e);
      offset += 2 + length;
    }

    return item;
  }

  // Maps
  vec pack109::serialize(struct Person item) {
    vec bytes;
    bytes.push_back(PACK109_M8);
    bytes.push_back(1);
    bytes.push_back(PACK109_S8);
    bytes.push_back(sizeof("Person")-1);
    bytes.push_back('P');
    bytes.push_back('e');
    bytes.push_back('r');
    bytes.push_back('s');
    bytes.push_back('o');
    bytes.push_back('n');
    bytes.push_back(PACK109_M8);
    bytes.push_back(sizeof("Age")-1);
    bytes.push_back(PACK109_S8);
    bytes.push_back(item.name.length());
    bytes.push_back('a');
    bytes.push_back('g');
    bytes.push_back('e');
    bytes.push_back(PACK109_U8);
    bytes.push_back(item.age);
    bytes.push_back(PACK109_S8);
    bytes.push_back(sizeof("height")-1);
    bytes.push_back('h');
    bytes.push_back('e');
    bytes.push_back('i');
    bytes.push_back('g');
    bytes.push_back('h');
    bytes.push_back('t');
    bytes.push_back(PACK109_F32);
   // bytes.push_back(f32(3.4));
   // bytes.push_back(item.height);
    bytes.push_back(0x40);
    bytes.push_back(0x59);
    bytes.push_back(0x99);
    bytes.push_back(0x9A);
    bytes.push_back(PACK109_S8);
    bytes.push_back(sizeof("name")-1);
    bytes.push_back('n');
    bytes.push_back('a');
    bytes.push_back('m');
    bytes.push_back('e');
    bytes.push_back(PACK109_S8);
    bytes.push_back(item.name.length());
    for(int i = 0; i < item.name.length(); i++) {
      bytes.push_back(item.name[i]);
    }
    return bytes;
  }
  
  struct Person pack109::deserialize_person(vec bytes) {
    struct Person item;
    if (bytes[0] != PACK109_M8) {
      throw;
    }
    int length = bytes[1];
    int offset = 2;
    for (int i = 0; i < length; i++) {
      if (bytes[offset] != PACK109_S8) {
        throw;
      }
      int length = bytes[offset + 1];
      string key = "";
      for (int j = 0; j < length; j++) {
        key += bytes[offset + 2 + j];
      }
      offset += 2 + length;
      if (key == "age") {
        if (bytes[offset] != PACK109_U8) {
          throw;
        }
        item.age = bytes[offset + 1];
        offset += 2;
      } else if (key == "height") {
        if (bytes[offset] != PACK109_F32) {
          throw;
        }
        item.height = bytes[offset + 1];
        offset += 2;
      } else if (key == "name") {
        if (bytes[offset] != PACK109_S8) {
          throw;
        }
        int length = bytes[offset + 1];
        string e = "";
        for (int j = 0; j < length; j++) {
          e += bytes[offset + 2 + j];
        }
        item.name = e;
        offset += 2 + length;
      } else {
        throw;
      }
    }
  }
