//-- CONTROLS	
    #include "\a3\editor_f\Data\Scripts\dikCodes.h";
	disableSerialization;
	[
		"TSP General", 
		"tsp_melee_meleeKeyDouble", 
		"Melee (Double Tap)", 
		{
			if !(tsp_cba_melee) exitWith {};			
			[] spawn {  //-- Double tap
				if (isNil "tsp_melee_lastKeyPress") exitWith {tsp_melee_lastKeyPress = true; sleep 0.5;tsp_melee_lastKeyPress = nil};  
				[player] spawn tsp_fnc_melee_on;				
			};
		},
		{[player] spawn tsp_fnc_melee_off},
		[null, [false, false, false]]
	] call CBA_fnc_addKeybind;

	[
		"TSP General", 
		"tsp_melee_meleeKeyToggle", 
		"Melee (Toggle)", 
		{
			if !(tsp_cba_melee) exitWith {};
			if (isNil "tsp_melee_meleeModeOn") then {
				[player] spawn tsp_fnc_melee_on;				
			} else {
				[player] spawn tsp_fnc_melee_off;	
			};
		},
		{},
		[null, [false, false, false]]
	] call CBA_fnc_addKeybind;

	[
		"TSP General", 
		"tsp_melee_meleeKeyDoubleTapToggle", 
		"Melee (Double Tap, Toggle)", 
		{
			if !(tsp_cba_melee) exitWith {};
			if (!isNil "tsp_melee_meleeModeOn") exitWith {[player] spawn tsp_fnc_melee_off};
			[] spawn {  //-- Double tap
				if (isNil "tsp_melee_lastKeyPress") exitWith {tsp_melee_lastKeyPress = true; sleep 0.5;tsp_melee_lastKeyPress = nil};  
				if (isNil "tsp_melee_meleeModeOn") then {[player] spawn tsp_fnc_melee_on};			
			};
		},
		{},
		[DIK_F, [false, false, false]]
	] call CBA_fnc_addKeybind;

//-- SETTINGS
	//-- Melee
    [
        "tsp_cba_melee", "CHECKBOX",
        ["Enable Melee", "Enables melee mode activation."],
        "TSP Melee", true, true, {}
    ] call CBA_Settings_fnc_init;

//-- BAYONET SWAPPING
	tsp_fnc_melee_bayonetSwap = {  //-- Add ACE actions for each knife that calls the function
		params ["_knife", "_bayonet"];		

		_displayName = "Convert " + (getText (configFile >> "CfgWeapons" >> _knife >> "displayName"));

		//-- Knife to bayonet
		_knifeToBayonetCond = (str _knife) + " in items player || handgunWeapon player == " + (str _knife);
		tsp_fnc_melee_knifeToBayonet = {
			params ["_knife", "_bayonet"];			
			switch (true) do {  //-- Remove knife from inventory/handgun slot
				case (_knife in items player): {player removeItem _knife};
				case (handgunWeapon player == _knife): {player removeWeapon _knife};
			};
			switch (true) do {  //-- Add bayonet to inventory if possible, else drop on ground
				case (player canAdd _bayonet): {player addItem _bayonet};
				default {
					_holder = createVehicle ["GroundWeaponHolder", getPosATL player, [], 0, "CAN_COLLIDE"];
					_holder addItemCargoGlobal [_bayonet, 1];
				};
			};
			player action ["GEAR", null];
		};
		_knifeToBayonetCode = "["+str _knife+","+str _bayonet+"] call tsp_fnc_melee_knifeToBayonet";
		_knifeToBayonetAction = [_displayName, _displayName, "\tsp_melee\gui\knife.paa", compile _knifeToBayonetCode, compile _knifeToBayonetCond] call ace_interact_menu_fnc_createAction;
		["CAManBase", 1, ["ACE_SelfActions","ACE_Equipment"], _knifeToBayonetAction, true] call ace_interact_menu_fnc_addActionToClass; 

		//-- Bayonet to knife
		_bayonetToKnifeCond = (str _bayonet) + " in items player || " + (str _bayonet) + " in primaryWeaponItems player";
		tsp_fnc_melee_bayonetToKnife = {
			params ["_knife", "_bayonet"];			
			switch (true) do {  //-- Remove bayonet from inventory/primary weapon attachment slot
				case (_bayonet in items player): {player removeItem _bayonet};
				case (_bayonet in primaryWeaponItems player): {player removePrimaryWeaponItem _bayonet};
			};
			switch (true) do {  //-- Add knife to handgun slot if possible, else try to put it in inventory or drop on ground if no space
				case (handgunWeapon player == ""): {player addWeapon _knife};
				case (player canAdd _knife): {player addItem _knife};
				default {
					_holder = createVehicle ["GroundWeaponHolder", getPosATL player, [], 0, "CAN_COLLIDE"];
					_holder addItemCargoGlobal [_knife, 1];
				};
			};
			player action ["GEAR", null];
		};
		_bayonetToKnifeCode = "["+str _knife+","+str _bayonet+"] call tsp_fnc_melee_bayonetToKnife";
		_bayonetToKnifeAction = [_displayName, _displayName, "\tsp_melee\gui\bayonet.paa", compile _bayonetToKnifeCode, compile _bayonetToKnifeCond] call ace_interact_menu_fnc_createAction;
		["CAManBase", 1, ["ACE_SelfActions","ACE_Equipment"], _bayonetToKnifeAction, true] call ace_interact_menu_fnc_addActionToClass; 
	};