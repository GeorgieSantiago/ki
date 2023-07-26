#include "movement.h"

void Movement::_bind_methods()
{
    BIND_VIRTUAL_METHOD(Movement, _move);
}

void Movement::_move(CharacterBody3D* character, float delta)
{
	if (mesh_instance == nullptr)
	{
        mesh_instance = get_mesh_instance(character);
	}
	
    //Keyboard controls
	Input* input_ptr = Input::get_singleton();
	Vector3 velocity = character->get_velocity();
    Vector3 direction;
    if (!character->is_on_floor())
	{
		velocity.y -= gravity * delta;
	}

	if (input_ptr->is_action_just_pressed("ui_accept"))
	{
		velocity.y = jump_velocity;
	}

	Vector2 input_dir = input_ptr->get_vector("ui_left", "ui_right", "ui_up", "ui_down");
	direction = (Vector3(input_dir.x, 0, input_dir.y)).normalized();
	bool has_direction = direction !=  Vector3(0, 0,0);
	velocity.x = has_direction 
		? direction.x * speed 
		: UtilityFunctions::move_toward(velocity.x, 0, speed);
	velocity.z = has_direction 
		? direction.z * speed
		: UtilityFunctions::move_toward(velocity.z, 0, speed);

	character->set_velocity(velocity);
	character->move_and_slide();

	if (has_direction) {
		mesh_instance->set_rotation(Vector3(
			mesh_instance->get_rotation().x,
			UtilityFunctions::lerp_angle(mesh_instance->get_rotation().y, atan2(-direction.x, -direction.z), delta * speed),
			mesh_instance->get_rotation().z
		));
	}
}

MeshInstance3D* Movement::get_mesh_instance(CharacterBody3D* character)
{
	if (mesh_instance != nullptr) { return mesh_instance; }
	Array children = get_children();
    for(int i = 0; i < get_child_count();i++)
	{
		MeshInstance3D* instance = Object::cast_to<MeshInstance3D>(children[i]);
		if (instance != nullptr)
		{
			mesh_instance = instance;
			break;
		}
	}
	return mesh_instance;
}