#include "character.h"

bool is_editor()
{
	return Engine::get_singleton()->is_editor_hint();
}

void print_vector(Vector3 vector, String message)
{
	UtilityFunctions::print(message);
	UtilityFunctions::print_rich(vector);
}

void Character::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("handle_navigation", "to"), &Character::handle_navigation);
	ClassDB::bind_method(D_METHOD("set_mesh_instance_ptr", "mesh"), &Character::set_mesh_instance_ptr);
	ClassDB::bind_method(D_METHOD("get_mesh_instance_ptr"), &Character::get_mesh_instance_ptr);
	ClassDB::bind_method(D_METHOD("set_movement", "_movement"), &Character::set_movement);
	ClassDB::bind_method(D_METHOD("get_movement"), &Character::get_movement);
	ClassDB::bind_method(D_METHOD("get_navigation_agent_node"), &Character::get_navigation_agent_node);
	ClassDB::bind_method(D_METHOD("set_navigation_agent_node", "path"), &Character::set_navigation_agent_node);

	ADD_PROPERTY(
		PropertyInfo(Variant::NODE_PATH, "mesh_instance_ptr"),
		"set_mesh_instance_ptr",
		"get_mesh_instance_ptr"
	);

	ADD_PROPERTY(
		PropertyInfo(Variant::NODE_PATH, "movement"),
		"set_movement",
		"get_movement"
	);

	ADD_PROPERTY(
		PropertyInfo(Variant::NODE_PATH, "navigation_agent_node"),
		"set_navigation_agent_node",
		"get_navigation_agent_node"
	);

}

void Character::handle_navigation(Vector3 position)
{
	nav_agent->set_target_position(position);
	// nav_agent->set_target_location(position);
}

NodePath Character::get_mesh_instance_ptr()
{
	return mesh_instance_ptr;
}

void Character::set_mesh_instance_ptr(NodePath mesh_instance)
{
	mesh_instance_ptr = mesh_instance;
}

NodePath Character::get_navigation_agent_node()
{
	return navigation_agent_node;
}

void Character::set_navigation_agent_node(NodePath path)
{
	navigation_agent_node = path;
}

void Character::_ready()
{
	if (is_editor()) return;
	mesh_instance = get_node<MeshInstance3D>(mesh_instance_ptr);
	nav_agent = get_node<NavigationAgent3D>(navigation_agent_node);
}

void Character::_enter_tree()
{
	Movement _movement = Movement();
	add_child(&_movement);
}