#ifndef KI_CHARACTER_H
#define KI_CHARACTER_H

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/navigation_agent3d.hpp>

using namespace godot;

class Character : public CharacterBody3D
{
	GDCLASS(Character, CharacterBody3D)

private:
	bool is_editor();
	void print_vector(Vector3 vector, String message);
protected:
	static void _bind_methods();
	const double speed = 5.0;
	const double jump_velocity = 4.5;
	const double angular_velocity = 0.1;
	float gravity = ProjectSettings::get_singleton()->get_setting("physics/3d/default_gravity");
	MeshInstance3D* mesh_instance;
	NavigationAgent3D* nav_agent;
public:

	bool debug = false;
	bool get_debug();
	void set_debug(bool mode);
	
	NodePath mesh_instance_ptr;
	NodePath get_mesh_instance_ptr();
	void set_mesh_instance_ptr(NodePath mesh_instance);

	NodePath navigation_agent_node;
	NodePath get_navigation_agent_node();
	void set_navigation_agent_node(NodePath path);

	void handle_navigation(Vector3 position);
	void _ready() override;
	void _physics_process(double delta) override;
};

#endif