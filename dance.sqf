//                         _         _                   _                _        ______ 
//                        | |       | |                 | |              | |       | ___ \
//   _ __ ___    __ _   __| |  ___  | |__   _   _   ___ | | __ ___   ___ | |_  ___ | |_/ /
//  | '_ ` _ \  / _` | / _` | / _ \ | '_ \ | | | | / __|| |/ // _ \ / _ \| __|/ _ \|    / 
//  | | | | | || (_| || (_| ||  __/ | |_) || |_| | \__ \|   <|  __/|  __/| |_|  __/| |\ \ 
//  |_| |_| |_| \__,_| \__,_| \___| |_.__/  \__, | |___/|_|\_\\___| \___| \__|\___|\_| \_|
//                                           __/ |                                        
//                                          |___/                                          

//this will allow players to celebrate only when the campfire is burning  ^.^
private["_ent"];
_ent = _this select 3;
player removeAction s_player_dance;
s_player_dance = -1;
 
player playMove "ActsPercMstpSnonWnonDnon_DancingDuoStefan";
 
cutText ["So you survived another day in the Hunters Den.....time to celebrate! Press \ to stop","PLAIN DOWN",4];
 
r_interrupt = false;
_animState = animationState player;
r_doLoop = true;
_started = false;
_finished = false;
 
    while {r_doLoop} do {
        _animState = animationState player;
        _isDancing = ["ActsPercMstpSnonWnonDnon_DancingDuoStefan",_animState] call fnc_inString;
        if (_isDancing) then {
            _started = true;
        };
        if (_started and !_isDancing) then {
            r_doLoop = false;
            _finished = true;
        };
        if (r_interrupt) then {
            r_doLoop = false;
        };
        sleep 0.1;
    };
    r_doLoop = false;
 
if (_finished) then {
 
cutText ["SkeeteR thanks you for the performance","PLAIN DOWN"];
 
} else {
r_interrupt = false;
[objNull, player, rSwitchMove,""] call RE;
player playActionNow "stop";
player addAction ["Stop Dancing","Fixes\stopdance.sqf","", 0, false, true, "",""];
cutText ["SkeeteR thanks you for the quick performance","PLAIN DOWN"];
};
