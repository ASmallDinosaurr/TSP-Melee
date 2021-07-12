class CfgPatches {
	class tsp_melee_ak {
		requiredAddons[] = {"cba_common","tsp_melee"};
		units[] = {};
	};
};

class Extended_PostInit_EventHandlers {
    class melee_ak {init = "['tsp_meleeWeapon_ak','tsp_meleeWeapon_ak_pointer'] call tsp_fnc_melee_bayonetSwap;";};
};

class rhs_russian_ak_barrel_slot {class compatibleItems;};
class CfgWeapons {
	class tsp_meleeWeapon_knifeUp;
	class tsp_meleeWeapon_ak: tsp_meleeWeapon_knifeUp {
		scope = 2;
		model="\tsp_melee_ak\ak.p3d";
		picture="\tsp_melee_ak\gui\ui.paa";
		displayname="AK-74 Bayonet";
		descriptionShort="Russian standard issue AK-74 bayonet";
	};

	class tsp_meleeWeapon_pointer;
	class tsp_meleeWeapon_ak_pointer: tsp_meleeWeapon_pointer {
		scope = 2;
		displayname="AK-74 Bayonet";
		descriptionShort="Russian standard issue AK-74 bayonet";
		model = "\tsp_melee_ak\akpointer.p3d";
		picture="\tsp_melee_ak\gui\ui.paa";
	};

	class Rifle_Base_F {class weaponSlotsInfo;};
	class rhs_weap_ak74m_Base_F: Rifle_Base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class pointerSlot: rhs_russian_ak_barrel_slot {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_ak_pointer = 1;};
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
			};
		};
	};
	class rhs_weap_ak74m: rhs_weap_ak74m_Base_F {
		#include "\tsp_melee_ak\weaponSlotsInfo.hpp"
	};
	class rhs_weap_ak74m_npz: rhs_weap_ak74m {
		#include "\tsp_melee_ak\weaponSlotsInfo.hpp"
	};
	
	class rhs_weap_akm: rhs_weap_ak74m {class weaponSlotsInfo;};
	class rhs_weap_ak103_base: rhs_weap_akm {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class pointerSlot: rhs_russian_ak_barrel_slot {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_ak_pointer = 1;};
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
			};
		};
	};
	class rhs_weap_ak103: rhs_weap_ak103_base {
		#include "\tsp_melee_ak\weaponSlotsInfo.hpp"
	};
	class rhs_weap_ak103_1: rhs_weap_ak103_base {
		#include "\tsp_melee_ak\weaponSlotsInfo.hpp"
	};
	class rhs_weap_ak103_1_npz: rhs_weap_ak103_1 {
		#include "\tsp_melee_ak\weaponSlotsInfo.hpp"
	};
	class rhs_weap_ak103_2: rhs_weap_ak103_base {
		#include "\tsp_melee_ak\weaponSlotsInfo.hpp"
	};
	class rhs_weap_ak103_2_npz: rhs_weap_ak103_2 {
		#include "\tsp_melee_ak\weaponSlotsInfo.hpp"
	};
	class rhs_weap_ak103_npz: rhs_weap_ak103 {
		#include "\tsp_melee_ak\weaponSlotsInfo.hpp"
	};


};