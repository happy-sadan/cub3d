#include "fakes/OpenFake.h"
#include "test.h"
extern "C" {
#include "cub3d.h"
}

FAKE_VALUE_FUNC_VARARG(int, open, const char *, int, ...);

using ::testing::Test;

DEFINE_FFF_GLOBALS;

class GetConfFdTest : public Test {
 protected:
    void SetUp() override {
      RESET_FAKE(open);
      open_fake.custom_fake = OpenFake;
    }
};

TEST_F(GetConfFdTest, handlesValidPath) {
  EXPECT_EQ(get_conf_fd(VALID_CFGPATH), VALID_FD);
}

TEST_F(GetConfFdTest, handlesInvalidPath) {
  ASSERT_ERR(get_conf_fd(INVALID_CFGPATH), E_CFGPATH);
}
