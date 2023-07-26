#ifndef KI_MOVEMENT_H
#define KI_MOVEMENT_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include "character.h"

using namespace godot;

class Movement : public Node
{
    GDCLASS(Movement, Node)
private:
    MeshInstance3D* get_mesh_instance(CharacterBody3D* character);
    MeshInstance3D* mesh_instance;
public:
	const double speed = 5.0;
	const double jump_velocity = 4.5;
	const double angular_velocity = 0.1;
	float gravity = ProjectSettings::get_singleton()->get_setting("physics/3d/default_gravity");
protected:
    static void _bind_methods();
    virtual void _move(CharacterBody3D* character, float delta);
};

#endif