#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include "Data.hpp"
#include <cstdint>
#include <iostream>

class Serializer {
 public:
	 static uintptr_t serialize(Data *ptr);
	 static Data* deserialize(uintptr_t raw);

 private:
  // Constuctor/Destructor
  Serializer(void);
  Serializer(const Serializer& other);
  Serializer& operator=(const Serializer& rhs);
  ~Serializer(void);

};

#endif
