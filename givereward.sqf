reward_active = true; //type false instead of true to make this file inactive.
_timeout = 1200; //amount of seconds before rewarding player again, since i typed "1200" it will be 20mins.
_weapon = currentWeapon player; //ignore this line.

while {reward_active} do {
    _rndLOut=floor(random 25);
    _ailoadout=
    switch (_rndLOut) do
    {
      case 0: {["LeeEnfield"]};
      case 1: {["AKS_74U"]};
      case 2: {["AK_74"]}; 
      case 3: {["AKS_74_kobra"]};
      case 4: {["AK_47_M"]};
      case 5: {["Winchester1866"]};
      case 6: {["MP5A5"]};
      case 7: {["huntingrifle"]};
	  case 8: {["M40A3"]};
      case 9: {["VSS_vintorez"]};
      case 10: {["MeleeHatchet"]}; 
      case 11: {["M9"]};
      case 12: {["FN_FAL"]};
      case 13: {["revolver_EP1"]};
      case 14: {["MP5A5","30Rnd_9x19_MP5"]};
      case 15: {["M14_EP1"]};
      case 16: {["M249_DZ"]};
      case 17: {["ItemMap"]}; 
      case 18: {["ItemGPS"]};
      case 19: {["M24"]};
      case 20: {["M16A4_ACG"]};
      case 21: {["M16A2"]};
      case 22: {["M4A1_Aim"]};
	  case 23: {["M1014"]};
	  case 24: {["MP5SD"]};    
    };
 

    _aiwep = _ailoadout select 0;  
    player addweapon _aiwep;

cutText [format["%1 have been given a %2 that has stacked on top of your %3", name player, _aiwep, _weapon], "PLAIN"];
sleep _timeout;
};