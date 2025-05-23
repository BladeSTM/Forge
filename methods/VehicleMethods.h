/*
* Copyright (C) 2010 - 2024 Forge Lua Engine <https://forgeluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef VEHICLEMETHODS_H
#define VEHICLEMETHODS_H

/***
 * Inherits all methods from: none
 */
namespace LuaVehicle
{
    /**
     * Returns true if the [Unit] passenger is on board
     *
     * @param [Unit] passenger
     * @return bool isOnBoard
     */
    int IsOnBoard(Forge* F, Vehicle* vehicle)
    {
        Unit* passenger = F->CHECKOBJ<Unit>(2);

        F->Push(passenger->IsOnVehicle(vehicle->GetBase()));
        return 1;
    }

    /**
     * Returns the [Vehicle]'s owner
     *
     * @return [Unit] owner
     */
    int GetOwner(Forge* F, Vehicle* vehicle)
    {
        F->Push(vehicle->GetBase());
        return 1;
    }

    /**
     * Returns the [Vehicle]'s entry
     *
     * @return uint32 entry
     */
    int GetEntry(Forge* F, Vehicle* vehicle)
    {
        F->Push(vehicle->GetVehicleInfo()->ID);
        return 1;
    }

    /**
     * Returns the [Vehicle]'s passenger in the specified seat
     *
     * @param int8 seat
     * @return [Unit] passenger
     */
    int GetPassenger(Forge* F, Vehicle* vehicle)
    {
        int8 seatId = F->CHECKVAL<int8>(2);
        F->Push(vehicle->GetPassenger(seatId));
        return 1;
    }

    /**
     * Adds [Unit] passenger to a specified seat in the [Vehicle]
     *
     * @param [Unit] passenger
     * @param int8 seat
     */
    int AddPassenger(Forge* F, Vehicle* vehicle)
    {
        Unit* passenger = F->CHECKOBJ<Unit>(2);
        int8 seatId = F->CHECKVAL<int8>(3);

        vehicle->AddPassenger(passenger, seatId);
        return 0;
    }

    /**
     * Removes [Unit] passenger from the [Vehicle]
     *
     * @param [Unit] passenger
     */
    int RemovePassenger(Forge* F, Vehicle* vehicle)
    {
        Unit* passenger = F->CHECKOBJ<Unit>(2);

        vehicle->RemovePassenger(passenger);
        return 0;
    }
    
    ForgeRegister<Vehicle> VehicleMethods[] =
    {
        // Getters
        { "GetOwner", &LuaVehicle::GetOwner },
        { "GetEntry", &LuaVehicle::GetEntry },
        { "GetPassenger", &LuaVehicle::GetPassenger },

        // Boolean
        { "IsOnBoard", &LuaVehicle::IsOnBoard },

        // Other
        { "AddPassenger", &LuaVehicle::AddPassenger },
        { "RemovePassenger", &LuaVehicle::RemovePassenger }
    };
}

#endif // VEHICLEMETHODS_H
