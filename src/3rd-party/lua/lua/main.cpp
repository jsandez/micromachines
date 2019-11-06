//#include <sol.hpp>
#include <cassert>

extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

int main() {
    L = luaL_newstate();
}