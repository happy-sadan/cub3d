#include "fakes/OpenFake.h"

int OpenFake(const char *path, int, va_list) {
  if (ft_strcmp(path, VALID_CFGPATH))
    return -1;
  return VALID_FD;
}
