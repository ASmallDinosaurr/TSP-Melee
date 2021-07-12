if (isNil "ace_medical_disabled") then {ace_medical_disabled = false};

tsp_fnc_melee_on = {    
    params ["_unit"];
    _currentMeleeWeapon = [_unit] call tsp_fnc_melee_getMeleeWeapon;

    //-- Exceptions
    if (!isNil "tsp_melee_meleeModeOn") exitWith {};  //-- No double calling of this function
    if (_unit getVariable ["ace_captives_isSurrendering", false]) exitWith {};  //-- No melee while surrendered
    if (_unit getVariable ["ace_captives_handcuffAnimEHID", -1] != -1) exitWith {};  //-- No melee while handcuffed
    if (vehicle _unit != _unit) exitWith {};  //-- No melee in vehicles
    if (isActionMenuVisible) exitWith {};  //-- No melee while scrolling
    if (tsp_gesture_current == "switch") then {tsp_gesture_current = ""};
    if (tsp_gesture_current != "") exitWith {};  //-- No melee while doing gestures
    if (stance _unit == "PRONE" || stance _unit == "UNDEFINED") exitWith {};  //-- No melee while prone    
    if (_currentMeleeWeapon == "") exitWith {};  //-- No melee if no valid weapon equipped

    tsp_melee_meleeModeOn = true;     
    [true] call tsp_fnc_melee_hideGui;

    //-- Play random ready animation
    _randomReadyAnimation = (selectRandom ([_currentMeleeWeapon, "ready"] call tsp_fnc_melee_getMeleeData))#0#1;
    [_unit, "" , 0, _randomReadyAnimation] spawn tsp_fnc_playGesture;  
    
    //-- Handle inputs   
    if !(isNil "tsp_eh_melee_mouse") then {(findDisplay 46) displayRemoveEventHandler ["MouseButtonDown", tsp_eh_melee_mouse]};  
    if !(isNil "tsp_eh_melee_mouseZ") then {(findDisplay 46) displayRemoveEventHandler ["MouseZChanged", tsp_eh_melee_mouseZ]}; 
    tsp_eh_melee_mouse = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", {[player, _this#1] spawn tsp_fnc_melee_input}];  
    tsp_eh_melee_mouseZ = (findDisplay 46) displayAddEventHandler ["MouseZChanged", {[player, 3] spawn tsp_fnc_melee_input}]; 

    //-- Exit melee mode if interupted by weapon, prone, gesture, or animation change
    _currentWeaponBeforeLoop = currentWeapon _unit;
    while {sleep 1; !isNil "tsp_melee_meleeModeOn"} do {
        _proneCond = (stance _unit == "PRONE");
        _doingGestureCond = (["melee", tsp_gesture_current] call BIS_fnc_inString || tsp_gesture_current == "");
        _doingAnimationCond = (["melee", animationState _unit] call BIS_fnc_inString);
        if ((_currentWeaponBeforeLoop != currentWeapon _unit) || !alive _unit) exitWith {[_unit] call tsp_fnc_melee_off};  //-- Split into 2 if statements cause it wouldnt work right with 1
        if ((!_doingGestureCond && !_doingAnimationCond) || _proneCond) exitWith {[_unit] call tsp_fnc_melee_off};
    };
};

tsp_fnc_melee_off = {    
    params ["_unit"];
    if (isNil "tsp_melee_meleeModeOn") exitWith {};
    tsp_melee_meleeModeOn = nil;
    [_unit, "", 0, "tsp_common_stop", 0, "", true] spawn tsp_fnc_playGesture;  //-- Stop melee gestures
    [false] call tsp_fnc_melee_hideGui;  //-- Bring the gui back
    if !(isNil "tsp_eh_melee_mouse") then {(findDisplay 46) displayRemoveEventHandler ["MouseButtonDown", tsp_eh_melee_mouse]};  
    if !(isNil "tsp_eh_melee_mouseZ") then {(findDisplay 46) displayRemoveEventHandler ["MouseZChanged", tsp_eh_melee_mouseZ]}; 
};

