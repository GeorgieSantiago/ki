#include "character.h"

void Character::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("handle_navigation", "to"), &Character::handle_navigation);
	ClassDB::bind_method(D_METHOD("set_mesh_instance_ptr", "mesh"), &Character::set_mesh_instance_ptr);
	ClassDB::bind_method(D_METHOD("get_mesh_instance_ptr"), &Character::get_mesh_instance_ptr);
	ClassDB::bind_method(D_METHOD("get_navigation_agent_node"), &Character::get_navigation_agent_node);
	ClassDB::bind_method(D_METHOD("set_navigation_agent_node", "path"), &Character::set_navigation_agent_node);
	ClassDB::bind_method(D_METHOD("get_debug"), &Character::get_debug);
	ClassDB::bind_method(D_METHOD("set_debug", "mode"), &Character::set_debug);

	ADD_PROPERTY(
	    PropertyInfo(Variant::BOOL, "debug"),
		"set_debug",
		"get_debug"
	);

	ADD_PROPERTY(
		PropertyInfo(Variant::NODE_PATH, "mesh_instance_ptr"),
		"set_mesh_instance_ptr",
		"get_mesh_instance_ptr"
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

bool Character::get_debug()
{
	return debug;
}

void Character::set_debug(bool mode)
{
	debug = mode;
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
	if (this->is_editor()) return;
	mesh_instance = get_node<MeshInstance3D>(mesh_instance_ptr);
	nav_agent = get_node<NavigationAgent3D>(navigation_agent_node);
}

void Character::_physics_process(double delta)
{
	//@TODO use navigation paths for input value
	if (is_editor()) return;
	//From nav agent
	Vector3 velocity = get_velocity();
	Vector3 direction;
	if (debug) {
		//Keyboard controls
		Input* input_ptr = Input::get_singleton();
		if (!is_on_floor())
		{
			velocity.y -= gravity * delta;
		}

		if (input_ptr->is_action_just_pressed("ui_accept"))
		{
			velocity.y = jump_velocity;
		}

		Vector2 input_dir = input_ptr->get_vector("ui_left", "ui_right", "ui_up", "ui_down");
		direction = (Vector3(input_dir.x, 0, input_dir.y)).normalized();
	}
	else {
		Vector3 next_location = nav_agent->get_next_path_position();
		Vector3 next_location_dir = get_global_position().direction_to(next_location);
		direction = (Vector3(next_location_dir.x, 0, next_location_dir.z)).normalized();
	}

	bool has_direction = direction != Vector3(0, 0, 0);
	velocity.x = has_direction 
		? direction.x * speed 
		: UtilityFunctions::move_toward(velocity.x, 0, speed);
	velocity.z = has_direction 
		? direction.z * speed 
		: UtilityFunctions::move_toward(velocity.z, 0, speed);

	set_velocity(velocity);
	move_and_slide();

	if (has_direction) {
		mesh_instance->set_rotation(Vector3(
			mesh_instance->get_rotation().x,
			UtilityFunctions::lerp_angle(mesh_instance->get_rotation().y, atan2(-direction.x, -direction.z), delta * speed),
			mesh_instance->get_rotation().z
		));
	}
}

bool Character::is_editor()
{
	return Engine::get_singleton()->is_editor_hint();
}

void Character::print_vector(Vector3 vector, String message)
{
	UtilityFunctions::print(message);
	UtilityFunctions::print_rich(vector);
}