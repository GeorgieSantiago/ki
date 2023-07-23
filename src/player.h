#ifndef COQUI_PLAYER_H
#define COQUI_PLAYER_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node3d.hpp>

using namespace godot;

class Player : public Node3D
{
	GDCLASS(Player, Node3D)
protected:
	static void _bind_methods() {};
};

#endif