tsp_fnc_melee_getMeleeData = {
    params ["_weapon", "_mode"];
    _allOfTheVariants = [];    
	(configProperties [(configFile >> "CfgWeapons" >> _weapon >> "meleeInfo" >> _mode), "true", true]) apply {
		_allAttributesOfOneVariant = [
			getArray (_x>>"animation"),			
			getArray (_x>>"damage"),	
			getArray (_x>>"damageEnviroment"),			
            getNumber (_x>>"reach"),
            getNumber (_x>>"angle"),
            getArray (_x>>"timing"),
            getArray (_x>>"soundSwing"),
			getArray (_x>>"soundImpact"),
			getArray (_x>>"soundKnockout"),
            getArray (_x>>"blockableDamage")
		];
		_allOfTheVariants pushBack _allAttributesOfOneVariant;
	};
	_allOfTheVariants
};

tsp_fnc_melee_getMeleeWeapon = {
    params ["_unit"];
    _current = currentWeapon _unit;
    _return = "";
    switch (true) do {  //-- Select which melee weapon to use based on what the unit has equipped        
        case (_current == ""): {_return = "tsp_meleeWeapon_fists"};    
        case (count ([_current, "ready"] call tsp_fnc_melee_getMeleeData) > 0): {_return = _current};  //-- Dedicated melee weapons
        case (_current == handgunWeapon _unit): {_return = "tsp_meleeWeapon_pistol"};
        case (_current == primaryWeapon _unit): {
            _return = "tsp_meleeWeapon_rifle";
            {if (count ([_x, "ready"] call tsp_fnc_melee_getMeleeData) > 0) exitWith {_return = _x}} forEach (primaryWeaponItems _unit);  //--Bayonet           
        };
    };    
    _return
};

