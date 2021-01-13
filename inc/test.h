#ifndef INC_TEST_H_
#define INC_TEST_H_

extern "C" {
#include "libft.h"
}

#include "fff.h"

#include <gtest/gtest.h>

#define VALID_CFGPATH (char *)"valid.cub"
#define INVALID_CFGPATH (char *)"invalid.cub"
#define VALID_FD 42

#define ASSERT_ERR(FUNC, ERR) \
	ASSERT_EXIT(FUNC, ::testing::ExitedWithCode(ERR), "")

#endif  // INC_TEST_H_
