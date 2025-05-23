/*
 * Copyright (C) 2010 - 2024 Forge Lua Engine <https://forgeluaengine.github.io/>
 * This program is free software licensed under GPL version 3
 * Please see the included DOCS/LICENSE.md for more information
 */

#include "Hooks.h"
#include "HookHelpers.h"
#include "LuaEngine.h"
#include "BindingMap.h"
#include "ForgeTemplate.h"

using namespace Hooks;

#define START_HOOK(EVENT) \
    auto key = EventKey<GroupEvents>(EVENT);\
    if (!GroupEventBindings->HasBindingsFor(key))\
        return;

#define START_HOOK_WITH_RETVAL(EVENT, RETVAL) \
    auto key = EventKey<GroupEvents>(EVENT);\
    if (!GroupEventBindings->HasBindingsFor(key))\
        return RETVAL;

void Forge::OnAddMember(Group* group, ObjectGuid guid)
{
    START_HOOK(GROUP_EVENT_ON_MEMBER_ADD);
    HookPush(group);
    HookPush(guid);
    CallAllFunctions(GroupEventBindings, key);
}

void Forge::OnInviteMember(Group* group, ObjectGuid guid)
{
    START_HOOK(GROUP_EVENT_ON_MEMBER_INVITE);
    HookPush(group);
    HookPush(guid);
    CallAllFunctions(GroupEventBindings, key);
}

void Forge::OnRemoveMember(Group* group, ObjectGuid guid, uint8 method)
{
    START_HOOK(GROUP_EVENT_ON_MEMBER_REMOVE);
    HookPush(group);
    HookPush(guid);
    HookPush(method);
    CallAllFunctions(GroupEventBindings, key);
}

void Forge::OnChangeLeader(Group* group, ObjectGuid newLeaderGuid, ObjectGuid oldLeaderGuid)
{
    START_HOOK(GROUP_EVENT_ON_LEADER_CHANGE);
    HookPush(group);
    HookPush(newLeaderGuid);
    HookPush(oldLeaderGuid);
    CallAllFunctions(GroupEventBindings, key);
}

void Forge::OnDisband(Group* group)
{
    START_HOOK(GROUP_EVENT_ON_DISBAND);
    HookPush(group);
    CallAllFunctions(GroupEventBindings, key);
}

void Forge::OnCreate(Group* group, ObjectGuid leaderGuid, GroupType groupType)
{
    START_HOOK(GROUP_EVENT_ON_CREATE);
    HookPush(group);
    HookPush(leaderGuid);
    HookPush(groupType);
    CallAllFunctions(GroupEventBindings, key);
}

bool Forge::OnMemberAccept(Group* group, Player* player)
{
    START_HOOK_WITH_RETVAL(GROUP_EVENT_ON_MEMBER_ACCEPT, true);
    HookPush(group);
    HookPush(player);
    return CallAllFunctionsBool(GroupEventBindings, key, true);
}