tsp_fnc_melee_input = {
    params ["_unit", "_input"];

    if (!isNil "tsp_melee_doingMeleeMove") exitWith {};  //-- So u cant spam melee/cant call this function again until it has finished
    tsp_melee_doingMeleeMove = true;

    //-- Select melee action to use     
    _actionToUse = ["main", "alt", "block", "kick"]#_input;
    _actionToUse = selectRandom ([[_unit] call tsp_fnc_melee_getMeleeWeapon, _actionToUse] call tsp_fnc_melee_getMeleeData);  //-- Pick random "v1", "v2" etc from config
    _actionToUse params [
        "_animation",
        "_damage", 
        "_damageEnviroment", 
        "_reach",
        "_angle",
        "_timing", 
        "_soundSwing", 
        "_soundImpact", 
        "_soundKnockout", 
        "_blockableDamage" 
    ];
    _animation params ["_animationType", "_animation"];
    _timing params ["_timeToSwing", "_timeToImpact", "_duration"];
    _damage params ["_damageType", "_damageQuantity", "_knockout"];

    //-- Play animation
    if (_animationType == "Gesture") then {[_unit, "", 0, _animation, -1, "", true] spawn tsp_fnc_playGesture};  
    if (_animationType == "Animation") then {_unit playMoveNow _animation};

    //-- Play swing sound
    sleep _timeToSwing;
    if !(_soundSwing isEqualTo []) then {playSound3D [selectRandom _soundSwing, _unit, false, getPosASL _unit, 3, 1, 20]};

    //-- Impact
    sleep (_timeToImpact - _timeToSwing);
    if (_input in [0,1,3]) then {  //-- Attacking
        //-- Breaching/glass
        if (!isNil "tsp_fnc_breach_door_melee") then {
            _startPos = positionCameraToWorld [0, 0, 0];
            _endPos = positionCameraToWorld [0, 0, 3];
            ([AGLtoASL _startPos, AGLtoASL _endPos, _unit] call tsp_fnc_breach_getDoor) params ["_house", "_door"];            
            if (_door != "") then {[_unit, _house, _door, _damageEnviroment] spawn tsp_fnc_breach_door_melee};            
        };
        [_unit, _damageEnviroment#0] call tsp_fnc_melee_damageWindow;

        _victim = "NOTHING";
        _sound = "tsp_melee\snd\slice1.ogg";

        //-- Select closest in sector
        _distance = _reach;
        {
            if ((_x distance _unit) < _distance && _x != _unit) then {
                if ([position _unit, getDir _unit, _angle, position _x] call BIS_fnc_inAngleSector) then {
                    _victim = _x;
                };
            };
        } forEach (_unit nearEntities _reach);

        //-- Raycast
        _startPos = eyePos _unit; 
        _endPos = _startPos vectorAdd (getCameraViewDirection _unit vectorMultiply _reach);
        _raycast = lineIntersectsSurfaces [_startPos, _endPos, _unit, objNull, true, 1];
        if !(_raycast isEqualTo []) then {_victim = _raycast#0#3};
        if (_victim isEqualTo "NOTHING") exitWith {};  //-- If no victim found

        if (_victim isKindOf "Man") then {
            _sound = selectRandom _soundImpact;

            if (!alive _victim) exitWith {};

            //-- Find bodypart
            _bodypart = [_victim, "IFIRE"] intersect [ASLToAGL _startPos, ASLToAGL _endPos];  //-- Second raycast to get body part
            if !(_bodyPart isEqualTo []) then {_bodyPart = _bodyPart#0#0};  //-- If raycast found something, use it
            _hitPoint = "";
            switch (true) do {  //-- Find ACE bodypart equivelant of memory point from raycast  
                case (["head", _bodyPart, false] call BIS_fnc_inString): {_bodypart = "head"; _hitPoint = "hitHead"};
                case (["neck", _bodyPart, false] call BIS_fnc_inString): {_bodypart = "head"; _hitPoint = "hitHead"};
                case (["spine", _bodyPart, false] call BIS_fnc_inString): {_bodypart = "body"; _hitPoint = "hitBody"};
                case (["arm", _bodyPart, false] call BIS_fnc_inString): {if (["right", _bodyPart, false] call BIS_fnc_inString) then {_bodypart = "hand_r"} else {_bodypart = "hand_l"}; _hitPoint = "hitHands"};
                case (["leg", _bodyPart, false] call BIS_fnc_inString): {if (["right", _bodyPart, false] call BIS_fnc_inString) then {_bodypart = "leg_r"} else {_bodypart = "leg_l"}; _hitPoint = "hitLegs"};
                default {_bodypart = "body"};  //-- Use body if nothing found
            }; 

            _damage = random _damageQuantity;

            //-- Calculate new damage if blocking, also play block noise instead if sufficiently blocked
            if (_victim getVariable ["blocking", false]) then {
                _victimBlockingData = (([([_victim] call tsp_fnc_melee_getMeleeWeapon), "block"] call tsp_fnc_melee_getMeleeData)#0#9);
                {  //-- Search victim's blocking data to see if he is able to block damage, if something found, then reduce damage
                    if (_x#0 == _damageType) exitWith {
                        _damage = _damage * (1 - (_x#1));
                        if (_x#1 > 0.75) then {_sound = _x#2};                        
                    };
                } forEach _victimBlockingData;
            };

            if (isClass(configFile >> "CfgPatches" >> "ace_common") && !ace_medical_disabled) then {  //-- Apply ACE damage  
                [_victim, _damage, _bodypart, _damageType] remoteExec ["ace_medical_fnc_addDamageToUnit", _victim];
            } else {  //-- Apply regular damage
                [_victim, [_hitPoint, ((_victim getHitPointDamage _hitPoint) + _damage)*2]] remoteExec ["setHitPointDamage", _victim];
            }; 

            if (isPlayer _victim) then {[] remoteExec ["BIS_fnc_indicateBleeding", _victim]};

            //-- Knockout        
            if ([headgear _victim] call tsp_fnc_hasArmor && _knockout != 1) then {_knockout = _knockout - 0.25};  //-- If victim has helmet and weapon isnt guaranteed knockout, reduce knockout chace
            if (_bodypart == "head" && (random 1 <= _knockout)) then {
                _sound = selectRandom _soundKnockout;
                if (isClass(configFile >> "CfgPatches" >> "ace_common") && !ace_medical_disabled) then {
                    [_victim, true, 10, true] call ace_medical_fnc_setUnconscious;
                } else {
                    //TODO: Dazed animation
                };
            };

            ["tsp_melee_damageMan", [_unit, _victim]] call CBA_fnc_localEvent;
        }; 

        //-- Sound
        _soundSource = _victim;
        if (isNull _victim) then {_soundSource = _unit};  //-- Use killer as sound source if victim is ground or smthn like that
        playSound3D [_sound, _soundSource, false, getPosASL _soundSource, 4.9, 1, 20];
    } else {  //-- Blocking
        _unit setVariable ["blocking", true, true];  //-- Broadcast blocking publicly so that attackers know          
    };

    //-- Cleanup
    sleep (_duration - (_timeToSwing + _timeToImpact));
    _unit setVariable ["blocking", false, true];

    if (!isNil "tsp_melee_meleeModeOn") then {  //-- Go back to ready if still in melee mode
        _randomReadyAnimation = (selectRandom ([[_unit] call tsp_fnc_melee_getMeleeWeapon, "ready"] call tsp_fnc_melee_getMeleeData))#0#1;
        [_unit, "" , 0, _randomReadyAnimation, -1, "", true] spawn tsp_fnc_playGesture;
    };

    sleep 0.2;  //-- To prevent spam
    tsp_melee_doingMeleeMove = nil; 
};

tsp_fnc_melee_damageWindow = {
    params ["_unit", "_damageToDo"];
    _startPos = eyePos _unit; 
    _endPos = _startPos vectorAdd (getCameraViewDirection _unit vectorMultiply 3);

	//-- Find house
    _intersections = (lineIntersectsSurfaces [_startPos, _endPos, _unit, objNull, true, 1, "GEOM"]);
    if (_intersections isEqualTo []) exitWith {};
	_intersections#0 params ["_intersectPos","_normalDir","_house"];

    //-- Find window selection
    _window = [_house, "FIRE"] intersect [ASLToAGL _startPos, ASLToAGL _endPos];	
    if (_window isEqualTo []) exitWith {}; 
    _window#0 params ["_selection","_distance"];

    //-- Find corresponding hitpoint to selection
    _hitpoints = getAllHitPointsDamage _house;
    _hitpoints params ["_nothingUseful", "_hitpoints", "_damage"];	
    _closest = [_selection, [0,0,0], 0];
    {
        _hitpoint = _x;
        _hitpointPos = _house modelToWorld (_house selectionPosition _hitpoint);
        if ([_selection, _hitpoint] call BIS_fnc_inString || [_hitpoint, _selection] call BIS_fnc_inString) then {
            if (["glass", _hitpoint] call BIS_fnc_inString || ["window", _hitpoint] call BIS_fnc_inString) then {
                _closest = [_hitpoint, _hitpointPos, _damage#_forEachIndex];
            };
        };
    } forEach _hitpoints;

    //-- Damage hitpoint
    _closest params ["_selection", "_position", "_health"];    
    [_house, [_selection, _health + _damageToDo]] remoteExec ["setHit", 0];
    _sound = format ["A3\Sounds_F\arsenal\sfx\bullet_hits\glass_0%1.wss", (floor random 8) + 1]; 
    playSound3D [_sound, _position, false, AGLtoASL _position, 2, 1, 25];
};

tsp_fnc_melee_hideGui = {
    params ["_hide"];
    if (_hide) then {
        //-- Hide action menu
        inGameUISetEventHandler ["PrevAction", "true"];  
        inGameUISetEventHandler ["NextAction", "true"];
        inGameUISetEventHandler ["Action", "true"];
        _hud = shownHUD; _hud set [7, false]; showHUD _hud;

        //-- Hide firemode indicator
        ((uiNamespace getVariable ["ACE_dlgSoldier", displayNull]) displayCtrl 187) ctrlSetFade 1; 
        ((uiNamespace getVariable ["ACE_dlgSoldier", displayNull]) displayCtrl 187) ctrlCommit 0;
    } else {
        inGameUISetEventHandler ["PrevAction", "false"];
        inGameUISetEventHandler ["NextAction", "false"];
        inGameUISetEventHandler ["Action", "false"];
        _hud = shownHUD; _hud set [7, true]; showHUD _hud;

        ((uiNamespace getVariable ["ACE_dlgSoldier", displayNull]) displayCtrl 187) ctrlSetFade 0; 
        ((uiNamespace getVariable ["ACE_dlgSoldier", displayNull]) displayCtrl 187) ctrlCommit 0;    
    };
};

//_helper = createVehicle ["Sign_Arrow_Blue_F", ASLToATL _startPos, [], 0, "CAN_COLLIDE"];