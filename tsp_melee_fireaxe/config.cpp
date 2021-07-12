class CfgPatches {
	class tsp_melee_fireaxe {
		requiredAddons[] = {"tsp_melee"};
		units[] = {};
	};
};

class CfgWeapons {
	class tsp_meleeWeapon_axe;
	class tsp_meleeWeapon_fireaxe: tsp_meleeWeapon_axe {
		scope = 2;
		model="\tsp_melee_fireaxe\fireaxe.p3d";
		picture="\tsp_melee_fireaxe\gui\ui.paa";
		displayname="Fireaxe";
		descriptionShort="Special axe used by fire departments for various purposes.";
	};
};