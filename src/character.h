#ifndef KI_CHARACTER_H
#define KI_CHARACTER_H

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/navigation_agent3d.hpp>
#include "movement.h"

using namespace godot;

class Character : public CharacterBody3D
{
	GDCLASS(Character, CharacterBody3D)

public:
	static void _bind_methods();
	MeshInstance3D* mesh_instance;
	NavigationAgent3D* nav_agent;

    NodePath movement;
    NodePath get_movement()  { return movement; }
	void set_movement(NodePath _movement) { movement = _movement; }

	NodePath mesh_instance_ptr;
	NodePath get_mesh_instance_ptr();
	void set_mesh_instance_ptr(NodePath mesh_instance);

	NodePath navigation_agent_node;
	NodePath get_navigation_agent_node();
	void set_navigation_agent_node(NodePath path);

	void handle_navigation(Vector3 position);
	void _ready() override;
	void _enter_tree();
};

#endif