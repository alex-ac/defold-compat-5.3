#define LIB_NAME "Compat53"
#define MODULE_NAME "compat53.module"

#include <dmsdk/sdk.h>

#include "lprefix.h"

LUAMOD_API int luaopen_compat53_utf8(lua_State*);
LUAMOD_API int luaopen_compat53_string(lua_State*);
LUAMOD_API int luaopen_compat53_table(lua_State*);
LUAMOD_API int luaopen_bit32(lua_State*);

dmExtension::Result AppInitializeCompat53(dmExtension::AppParams* params) {
	return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeCompat53(dmExtension::Params* params) {
	// luaopen_bit32(params->m_L);
	// luaopen_string(params->m_L);
	// luaopen_table(params->m_L);
	lua_getglobal(params->m_L, "package");
	lua_getfield(params->m_L, -1, "loaded");
	luaopen_compat53_utf8(params->m_L);
	lua_setfield(params->m_L, -2, "compat53.utf8");
	luaopen_compat53_string(params->m_L);
	lua_setfield(params->m_L, -2, "compat53.string");
	luaopen_compat53_table(params->m_L);
	lua_setfield(params->m_L, -2, "compat53.table");
	lua_pop(params->m_L, 2);
	return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeCompat53(dmExtension::AppParams* params) {
	return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeCompat53(dmExtension::Params* params) {
	return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(Compat53, LIB_NAME, AppInitializeCompat53, AppFinalizeCompat53, InitializeCompat53, NULL, NULL, FinalizeCompat53);