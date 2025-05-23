/*
* Copyright (C) 2010 - 2024 Forge Lua Engine <https://forgeluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

// This file is used for custom Lua methods, without needing to edit the existing method header files.
// This can also be used to override default methods without needing to edit existing methods.
// It follows the same structure as any other method header, except you can use RegisterCustomFunction
// to register multiple method tables in a single file.

#include "ForgeTemplate.h"
#include "ForgeIncludes.h"

#ifndef CUSTOMMETHODS_H
#define CUSTOMMETHODS_H

namespace LuaCustom
{
    // Define a custom method that returns the players name
    int CustomPlayerMethod(Forge* F, Player* player)
    {
        F->Push(player->GetName());
        return 1;
    }

    // Create a custom player method registry
    ForgeRegister<Player> CustomPlayerMethods[] =
    {
        // Add the custom player method to the registry
        { "CustomPlayerMethod", &LuaCustom::CustomPlayerMethod },
    };

    inline void RegisterCustomMethods([[maybe_unused]] Forge* F)
    {
        // Append all the custom Player methods to the Player object
        ForgeTemplate<Player>::SetMethods(F, CustomPlayerMethods);
    };
};

#endif
