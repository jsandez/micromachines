#include "includes/3rd-party/lua/LuaInterprete.hpp"


LuaInterpreter::LuaInterpreter(){
    L = luaL_newstate();
    luaL_openlibs(L);
}


void LuaInterpreter::init_script(const char * filepath){
	int ret = luaL_dofile(L, filepath);
	if (ret){
		throw std::runtime_error("Error en el script: " + std::string(lua_tostring(L, ret)));
	}
}

template<typename T>
T LuaInterpreter::get() {
  int stackSize = lua_gettop(L);
  if (!stackSize){
  	throw std::runtime_error("No hay elementos en el stack");
  }
  T element;
  element = lua_get<T>();
  lua_pop(L, -1);

  return element;
}


void LuaInterpreter::call_function(const char * fname, int params, int outparams){
  lua_call(L, params, outparams);
}


void LuaInterpreter::operator<<(const std::string &str){
	lua_pushlstring(L, str.c_str(), str.size());
}

void LuaInterpreter::operator<<(int num){
		lua_pushnumber(L, num);
}

void LuaInterpreter::operator<<(float num){
		lua_pushnumber(L, num);
}

void LuaInterpreter::operator<<(bool b){
		lua_pushboolean(L, b);
}

LuaInterpreter::~LuaInterpreter(){
    if(L){
    	lua_close(L);
	}
}