#include "../include/Serializer.hpp"

int main() {
  Serializer serializer;
  Data *data = new Data;
  Data *data2;
  uintptr_t raw;

  data->str = "Up";
  data->num = 42;
  data->ch = 'J';
  data->fl = 42.42f;
  data->dbl = 42.42;

  raw = serializer.serialize(data);

  std::cout << "Serial representation:" << raw << std::endl;
  data2 = serializer.deserialize(raw);
  std::cout << data2->str << std::endl;
  std::cout << data2->num << std::endl;
  std::cout << data2->ch << std::endl;
  std::cout << data2->fl << 'f' << std::endl;
  std::cout << data2->dbl << std::endl;

  delete data;
  return 0;
}