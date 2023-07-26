#ifndef KI_PLAYER_H
#define KI_PLAYER_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include "character.h"

using namespace godot;

class Player : public Character
{
	GDCLASS(Player, Character)
protected:
	static void _bind_methods() {};
};

#endif