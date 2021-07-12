//-- This method sucks, if anyone knows how to make proper movesets, let me know
tsp_fnc_melee_getMoveset = {
    params ["_unit"];
    _currentAnimMoveset = getNumber (configFile >> "CfgMovesMaleSdr" >> "States">> (animationState _unit) >> "knifeMoveset");
    if (_currentAnimMoveset == 0) exitWith {"default"};
    if (_currentAnimMoveset == 1) exitWith {"knife"};
};

tsp_fnc_melee_movesetChanger = {
    params ["_unit", "_moveset"];
    if (([_unit] call tsp_fnc_melee_getMoveset) isEqualTo _moveset) exitWith {};  //-- If trying to replace current moveset with same one, do nothing
    if (vehicle _unit != _unit) exitWith {};
    if !(isNil "tsp_melee_movesetChange") exitWith {};
    [] spawn {tsp_melee_movesetChange = true; sleep 0.5; tsp_melee_movesetChange = nil};
    _animToPlay = "";
    if (_moveset == "knife") then {
        //systemChat "KNIFE";
        _animToPlay = "tsp_" + (animationState player);
        if (["wpst", _animToPlay] call BIS_fnc_inString || ["wrfl", _animToPlay] call BIS_fnc_inString) then {
            _front = [_animToPlay, 0, 15] call BIS_fnc_trimString;
            _back = [_animToPlay, 24] call BIS_fnc_trimString;
            _animToPlay = _front + "snonwnon" + _back;  
            _unit playActionNow "tsp_common_stop";  
        };
        if (["mtac", _animToPlay] call BIS_fnc_inString) then {
            _front = [_animToPlay, 0, 11] call BIS_fnc_trimString;
            _back = [_animToPlay, 16] call BIS_fnc_trimString;
            _animToPlay = _front + "mwlk" + _back;
            //systemChat ("MWLK: " + _animToPlay);
        };        
    } else {
        //systemChat "DEFAULT";
        _animToPlay = ((animationState player) splitString "_")#1;
        _front = [_animToPlay, 0, 11] call BIS_fnc_trimString;
        _back = [_animToPlay, 20] call BIS_fnc_trimString;
        if (!isNil "tsp_melee_meleeModeOn") then {_animToPlay = _front + "sraswpst" + _back};
        if (isNil "tsp_melee_meleeModeOn") then {_unit playActionNow "tsp_common_stop"};
    };
    _unit playMoveNow _animToPlay;
    if (isNil "tsp_melee_meleeModeOn") then {_unit playActionNow "tsp_common_stop"};
};

tsp_fnc_melee_movesetHandler = {
    params ["_unit"];
    _moveset = getNumber (configFile >> "CfgWeapons" >> (currentWeapon _unit) >> "meleeInfo" >> "moveset");
    if (_moveset == 1) then {  //-- If current weapon has custom moveset
        if (!isNil "tsp_melee_meleeModeOn") then {  //-- If melee mode
            _movesetReady = getText (configFile >> "CfgWeapons" >> (currentWeapon _unit) >> "meleeInfo" >> "movesetReady");
            [_unit, _movesetReady] call tsp_fnc_melee_movesetChanger;
        } else {
            _movesetRest = getText (configFile >> "CfgWeapons" >> (currentWeapon _unit) >> "meleeInfo" >> "movesetRest");
            [_unit, _movesetRest] call tsp_fnc_melee_movesetChanger;
        }; 
    } else {
        [_unit, "default"] call tsp_fnc_melee_movesetChanger;
    };
};

[] spawn {    
    //sleep 1;
    (findDisplay 46) displayAddEventHandler ["KeyDown", {
        if (!tsp_cba_melee_moveset) exitWith {};
        [player] spawn tsp_fnc_melee_movesetHandler;
    }];
    while {tsp_cba_melee_moveset} do {
        sleep tsp_cba_melee_movesetPoll;             
        [player] call tsp_fnc_melee_movesetHandler;
    };
};