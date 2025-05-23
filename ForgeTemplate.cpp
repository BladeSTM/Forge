/*
* Copyright (C) 2010 - 2024 Forge Lua Engine <https://forgeluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

// Forge
#include "LuaEngine.h"
#include "ForgeIncludes.h"
#include "ForgeTemplate.h"
#include "ForgeUtility.h"

template<> inline int ForgeTemplate<unsigned long long>::Add(lua_State* L) { return ForgeTemplateHelper<unsigned long long>::PerformOp(L, std::plus()); }
template<> inline int ForgeTemplate<unsigned long long>::Subtract(lua_State* L) { return ForgeTemplateHelper<unsigned long long>::PerformOp(L, std::minus()); }
template<> inline int ForgeTemplate<unsigned long long>::Multiply(lua_State* L) { return ForgeTemplateHelper<unsigned long long>::PerformOp(L, std::multiplies()); }
template<> inline int ForgeTemplate<unsigned long long>::Divide(lua_State* L) { return ForgeTemplateHelper<unsigned long long>::PerformOp(L, std::divides()); }
template<> inline int ForgeTemplate<unsigned long long>::Mod(lua_State* L) { return ForgeTemplateHelper<unsigned long long>::PerformOp(L, std::modulus()); }
template<> inline int ForgeTemplate<unsigned long long>::Equal(lua_State* L) { return ForgeTemplateHelper<unsigned long long>::PerformOp(L, std::equal_to()); }
template<> inline int ForgeTemplate<unsigned long long>::Less(lua_State* L) { return ForgeTemplateHelper<unsigned long long>::PerformOp(L, std::less()); }
template<> inline int ForgeTemplate<unsigned long long>::LessOrEqual(lua_State* L) { return ForgeTemplateHelper<unsigned long long>::PerformOp(L, std::less_equal()); }
template<> inline int ForgeTemplate<unsigned long long>::ToString(lua_State* L) { return ForgeTemplateHelper<unsigned long long>::ToString(L); }
template<> inline int ForgeTemplate<unsigned long long>::Pow(lua_State* L) { return ForgeTemplateHelper<unsigned long long>::Pow(L); }

template<> inline int ForgeTemplate<long long>::Add(lua_State* L) { return ForgeTemplateHelper<long long>::PerformOp(L, std::plus()); }
template<> inline int ForgeTemplate<long long>::Subtract(lua_State* L) { return ForgeTemplateHelper<long long>::PerformOp(L, std::minus()); }
template<> inline int ForgeTemplate<long long>::Multiply(lua_State* L) { return ForgeTemplateHelper<long long>::PerformOp(L, std::multiplies()); }
template<> inline int ForgeTemplate<long long>::Divide(lua_State* L) { return ForgeTemplateHelper<long long>::PerformOp(L, std::divides()); }
template<> inline int ForgeTemplate<long long>::Mod(lua_State* L) { return ForgeTemplateHelper<long long>::PerformOp(L, std::modulus()); }
template<> inline int ForgeTemplate<long long>::UnaryMinus(lua_State* L) { return ForgeTemplateHelper<long long>::PerformOp(L, std::negate()); }
template<> inline int ForgeTemplate<long long>::Equal(lua_State* L) { return ForgeTemplateHelper<long long>::PerformOp(L, std::equal_to()); }
template<> inline int ForgeTemplate<long long>::Less(lua_State* L) { return ForgeTemplateHelper<long long>::PerformOp(L, std::less()); }
template<> inline int ForgeTemplate<long long>::LessOrEqual(lua_State* L) { return ForgeTemplateHelper<long long>::PerformOp(L, std::less_equal()); }
template<> inline int ForgeTemplate<long long>::ToString(lua_State* L) { return ForgeTemplateHelper<long long>::ToString(L); }
template<> inline int ForgeTemplate<long long>::Pow(lua_State* L) { return ForgeTemplateHelper<long long>::Pow(L); }

template<> inline int ForgeTemplate<ObjectGuid>::Equal(lua_State* L) { Forge* F = Forge::GetForge(L); F->Push(F->CHECKVAL<ObjectGuid>(1) == F->CHECKVAL<ObjectGuid>(2)); return 1; }
template<> inline int ForgeTemplate<ObjectGuid>::ToString(lua_State* L)
{
    Forge* F = Forge::GetForge(L);
#if defined FORGE_TRINITY
    F->Push(F->CHECKVAL<ObjectGuid>(1).ToString());
#else
    F->Push(F->CHECKVAL<ObjectGuid>(1).GetString());
#endif
    return 1;
}
