//-- SETTINGS
	//-- Moveset
    [
        "tsp_cba_melee_moveset", "CHECKBOX",
        ["Enable Knife Moveset", "Enables custom moveset when knife is equipped."],
        "TSP Melee", true, true, {}
    ] call CBA_Settings_fnc_init;

    //-- Polling Rate
    [
	    "tsp_cba_melee_movesetPoll", "SLIDER",
        ["Knife Moveset Polling Rate", "How often the script runs."],
        "TSP Melee", [0, 1, 0.25], false, {}
    ] call CBA_Settings_fnc_init;